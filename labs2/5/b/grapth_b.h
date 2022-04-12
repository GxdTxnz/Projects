#ifndef __GRAPTH_B_H__
#define __GRAPTH_B_H__

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

template <typename T>
class grapth_a
{
private:
	std::vector<std::vector<T>>	grapth;
public:
	grapth_a();
	grapth_a(std::vector<std::vector<T>> graf);
	void print_grapth(void);
	std::vector<bool> cycle(int x, int p, std::vector<bool> visit);
	std::vector<int> dfs_inv(int x, std::vector<bool> &visit, std::vector<int> stack);
	void dfs(void);
	int	count_dfs(int x, int count, std::vector<bool>&	visit, std::vector<std::vector<T>> graf);
	bool is_one(int x, std::vector<std::vector<T>> graf);
	bool is_bridge(int x, int c, std::vector<std::vector<T>> graf);
	int count_n(void);
	bool is_empty(std::vector<std::vector<T> > graf);
	void Fleri(void);
	void check_v(void);
	std::vector<int> find_euler_path(int s, std::vector<std::vector<T>>& graf, std::vector<int> result);
	void find_cycle(int s);
	std::vector<std::vector<T>>	Trans(std::vector<std::vector<T>> graf);
	void K_dfs(int x, std::vector<bool>& visit, std::vector<std::vector<T> > graf);
	void K_dfs_inv(int x, std::vector<bool>& visit, std::vector<int>& stack, std::vector<std::vector<T> > graf);
	void Kosaraju(void);
};

#include "grapth_b.cpp"
#endif
