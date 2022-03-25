
#ifndef MAPAVL_H
#define MAPAVL_H

#include <iostream>
#include <algorithm>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T1, typename T2>
struct node
{
		T1 first;
		T2 second;
		int h;
		node<T1, T2>* left;
		node<T1, T2>* right;
};

template <typename T1, typename T2>
class map_iterator
{
		public:
		node<T1, T2>* p;
		node<T1, T2>* root;
		map_iterator(node<T1, T2>* p1, node<T1, T2>* root1);
		map_iterator();
		bool operator!=(map_iterator<T1, T2> ob);
		bool operator==(map_iterator<T1, T2> ob);
		map_iterator<T1, T2> operator++();
		const map_iterator<T1, T2> operator++(int);
		map_iterator<T1, T2> operator--();
		const map_iterator<T1, T2> operator--(int);
		node<T1, T2> operator*();
		node<T1, T2>* operator->();
};

template <typename T1, typename T2>
map_iterator<T1, T2> :: map_iterator()
{
		p = root = NULL;
}

template <typename T1, typename T2>
map_iterator<T1, T2> :: map_iterator(node<T1, T2>* p1, node<T1, T2>* root1)
{
		p = p1;
		root = root1;
}

template <typename T1, typename T2>
bool map_iterator<T1, T2> :: operator!=(map_iterator<T1, T2> ob)
{
		return this->p != ob.p;
}

template <typename T1, typename T2>
bool map_iterator<T1, T2> :: operator==(map_iterator<T1, T2> ob)
{
		return this->p == ob.p;
}

template <typename T1, typename T2>
map_iterator<T1, T2> map_iterator<T1, T2> :: operator++()
{
		if (p->right != NULL) {
				p = p->right;
				while (p->left != NULL)
						p = p->left;
				return *this;
		}
		else {
			node<T1, T2>* q = root;
			node<T1, T2>* suc = NULL;

			while (q != NULL) {		
				if (q->first > p->first) {
						suc = q;
						q = q->left;
				}
				else if (q->first < p->first)
						q = q->right;
				else		
						break;
			}
			p = suc;
			return *this;

		}
}

template <typename T1, typename T2>
const map_iterator<T1, T2> map_iterator<T1, T2> :: operator++(int)
{
		map_iterator<T1, T2> obj = *this;
		if (p->right != NULL) {
				p = p->right;
				while (p->left != NULL)
						p = p->left;
				return obj;
		}
		else {
			node<T1, T2>* q = root;
			node<T1, T2>* suc = NULL;

			while (q != NULL) {		
				if (q->first > p->first) {
						suc = q;
						q = q->left;
				}
				else if (q->first < p->first)
						q = q->right;
				else		
						break;
			}
			p = suc;
			return obj;

		}
}

template <typename T1, typename T2>
map_iterator<T1, T2> map_iterator<T1, T2> :: operator--()
{
		if (p == NULL) {
				p = root;
				while (p->right != NULL)
						p = p->right;
				return *this;
		}

		if (p->left != NULL) {
				p = p->left;
				while (p->right != NULL)
						p = p->right;
				return *this;
		}
		else {
			node<T1, T2>* q = root;
			node<T1, T2>* suc = NULL;

			while (q != NULL) {		
				if (q->first < p->first) {
						suc = q;
						q = q->right;
				}
				else if (q->first > p->first)
						q = q->left;
				else		
						break;
			}
			p = suc;
			return *this;

		}
}

template <typename T1, typename T2>
const map_iterator<T1, T2> map_iterator<T1, T2> :: operator--(int)
{
		if (p == NULL) {
				p = root;
				while (p->right != NULL)
						p = p->right;
				return *this;
		}

		map_iterator<T1, T2> obj = *this;
		if (p->left != NULL) {
				p = p->left;
				while (p->right != NULL)
						p = p->right;
				return obj;
		}
		else {
			node<T1, T2>* q = root;
			node<T1, T2>* suc = NULL;

			while (q != NULL) {		
				if (q->first < p->first) {
						suc = q;
						q = q->right;
				}
				else if (q->first > p->first)
						q = q->left;
				else		
						break;
			}
			p = suc;
			return obj;

		}
}

