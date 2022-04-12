#include "grapth_b.h"

template <typename T>
grapth_a<T>::grapth_a(){}

template <typename T>
grapth_a<T>::grapth_a(std::vector<std::vector<T> > graf) 
{ 
	this->grapth = graf; 
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

template <typename T>
std::vector<bool> grapth_a<T>::cycle(int x, int p, std::vector<bool> visit)
{
	visit[x] = true;
	for (int i = 0; i < grapth[x].size(); i++)
	{
		if (grapth[x][i] != 0)
		{
			if (visit[i] == false)
			{
				visit = cycle(i, x, visit);
			}
			else if (i == p)
			{
				std::cout << "ОШИБКА(неправильное значение)" << std::endl;
				exit(1);
			}
		}
	}
	return (visit);
}

template <typename T>
std::vector<int> grapth_a<T>::dfs_inv(int x, std::vector<bool> &visit, std::vector<int> stack)
{
	visit[x] = true;
	for (int i = 0; i < grapth[x].size(); ++i)
	{
		if ((grapth[x][i] != 0) && (visit[i] == false))
		{
			stack = dfs_inv(i, visit, stack);
		}
	}
	stack.push_back(x + 1);
	return (stack);
}

template <typename T>
void grapth_a<T>::dfs(void)
{
	if (typeid(T) != typeid(bool))
	{
		std::cout << "ОШИБКА(заполнение)" << std::endl;
		exit(1);
	}
	for (int i = 0; i < grapth.size(); ++i)
	{
		if (grapth[i].size() != grapth.size())
		{
			std::cout << "ОШИБКА(размер)" << std::endl;
			exit(1);
		}
	}
	std::vector<bool> visit(grapth.size(), false);
	for (int i = 0; i < grapth.size(); ++i)
	{
		cycle(i, 0, visit);
	}
	for (int i = 0; i < visit.size(); ++i)
	{
		visit[i] = false;
	}
	std::vector<int> stack;
	for (int i = 0; i < grapth.size(); ++i)
	{
		if (visit[i] == false)
		{
			stack = dfs_inv(i, visit, stack);
		}
	}
	std::cout<< "DFS" << std::endl;
	for (int i = 0; i < stack.size(); ++i)
	{
		std::cout<< stack[i] << " "; 
	}
	std::cout << std::endl;
}
template <typename T>
int grapth_a<T>::count_dfs(int x, int count, std::vector<bool>&	visit, std::vector<std::vector<T>> graf)
{
	visit[x] = true;
	for (int i = 0; i < graf[x].size(); i++)
	{
		if (graf[x][i] != 0)
		{
			if (visit[i] == false)
			{
				count = count_dfs(i, count, visit, graf);
			}
		}
	}
	return (count);
}

template <typename T>
bool grapth_a<T>::is_one(int x, std::vector<std::vector<T>> graf)
{
	int count;
	count = 0;
	for (int i = 0; i < graf[x].size(); ++i)
	{
		if (graf[x][i] != 0)
			count++;
	}
	if (count > 1)
	{
		return (false);
	}
	return(true);
}

template <typename T>
bool grapth_a<T>::is_bridge(int x, int c, std::vector<std::vector<T> > graf)
{
	int count;
	int d_count;
	T weight;
	std::vector<bool> visit(grapth.size(), false);
	count = count_dfs(x, count, visit, graf);
	weight = graf[x][c];
	graf[x][c] = 0;
	graf[c][x] = 0;
	d_count = count_dfs(x, count, visit, graf);
	graf[x][c] = weight;
	graf[c][x] = weight;
	return ((count > d_count) ? true : false);
}
template <typename T>
int grapth_a<T>::count_n(void)
{
	std::vector<int> count_edge(grapth.size(), 0);
	int neg;
	neg = 0;
	for (int i = 0; i < grapth.size(); ++i)
	{
		for (int j = 0; j < grapth[i].size(); ++j)
		{
			if (grapth[i][j] != 0)
			{
				count_edge[i]++;
			}
		}
	}
	for (int i = 0; i < count_edge.size(); ++i)
	{
		if ((count_edge[i] % 2) == 1)
		{
			neg++;
		}
	}
	if (neg == 0)
	{
		return (0);
	}
	else if ((neg % 2) == 0)
	{
		for (int i = 0; i < count_edge.size(); ++i)
		{
			if (((count_edge[i] % 2) == 1) && !is_one(i, grapth))
			{
				return (i);
			}
		}
		for (int i = 0; i < count_edge.size(); ++i)
		{
			if ((count_edge[i] % 2) == 1)
			{
				return (i);
			}
		}
	}
	else
	{
		std::cout<< "ОШИБКА(неправильное значение)" << std::endl;
		return (-1);
			//exit(1);
	}
	return (-1);
}

template <typename T>
bool grapth_a<T>::is_empty(std::vector<std::vector<T> > graf)
{
	int count;
	count = 0;
	for (int i = 0; i < graf.size(); ++i)
	{
		for (int j = 0; j < graf[i].size(); ++j)
		{
			if (graf[i][j] != 0)
			{
				count++;
			}
		}
	}
	if (count == 0)
	{
		return (true);
	}
	return(false);
}

template <typename T>
void grapth_a<T>::Fleri(void)
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
	std::vector<std::vector<T>> graf;
	std::vector<std::pair<int, int>> result;
	int s;
	int count;
	int flag;
	int i;
	graf = grapth;
	count = 0;
	i = 0;
	s = count_n();
	if (s < 0)
	{
		std::cout<< "ОШИБКА(S)" << std::endl;
		return ;
	}
	while (!is_empty(graf))
	{
		for (int i = 0; i < graf[s].size(); ++i)
		{
			if (graf[s][i] != 0)
			{
				if (!is_bridge(s, i, graf) || is_one(s, graf))
				{
					graf[s][i] = 0;
					graf[i][s] = 0;
					result.push_back(std::make_pair(s + 1, i + 1));
					s = i;
				}
			}
		}
	}
	std::cout<< "Результат для Флери" << std::endl;
	for (int j = 0; j < result.size(); ++j)
	{
		std::cout << "(" << result[j].first << ", " << result[j].second << ") "; 
	}
	std::cout << std::endl;
}

