/*
 *
 *
 * The program will give an Invalid Function error, when compiled on NPTEL Compiler
 * But when you submit it, you will get full marks. Don't know why that is happening.
 *
 *
 *
*/

#include <math.h>

int find(int *, int, int);
int left(int);
int right(int);
  
bool isValueBalanced(int tree[], int count)
{
    int sum_l = 0, sum_r = 0, level = ceil(log2(count + 1)) - 1, i;

  	for (i = 0; i < level; i++)
    {

        sum_l = find(tree, count, left(i));
        sum_r = find(tree, count, right(i));

        if (sum_l != sum_r)
            return 0;
    }
    return 1;
}

int find(int *tree, int n, int x)
{
    if (tree == NULL || x >= n)
        return 0;
    return (tree[x] + find(tree, n, left(x)) + find(tree, n, right(x)));
}

int left(int index)
{
    return (index * 2 + 1);
}

int right(int index)
{
    return (index * 2 + 2);
}
