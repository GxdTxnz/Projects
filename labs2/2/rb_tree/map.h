#ifndef __MAP_H__
# define __MAP_H__

#include <stdlib.h>
#include <utility>
#include <iostream>
#include <cmath>

template <typename T1, typename T2>
struct node
{
    struct node *parent;
    struct node *left;
    struct node *right;
    std::pair<T1,T2> val;
    bool color; // 0 - BLACK, 1 - RED
};

template <typename T>
bool comparator (T a, T b)
{
    return a > b;
};

template <typename T1, typename T2>
class compare
{
private:
    T2 comp;
public:
    compare() 
    { 
		comp = NULL; 
	};
    compare(T2 comp) 
    { 
		this->comp = comp; 
	};
    bool check(T1 val1, T1 val2)
    {
        if (comp)
        {
            return comp(val1, val2);
		}
        else
        {
            return val1 > val2;
		}
    };
};

template <typename T1,typename T2, typename T3>
class map
{
private:
    struct node<T1,T2> *head;
public:
    map() 
    { 
		head = NULL; 
	};
    ~map() 
    {
        del(this->head);
        this->head = NULL;
    }
    node<T1,T2> *copy(node<T1,T2> *head)
    {
        node<T1,T2> *new_head;
        new_head = new node<T1,T2>;
        if (!(head))
        {
            return (NULL);
		}
        else
        {
            new_head->val = head->val;
            new_head->color = head->color;
            new_head->parent = head->parent;
            new_head->left = copy(head->left);
            new_head->right = copy(head->right);
        }
        return (new_head);
    };
    node<T1,T2> *copy_all(void) { return (copy(this->head)); };
    map& operator=(map& tree)
    {
        head = copy(tree.head);
        return (*this);
    };
    bool empty(void) { return (head == NULL); };
    void print(node<T1,T2> *x, int space)
    {
        if (!x)
        {
            return;
		}
        space += 5;
        print(x->right, space);
        std::cout << std::endl;
        for (int i = 5; i < space; i++)
        {
            std::cout<<" ";
		}
        if (x->color)
        {
            std::cout << x->val.first << "`" << "\n";
		}
        else
        {
            std::cout << x->val.first << "\n";
		}
        print(x->left, space);
    };
    void tree_print(int space) { print(head, space); };
    void del(node<T1,T2> *x)
    {
        if (x)
        {
            if (x->left)
            {
                del(x->left);
                x->left = NULL;
            }
            if (x->right)
            {
                del(x->right);
                x->right = NULL;
            }
            delete(x);
        }
    };
    void del_all(void)
    {
		del(this->head);
		this->head = NULL;
	};
#define BLACK (0)
#define RED (1)

#define DAD(x) ((x)->parent)
#define GRANDPA(x) ((DAD(x) == NULL)?(NULL):(DAD(DAD(x))))
  
#define UNSAFE_BROTHER(x) ((DAD(x)->left == x) ? (DAD(x)->right) : (DAD(x)->left))
#define BROTHER(x) ((DAD(x) == NULL)?(NULL):(UNSAFE_BROTHER(x)))
#define UNCLE(x) (BROTHER(DAD(x)))
  
#define COLOR(x) (((x) == NULL) ? (BLACK) : ((x)->color))

