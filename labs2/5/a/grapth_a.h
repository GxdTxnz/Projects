#ifndef __GRAPTH_A_H__
#define __GRAPTH_A_H__

//#include "grapth_a.cpp"
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <climits>

template <typename T>
class grapth_a
{
private:
    std::vector<std::vector<T>> grapth;
public:
    grapth_a();
    grapth_a(std::vector<std::vector<T> > graf);
	std::vector<bool> find_depth(int x, std::vector<bool> visit);
	void dfs(void);
	void bfs(void);
	void Dijkstra(int s);
	void Floyd(void);
	void Prim(void);
	void Kruskal(void);
	void print_grapth(void);
};
#include "grapth_a.cpp"
#endif
