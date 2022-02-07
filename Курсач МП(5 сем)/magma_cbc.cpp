#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

static unsigned char S_box[8][16]=
{
	{9,6,3,2,8,11,1,7,10,4,14,15,12,0,13,5},
	{3,7,14,9,8,10,15,0,5,2,6,12,11,4,13,1},
	{14,4,6,2,11,3,13,8,12,15,5,10,0,7,1,9},
	{14,7,10,12,13,1,3,9,0,2,11,4,15,8,5,6},        //Узел замены RFC4357
	{11,5,1,9,8,13,15,0,14,4,2,3,12,7,10,6},
	{3,10,13,12,1,2,0,11,7,5,9,4,8,15,14,6},
	{1,13,2,9,7,10,6,0,8,12,4,5,15,3,11,14},
	{11,10,15,5,0,12,14,8,6,2,3,9,1,7,13,4}
};


uint32_t File_Size(char*);
uint32_t Blocks(uint32_t);

static uint8_t Key[32];
static uint8_t Key_Iter[32][3];

void Add_mod2(uint8_t*, uint8_t*, uint8_t*);
void addition_mod2(uint8_t*, uint8_t*, uint8_t*);
void add_mod32(uint8_t*, uint8_t*, uint8_t*);

void Produce_key();
void Produce_IV(uint8_t*);

void GOST_28147_89_T(uint8_t*, uint8_t*);
void GOST_28147_89_Extend_Key(uint8_t[32][3]);
void GOST_28147_89_g(uint8_t*, uint8_t*, uint8_t*);
void GOST_28147_89_G(uint8_t*, uint8_t*, uint8_t*);
void GOST_28147_89_G_Finally(uint8_t*, uint8_t*, uint8_t*);
void GOST_28147_89_encrypt(uint8_t *, uint8_t*);
void GOST_28147_89_decrypt(uint8_t*, uint8_t*);


