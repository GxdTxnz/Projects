#include "grapth_a.h"

template <typename T> 
grapth_a<T>::grapth_a(){}

template <typename T>
grapth_a<T>::grapth_a(std::vector<std::vector<T> > graf) 
{ 
	this->grapth = graf; 
}

template <typename T>
std::vector<bool> grapth_a<T>::find_depth(int x, std::vector<bool> visit)
{
	visit[x] = true;
	for (int i = 0; i < grapth[x].size(); i++)
	{
		if (grapth[x][i] != 0)
		{
			if (visit[i] == false)
			{
				std::cout<< "От " << x + 1 << " до " << i + 1 << std::endl;
				visit = find_depth(i, visit);
			}
		}
	}
	return (visit);
}

template <typename T>
void grapth_a<T>::dfs(void)
{
	if (typeid(T) != typeid(bool))
	{
		std::cout<< "ОШИБКА(заполнение)" << std::endl;
		exit(1);
	}
	for (int i = 0; i < grapth.size(); ++i)
	{
		if (grapth[i].size() != grapth.size())
		{
			std::cout<< "ОШИБКА(размер)" << std::endl;
			exit(1);
		}
	}
	std::vector<bool> visit(grapth.size(), false);
	find_depth(0, visit);
}

template <typename T>
void grapth_a<T>::bfs(void)
{
	if (typeid(T) != typeid(bool))
	{
		std::cout<< "ОШИБКА(заполнение)" << std::endl;
		exit(1);
	}
	for (int i = 0; i < grapth.size(); ++i)
	{
		if (grapth[i].size() != grapth.size())
		{
			std::cout<< "ОШИБКА(размер)" << std::endl;
			exit(1);
		}
	}
	std::vector<bool> visit(grapth.size(), false);
	std::queue<int>	 q;
	q.push(0);
	visit[0] = true;
	while (!q.empty())
	{
		int	v = q.front();
		q.pop();
		for (int i = 0; i < grapth[v].size(); ++i)
		{
			if (grapth[v][i] != 0)
			{
				if (visit[i] == false)
				{
					std::cout<< "От " << v + 1 << " до " << i + 1 << std::endl;
					q.push(i);
					visit[i] = true;
				}
			}
		}
	}
}

template <typename T>
void grapth_a<T>::Dijkstra(int s)
{
	if (typeid(T) != typeid(int))
	{
		std::cout<< "ОШИБКА(заполнение)" << std::endl;
		exit(1);
	}
	for (int i = 0; i < grapth.size(); ++i)
	{
		if (grapth[i].size() != grapth.size())
		{
			std::cout<< "ОШИБКА(размер)" << std::endl;
			exit(1);
		}
	}
	for (int i = 0; i < grapth.size(); i++)
	{
		for (int j = 0; j < grapth[i].size(); j++)
		{
			if (grapth[i][j] < 0)
			{
				std::cout<< "ОШИБКА(неправильное значение)" << std::endl;
				exit(1);
			}
		}
	}
	if (s > grapth.size())
	{
		std::cout<< "ОШИБКА(S)" << std::endl;
		exit(1);
	}
	const int INF = INT_MAX;
	std::vector<bool> visit(grapth.size(), false);
	std::vector<int> D(grapth.size(), INF);
	bool result;
	int v = 0;
	result = false;
	D[s - 1] = 0;
	while (!result)
	{
		for (int i = 0; i < grapth.size(); ++i)
		{
			int min = INF;
			for (int j = 0; j < grapth[i].size(); ++j)
			{
				if ((visit[j] == false) && (D[j] < min))
				{
					min = D[j];
					v = j;
				}
			}
			visit[v] = true;
			for (int u = 0; u < grapth[i].size(); ++u)
			{
				if ((grapth[v][u] != 0) && (visit[u] == false) && (D[v] != INF) && (D[u] > D[v] + grapth[v][u]))
				{
					D[u] = D[v] + grapth[v][u];
				}
			}
		}
		result = true;
		for (int i = 0; i < visit.size(); ++i)
		{
			result = result & visit[i];
		}
	}
	std::cout << "Алгоритм Дейкстры: S = " << s << std::endl;
	for (int i = 0; i < D.size(); ++i)
	{
		if (D[i] == INF)
		{
			std::cout << "INF ";
		}
		else
		{
			std::cout << D[i] << " ";
		}
	}
	std::cout << std::endl;
}

