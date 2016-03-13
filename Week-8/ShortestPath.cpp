/*
 *
 * Function to determine the shortest path using Dijsktra's Algorithm
 *
*/

#define UNREACHABLE 1000

//get the minimum value index of adjacent vertex
int minimumDistance(int *dist, int *spt, int n)
{
    int min = UNREACHABLE, index, i;

    for (i = 0; i < n; i++)
    {
        if (spt[i] == 0 and dist[i] <= min)
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

int *shortestDist(int **graph, int src, int n)
{
    //to keep the track of the shortest distance and the path to travel for SPT
    int *shortDist = new int[n], *spt = new int[n];
    int i, flag = 0, j;

    //set all the distance to INFINITE and SPT to 0
    for (i = 0; i < n; i++)
    {
        shortDist[i] = UNREACHABLE;
        spt[i] = 0;
    }

    //distance of source vertex to itself is 0
    shortDist[src] = 0;

    for (i = 0; i < n - 1; i++)
    {
        //take the minimum distance vertex from the set of vertex which are not included in SPT
        flag = minimumDistance(shortDist, spt, n);

        //marke the picked vertex
        spt[flag] = 1;
        
        //update the values of adjacent vertex
        for (j = 0; j < n; j++)
        {
            //update shortest distance only if it is not in SPT and total weight of path from
            //src to j through flag is smaller than the current value of shortDist[j]
            if (!spt[j] and graph[flag][j] and shortDist[flag] != UNREACHABLE and shortDist[flag] + graph[flag][j] < shortDist[j])
                shortDist[j] = shortDist[flag] + graph[flag][j];
        }
    }

    delete spt;
    return shortDist;
}
