/*
 * This program uses the concept of hashing.
 * By keeping the record of the number of times the element has occured,
 * Union and Intersection operation can be performed.
 *
*/

LNodeP unionlist(LNodeP first, LNodeP second)
{
    LNodeP ptr = NULL, temp, prev;
    int max = 0;

    //set a temporary pointer to the head of the first list
    temp = first;
    while (temp)
    {
        //create a new list that contains both the first list and the second list
        append(&ptr, temp -> data);
        if (temp -> data > max)
            max = temp -> data;
        temp = temp -> next;
    }
    
    //second list
    temp = second;
    while (temp)
    {
        append(&ptr, temp -> data);
        if (temp -> data > max)
            max = temp -> data;
        temp = temp -> next;
    }

    //create a hash array which keeps the record of the elements that occur
    //size of hash array is the maximum element present in the list.
    int hash[max+1], i;

    //set all the entries to 0
    for (i = 0; i < max + 1; i++)
        hash[i] = 0;
    
    temp = ptr;
    while (temp)
    {
        //if the hash value is 0 for the current data, set it to 1
        if (!hash[temp -> data])
            hash[temp -> data] = 1;
        temp = temp -> next;
    }
    temp = ptr;
    while (temp)
    {
        //if the data is being traversed for the first time
        if (hash[temp -> data])
        {
            hash[temp -> data] = 0;
            prev = temp;
            temp = temp -> next;
        }
        else        //else remove that node from the list
        {
            prev -> next = temp -> next;
            temp -> next = NULL;
            free(temp);
            temp = NULL;
            temp = prev -> next;
        }
    }
    
    //return the head of the new list
    return ptr;
}

LNodeP intersection(LNodeP first, LNodeP second)
{
    LNodeP ptr = NULL, temp, prev = NULL;
    int max = 0;
    
    //join both the list to a new list
    temp = first;
    while (temp)
    {
        append(&ptr, temp -> data);
        if (temp -> data > max)
            max = temp -> data;
        temp = temp -> next;
    }
    temp = second;
    while (temp)
    {
        append(&ptr, temp -> data);
        if (temp -> data > max)
            max = temp -> data;
        temp = temp -> next;
    }

    //create a hash array
    int hash[max+1], i;

    //set hash values to 0
    for (i = 0; i < max + 1; i++)
        hash[i] = 0;

    temp = ptr;
    while (temp)
    {
        //for every element in the linked list, count the number of times it occurs
        hash[temp -> data]++;
        temp = temp -> next;
    }
    temp = ptr;
    while (temp)
    {
        //if the hash entry is greater than 1, then the data is to be kept in the list
        if (hash[temp->data] > 1)
        {
            hash[temp->data] = 0;
            prev = temp;
            temp = temp -> next;
        }
        else            //else the node is to be removed
        {
            //if the removed node is the first node
            if (temp == ptr)
            {
                ptr = ptr -> next;
                temp -> next = NULL;
                free(temp);
                temp = NULL;
                temp = ptr;
            }
            else
            {
                prev -> next = temp -> next;
                temp -> next = NULL;
                free(temp);
                temp = NULL;
                temp = prev -> next;
            }
        }
    }
    
    //return the head of the new list
    return ptr;
}
