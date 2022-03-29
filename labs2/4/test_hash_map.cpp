#include "hash_map.h"

int main (int argc, char **argv)
{
    hash_map<int, int, std::hash<int>> tree;
    int	i;
    i = 0;
    tree.add(10, 10);
   	for (int i = 0; i < 15; ++i)
   	{
   		tree.add(i, i);
   	}
    tree.print();
    tree.del_key(10);
    tree.print();
    std::cout<< "Find " << tree.find(5) << std::endl;
    tree.del();
    tree.print();
    return (0);
}
