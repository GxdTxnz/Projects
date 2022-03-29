#ifndef __HASH_MAP_H__
#define __HASH_MAP_H__

#include <iostream>
#include <vector>
#include <list>

template <typename T1,typename T2, typename T3>
class hash_map
{
private:
	std::vector<std::list<std::pair<T1,T2>>> hash_table;
	int	count_of_elem;
	int	count_of_list;
	float k;
	void new_hash(void)
	{
		std::vector<std::list<std::pair<T1,T2>>> old_hash_table;
		int	old_count_of_elem;
		int	old_count_of_list;
		old_hash_table = hash_table;
		old_count_of_list = count_of_list;
		old_count_of_elem = count_of_elem;
		del();
		count_of_list = 2 * old_count_of_list + 1;
		count_of_elem = old_count_of_elem;
		for (int i = 0; i < count_of_list; i++)
		{
			std::list<std::pair<T1,T2>> new_list;
			hash_table.push_back(new_list);
		}
		for (int i = 0; i < old_count_of_list; i++)
		{
			for (auto it = old_hash_table[i].begin(); it != old_hash_table[i].end(); it++)
			{
				add((*it).first, (*it).second);
			}
		}
	};
public:
	hash_map()
	{
		count_of_list = 0;
		count_of_elem = 0;
		k = 2.0;
	};
	~hash_map()
	{
		del();
		k = 2.0;
	};
	void del(void)
	{
		for (int i = 0; i < hash_table.size(); i++)
		{
			hash_table[i].clear();
		}
		hash_table.clear();
		count_of_list = 0;
		count_of_elem = 0;
	};
	void add(T1 key, T2 value)
	{
		std::pair<T1,T2> val;
		std::list<std::pair<T1,T2>>	*list;
		float level;
		size_t h;
		T3 hash;
		val.first = key;
		val.second = value;
		if (count_of_elem == 0)
		{
			new_hash();
		}
		else if ((level = level_current()) == k)
		{
			new_hash();
		}
		h = hash(key) % count_of_list;
		list = &(this->hash_table[h]);
		if (list == NULL)
		{
			(*list).push_back(val);
    		count_of_elem++;
		}
		else
		{
			for (auto it = (*list).begin(); it != (*list).end(); it++)
			{
				if ((*it).first == key)
				{
					(*it).second = value;
					return ;
				}
			}
			(*list).push_back(val);
    		count_of_elem++;
		}
	};
	T2 find(T1 key)
	{
		size_t h;
		T3 hash;
		h = hash(key) % count_of_list;
		for (auto it = hash_table[h].begin(); it != hash_table[h].end(); it++)
		{
			if ((*it).first == key)
			{
				return ((*it).second);
			}
		}
		add(key, T2());
		return (find(key));
	};
	T2 & operator[](T1 key) 
	{ 
		return (find(key)); 
	};
	void del_key(T1 key)
	{
		size_t h;
		T3 hash;
		std::list<std::pair<T1,T2>> *list;
		h = hash(key) % count_of_list;
		list = &(this->hash_table[h]);
		for (auto it = (*list).begin(); it != (*list).end(); it++)
		{
			if ((*it).first == key)
			{
				(*list).erase(it);
				return ;
			}
		}
		return ;
	};
	int	getCountElem(void) 
	{ 
		return (count_of_elem); 
	};
	float level_current(void) 
	{ 
		return (count_of_elem / count_of_list); 
	};
	float getK(void) 
	{ 
		return (k); 
	};
	void change_k(float new_k) 
	{
		 k = new_k; 
	};
	void print(void)
	{
		for (int i = 0; i < hash_table.size(); i++)
		{
			for (auto it = hash_table[i].begin(); it != hash_table[i].end(); it++)
			{
				std::cout<< (*it).first << " ";
			}
			std::cout << std::endl;
		}
	};
};

#endif
