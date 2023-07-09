
// Простенькая реализация AES-128 в режиме ECB(не рекомендуется) с функцией выработки ключа PBKDF2-HMAC-SHA1


#include <iostream>
#include <fstream>
#include <string>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>
#include <cryptopp/pwdbased.h>
#include <cryptopp/sha.h>

using namespace std;
using namespace CryptoPP;

int main() {
    // Ввод пароля
    string password;
    cout << "Введите пароль: ";
    cin >> password;

    // Ввод соли
    string salt;
    cout << "Введите соль: ";
    cin >> salt;

    // Входные параметры
    int iterations = 65;
    int dkLen = 16; // Длина ключа в байтах (128 бит)

    // Выработка ключа с использованием PBKDF2-HMAC-SHA1
    SecByteBlock key(dkLen);
    PKCS5_PBKDF2_HMAC<SHA1> pbkdf2;
    pbkdf2.DeriveKey(key, key.size(), 0, (byte*)password.data(), password.size(), (byte*)salt.data(), salt.size(), iterations);

    // Открытие файла с исходными данными
    string input_file = "test.txt";
    ifstream ifs(input_file, ios::binary);
    if (!ifs) {
        cerr << "Не удалось открыть файл с исходными данными." << endl;
        return 1;
    }

    // Чтение данных из файла
    string data((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));

    // Шифрование данных с использованием AES-128 в режиме ECB
    string ciphertext;
    ECB_Mode<AES>::Encryption e;
    e.SetKey(key, key.size());
    StringSource(data, true,
        new StreamTransformationFilter(e,
            new StringSink(ciphertext)
        )
    );

    // Запись зашифрованных данных в файл
    string output_file = "output.txt";
    ofstream ofs(output_file, ios::binary);
    if (!ofs) {
        cerr << "Не удалось создать файл для записи зашифрованных данных." << endl;
        return 1;
    }
    ofs << ciphertext;
    ofs.close();

    cout << "Исходные данные: " << data.size() << " байт" << endl;
    cout << "Зашифрованные данные: " << ciphertext.size() << " байт" << endl;
    cout << "Зашифрованные данные записаны в файл: " << output_file << endl;

    return 0;
}
