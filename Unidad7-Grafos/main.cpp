
#include <bits/stdc++.h>
using namespace std;
 

void addEdge(vector <pair<int, int> > adj[], int u,
                                     int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}
 

void printGraph(vector<pair<int,int> > adj[], int V)
{
    int v, w;
    for (int i = 0; i < V; i++)
    {
        cout << "Node " << (char)i << " makes an edge with \n";
        for (auto it = adj[i].begin(); it!=adj[i].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\tNode " << (char)v << " with edge weight ="
                 << w << "\n";
        }
        cout << "\n";
    }
}
 
int main()
{
    int A{65}, B{66}, C{67}, D{68}, E{69}, F{70}, G{71}, H{72};
    
    int V = 7;
    vector<pair<int, int> > adj[V];
    
    addEdge(adj, A, H, 10);
    addEdge(adj, A, B, 3);
    addEdge(adj, A, C, 5);
    addEdge(adj, A, D, 2);

    addEdge(adj, B, A, 3);
    addEdge(adj, B, C, 5);
    addEdge(adj, B, E, 4);
    addEdge(adj, B, G, 6);
    addEdge(adj, B, D, 8);
    addEdge(adj, B, H, 6);

    addEdge(adj, C, F, 7);
    addEdge(adj, C, E, 1);


    addEdge(adj, D, H, 6);
    addEdge(adj, D, E, 12);

    addEdge(adj, E, G, 15);

    addEdge(adj, F, H, 9);

    addEdge(adj, G, H, 3);



    printGraph(adj, V);
    return 0;
    


}