template <typename T>
void grapth_a<T>::check_v(void)
{
	std::vector<int> count_edge(grapth.size(), 0);
	for (int i = 0; i < grapth.size(); ++i)
	{
		for (int j = 0; j < grapth[i].size(); ++j)
		{
			if (grapth[i][j] != 0)
			{
				count_edge[i]++;
			}
		}
	}
	for (int i = 0; i < count_edge.size(); ++i)
	{
		if ((count_edge[i] % 2) == 1)
		{
			std::cout<< "ОШИБКА(неправильное значение)" << std::endl;
			exit(1);
		}
	}
}

template <typename T>
std::vector<int> grapth_a<T>::find_euler_path(int s, std::vector<std::vector<T> >& graf, std::vector<int> result)
{
	for (int i = 0; i < graf[s].size(); ++i)
	{
		if (graf[s][i] != 0)
		{
			graf[s][i] = 0;
			graf[i][s] = 0;
			result = find_euler_path(i, graf, result);
		}
	}
	result.push_back(s + 1);
	return (result);
}

template <typename T>
void grapth_a<T>::find_cycle(int s)
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
		std::cout<< "ОШИБКА(значение S)" << std::endl;
		exit(1);
	}
	std::vector<std::vector<T> > graf;
	std::vector<int> result;
	s = s - 1;
	check_v();
	graf = grapth;
	result = find_euler_path(s, graf, result);
	std::cout<< "Результат для Эйлера s = " << s + 1 << std::endl;
	for (int j = 0; j < result.size(); ++j)
	{
		std::cout << result[j] << " "; 
	}
	std::cout << std::endl;
}
template<typename T>
void grapth_a<T>::K_dfs_inv(int x, std::vector<bool>& visit, std::vector<int>& stack, std::vector<std::vector<T> > graf)
{
	visit[x] = true;
	for (int i = 0; i < graf[x].size(); ++i)
	{
		if ((graf[x][i] != 0) && (visit[i] == false))
		{
			K_dfs_inv(i, visit, stack, graf);
		}
	}
	stack.push_back(x + 1);
}

template<typename T>
std::vector<std::vector<T>>	grapth_a<T>::Trans(std::vector<std::vector<T> > graf)
{
	std::vector<std::vector<T>>	n_graf;
	n_graf = graf;
	for (int i = 0; i < graf.size(); ++i)
	{
		for (int j = 0; j < graf[i].size(); ++j)
		{
			n_graf[i][j] = graf[j][i];
		}
	}
	return(n_graf);
}

template<typename T>
void grapth_a<T>::K_dfs(int x, std::vector<bool>& visit, std::vector<std::vector<T> > graf)
{
	visit[x] = true;
	std::cout << x + 1 << " ";
	for (int i = 0; i < graf[x].size(); ++i)
	{
		if ((graf[x][i] != 0) && (visit[i] == false))
		{
			K_dfs(i, visit, graf);
		}
	}
}

template<typename T>
void grapth_a<T>::Kosaraju(void)
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
	std::vector<bool> visit(grapth.size(), false);
	std::vector<std::vector<T>>	graf;
	std::vector<int> comp(grapth.size());
	std::vector<int> stack;
	int v;
	graf = grapth;
	for (int i = 0; i < grapth.size(); ++i)
	{
		if (visit[i] == false)
		{
			K_dfs_inv(i, visit, stack, Trans(graf));
		}
	}
	for (int i = 0; i < grapth.size(); ++i)
	{
		visit[i] = false;
	}
	std::cout<< "Результат для Косарайю" << std::endl;
	while (!stack.empty())
	{
		v = stack[stack.size() - 1] - 1;
		stack.pop_back();
		if (visit[v] == false)
		{
			K_dfs(v, visit, graf);
			std::cout << std::endl;
		}
	}
}