int main(int argc, char* argv[]) 
{
	char INPUT_DATA_1[32], INPUT_DATA_2[32], E, K, T = 'N'; 
	uint8_t Buff[8], Enc[8], IV[8];
	cout<<"Введите 'E' для шифрования, 'D' для расшифровки файла"<<endl;
	cin>>E;
	if(E == 'E') 
	{
		cout<<"Введите файл для шифрования: "<<endl;
		cin>>INPUT_DATA_1;
		ifstream fs(INPUT_DATA_1, ios_base::binary);
		while(!fs.is_open())
		{
			cout<<"Файл не существует. Пожалуйста, попробуйте еще раз: "<<endl;
			cin>>INPUT_DATA_1;
			fs.open(INPUT_DATA_1, ios_base::binary);
		}
		cout<<"Введите 'Y' для создания ключа или 'N', чтобы использовать свой ключ:"<<endl;
		cin>>K;
		if(K == 'Y') 
		{
			cout<<"Ваш ключ будет сохранен как 'key.txt'"<<endl;
			Produce_key();
		}
		else if(K == 'N')
		{
			cout<<"Введите свой ключ файл:"<<endl;
			cin>>INPUT_DATA_2;
			ifstream Key_file(INPUT_DATA_2, ios_base::binary);
			while(!Key_file.is_open())
			{
				cout<<"Что-то не так с вашим ключевым файлом. Пожалуйста, попробуйте еще раз: "<<endl;
				cin>>INPUT_DATA_2;
				Key_file.open(INPUT_DATA_2, ios_base::binary);
			}
			Key_file.read((char*)Key, 32);
			Key_file.close();
		}
		GOST_28147_89_Extend_Key(Key_Iter);
		Produce_IV(IV);
		
		cout<<"Зашифрованный текст будет сохранен как 'ENCRYPTED.txt'"<<endl;
		ofstream OUT("ENCRYPTED.txt" , ios_base::binary);
		
		for(int i = 0; i < 8; i++)
		{
			OUT<<IV[i];
		}
		uint8_t Buff[8];
		for(int i = 0; i < 8; i++)
		{
			Buff[i] = 0;
		}
		
		uint32_t size = File_Size(INPUT_DATA_1);
		uint32_t Blocks_32 = Blocks(size);
		int cursor = 0, temp = 8;
		for(int k = 0; k < Blocks_32; k++) 
		{
			if((cursor + temp) <= size) 
			{
				fs.read((char*)Buff, temp);
				Add_mod2(IV, Buff, IV);
				GOST_28147_89_encrypt(IV, IV);
				for(int i = 0; i < 8; i++) OUT<<IV[i];
				cursor += temp;
			}
			else 
			{
				temp = size - cursor;
				if(temp > 0) 
				{
					for(int i = 0; i < 8; i++) Buff[i] = 0;
					fs.read((char*)Buff, temp);
					Add_mod2(IV, Buff, IV);
					GOST_28147_89_encrypt(IV, IV);
					for(int i = 0; i < 8; i++) OUT<<IV[i]; 
				}
			}
		}
		fs.close();
		OUT.close();
		cout<<"Готово!"<<endl;
	}
	else if(E == 'D') 
	{
		cout<<"Введите файл для расшифровки: "<<endl;
		cin>>INPUT_DATA_1;
		ifstream CT(INPUT_DATA_1, ios_base::binary);
	
		while(!CT.is_open())
		{
			cout<<"Файл не найден. Пожалуйста, попробуйте еще раз: "<<endl;
			cin>>INPUT_DATA_1;
			CT.open(INPUT_DATA_1, ios_base::binary);
		}
		
		cout<<"Введите файл, содержащий ключ:"<<endl;
		cin>>INPUT_DATA_2;
		ifstream Key_file(INPUT_DATA_2, ios_base::binary);
		
		while(!Key_file.is_open())
		{
			cout<<"Что-то не так с файлом, содержащим ключ. Пожалуйста, попробуйте еще раз: "<<endl;
			cin>>INPUT_DATA_2;
			Key_file.open(INPUT_DATA_2, ios_base::binary);
		}
		
		Key_file.read((char*)Key, 32);
		Key_file.close();
		GOST_28147_89_Extend_Key(Key_Iter);
		CT.read((char*)IV, 8);
	
		cout<<"Введите как назвать открытый текстовый файл: "<<endl;
		cin>>INPUT_DATA_2;
		uint8_t Gamma[8];
		long size = File_Size(INPUT_DATA_1) - 8;
		long Blocks_32 = Blocks(size);	
	
		ofstream Open_text(INPUT_DATA_2, ios_base::binary);
		long cursor = 0, temp = 8;
		for(int i = 0; i < 8; i++)
		{
			Enc[i] = 0;
		}
		for(int k = 0; k < Blocks_32; k++)
		{
			if((cursor + temp) <= size) 
			{
				CT.read((char*)Enc, temp);
				for(int i = 0; i < 8; i++) 
				{
					Gamma[i] = Enc[i];
				}
				GOST_28147_89_decrypt(Enc, Enc);
				Add_mod2(IV, Enc, Enc);
				for(int i = 0; i < 8; i++) 
				{
					Open_text<<Enc[i];
					IV[i] = Gamma[i];
				}
				cursor += temp;	
			}
			else
			{
				temp = size - cursor;
				if(temp > 0)
				{
					for(int i = 0; i < 8; i++) Enc[i] = 0;
					CT.read((char*)Enc, temp);
					for(int i = 0; i < 8; i++)
					{
						Gamma[i] = Enc[i];
					}
					GOST_28147_89_decrypt(Enc, Enc);
					Add_mod2(IV, Enc, Enc);
					for(int i = 0; i < 8; i++) Open_text<<Enc[i];
				}
			}
		}
		CT.close();
		Open_text.close();
		cout<<"Готово"<<endl;
	}
	return 0;
}

void Add_mod2(uint8_t* A, uint8_t* B, uint8_t* C)         //Сложение двух двоичных векторов по mod2 (каждый байт 1-го ксорим с соотв байтом 2-го; результат пишем в 3-й вектор)
{
	for(int i = 0; i < 8; i++) C[i] = A[i]^B[i];
}

void addition_mod2(uint8_t* A, uint8_t* B, uint8_t* C)
{
	for(int i = 0; i < 4; i++) C[i] = A[i]^B[i];
}
void add_mod32(uint8_t* A, uint8_t* B, uint8_t* C)        //Сложение 2-х двоичных векторов по mod32 (2 исходных 4-байтовых вектора представ. как два 32битных числа и затем складываются)
{
	uint8_t inner = 0;
	for(int i = 3; i >= 0; i--) 
	{
		inner = A[i] + B[i] + (inner >> 8);
		C[i] = inner & 0xff;
	}
}

uint32_t File_Size(char* file) 
{
	ifstream stream(file, ios_base::binary);
	uint32_t cursor, length;
	cursor = stream.tellg();
	stream.seekg(0,ios_base::end);
	length = stream.tellg();;
	stream.seekg(0,ios_base::beg);
	stream.close();
	return length;
}

uint32_t Blocks(uint32_t size)
{
	if(size % 8 == 0) return size/8;
	else return size/8 + 1;
}

void Produce_key() 
{
	ofstream out;
	out.open("key.txt");
	random_device rd;
	uniform_int_distribution<uint32_t> distr;
	for(int i = 0; i < 32; i++) 
	{
		Key[i] = distr(rd);
		out<<Key[i];
	}
	out.close();
}
void Produce_IV(uint8_t* IV)                 //Отвечает за синхропосылку(IV)
{
	random_device rd;
	uniform_int_distribution<uint32_t> distr;
	for(int i = 0; i < 8; i++) 
	{
		IV[i] = distr(rd);
	}
}

