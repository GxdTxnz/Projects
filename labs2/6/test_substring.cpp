#include "substring.h"

int main(int argc, char const *argv[])
{
	std::vector<int> P;
	std::vector<int> T;
	std::vector<int> result;
	
	T = {3, 2, 1, 6, 9, 9, 0, 2, 6, 6, 0, 0};
	P = {2, 6, 6, 0};
	substring *sub = new substring();
	std::cout << "T: ";
	for (int i = 0; i < T.size(); ++i)
	{
		std::cout << T[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "P: ";
	for (int i = 0; i < P.size(); ++i)
	{
		std::cout << P[i] << " ";
	}
	std::cout << std::endl;
	result = sub->Rabin_Karp(T, P);	
	std::cout << "Результат для Рабина-Карпа: ";
	for (int i = 0; i < result.size(); ++i)
	{
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;
	P.clear();
	P.push_back(0);
	result = sub->Rabin_Karp(T, P);
	std::cout << "Результат для Рабина-Карпа: ";
	for (int i = 0; i < result.size(); ++i)
	{
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;
	std::vector<char> P1;
	std::vector<char> T1;
	T1 = {'a', 'b', 'c', 'd', 'c', 'b', 'a', 'b', 'c', 'd', 'a', 'b', 'd', 'a', 'c', 'b'};
	P1 = {'a', 'b', 'c', 'd'};
	result.clear();
	result = sub->knuth_morris_pratt(T1, P1);
	std::cout << "T: ";
	for (int i = 0; i < T1.size(); ++i)
	{
		std::cout << T1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "P: ";
	for (int i = 0; i < P1.size(); ++i)
	{
		std::cout << P1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Результат для Кнута-Морриса-Пратта: ";
	for (int i = 0; i < result.size(); ++i)
	{
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;
	result.clear();
	T1.clear();
	P1.clear();
	P1 = {'a', 'b', 'd', 'b', 'a', 'b'};
	T1 = {'a', 'b', 'c', 'b', 'a', 'c', 'd', 'a', 'b', 'd', 'b', 'a', 'b', 'd', 'b', 'a', 'b', 'c', 'a', 'b', 'd', 'd', 'b', 'a'};
	result = sub->boyer_moor(T1, P1);
	std::cout << "T: ";
	for (int i = 0; i < T1.size(); ++i)
	{
		std::cout << T1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "P: ";
	for (int i = 0; i < P1.size(); ++i)
	{
		std::cout << P1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Результат для Бойера-Мура: ";
	for (int i = 0; i < result.size(); ++i)
	{
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;
	result.clear();
	T1.clear();
	P1.clear();
	P1 = {'a', 'b'};
	T1 = {'a', 'b', 'c', 'b', 'a', 'c', 'd', 'a', 'b', 'd', 'b', 'a', 'b', 'd', 'b', 'a', 'b', 'c', 'a', 'b', 'd', 'd', 'b', 'a'};
	result = sub->boyer_moor(T1, P1);
	std::cout << "T: ";
	for (int i = 0; i < T1.size(); ++i)
	{
		std::cout << T1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "P: ";
	for (int i = 0; i < P1.size(); ++i)
	{
		std::cout << P1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Результат для Бойера-Мура: ";
	for (int i = 0; i < result.size(); ++i)
	{
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
