/*    Function to load the numbers onto the linked list
      Return a pointer to the head of the list  */
Node loadNum()
{
    //declare a node head and set it to NULL
    Node head;
    head = NULL;
    int val;

    //repeat the loop until -1 is received
    do
    {
        Node ptr;

        scanf ("%d", &val);
        
        //allocate the new pointer memory
        ptr = (Node)malloc(sizeof(Node));
        ptr -> data = val;
        
        //if the current node is the first node
        if (head == NULL)
        {
            ptr -> next = head;
            head = ptr;
        }
        else
        {
            Node p, temp = head;
            
            //else insert the new node after the n'th node
            while (temp != NULL)
            {
                p = temp;
                temp = temp -> next;
            }
            ptr -> next = temp;
            p -> next = ptr;
        }
    }while (val != -1);

    return head;
}

/* Function to release the memory after every iteration */
void releaseMem(Node head)
{
    Node aux, iter;

    if (head == NULL)
        return;

    iter = head;
    while (iter)
    {
        aux = iter -> next;
        free(iter);
        iter = NULL;
        iter = aux;
    }
    head = NULL;
}
