#ifndef __BTREE_H__
#define __BTREE_H__

#include <stdlib.h>
#include <utility>
#include <iostream>
#include <vector>

int t = 2;

template <typename T1, typename T2>
struct Node
{
    std::vector<std::pair<T1,T2>> val;
    std::vector<struct Node*> child;
};

template <typename T>
bool comparator (T a, T b)
{
    return a > b;
};

template <typename T1, typename T2>
class compare
{
private:
	T2 comp;
public:
    compare() 
    { 
		comp = NULL; 
	};
    compare(T2 comp) 
    { 
		this->comp = comp; 
	};
    bool check(T1 val1, T1 val2)
    {
        if(comp)
        {
            return comp(val1, val2);
		}
        else
        {
            return val1 > val2;
		}
    };
};

template <typename T1,typename T2, typename T3>
class btree_map
{
private:
	struct Node<T1,T2> *head;
public:
	btree_map() 
	{ 
		head = NULL; 
	};
	~btree_map()
	{
		del(this->head);
		this->head = NULL;
	};
	btree_map(int new_t)
	{
		t = new_t;
		head = NULL;
	};
	btree_map(const btree_map& m)
	{
		head = copy(m.head);
	};
	btree_map&  operator=(const btree_map& tree)
	{
		if(this == &tree)
		{
			return (*this);
		}
		head = copy(tree.head);
		return (*this);
	};
	Node<T1,T2> *copy(Node<T1,T2> *x)
	{
		Node<T1,T2> *new_head;
		int i;
		i = 0;
		new_head = new Node<T1,T2>;
		if (x == NULL)
		{
			return (NULL);
		}
		else
		{
			if ((x->child.size() > 2 * t) || (x->val.size() > 2 * t - 1))
			{
				std::cout << "ERROR SIZE" << std::endl;
				return (NULL);
			}
			if ((x != this->head) && (((x->child.size() < t) && (x->child.size() > 0)) || ((x->val.size() < t - 1) && (x->val.size() > 0))))
			{
				std::cout << "ERROR SIZE2" << std::endl;
				return (NULL);
			}
			while (i < x->val.size())
			{
				new_head->val.push_back(x->val[i]);
				if (i < x->child.size())
				{
					new_head->child.push_back(copy(x->child[i]));
				}
				i++;
			}
			while (i < x->child.size())
			{
				new_head->child.push_back(copy(x->child[i]));
				i++;
			}
		}
		return (new_head);
	};
	bool empty(void) 
	{ 
		return (head == NULL); 
	};
    void del(Node<T1,T2> *x)
    {
		int i;
		i = 0;
		if (x != NULL)
		{
			if (x->child.size())
			{
				while (i < x->child.size())
				{
					del(x->child[i]); 
					x->child.clear();
					x->val.clear();
					i++;
				}
			}
			else
			{
				x->val.clear();
			}
		}
	};
	bool heck_h(Node<T1,T2> *x, int count, int height)
    {
		std::vector<bool> is_correct;
		bool result;
		int i;
		int j;
		i = 0;
		j = 0;
		result = 1;
		if (x == NULL)
		{
            return (count == height);
		}
        while (i < x->child.size())
        {
			is_correct.push_back(heck_h(x->child[i], count + 1, height));
			i++;
		}
		while (j < is_correct.size())
		{
			result = result && is_correct[i];
			j++;
		}
		return (result);
	};
	int check_h(int h)
	{
		Node<T1,T2> *head;
		int height;
		head = new Node<T1,T2>;
		head = this->head;
		height = 0;
		while (head != NULL)
		{
			height++;
			if (head->child.empty())
			{
				break;
			}
			else
			{
				head = head->child[0];
			}
		}
		if (heck_h(head, 0, height))
		{
			if (h < height)
			{
				return (1);
			}
			else if (h == height)
            {
				return (0);
			}
			else
			{
				return (-1);
			}
        }
		else
		{
			return (-1);
		}
	};
	int b_find(Node<T1,T2> *x, std::pair<T1,T2> val)
	{
		compare<T1,T3> *item;
        int shift;
        int left;
        int right;
        int mid;
		shift = 0;
		left = 0;
		right = x->val.size();
		item = new compare<T1,T3>(comparator);
        while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (item->check(x->val[mid].first, val.first))
			{
				if (mid - 1 >= 0)
				{
					if (!(item->check(x->val[mid - 1].first, val.first)) || (val.first == x->val[mid - 1].first))
					{
						shift = mid;
						break;
					}
					right = mid - 1;
				}
				else
				{
					shift = 0;
					break;
				}
			}
			else if (!(item->check(x->val[mid].first, val.first)))
			{
				if (mid + 1 < x->val.size())
				{
					if (item->check(x->val[mid + 1].first, val.first) || (val.first == x->val[mid + 1].first))
					{
						shift = mid + 1;
						break;
					}
					left = mid + 1;
				}
				else
				{
					shift = mid + 1;
					break;
				}
			}
			else
			{
				shift = mid;
				break;
			}
		}
		return (shift);
	};
    Node<T1,T2> *breaking(Node<T1,T2> *x, Node<T1,T2> *parent)
	{
		Node<T1,T2> *elem;
		Node<T1,T2> *child1;
		Node<T1,T2> *child2;
		int i;
		int j;
		i = 0;
		j = 0;
		child1 = new Node<T1,T2>;
		child2 = new Node<T1,T2>;
		elem = new Node<T1,T2>;
		if ((x == this->head) && (parent == NULL))
		{
			elem->val.push_back(x->val[x->val.size() / 2]);
			while (i < t - 1)
			{
				child1->val.push_back(x->val[i]);
				i++;
			}
			while (j < x->child.size() / 2)
			{
				child1->child.push_back(copy(x->child[j]));
				j++;
			}
			while (++i < 2 * t - 1)
			{
				child2->val.push_back(x->val[i]);
			}
            while (j < x->child.size())
            {
				child2->child.push_back(copy(x->child[j]));
				j++;
			}
			elem->child.push_back(child1);
			elem->child.push_back(child2);
			del(x);
			this->head = elem;
			return (this->head);
		}
		else
		{
			int shift;
			shift = b_find(parent, x->val[x->val.size() / 2]);
			auto iter = parent->val.cbegin() + shift;
			parent->val.emplace(iter, x->val[x->val.size() / 2]);
			while (i < t - 1)
			{
				child1->val.push_back(x->val[i]);
				i++;
			}
			while (j < x->child.size() / 2)
			{
				child1->child.push_back(copy(x->child[j]));
				j++;
			}
			while (++i < 2 * t - 1)
			{
				child2->val.push_back(x->val[i]);
			}
			while (j < x->child.size())
			{
				child2->child.push_back(copy(x->child[j]));
				j++;
			}
			auto iter_n = parent->child.cbegin() + shift;
			parent->child.erase(iter_n);
			parent->child.insert(iter_n, {child1, child2});
			del(x);
			return (parent);
		}            
	};
	void add_key(Node<T1,T2> *x, Node<T1,T2> *parent, std::pair<T1,T2> val, int h)
	{
		int shift;
		if (x->val.size() == (2 * t - 1))
		{
			x = breaking(x, parent);
			h = h - 1;
		}
		if (check_h(h) < 0)
		{
			std::cout << "ERROR H" << std::endl;
			del(this->head);
			return ;
		}
		if ((x->child.size() > 2 * t) || (x->val.size() > 2 * t - 1))
		{
			std::cout << "ERROR SIZE1" << std::endl;
			return ;
		}
		if ((x != this->head) && (((x->child.size() < t) && (x->child.size() > 0)) || ((x->val.size() < t - 1) && (x->val.size() > 0))))
		{
			std::cout << "ERROR SIZE2" << std::endl;
			return ;
		}
		shift = b_find(x, val);
		if ((x->child.size() > 0) && check_h(h))
		{
			add_key(x->child[shift], x, val, h + 1);
		}
		else
		{
			auto iter = x->val.cbegin() + shift;
			x->val.emplace(iter, val);
		}
	};
	void add(T1 key, T2 val)
	{
		Node<T1,T2> *head;
		Node<T1,T2> *elem;
		std::pair<T1,T2> value;
		elem = new Node<T1,T2>;
        head = new Node<T1,T2>;
        value.first = key;
        value.second = val;
		if (this->head == NULL)
		{
			elem->val.push_back(value);
			this->head = elem;  
			return ;
		}
		else
		{
			head = this->head;
			add_key(head, NULL, value, 1);
		}
	};
	T2 find_key(T1 key, Node<T1,T2> *x, compare<T1,T3> *item)
	{
		int left;
		int right;
		int mid;
		left = 0;
		right = x->val.size();
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (x->val[mid].first == key)
			{
                return (x->val[mid].second);
			}
			if (item->check(x->val[mid].first, key))
			{
				if (mid - 1 >= 0)
				{
					if (key == x->val[mid - 1].first)
					{
						return (x->val[mid - 1].second);
					}
					if (!(item->check(x->val[mid - 1].first, key)))
					{
						if (x->child.size() > 0)
						{
							return (find_key(key, x->child[mid], item));
						}
						else
                        {
							return (T2());
						}
					}
					right = mid - 1;
				}
				else
				{
					if (x->child.size() > 0)
					{
						return (find_key(key, x->child[0], item));
					}
					else
					{
						return (T2());
					}
				}
			}
			else if (!(item->check(x->val[mid].first, key)))
			{
				if (mid + 1 < x->val.size())
				{
					if (key == x->val[mid + 1].first)
					{
						return (x->val[mid + 1].second);
					}
					if (item->check(x->val[mid + 1].first, key))
					{
						if (x->child.size() > 0)
						{
							return (find_key(key, x->child[mid + 1], item));
						}
						else
						{
							return (T2());
						}
					}
					left = mid + 1;
				}
				else
				{
					if ((x->child.size() > 0))
					{
						return (find_key(key, x->child[mid], item));
					}
					else
					{
						return (T2());
					}
				}
			}
		}
		return (T2());
	};
	T2 find(T1 key)
	{
		compare<T1,T3> *item;
		T2 result;
		item = new compare<T1,T3>(comparator);
		if (!(this->head))
		{
			add(key, T2());
			return (find_key(key, this->head, item));
		}
		if (find_key(key, this->head, item) == T2())
		{
			add(key, T2());
		}
		return (find_key(key, this->head, item));
	};
	T2 & operator[](T1 key) 
	{ 
		return (find(key)); 
	};
	void print(void)
	{
		for (int i = 0; i < head->val.size(); i++)
		{
			std::cout << "ADD = " << head->val[i].first << "second " << head->val[i].second << std::endl;
		}
	};
	void del_all(void) 
	{ 
		del(this->head); 
	};
};
#endif
