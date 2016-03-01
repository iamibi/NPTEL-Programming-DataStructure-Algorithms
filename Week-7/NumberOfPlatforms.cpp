/*
 *
 * This program counts the minimum number of platforms for every train to be present
 * 
*/

//Insertion Sort
void InsertionSort(int *arr, int n)
{
    int temp, i, j;

    for (i = 0; i < n; i++)
    {
        temp = arr[i];
        j = i;

        while (temp < arr[j-1] && j > 0)
        {
            arr[j] = arr[j-1];
            j--;
        }

        arr[j] = temp;
    }
}

int findPlatform(int arr[], int dep[], int n)
{
    //sort the arrival array
    InsertionSort(arr, n);
    
    //sort the departure array
    InsertionSort(dep, n);
 
    //since there has to be a minimum of 1 platform, set the count to 1
    int count = 1, res, i, j;

    //result platform is also set to 1
    res = 1;
    for (i = 0, j = 1; i < n && j < n; )
    {
        //if the value of arrival platform is less than the departure platform
        if (arr[j] < dep[i])
        {
            //increment the number of platforms until the arrival time is greater than
            //the departure time
            count++;
            j++;

            //is the current count the maximum count ?
            if (count > res)
                res = count;
        }
        else
        {
            //else decrement the number of platforms until the departure platform is greater
            count--;
            i++;
        }
    }
 
    return res;
}
