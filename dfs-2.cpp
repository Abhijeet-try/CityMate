#include <bits/stdc++.h>
using namespace std;
 
#define V 5
 
int minKey(int key[], bool Set[])
{
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (Set[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}
 
void printT(int out[], int graph[V][V])
{
    cout<<"Path\n";
    for (int i = 1; i < V; i++)
        cout<<out[i]<<" - ";
}
 
void primsT(int graph[V][V])
{
    int out[V];
     
    int key[V];
    bool Set[V];
 
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, Set[i] = false;
    key[0] = 0;
    out[0] = -1; 
 
    for (int count = 0; count < V - 1; count++)
    {
        
        int u = minKey(key, Set);
 
        Set[u] = true;
 
        for (int v = 0; v < V; v++)
 
            if (graph[u][v] && Set[v] == false && graph[u][v] < key[v])
                out[v] = u, key[v] = graph[u][v];
    }
   printT(out, graph);
}
 
int main()
{
 
    int graph[V][V] = { { 0, 5, 7, 6, 0 },
                        { 5, 0, 3, 8, 5 },
                        { 7, 3, 0, 2, 7 },
                        { 6, 8, 2, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    primsT(graph);
 
    return 0;
}