/*
 *
 * This function returns the Nearest larger number(NLN) of elements of Stack
 * else a -1 is returned.
 *
*/

Stack returnStackWithNearestGreater(Stack inputStack)
{
    int i, arr[MAX], j, max, k, flag = 0;

    for (i = 0; ; i++)
    {
        //empty the whole stack in an array
        arr[i] = inputStack.pop();
        
        //if the stack is now empty, we have reached the end
        if (arr[i] == -1)
            break;
    }

    for (k = 0; k < i; k++)
    {
        flag = 0;
        max = arr[k];
        for (j = k; j < i; j++)
        {
            //is there an element greater than the current element
            //just below the current element
            if (arr[j] > max)
            {
                max = arr[j];
                flag = 1;
                break;
            }
        }
        
        //if yes, set the value, else set -1
        if (flag)
            arr[k] = max;
        else
            arr[k] = -1;
    }
    
    //push the elements of array in the stack
    for (j = i - 1; j >= 0; j--)
        inputStack.push(arr[j]);
        
    return inputStack;
}
