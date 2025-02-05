#include <iostream>

#define MAX_EDGES 100
#define MAX_VERTICES 100

using namespace std;

struct Edge
{
    int u, v, weight;
};

int parent[MAX_VERTICES];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSets(int u, int v)
{
    int root_u = find(u);
    int root_v = find(v);
    parent[root_u] = root_v;
}

void kruskal(Edge edges[], int V, int E)
{
    //simple bubble sort for sorting
    for (int i = 0; i < E - 1; i++)
    {
        for (int j = 0; j < E - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    int mstWeight = 0;

    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (int i = 0; i < E; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        // check cycle
        if (find(u) != find(v))
        {
            cout << u << " - " << v << " : " << weight << endl;
            mstWeight += weight;
            unionSets(u, v);
        }
    }

    cout << "Total weight of MST: " << mstWeight << endl;
}

int main()
{
    int V, E;
    Edge edges[MAX_EDGES];

    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    cout << "Enter each edge as (source, destination, weight):" << endl;
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    kruskal(edges, V, E);

    return 0;
}
