#include <iostream>
#include "mapavl.h"

using namespace std;


int main()
{
		map<int, int> h, h1;
		map<int, int> :: iterator it, it1;
		pair< map<int, int> :: iterator, bool> ap;
		int n, opt, j, m;
		
		srand(time(NULL));
		for (int i = 0; i < 10; i++) {
				j = rand()%3000;
				m = rand()%3000;
				h.insert(pair<int, int>(j, j));
				h1.insert(pair<int, int>(m, m));
		}
		
	map<int, int> :: value_type val(*h.begin());
	
	
		map<int, int> h2(h1);
	
		
		cout << "Первый пример\n";
		for (it = h.begin(); it != h.end(); ++it) 
				cout << it->first <<  "->" << it->second << " ";
		cout << endl;		
		cout << "Второй пример\n";
		for (it = h2.begin(); it != h2.end(); ++it) 
				cout << it->first <<  "->" << it->second << " ";
		cout << endl;
		
		cout << "резултат < сравнения:" << (h < h2) << endl;
		cout << "результат > сравнения " << (h > h2) << endl;
		cout << "результат <= сравнения: " << (h <= h2) << endl;
		cout << "результат >= сравнения: " << (h >= h2) << endl;
		cout << "результат == сравнения: " << (h == h2) << endl;
		cout << "результат != сравнения: " << (h != h2) << endl;

	cout << "выберите действие\n";
	
	do {
	cout << "1.поиск\n2.удаление по ключу\n3.вывод\n4.добавить элемент\\изменить по []\n5.выполнить вставку за  вставкой\n6.удалить с помощью iterator\n7.вывести нижний элемент\n8.вывести высший элемент\n9.вывести размер\n10.посчитать\n11.выход\n";
	cin >> opt;
	switch(opt)
	{
		case 1:
		cout << "введите ключ\n";
			cin >> n;
			it = h.find(n);
			if (it != h.end())
				cout << "найдено\n";
			else
				cout << "ошибка поиска\n";
			break;
		case 2:
		cout << "введите ключ\n";
			cin >> n;
			h.erase(n);
			break;
		case 3:
		for (it = h.begin(); it != h.end(); ++it) 
				cout << (*it).first <<  "->" << (*it).second << " ";
		cout << endl;		
			break;
		case 4:
		cout << "введите ключ и значение\n";
			cin >> n >> m;
			h[n] = m;
			break;
		case 5:
		cout << "введите ключ и значение\n";
			cin >> n >> m;
			ap = h.insert(pair<int,int> (n,m));
			if (ap.second == false)
				cout << "элемент уже существует\n";
			else 
				cout << "выполнено\n";
			break;
		case 6:
		cout << "введите ключ\n";
			cin >> n;
			it = h.find(n);
			h.erase(n);
			break;
		case 7:
		cout << "введите ключ\n";
			cin >> n;
			it = h.find(n);
			for (it1 = it; it1 != h.begin(); --it1)
				cout << it1->first << "->" << it1->second << " ";
			cout << it1->first << "->" << it1->second << endl;
			break;			
		case 8:
		cout << "введите ключ\n";
			cin >> n;
			it = h.find(n);
			for (it1 = it; it1 != h.end(); ++it1)
				cout << it1->first << "->" << it1->second << " ";
			cout << endl;	
			break;	
		case 9:
			cout << h.size() << endl;	
			break;
		case 10:
			cout << "введите ключ\n";
			cin >> n;
			cout <<  h.count(n) << endl;
			break;	
	default:
			break;
	};
	}while (opt != 11);					
	
		return 0;
}


