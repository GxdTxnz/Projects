#include "grapth_a.h"

int	main(int argc, char const *argv[])
{
	std::vector<std::vector<bool>> table;
	std::vector<std::vector<int>> table_int;
	table = { { 0, 1, 1, 0, 0, 0, 0 },
			{ 1, 0, 0, 1, 1, 0, 0 }, 
			{ 1, 0, 0, 1, 0, 1, 1 },  
			{ 0, 1, 1, 0, 1, 0, 0 },
			{ 0, 1, 0, 1, 0, 0, 0 },
			{ 0, 0, 1, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0, 0, 0 } };
	grapth_a<bool> *graf = new grapth_a<bool>(table);
	graf->print_grapth();
	std::cout<< "Поиск DFS"<< std::endl;
	graf->dfs();
	std::cout<< "Поиск BFS"<< std::endl;
	graf->bfs();
	std::cout<< std::endl;
	table_int = { { 0, 2, 1, 4, 0, 6, 0 },
				{ 2, 0, 0, 1, 3, 0, 0 }, 
				{ 1, 0, 0, 2, 0, 4, 0 },  
				{ 4, 1, 2, 0, 0, 0, 1 },
				{ 0, 3, 0, 0, 0, 0, 4 },
				{ 6, 0, 4, 0, 0, 0, 7 },
				{ 0, 0, 0, 1, 4, 7, 0 } };
	grapth_a<int> *graf_D = new grapth_a<int>(table_int);
	graf_D->print_grapth();
	graf_D->Dijkstra(4);
	graf_D->Dijkstra(1);
	graf_D->Floyd();
	table_int.clear();
	std::cout<< std::endl;
	table_int = { { 0, 1, 2, 4, 0, 6, 0 },
				{ 1, 0, 0, 2, 5, 0, 0 }, 
				{ 2, 0, 0, 7, 0, 4, 1 },  
				{ 4, 2, 7, 0, 1, 0, 1 },
				{ 0, 5, 0, 1, 0, 0, 0 },
				{ 0, 0, 4, 0, 0, 0, 0 },
				{ 0, 0, 1, 1, 0, 0, 0 } };
	grapth_a<int> *graf_F = new grapth_a<int>(table_int);
	graf_F->print_grapth();
	graf_F->Floyd();
	table_int.clear();
	std::cout<< std::endl;
	table_int = { { 0, 1, 2, 4, 0, 6, -5 },
				{ 1, 0, 0, 2, 5, 0, 0 }, 
				{ 2, 0, 0, 7, 0, 4, 1 },  
				{ 4, 2, 7, 0, 1, 0, 1 },
				{ 0, 5, 0, 1, 0, 0, 0 },
				{ 0, 0, 4, 0, 0, 0, 0 },
				{ 0, 0, 1, 1, 0, 0, 0 } };
	grapth_a<int> *graf_F_neg = new grapth_a<int>(table_int);
	graf_F_neg->print_grapth();
	graf_F_neg->Floyd();
	table_int.clear();
	std::cout<< std::endl;
	table_int = { { 0, 2, 1, 3, 0, 6, 0 },
				{ 2, 0, 0, 1, 3, 0, 0 }, 
				{ 1, 0, 0, 2, 0, 3, 0 },  
				{ 3, 1, 2, 0, 0, 0, 1 },
				{ 0, 3, 0, 0, 0, 0, 4 },
				{ 6, 0, 3, 0, 0, 0, 7 },
				{ 0, 0, 0, 1, 4, 7, 0 } };
	grapth_a<int> *graf_P = new grapth_a<int>(table_int);
	graf_P->print_grapth();
	graf_P->Prim();
	graf_P->Kruskal();
	return 0;
}