template <typename T>
void grapth_a<T>::Floyd(void)
{
	if (typeid(T) != typeid(int))
	{
		std::cout<< "ОШИБКА(заполнение)" << std::endl;
		exit(1);
	}
	for (int i = 0; i < grapth.size(); ++i)
	{
		if (grapth[i].size() != grapth.size())
		{
			std::cout<< "ОШИБКА(размер)" << std::endl;
			exit(1);
		}
	}
	/*for (int i = 0; i < grapth.size(); i++)
	{
		for (int j = 0; j < grapth[i].size(); j++)
		{
			if (grapth[i][j] < 0)
			{
				std::cout<< "Ошибка(значение)" << std::endl;
				exit(1);
			}
		}
	}*/

	const int INF = INT_MAX;
	std::vector<int> mini_D(grapth.size(), INF);
	std::vector<std::vector<int> >	D(grapth.size(), mini_D);
	bool neg;
	neg = false;
	mini_D.clear();
	for (int i = 0; i < grapth.size(); ++i)
	{
		for (int j = 0; j < grapth[i].size(); ++j)
		{
			if (i == j)
			{
				D[i][j] = 0;
			}
			else if (grapth[i][j] == 0)
			{
				D[i][j] = INF;
			}
			else
			{
				D[i][j] = grapth[i][j];
			}
		}
	}
	for (int k = 0; k < grapth.size(); ++k)
	{
		for (int i = 0; i < grapth.size(); ++i)
		{
			for (int j = 0; j < grapth.size(); ++j)
			{
				if (D[i][k] < INF && D[k][j] < INF)
				{
					D[i][j] = std::min(D[i][j], D[i][k] + D[k][j]);
				}
			}
		}
		for (int i = 0; i < grapth.size(); ++i)
		{
			if (D[i][i] < 0)
			{
				neg = true;
				break ;
			}
		}
	}
	std::cout << "Результат для Флойда" << std::endl;
	if (neg == true)
	{
		std::cout << "Существует хотя бы одно ребро с отрицательным весом" << std::endl;
	}
	else
	{
		for (int i = 0; i < D.size(); i++)
		{
			for (int j = 0; j < D[i].size(); j++)
			{
				if (D[i][j] == INF)
				{
					std::cout << "INF ";
				}
				else
				{
					std::cout << D[i][j] << " ";
				}
			}
			std::cout << std::endl;
		}
	}
}