template <typename T1, typename T2>
node<T1, T2> map_iterator<T1, T2> :: operator*()
{
		return *p;
}

template <typename T1, typename T2>
node<T1, T2>* map_iterator<T1, T2> :: operator->()
{
		return p;
}

template <typename T1, typename T2>
class map
{
		public:
		typedef size_t size_type;
		typedef map_iterator< T1, T2> iterator;
		typedef pair< iterator, bool> pl;
		typedef const map_iterator<T1, T2> const_iterator;
		typedef node<T1, T2> value_type;
		typedef ptrdiff_t difference_type;
		typedef const node<T1, T2>& const_reference;
		node<T1, T2>* root;
		size_type sz;
		map();
		map(map<T1, T2>& obj);
		map<T1, T2>& operator=(map<T1, T2>& obj);
		~map();
		bool operator==(map<T1, T2>& obj);
		bool operator!=(map<T1, T2>& obj);
		bool operator<(map<T1, T2>& obj);
		bool operator>(map<T1, T2>& obj);
		bool operator<=(map<T1, T2>& obj);
		bool operator>=(map<T1, T2>& obj);
		T2& operator[](T1 x);
		void swap(map<T1, T2> &ob);
		size_type  size() const;
		size_type max_size() const;
		bool empty() const;
		void clear();
		iterator begin();
		iterator end();
		node<T1, T2>* make(T1 key, T2 val);
		int height(node<T1, T2>* &p);
		void setheight(node<T1, T2>* &r);
		int getbalance(node<T1, T2>* &r);
		void rightrotate(node<T1, T2>* &r);
		void leftrotate(node<T1, T2>* &r);
		pl insert(pair<T1, T2> pa);
		iterator find(T1 x);
		int count(T1 x);
		void erase(T1 x);
		void erase(iterator it);
		pl inst(  node<T1, T2>* &p, T1 key, T2 val);
		void del(node<T1, T2>* &r, T1 x);
		void traverse(node<T1, T2>* &p, list<pair<T1, T2> > &lst);
};

template <typename T1, typename T2>
map<T1, T2> :: map()
{
	 root = NULL;
	 sz = 0;
}

template <typename T1, typename T2>
map<T1, T2> :: map(map<T1, T2>& ob)
{
		this->root = ob.root;
		this->sz = ob.sz;
}

template <typename T1, typename T2>
map<T1, T2>& map<T1, T2> :: operator=(map<T1, T2>& obj)
{
		this->root = obj.root;
		return *this;
}

template <typename T1, typename T2>
map<T1, T2> :: ~map()
{
		root = NULL;
}

template <typename T1, typename T2>
bool map<T1, T2> :: operator==(map<T1, T2>& obj)
{
		list < pair<T1, T2> > l1, l2;
		traverse(obj.root, l1);
		traverse(this->root, l2);

		return l1 == l2;
}
		
template <typename T1, typename T2>
bool map<T1, T2> :: operator!=(map<T1, T2>& obj)
{
		list < pair<T1, T2> > l1, l2;
		traverse(obj.root, l2);
		traverse(this->root, l1);

		return l1 != l2;
}

template <typename T1, typename T2>
bool map<T1, T2> :: operator<(map<T1, T2>& obj)
{
		list < pair<T1, T2> > l1, l2;
		traverse(obj.root, l2);
		traverse(this->root, l1);

		return l1 < l2;
}

template <typename T1, typename T2>
bool map<T1, T2> :: operator>(map<T1, T2>& obj)
{
		list < pair<T1, T2> > l1, l2;
		traverse(obj.root, l2);
		traverse(this->root, l1);

		return l1 > l2;
}

