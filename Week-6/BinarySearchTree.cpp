/*
 *
 * Sorry for the late upload. Was having trouble getting 100.0/100.
 * But finally figured it out ;)
 *
 * The compiler of NPTEL may give an error of Invalid Function. To get pass that, either recompile again and again
 * until it says passed and then try to submit the solution. If you get 0.0/100, resubmit the solution again.
 * Their compiler seems to be buggy.
*/

//insert into binary search tree
treeNode* binarySearchTree :: insert(int key)
{
    //if the tree is empty
    if (root == NULL)
    {
        treeNode *newNode;
        newNode = new treeNode;
        newNode -> data = key;
        newNode -> left = newNode -> right = NULL;
        root = newNode;

        return root;
    }

    //if the tree has nodes, traverse the tree and find the correct position of the node
    treeNode *ptr = root;
    
    while (1)
    {
        if (ptr -> data == key)
            return NULL;
        else if (key < ptr -> data)
        {
            if (ptr -> left != NULL)
                ptr = ptr -> left;
            else
            {
                treeNode *newNode = new treeNode;

                newNode -> data = key;
                ptr -> left = newNode;
                newNode -> left = newNode -> right = NULL;
                return root;
            }
        }
        else if (key > ptr -> data)
        {
            if (ptr -> right != NULL)
                ptr = ptr -> right;
            else
            {
                treeNode *newNode = new treeNode;

                newNode -> data = key;
                ptr -> right = newNode;
                newNode -> left = newNode -> right = NULL;
                return root;
            }
        }
    }
    return root;
}

//removal in binary search tree
int binarySearchTree :: remove(int key)
{
    //if the tree doesn't exist
    if (root == NULL)
        return -1;

    //tree has some nodes
    treeNode *current = root, *prev = NULL;
    int flag = 0;

    while (current != NULL)
    {
        if (current -> data == key)
        {
            flag = 1;
            break;
        }
        prev = current;
        if (key < current -> data)
            current = current -> left;
        else
            current = current -> right;
    }

    //if the key value doesn't exist in the tree
    if (!flag || current == NULL)
        return 0;

    //if the key value exist in the tree
    if(current -> data == key)
    {
        if(!current -> left && !current -> right)   //left and right child doesn't exist
        {
            if(current != root && prev)             //current node is not root and previous pointer is not null
            {
                if(prev -> left == current)
                    prev -> left = NULL;
                else
                    prev -> right = NULL;
            }
            else
                root = NULL;
        }
        else if (current -> left && current -> right)   //left and right child exist
        {
            treeNode *temp, *predc = NULL;

            temp = current -> left;

            while (temp -> right != NULL)
            {
                predc = temp;
                temp = temp -> right;
            }

            current -> data = temp -> data;             //set the current node's data to the inorderly traversed node's data
            
            //if the successor node is not the current node
            //it's something new in c++ that you can substitute '&&' with 'and'
            if (predc and predc != root and predc != current)
            {
                predc -> right = temp -> left;
                temp -> left = NULL;
                delete temp;
                return 1;
            }
            else
            {
                if (temp -> left)
                {
                    current -> left = temp -> left;
                    temp -> left = NULL;
                }
                else
                    current -> left = NULL;
                delete temp;
                return 1;
            }
        }
        else    //only a single child exist
        {
            if(current != root && prev)     //current node is not root node
            {
                if (prev -> left == current)
                {
                    if (current -> left)
                        prev -> left = current -> left;
                    else
                        prev -> left = current -> right;
                }
                else
                {
                    if (current -> left)
                        prev -> right = current -> left;
                    else
                        prev -> right = current -> right;
                }
            }
            else                            //current node is the root node
            {
                if (current -> left)
                    root = root -> left;
                else
                    root = root -> right;
            }
            current -> left = current -> right = NULL;
            if (prev)
                prev = NULL;

            delete current;
        }
        return 1;
    }
    return 1;
}
