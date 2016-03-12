/*
 *
 * Funtion that calculates the minimum spanning tree using Prim's algorithm.
 *
 *
*/

//funtion to calculate the mimimum cost of adjacent edges of each vertex
//that are not included in the MST
int minimumEdgeCost(int *edgeCost, int n, short *mst)
{
    //set the minimum value to infinite(9999)
    int min = 9999, index, i;

    for (i = 0; i < n; i++)
    {
        if (mst[i] == 0 and edgeCost[i] < min)
        {
            min = edgeCost[i];
            index = i;
        }
    }
    return index;
}

int* prim(int** graph, int n)
{
    int *parent = (int *)malloc(sizeof(int) * n);
    
    //cost of edges between two vertex
    int *edgeCost = (int *)malloc(sizeof(int) * n);
    
    //the original MST
    short *mst = (short *)malloc(sizeof(short) * n);
    int i, flag = 0, j;
    
    // MST is to be stored in parent array ;
    //parent[i] stores the parent of vertex i;

    //cost of edge of first vertex is 0 
    edgeCost[0] = 0;
    
    //first vertex is the root vertex
    parent[0] = -1;
    
    //set the cost of every other edge of each vertex except the first vertex to infinite(9999)
    //and MST to 0, as no vertex is inserted currently
    for (i = 1; i < n; i++)
    {
        edgeCost[i] = 9999;
        mst[i] = 0;
    }

    for (i = 0; i < n - 1; i++)
    {
        //pick the minimum edge vertex that is not included in the original MST
        flag = minimumEdgeCost(edgeCost, n, mst);
        
        //set the MST value at position 'flag' to 1
        mst[flag] = 1;

        //set the cost of edge and parent index of adjacent vertex only
        //if the vertex is not in MST
        for (j = 0; j < n; j++)
        {
            if (graph[flag][j] and mst[j] == 0 and graph[flag][j] < edgeCost[j])
            {
                parent[j] = flag;
                edgeCost[j] = graph[flag][j];
            }
        }
    }

    //return the parent
    return parent;
}
