#include "map.h"
int main (int argc, char **argv)
{
    map<int, int, bool(*)(int,int)> tree, n, k, m, r;
    int i;

    i = 0;
    tree.add(2, 5);
    tree.add(1, 5);
    tree.add(8, 5);
    tree.add(6, 5);
    tree.add(9, 5);
    tree.add(3, 5);
    tree.add(7, 5);
    tree.add(4, 5);
    tree.tree_print(0);
    n = tree;
    n.tree_print(0);
    for (i = 10000; i < 1000000; i++)
    {
        k.add(i, i);
    }
    if (!k.check() && k.heck_black_height() && k.check_log())
    {
    	k.tree_print(0);
	}
    else
    {
    	std::cout << "error" << std::endl;
	}
    std::cout << "------------------------" << std::endl;
    for (i = 1000000; i > 10000; i--)
    {
    	m.add(i, i);
    }
    if (!m.check() && m.heck_black_height() && m.check_log())
    {
    	m.tree_print(0);
	}
    else
    {
    	std::cout << "error" << std::endl;
	}
    std::cout << "------------------------" << std::endl;
    for (i = 10000; i < 1000000; i++)
    {
    	r.add(10000 + rand() % 1000000, i);
    }
    if (!r.check())
    {
    	r.tree_print(0);
	}
    else
    {
    	std::cout << "error" << std::endl;
	}
    //n.del_all();
    //n.tree_print(0);
    return (0);
}
