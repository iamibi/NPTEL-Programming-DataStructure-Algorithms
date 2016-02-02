/*
 * This program calculates the bronze medalist i.e., the third position holder
 * I have taken a temporary array which I have sorted using Merge Sort and then finally
 * checked the original array with the index 2 of temporary array and printed the index.
*/

#include <stdio.h>

//Prototypes for merge sort and partition
void mergeSort(int [], int, int, int);
void partition(int [], int, int);

int Bronze()
{
    int arr[10], i, temp[10];       //temporary array

    for (i = 0; i < 10; i++)
    {
        scanf ("%d", &arr[i]);
        temp[i] = arr[i];           //copy all the elements of original array to temporary array
    }

    //sort the temporary array
    partition(temp, 0, 9);
    
    for (i = 0; i < 10; i++)
    {
        //check for index values in the original array curresponding to index 2 of temporary array
        if (arr[i] == temp[2])
        {
            //print the index + 1
            printf ("%d", i + 1);
            return 0;
        }
    }
    return 0;
}

int main()
{
    int i, t;

    scanf ("%d", &t);
    for (i = 0; i < t; i++)
    {
        Bronze();
        
        //had to include this line due to presentation error
      	if (i != t - 1)
        	printf ("\n");
    }
    return 0;
}

void partition(int arr[], int low, int high)
{
    int mid;
    
    if(low < high)
    {
        mid = (low + high) / 2;
        partition(arr, low, mid);
        partition(arr, mid + 1, high);
        mergeSort(arr, low, mid, high);
    }
}

void mergeSort(int arr[], int low, int mid, int high)
{
    int i, m, k, l, temp[10];

    l = low;
    i = low;
    m = mid + 1;

    while(l <= mid && m <= high)
    {
        if(arr[l] <= arr[m])
        {
            temp[i]=arr[l];
            l++;
        }
        else
        {
            temp[i]=arr[m];
            m++;
        }
        i++;
    }

    if(l > mid)
    {
        for(k = m; k <= high; k++)
        {
             temp[i] = arr[k];
             i++;
        }
    }
    else
    {
        for(k = l; k <= mid; k++)
        {
             temp[i]=arr[k];
             i++;
        }
    }
   
    for(k = low; k <= high; k++)
         arr[k]=temp[k];
}
