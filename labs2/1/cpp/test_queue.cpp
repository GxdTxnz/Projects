#include "priority_queue.h"

int main(int argc, char **argv)
{
	priority_queue<int> queue;
	int	i;
	i = 1;
	std::cout << "ADD:" << std::endl;
	while(i < argc)
	{
		queue.add(atoi(argv[i]));
		i++;
	}
	queue.print();
	std::cout << "\nDEL:" << std::endl;
	while(!queue.empty())
	{
		std::cout << queue.max() << std::endl;
		queue.del();
    //std::cout << "DEL:" << std::endl;
    //queue.print();
    //std::cout << "\n" << std::endl;
	}
	return (0);
}
