#include "grapth_b.h"

int	main(int argc, char const *argv[])
{

	std::vector<std::vector<bool>> table;
	std::vector<std::vector<int>> table_int;

	/*table = { { 0, 1, 1, 0, 0, 0, 0 },
			{ 1, 0, 0, 1, 1, 0, 0 }, 
			{ 1, 0, 0, 1, 0, 1, 1 },  
			{ 0, 1, 1, 0, 1, 0, 0 },
			{ 0, 1, 0, 1, 0, 0, 0 },
			{ 0, 0, 1, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0, 0, 0 } };*/
	table = { { 0, 1, 1, 0, 0, 0, 0 },
			{ 0, 0, 0, 1, 0, 0, 0 }, 
			{ 0, 0, 0, 1, 0, 1, 0 },  
			{ 0, 0, 0, 0, 0, 0, 1 },
			{ 0, 0, 0, 0, 0, 1, 0 },
			{ 0, 0, 0, 0, 0, 0, 1 },
			{ 0, 0, 0, 0, 0, 0, 0 } };
	grapth_a<bool> *graf = new grapth_a<bool>(table);
	graf->print_grapth();
	graf->dfs();
	std::cout<< std::endl;
	table_int = { { 0, 1, 0, 1, 0, 0 },
				{ 1, 0, 1, 0, 1, 1 }, 
				{ 0, 1, 0, 1, 1, 1 },  
				{ 1, 0, 1, 0, 1, 1 },
				{ 0, 1, 1, 1, 0, 1 },
				{ 0, 1, 1, 1, 1, 0 } };
	grapth_a<int> *graf_F = new grapth_a<int>(table_int);
	graf_F->print_grapth();
	graf_F->Fleri();
	std::cout<< std::endl;
	table_int = { { 0, 1, 1, 1, 1, 0 },
				{ 1, 0, 1, 1, 1, 0 }, 
				{ 1, 1, 0, 1, 0, 1 },  
				{ 1, 1, 1, 0, 1, 0 },
				{ 1, 1, 0, 1, 0, 1 },
				{ 0, 0, 1, 0, 1, 0 } };
	grapth_a<int> *graf_U = new grapth_a<int>(table_int);
	graf_U->print_grapth();
	graf_U->find_cycle(6);
	std::cout<< std::endl;
	table_int = { { 0, 0, 0, 1, 0, 0, 0, 0 },
				{ 1, 0, 0, 0, 0, 0, 0, 0 }, 
				{ 0, 1, 0, 0, 1, 0, 1, 0 },  
				{ 1, 0, 0, 0, 1, 0, 0, 0 },
				{ 0, 1, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 0, 1, 0, 0, 0 },
				{ 0, 1, 1, 0, 0, 1, 0, 0 },
				{ 0, 0, 0, 0, 1, 0, 1, 0 }, };
	grapth_a<int> *graf_K = new grapth_a<int>(table_int);
	graf_K->print_grapth();
	graf_K->Kosaraju();
	return 0;
}
