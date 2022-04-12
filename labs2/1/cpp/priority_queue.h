#ifndef __PRIORITY_QUEUE_H__
# define __PRIORITY_QUEUE_H__

# include <stdio.h>
# include <stdlib.h>
# include <vector>
# include <string>
# include <iostream>

template <typename T>
class priority_queue
{
	private:
		std::vector <T>	mass;
	public:
		bool empty(void)
		{
			return mass.empty();
		};
		int	len(void)
		{
			return (mass.size());
		};
		T max(void)
		{
			return (mass.front());
		};
		void del(void)
		{
			int	i;
			T k;
			T n;
			k = mass.back();
			mass.pop_back();
			mass[0] = k;
			i = 0;
			while (i < mass.size())
			{
				if (2 * i + 1 < mass.size() && (mass[i] < mass[2 * i + 1]))
				{
					if (2 * i + 2 < mass.size() && (mass[i] < mass[2 * i + 2]))
					{
						if (mass[2 * i + 1] < mass[2 * i + 2])
						{
							n = mass[i];
							mass[i] = mass[2 * i + 2];
							mass[2 * i + 2] = n;
							i = 2 * i + 2;
						}
						else
						{
							n = mass[i];
							mass[i] = mass[2 * i + 1];
							mass[2 * i + 1] = n;
							i = 2 * i + 1;
						}
					}
					else
					{
						n = mass[i];
						mass[i] = mass[2 * i + 1];
						mass[2 * i + 1] = n;
						i = 2 * i + 1;
					}
				}
				else if (2 * i + 2 < mass.size() && (mass[i] < mass[2 * i + 2]))
				{
					n = mass[i];
					mass[i] = mass[2 * i + 2];
					mass[2 * i + 2] = n;
					i = 2 * i + 2;
				}
				else
				{
					break;
				}
			}
		};
		void add(T n_elem)
		{
			int	i;
			T k;
			mass.push_back(n_elem);
			i = mass.size() - 1;
			while (i > 0)
			{
				if (mass[i] > mass[(i - 1) / 2])
				{
					k = mass[i];
					mass[i] = mass[(i - 1) / 2];
					mass[(i - 1) / 2] = k;
					i = (i - 1) / 2;
				}
				else
				{
					break;      
				}
			}
		};
		void print(void)
		{
			for (int i = 0 ; i < mass.size() ; i++ )
			{
				std::cout << ">>" << mass[i] << std::endl;
			}
		};
};

#endif
