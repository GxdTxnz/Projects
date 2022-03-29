#include "btree.h"

int main (int argc, char **argv)
{
	btree_map<int, int, bool(*)(int,int)> tree, n, r, k, tree1;
	int i;
	i = 0;
	tree.add(10, 7);
	std::cout << "------------------" << std::endl;
	tree.add(5, 6);
	while (i < 100000)
	{
        //std::cout << "------------------" << std::endl;
        //std::cout << "ADD " << i << std::endl;
		tree.add(i, i);
		i++;
	}
	std::cout << "FIND " << tree.find(1) << std::endl;
	std::cout << "FIND " << tree.find(255) << std::endl;
	std::cout << "FIND " << tree.find(16383) << std::endl;
	while (i > 0)
	{
        //std::cout << "------------------" << std::endl;
        //std::cout << "ADD " << i << std::endl;
		n.add(i, i);
		i--;
	}
	for (i = 10000; i < 100000; i++)
	{
		r.add(10000 + rand() % 1000000, i);
	}
	k = r;
	tree1.add(10, 7);
	tree1.add(5, 6);
	tree1.add(1, 100);
	std::cout << "FIND " << tree1.find(1) << std::endl;
	tree.del_all();
	tree.print();
	return (0);
}