    node<T1,T2>* right_swap(node<T1,T2> *x)
    {
        if ( x->right != NULL )
        {
            DAD(x->right) = DAD(x); 
		}
        DAD(x)->left = x->right;
        x->right = DAD(x);
        DAD(x) = GRANDPA(x);
        x->right->parent = x;
        if ( DAD(x) != NULL )
        {
            if ( DAD(x)->left == x->right )
            {
                DAD(x)->left  = x;
			}
            else DAD(x)->right  = x;
        }
        else
        {
            head = x;
        }
        return x->right;    
    };
    node<T1,T2>* left_swap(node<T1,T2> *x)
    {
        if ( x->left != NULL )
        {
            DAD(x->left) = DAD(x);
		}
        DAD(x)->right = x->left;
        x->left = DAD(x);
        DAD(x) = GRANDPA(x);
        x->left->parent = x;
        if ( DAD(x) != NULL )
        {
            if ( DAD(x)->left == x->left )
            {
                DAD(x)->left  = x;
			}
            else DAD(x)->right  = x;
        }
        else
        {
            head = x;
        }
        return x->left;    
    };
    node<T1,T2>* balance(node<T1,T2> *x)
    {
        if (x == head)
        {
            x->color = 0;
            return x;
        }
        if ( GRANDPA(x) == NULL )
        {
            return x;
        }
        if (COLOR(UNCLE(x)) == RED)
        {
            GRANDPA(x)->color = RED;
            UNCLE(x)->color = BLACK;
            DAD(x)->color = BLACK;
            return balance(GRANDPA(x));
        }
        if (COLOR(DAD(x)) != RED)
        {
            return (x);
		}
        if ((DAD(x)->left == x) && (GRANDPA(x)->right == DAD(x)))
        {
            return balance(right_swap(x));
        }
        else if ((DAD(x)->right == x) && (GRANDPA(x)->left == DAD(x)))
        {
            return balance(left_swap(x));
        }
        if ((DAD(x)->left == x) && (GRANDPA(x)->left == DAD(x)))
        {
            GRANDPA(x)->color = RED;
            DAD(x)->color = BLACK;
            return balance(right_swap(DAD(x)));
        }
        else if ((DAD(x)->right == x) && (GRANDPA(x)->right == DAD(x)))
        {
            GRANDPA(x)->color = RED;
            DAD(x)->color = BLACK;
            return balance(left_swap(DAD(x)));
        }
        return x;    
    };
    void add(T1 key,T2 val)
    {
        node<T1,T2> *elem, *head;
        compare<T1,T3> *item;
        item = new compare<T1,T3>(comparator);
        elem = new node<T1,T2>;
        elem->val.first = key;
        elem->val.second = val;
        elem->color = RED;
        elem->left = elem->right = elem->parent = NULL;
        if (this->head == NULL)
        {
            elem->color = BLACK;
            this->head = elem;  
            return ;
        }   
        head = this->head;
        while (true)
        {
            if (item->check(head->val.first, key))
            {
                if (head->left == NULL)
                {
                    elem->parent = head;
                    head->left = elem;
                    break;
                }
                head = head->left;
            }
            else
            {
                if (head->right == NULL)
                {
                    elem->parent = head;
                    head->right = elem;
                    break;
                }
                head = head->right;
            }
        }
        balance(elem);
    };
    T2 & operator[](T1 key)
    {
        return (find(key));
    };
    T2 find(T1 key)
    {
		compare<T1,T3> *item;
        node<T1,T2>    *head;
        item = new compare<T1,T3>(comparator);
        if (!(this->head))
        {
            return (NULL);
		}
        head = this->head;
        while ((head->left || head->right) && key != head->val.first)
        {
            if (item->check(head->val.first, key) && head->left)
            {
                head = head->left;
			}
            else if (!item->check(head->val.first, key) && head->right)
            {
                head = head->right;
			}
            else
            {
                break;
			}
        }
        if (key == head->val.first)
        {
            return (head->val.second);
		}
        return (NULL);
    };
    bool check_tree(node<T1,T2> *x)
    {
        if (x->color)
        {
            if (x->left != NULL && x->left->color)
            {
                return (1);
			}
            if (x->right != NULL && x->right->color)
            {
                return (1);
			}
        }
        if (x->left != NULL)
        {
            check_tree(x->left);
		}
        if (x->right != NULL)
        {
            check_tree(x->right);
		}
    };
    bool check(void)
    {
        node<T1,T2> *head;
        head = this->head;
        if (head->color == 1)
		{
            return (1);
		}
        if (check_tree(head->left))
        {
            return (1);
		}
        if (check_tree(head->right))
        {
            return (1);
		}
        return (0);
    };
    bool check_black_height(node<T1,T2> *x, int current_black_height, const int tree_black_height)
    {
        if (x == NULL)
        {
            return current_black_height == tree_black_height;
		}
        int is_black = (x->color == BLACK);
        bool left_is_correct = check_black_height(x->left, current_black_height + is_black, tree_black_height);
        bool right_is_correct = check_black_height(x->right, current_black_height + is_black, tree_black_height);
        return left_is_correct && right_is_correct;
    };
    bool heck_black_height(void)
    {
        node<T1,T2> *x = head;
        int black_height = 0;
        while (x != NULL)
        {
            if (x->color == BLACK)
            {
                black_height++;
			}
            x = x->left;
        }
        return check_black_height(head, 0, black_height);
    };
    int count(node<T1,T2> *x)
    {
        if (x == NULL)
        {
            return 0;
		}
        return count(x->right) + count(x->left) + 1;
    };
    bool check_log_n(node<T1,T2> *x, int height, int size)
    {
        if (x == NULL)
        {
            return height <= (2 * log2(size + 1));
		}
        bool left_is_correct = check_log_n(x->left, height + 1, size);
        bool right_is_correct = check_log_n(x->right, height + 1, size);
        return (left_is_correct && right_is_correct);
    };
    bool check_log(void)
    {
        //std::cout << "count = " << count(head) << std::endl;
        return (check_log_n(head, 0, count(head)));
    };
};
#endif