template <typename T>
void grapth_a<T>::Prim(void)
{
	if (typeid(T) != typeid(int))
	{
		std::cout<< "ОШИБКА(заполнение)" << std::endl;
		exit(1);
	}
	for (int i = 0; i < grapth.size(); ++i)
	{
		if (grapth[i].size() != grapth.size())
		{
			std::cout<< "ОШИБКА(размер)" << std::endl;
			exit(1);
		}
	}
	for (int i = 0; i < grapth.size(); i++)
	{
		for (int j = 0; j < grapth[i].size(); j++)
		{
			if (grapth[i][j] < 0)
			{
				std::cout<< "ОШИБКА(неправильное значение)" << std::endl;
				exit(1);
			}
		}
	}
	const int INF = INT_MAX;
	std::vector<bool> visit(grapth.size(), false);
	std::vector<int> D(grapth.size(), INF);
	std::vector<int> P(grapth.size(), 0);
	bool result;
	int n = 0;
	std::vector<std::pair<int, int>> res;
	std::pair<int, int>	edge;
	D[0] = 0;
	result = false;
	while (!result)
	{
		for (int i = 0; i < grapth.size(); ++i)
		{
			int min = INF;
			for (int j = 0; j < grapth[i].size(); ++j)
			{
				if ((visit[j] == false) && (D[j] < min))
				{
					min = D[j];
					n = j;
				}
			}
			visit[n] = true;
			for (int v = 0; v < grapth[i].size(); ++v)
			{
				if ((grapth[n][v] != 0) && (visit[v] == false) && (D[v] > grapth[n][v]))
				{
					D[v] = grapth[n][v];
					P[v] = n + 1;
				}
			}
		}
		result = true;
		for (int i = 0; i < visit.size(); ++i)
		{
			result = result & visit[i];
		}
	}
	std::cout << "Результат для Прима" << std::endl;
	for (int i = 0; i < P.size(); ++i)
	{
		if (P[i] != 0)
		{
			std::cout << "v = " << i + 1 << " Родитель[" << i + 1 << "] = " << P[i] << std::endl;
			edge.first = i + 1;
			edge.second = P[i];
			res.push_back(edge);
		}
	}
}

template <typename T>
void grapth_a<T>::Kruskal(void)
{
	if (typeid(T) != typeid(int))
	{
		std::cout<< "ОШИБКА(заполнение)" << std::endl;
		exit(1);
	}
	for (int i = 0; i < grapth.size(); ++i)
	{
		if (grapth[i].size() != grapth.size())
		{
			std::cout<< "ОШИБКА(размер)" << std::endl;
			exit(1);
		}
	}
	for (int i = 0; i < grapth.size(); i++)
	{
		for (int j = 0; j < grapth[i].size(); j++)
		{
			if (grapth[i][j] < 0)
			{
				std::cout<< "ОШИБКА(неправильное значение)" << std::endl;
				exit(1);
			}
		}
	}
	std::vector<int> D(grapth.size());
	std::vector<std::pair<int, std::pair<int, int>>> edge;
	std::pair<int, std::pair<int, int>> node;
	std::pair<int, int>	mini_edge;
	std::vector<std::pair<int, int>> result;
	int temp;
	for (int i = 0; i < grapth.size(); ++i)
	{
		D[i] = i;
	}
	for (int i = 0; i < grapth.size(); ++i)
	{
		for (int j = i + 1; j < grapth[i].size(); ++j)
		{
			mini_edge.first = i;
			mini_edge.second = j;
			node.second = mini_edge;
			node.first = grapth[i][j];
			edge.push_back(node);
		}
	}
	std::sort(edge.begin(), edge.end(), std::greater<std::pair<int, std::pair<int, int>>>());
		//std::cout<< "SORT" << std::endl;
		//for (int i = 0; i < edge.size(); ++i)
		//{
			//std::cout<< "i = "<< edge[i].second.first << " j = " << edge[i].second.second << " weight = " << edge[i].first << std::endl;
			//if (((i + 1) % 7) == 0)
				//std::cout<< "------" << std::endl;
		//}
	for (int i = edge.size(); i >= 0; --i)
	{
		if ((edge[i].first != 0) && (D[edge[i].second.first] != D[edge[i].second.second]))
		{
			result.push_back(edge[i].second);
			temp = D[edge[i].second.first];
			for (int k = 0; k < grapth.size(); ++k)
			{
				if (D[k] == temp)
				{
					D[k] = D[edge[i].second.second];
				}
			}
		}
	}
	std::cout<< "Результат для Крускала" << std::endl;
	for (int i = 0; i < result.size(); ++i)
	{
		std::cout << "i = " << result[i].first + 1 << " j = " << result[i].second + 1 << std::endl;
	}
}

template <typename T>
void grapth_a<T>::print_grapth(void)
{
	for (int i = 0; i < grapth.size(); i++)
	{
		for (int j = 0; j < grapth[i].size(); j++)
		{
			std::cout << grapth[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
