#include "substring.h"

substring::substring() { };

std::vector<int> substring::Rabin_Karp(std::vector<int> T, std::vector<int> P)
{
	int	n;
	int	m;
	int	d_m;
	int	h;
	int	sub_h;
	int	u;
	int	count;
	int	d = 10;
	int	q = 31;
	std::vector<int> result;
	count = 0;
	h = sub_h = 0;
	n = T.size();
	m = P.size();
	u = pow(d, m - 1);
	d_m = u%q;
	for (int i = 0; i < m; ++i)
	{
		h = (d * h + P[i]) % q;
		sub_h = (d * sub_h + T[i]) % q;
	}
	for (int s = 0; s < n - m + 1; ++s)
	{
		if (h == sub_h)
		{
			count = 0;
			for (int i = 0; i < m; ++i)
			{
				if (P[i] == T[s + i])
				{
					count++;
				}
			}
			if (count == m)
			{
				result.push_back(s);
			}
		}
		if (s < n - m)
		{
			sub_h = (d * (sub_h - d_m * T[s]) + T[s + m]) % q;
			if (sub_h < 0)
			{
				sub_h = q + sub_h;
			}
		}
	}
	return (result);
}

std::vector<int> substring::prefix_func(std::vector<char> S)
{
	int	k;
	std::vector<int> pi(S.size(), 0);
	k = 0;
	pi[0] = 0;
	for (int i = 1; i < S.size(); ++i)
	{
		while ((k > 0) && (S[k] != S[i]))
		{
			k = pi[k - 1];
		}
		if (S[k] == S[i])
		{
			k = k + 1;
		}
		pi[i] = k;
	}
	return (pi);
}

std::vector<int> substring::knuth_morris_pratt(std::vector<char> T, std::vector<char> P)
{
	std::vector<int> pi;
	std::vector<int> result;
	int	k;
	k = 0;
	pi = prefix_func(P);
	for (int i = 0; i < T.size(); ++i)
	{
		while ((k > 0) && (P[k] != T[i]))
		{
			k = pi[k - 1];
		}
		if (P[k] == T[i])
		{
			k = k + 1;
		}
		if (k == P.size())
		{
			result.push_back(i - P.size() + 1);
			k = pi[k - 1];
		}
	}
	return (result);
}

std::vector<int> substring::getSuffixTable(std::vector<char> P)
{
	int	m;
	int	ind;
	int	shift;
	std::vector<int> pi;
	std::vector<int> pi_sub;
	m = P.size();
	std::vector<int> table(m + 1);
	pi = prefix_func(P);
	std::reverse(P.begin(), P.end());
	pi_sub = prefix_func(P);
	for (int i = 0; i < m + 1; ++i)
	{
		table[i] = m - pi[m - 1];
	}
	for (int i = 0; i < m; ++i)
	{
		ind = m - pi_sub[i];
		shift = i - pi_sub[i] + 1;
		if (table[ind] > shift)
		{
			table[ind] = shift;
		}
	}
	return (table);
}

std::vector<int> substring::getStopTable(std::vector<char> P)
{
	std::vector<int> result(256, -1);
	for (int i = 0; i < P.size() - 1; ++i)
	{
		result[(int) P[i]] = i;
	}
	return(result);
}

std::vector<int> substring::boyer_moor(std::vector<char> T, std::vector<char> P)
{
	std::vector<int> suff;
	std::vector<int> stop;
	int	j;
	int delta_stop;
	int	delta_suff;
	std::vector<int> result;
	j = 0;
	suff = getSuffixTable(P);
	stop = getStopTable(P);
	for (int i = 0; i < T.size() - P.size() + 2; )
	{
		j = P.size() - 1;
		while ((j >= 0) && (P[j] == T[i + j]))
		{
			j = j - 1;
		}
		if (j == -1)
		{
			result.push_back(i);
			delta_stop = 1;
		}
		else
		{
			delta_stop = j - stop[T[i + j]];
		}
		delta_suff = suff[j + 1];
		i = i + fmax(delta_suff, delta_stop);
	}
	return (result);
}