void GOST_28147_89_T (uint8_t *in_data, uint8_t *out_data)               //Функция, выполняющая нелинейное биективное преобразование
{
	uint8_t first_section_Byte, sec_section_Byte;
	for(int i = 0; i < 4; i ++) 
	{
		first_section_Byte = (in_data[i] & 0xf0) >> 4;
		sec_section_Byte = (in_data[i] & 0x0f);
		first_section_Byte = S_box[i*2][first_section_Byte];
		sec_section_Byte = S_box[i*2 + 1][sec_section_Byte];
		out_data[i] = (first_section_Byte << 4) | sec_section_Byte; 
	}
}

void GOST_28147_89_Extend_Key(uint8_t Key_Iter[32][3]) 
{
	for(int i = 0; i < 24; i++) 
	{
		for(int j = 0; j < 4; j++) Key_Iter[i][j] = Key[(i%8)*4+j];	
	}
	for(int i = 24; i < 32; i++) 
	{
		for(int j = 0; j < 4; j++) Key_Iter[i][j] = Key[28-(i%8)*4+j];
	}
}

void GOST_28147_89_g(uint8_t* Key, uint8_t* B, uint8_t* out_data)                //Сложение правой части блока с итерационным ключом по модулю 32, нелинейное биективное преобразование
{                                                                               //сдвиг влево на 11 разрядов (циклический сдвиг)
	uint8_t inner[4];
	uint32_t out_data_32 = 0;
	add_mod32(B, Key, inner);
	GOST_28147_89_T(inner, inner);
	out_data_32 = inner[0];
	out_data_32 = (out_data_32 << 8) + inner[1];
	out_data_32= (out_data_32 << 8) + inner[2];
	out_data_32 = (out_data_32 << 8) + inner[3];
	out_data_32 = (out_data_32 << 11) | (out_data_32 >> 21);
	for(int i = 3; i >= 0; i--) out_data[i] = out_data_32 >> ((3 - i)*8);
}

void GOST_28147_89_G(uint8_t* Key, uint8_t* A, uint8_t* out_data)           //Представляет собой одну итерацию цикла зашифрования или расшифрования (с 1 по 31)
{                                                                          //включает в себя преобразование g, слодение по mod2 рез-та преобразования g с правой половиной блока
	uint8_t a_0[4];                                                       //обмен содержимым между правой и левой частью блока
	uint8_t a_1[4];
	uint8_t G[4];
	for(int i = 0; i < 4; i++) 
	{
		a_0[i] = A[i + 4];
		a_1[i] = A[i];
	}
	GOST_28147_89_g(Key, a_0, G);
	addition_mod2(a_1, G, G);
	for(int i = 0; i < 4; i++) 
	{
		a_1[i] = a_0[i];
		a_0[i] = G[i];
	}
	for(int i = 0; i < 4; i++)
	{
		out_data[i] = a_1[i];
		out_data[4 + i] = a_0[i];
	}
}

void GOST_28147_89_G_Finally(uint8_t* Key, uint8_t* A, uint8_t *out_data)   //финальное преобразование. 32 итерация цикла шифр/дешифр. Отсутствует обмен значениями между правой и левой частями
{
	uint8_t a_0[4];
	uint8_t a_1[4]; 
	uint8_t G[4];
	for(int i = 0; i < 4; i++) 
	{
		a_0[i] = A[i + 4];
		a_1[i] = A[i];
	}
	GOST_28147_89_g(Key, a_0, G);
	addition_mod2(a_1, G, G);
	for(int i = 0; i < 4; i++) a_1[i] = G[i];
	for(int i = 0; i < 4; i++) 
	{
		out_data[i] = a_1[i];
		out_data[4 + i] = a_0[i];
	}
}

void GOST_28147_89_encrypt(uint8_t *blk, uint8_t *OUTPUT_block)            //Функция для шифровки ( с 1 по 31 выполняется преобр G, 32  - преоьразование G_finally)
{
	GOST_28147_89_G(Key_Iter[0], blk, OUTPUT_block);
	for(int i = 1; i < 31; i++) GOST_28147_89_G(Key_Iter[i],OUTPUT_block, OUTPUT_block);
	GOST_28147_89_G_Finally(Key_Iter[31], OUTPUT_block, OUTPUT_block);	
}

void GOST_28147_89_decrypt(uint8_t *blk, uint8_t *OUTPUT_block)            //Функция для дешифра
{
	GOST_28147_89_G(Key_Iter[31], blk, OUTPUT_block);
	for(int i = 30; i > 0; i--) GOST_28147_89_G(Key_Iter[i], OUTPUT_block, OUTPUT_block);
	GOST_28147_89_G_Finally(Key_Iter[0], OUTPUT_block, OUTPUT_block);	
}
