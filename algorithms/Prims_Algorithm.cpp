#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
typedef pair<int, int> iPair;

#define V 5
#define E 5

int min(int key[], bool mstSet[])
{
    int min = INT_MAX;
    int min_index;
    for (int k = 0; k < V; k++)
    {
        if (mstSet[k] == false && key[k] < min)
        {
            min = key[k];
            min_index = k;
        }
    }

    return min_index;
}

void prnt(int parent[], int Graph[V][V])
{
    cout << "Edge \t Weight \n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << " \t " << Graph[i][parent[i]] << "\n";
    }
}

void PrimMsT(int Graph[V][V])
{
    int parent[V];
    int k[V];
    bool set[V];
    for (int i = 0; i < V; i++)
    {
        k[i] = INT_MAX;
        set[i] = false;
    }

    k[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < V - 1; i++)
    {
        int u = min(k, set);

        set[i] = true;
        for (int j = 0; j < V; j++)
        {
            if (Graph[u][j] && set[j] == false && Graph[u][j] < k[j])
            {
                parent[j] = u;
                k[i] = Graph[u][j];
            }
        }
    }

    prnt(parent, Graph);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //cout<<"Number of Vertices = ";
    //cin >> V;
    //cout<<"Number of Edges = ";
    //cin >> E;
    int Graph[V][V];
    //cout<<"Enter The Graph Matrix = ";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> Graph[i][j];
        }
    }
    PrimMsT(Graph);
}