template <typename T1, typename T2>
bool map<T1, T2> :: operator<=(map<T1, T2>& obj)
{
		list < pair<T1, T2> > l1, l2;
		traverse(obj.root, l2);
		traverse(this->root, l1);

		return l1 <= l2;
}

template <typename T1, typename T2>
bool map<T1, T2> :: operator>=(map<T1, T2>& obj)
{
		list < pair<T1, T2> > l1, l2;
		traverse(obj.root, l2);
		traverse(this->root, l1);

		return l1 >= l2;
}

template <typename T1, typename T2>
void map<T1, T2> :: swap(map<T1, T2> &obj)
{
		node<T1, T2>* p = obj.root;
		obj.root = this->root;
		this->root = p;
}

template <typename T1, typename T2>
size_t map<T1, T2> :: size() const
{
		return sz;
}

template <typename T1, typename T2>
size_t map<T1, T2> :: max_size() const
{
		return 461168601842738790;
}

template <typename T1, typename T2>
bool map<T1, T2> :: empty() const
{
		return sz == 0;
}

template <typename T1, typename T2>
map_iterator<T1, T2> map<T1, T2> :: begin()
{
		 iterator it;
		 it.p = root;
		 while (it.p->left != NULL)
				 it.p = it.p->left;
		it.root = root;
	
		return it;		 
}

template <typename T1, typename T2>
map_iterator<T1, T2> map<T1, T2> :: end()
{
		 iterator it;
		 it.p = NULL;
		 it.root = root;

		return it;
}

template <typename T1, typename T2>
node<T1, T2>* map<T1,T2> :: make(T1 key, T2 val)
{
	node<T1, T2>* r = new node<T1, T2>;
	r->first = key;
	r->second = val;
	r->h = 1;
	r->left = NULL;
	r->right = NULL;
}

template <typename T1, typename T2>
int map<T1,T2> :: height(node<T1, T2>* &p)
{
		if (p == NULL)
				return 0;
		
		return p->h;
}

template <typename T1, typename T2>
void map<T1, T2> :: setheight(node<T1, T2>* &r)
{
		if (r == 0)
				return;

		r->h = 1 + max( height(r->left), height(r->right));
}

template <typename T1, typename T2>
int map<T1,T2> :: getbalance(node<T1, T2>* &r)
{
		if (r == NULL)
				return 0;
		return height(r->left) - height(r->right);
}

template <typename T1, typename T2>
void map<T1, T2> :: rightrotate(node<T1, T2>* &r)
{
		node<T1, T2>* z = r;
		node<T1, T2>* y = r->left;
		node<T1, T2>* tmp = y->right;

		r = y;
		r->right = z;
		z->left = tmp;

		setheight(r->right);
		setheight(r);
		return;
}

template <typename T1, typename T2>
void map<T1, T2> :: leftrotate(node<T1, T2>* &r)
{
		node<T1, T2>* z = r;
		node<T1, T2>* y = r->right;
		node<T1, T2>* tmp = y->left;

		r = y;
		r->left = z;
		z->right = tmp;

		setheight(r->left);
		setheight(r);
		return;
}

template <typename T1, typename T2>
 pair<typename map<T1, T2> ::iterator, bool> map<T1, T2> :: insert(pair<T1, T2> pa)
{
	pl ap = inst( root, pa.first, pa.second);
	if (ap.second)
			sz++;
	return ap;
}


template <typename T1, typename T2>
int map<T1, T2> :: count(T1 x)
{
		iterator it = find(x);
		if (it.p == NULL)
			return 0;
		
		return 1;
}

template <typename T1, typename T2>
typename map<T1, T2> :: iterator map<T1, T2> :: find(T1 x)
{
		node<T1, T2>* tmp = root;

		while (tmp != NULL) {
			if (tmp->first < x)
					tmp = tmp->right;
			else if (tmp->first > x)
					tmp = tmp->left;
			else
					break;
		}
		return iterator(tmp, root);
}

