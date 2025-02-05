#include <iostream>
#define INF 99999

using namespace std;

void dijkstra(int graph[100][100], int V, int source)
{
    int dist[100];
    bool visited[100];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[source] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int minDist = INF, u = -1;
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && dist[v] < minDist)
            {
                minDist = dist[v];
                u = v;
            }
        }

        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main()
{
    int V, E;
    int graph[100][100] = {0};

    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    cout << "Enter each edge as (source, destination, weight):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    dijkstra(graph, V, source);

    return 0;
}
