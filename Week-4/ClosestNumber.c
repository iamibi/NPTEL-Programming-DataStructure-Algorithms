/*
 * This program prints out the closest numbers that are around 'k'
 *
 * Program complexity is O(logn)
*/

//Binary search algorithm
int BinarySearch(int *arr, int n, int x)
{
    int low = 0, high = n - 1, mid = (low + high) / 2;

    while (low <= high)
    {
        if (arr[mid] <= x && arr[mid+1] > x)
            return mid;
        else if (arr[mid] < x)
            low = mid + 1;
        else if (arr[mid] > x)
            high = mid - 1;

        mid = (low + high) / 2;
    }
    if (arr[high] <= x)
        return high;
    else if (arr[low] > x)
        return low;
}

int printclosest(int *arr, int k, int n)
{
    int pivot, i, j = 0, right, count = 0;
  	int temp[n];

    //search for the index closest to or equal to 'k' using binary search
    pivot = BinarySearch(arr, n, k);
    right = pivot + 1;                  //set the right index to pivot + 1

    //if there are multiple values, take them into account
    if (arr[pivot] == k)
    {
        temp[j++] = arr[pivot];
        pivot--;                        //decrement the pivot element
        count++;                        //have we reached the number 5 ?
    }

    //repeat until we have got the 5 elements or pivot has reached the starting or right index has
    //reached the end of array
    while (pivot >= 0 && right < n && count < 5)
    {
        //check for the difference
        if (k - arr[pivot] < arr[right] - k)
        {
            temp[j++] = arr[pivot];
            pivot--;                    //decrement the pivot
        }
        else
        {
            temp[j++] = arr[right];
            right++;                    //increment the right index
        }
        count++;                        //increase the count
    }

    //if all the elements are not yet taken, take the left half into account
    while (count < 5 && pivot >= 0)
    {
        temp[j++] = arr[pivot];
        pivot--;
        count++;
    }
    
    //now, take the right half into account
    while (count < 5 && right < n)
    {
        temp[j++] = arr[right];
        right++;
        count++;
    }
  
    //finally print the whole temporary array 
  	for (i = 0; i < j; i++)
    {
		printf ("%d", temp[i]);
      	if (i != j - 1)
            printf (" ");
    }
    return 0;
}
