#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <openssl/evp.h>
#include <sys/stat.h>

using namespace std;

int main() 
{
    string n;
    cout << "Введите для папки Passes: ";
    cin >> n;
    string result_dir = "Results_" + n;
    mkdir(result_dir.c_str(), 0777);
    const unsigned char salt[] = "SALT";
    const int iterations = 100;
    const unsigned char decripted_data[] = {0x70, 0xA8, 0xEF, 0xF7, 0x63, 0x01, 0xD2, 0x8A, 0xF3, 0xF4, 0x76, 0x7D, 0xA3, 0x11, 0xCE, 0xF5,
                                            0x3F, 0x74, 0x33, 0xBA, 0xF6, 0xE1, 0xC9, 0x5B, 0xEA, 0xF5, 0x33, 0x47, 0x56, 0x15, 0x81, 0x75,
                                            0xC9, 0x7E, 0xF1, 0x19, 0x41, 0xB3, 0x4A, 0x78, 0x6C, 0x60, 0x34, 0x92, 0xB3, 0xBA, 0x87, 0x25,
                                            0x78, 0x2A, 0xAC, 0x5A, 0x98, 0x3B, 0x96, 0x4E, 0xD3, 0x62, 0x4F, 0x34, 0x26, 0xA1, 0x14, 0xBD};
    for (int i = 4; i < 12; i++) 
    {
        string comb_file = "Passes_" + n + "/comb_" + to_string(i) + ".txt";
        ifstream f(comb_file);
        if (!f.good()) 
        {
            cerr << "Could not open " << comb_file << endl;
            continue;
        }
        string result_file = result_dir + "/result_" + to_string(i) + ".txt";
        ofstream f_result(result_file);
        if (!f_result.good()) 
        {
            cerr << "Could not open " << result_file << endl;
            continue;
        }
        int total_lines = std::count(std::istreambuf_iterator<char>(f), std::istreambuf_iterator<char>(), '\n');
        f.seekg(0);
        int num_line = 0;
        for (string line; getline(f, line); num_line++) 
        {
            unsigned char password[line.length()];
            memcpy(password, line.c_str(), line.length());
            unsigned char key[16];
            PKCS5_PBKDF2_HMAC((const char *)password, line.length(), salt, sizeof(salt), iterations, EVP_sha1(), 16, key);
            EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
            EVP_DecryptInit_ex(ctx, EVP_aes_128_ecb(), NULL, key, NULL);
            unsigned char encripted_data[64];
            int out_len = 0;
            EVP_DecryptUpdate(ctx, encripted_data, &out_len, decripted_data, sizeof(decripted_data));
            int final_len = 0;
            EVP_DecryptFinal_ex(ctx, encripted_data + out_len, &final_len);
            EVP_CIPHER_CTX_free(ctx);
            string s((char *)encripted_data, out_len + final_len);
            f_result << s << endl;
            int percent = num_line * 100 / total_lines;
            int fill_length = percent / 2;
            int empty_length = 50 - fill_length;
            cout << i << "[" << string(fill_length, '=') << string(empty_length, ' ') << "] " << percent << "%" << '\r' << flush;
        }
        cout << endl;
    }
    cout << "\nГотово!" << endl;
    return 0;
}
