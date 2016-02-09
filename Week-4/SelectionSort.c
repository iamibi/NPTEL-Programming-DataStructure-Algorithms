/* Write a function that prints the elements after k iterations
   of selection sort
*/
void printSelectSortIter(int arr[], int n, int k)
{
    int i, j, pos, temp;

    //selection sort upto k'th times
    for (i = 0; i < k; i++)
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
    
    //print the latest sorted array
    for (i = 0; i < n; i++)
    {
        if (i != n - 1)
            printf ("%d ", arr[i]);
        else
            printf ("%d", arr[i]);
    }
}
