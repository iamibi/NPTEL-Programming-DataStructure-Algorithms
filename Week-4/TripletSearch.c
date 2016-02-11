/*
 * This program searches for any triplets that may exist in the array whose sum
 * is equal to the given 'sum'
 *
 * Complexity of this program is O(n^2)
*/

#include <stdio.h>

//selection sort for sorting the array
void SelectionSort(int *arr, int n)
{
    int i, j, temp, pos;
    
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[pos] > arr[j])
                pos = j;
        }
        if (pos != i)
        {
            temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
        }
    }
}

int main()
{
    int n, sum, i, j, k, count = 0;

    scanf ("%d%d", &n, &sum);
    int arr[n];

    for (i = 0; i < n; i++)
        scanf ("%d", &arr[i]);

    //if n is less than or equal to 2, then the triplets cannot exist
    if (n <= 2)
    {
        printf ("0");
        return 0;
    }

    //sort the given array using selection sort
    SelectionSort(arr, n);
    
    //start searching for the triplets
    for (i = 0; i < n - 2; i++)
    {
        j = i + 1;
        k = n - 1;

        while (j < k && j < n && k >= 0)
        {
            //if the triplets are found, increment the count
            if (arr[i] + arr[j] + arr[k] == sum)
            {
                count++;
                j++;                //since the elements are unique, the pointers can be moved ahead
                k--;
            }
            else if (arr[i] + arr[j] + arr[k] < sum)
                j++;
            else
                k--;
        }
    }

    printf ("%d", count);

    return 0;
}