template <typename T1, typename T2>
T2& map<T1,T2> :: operator[](T1 x)
{
		iterator it = find(x);
		pair<iterator, bool> pa;
		if (it.p == NULL) {
				pa = inst(root, x,x);
				sz++;
				cout << pa.first->second << endl;
				return pa.first->second;
		}
		else 
				return it->second;
}

template <typename T1, typename T2>
void map<T1, T2> :: erase(T1 x)
{
		del(root, x);
		sz--;
}

template <typename T1, typename T2>
void map<T1, T2> :: erase(iterator it)
{
		if (it.p != NULL) {
		del(root, it->first);
		sz--;
		}
}

template <typename T1, typename T2>
pair<typename map<T1,T2> :: iterator, bool> map<T1, T2> :: inst(  node<T1, T2>* &p, T1 key, T2 val)
{
		if (p == NULL) {
				p = make(key, val);
				return pl(iterator(p,root), true);
		}
		
		bool flag = true;
		pl ap;
		if (p->first < key)
				 ap = inst( p->right, key, val);
		else if (p->first > key)
				 ap =  inst( p->left, key, val);
		else
				flag = false;

		setheight(p);		

		int bal = getbalance(p);
		node<T1, T2>* tmp;

		if (bal == 2) {	
			tmp = p->left;
			if (height(tmp->left) >= height(tmp->right) ) 
					rightrotate(p);
			else {
					leftrotate(p->left);
					rightrotate(p);
			}
		}
		else if (bal == -2) {
			tmp = p->right;
			if (height(tmp->right) >= height(tmp->left))
					leftrotate(p);
			else {
					rightrotate(p->right);
					leftrotate(p);
			}
		}
		return (flag) ? ap : pl(iterator(p,root), flag);
}

template <typename T1, typename T2>
void map<T1, T2> :: del(node<T1, T2>* &r, T1 x)
{
		node<T1, T2>* tmp;
		int bal;
		if (r == NULL)
				return;

		if (r->first == x) {
				if (r->left == NULL && r->right == NULL) 
						r = NULL;
				else if (r->left != NULL && r->right != NULL) {
						tmp = r->right;

						while (tmp->left != NULL) 
								tmp = tmp->left;

						std::swap(r->first, tmp->first);
						std::swap(r->second, tmp->second);
						del(r->right, x);		
				}
				else if (r->left != NULL && r->right == NULL) 
						r = r->left;
				else
						r = r->right;
		}
		else if (r->first <= x)
				del(r->right, x);
		else
				del(r->left, x);
	
		if (r != NULL) {	
				setheight(r->left);	
				setheight(r->right);	
				setheight(r);
		}

		 bal = getbalance(r);
		if (bal > 1) {	
			tmp =r->left;
			if (height(tmp->left) >= height(tmp->right) ) 
					rightrotate(r);
			else {
					leftrotate(r->left);
					rightrotate(r);
			}
		}
		else if (bal < -1) {
			tmp = r->right;
			if (height(tmp->right) >= height(tmp->left))
					leftrotate(r);
			else {
					rightrotate(r->right);
					leftrotate(r);
			}
		}
}

template <typename T1, typename T2>
void map<T1, T2> :: clear()
{
	sz = 0;
	root = NULL;
}

template <typename T1, typename T2>
void map<T1, T2> :: traverse(node<T1, T2>* &p, list< pair<T1, T2> >&lst)
{
		if (p != NULL) {
				traverse(p->left, lst);
				int bal = getbalance(p);
				if ( !(bal <= 1 && bal >= -1))  {
						cout << "problem" << p->first << " " << p->h << endl;
						getchar();
				}

				lst.push_back(pair<T1, T2>(p->first, p->second));
				traverse(p->right, lst);
		}
}


#endif
