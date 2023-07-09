#include <algorithm>
#include <iostream>
#include <fstream>
//#include <sys/stat.h>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void generate_permutations(string& current_input, int start_index, int length, ofstream& file) 
{
    if (start_index == length) 
    {
        file << current_input.substr(0, length) << '\n';
        return;
    }
    for (int i = start_index; i < static_cast<int>(current_input.length()); ++i) 
    {
        swap(current_input[start_index], current_input[i]);
        generate_permutations(current_input, start_index + 1, length, file);
        swap(current_input[start_index], current_input[i]);
    }
}

int main() 
{

    string password;
	cout << "Password: "; 
    // cout << "Введите пароль: ";
    cin >> password;
	int i;
	cout << "Min password length: ";
	//cout << "Минимальная длина пароля: ";
	cin >> i;
	
    string folder_name;
	cout << "Folder: ";
    //cout << "Введите название папки: ";
    cin >> folder_name;

    try 
    {
        fs::create_directory(folder_name);
    } 
    catch (const fs::filesystem_error& e) 
    {
		cout << "Error folder create: " << e.what() << endl;
        //cout << "Ошибка при создании папки: " << e.what() << endl;
        return 1;
    }

	for(i; i <= static_cast<int>(password.length()); ++i)
    {
        string file_path = folder_name + "/comb_" + to_string(i) + ".txt";
        ofstream file(file_path);
        if(!file.is_open())
        {
			cout << "Error open file" << endl;
            //cout << "Ошибка при открытии файла" << endl;
            continue;
        }
        generate_permutations(password, 0, i, file);
        file.close();
    }
    return 0;
}