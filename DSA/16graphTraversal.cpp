#include "16stack&queueForGraphTraversal.h"

int adjacencyMatrix[20][20];
int numberOfVertices = 0;

void addEdge(int source, int destination)
{
    if (source >= numberOfVertices || destination >= numberOfVertices || source < 0 || destination < 0)
    {
        cout << "\n\t[Invalid vertices!]" << endl;
        return;
    }
    adjacencyMatrix[source][destination] = 1;
    adjacencyMatrix[destination][source] = 1;
}

void BFS(int startVertex)
{
    if (startVertex >= numberOfVertices || startVertex < 0)
    {
        cout << "\n\t[Invalid starting vertex!]" << endl;
        return;
    }

    bool visited[20] = {false};
    enqueue(startVertex);
    visited[startVertex] = true;
    cout << "\n\t[BFS Traversal: ";

    while (!isqueueEmpty())
    {
        int vertex = dequeue();
        cout << vertex << " ";

        for (int i = 0; i < numberOfVertices; i++)
        {
            if (adjacencyMatrix[vertex][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = true;
            }
        }
    }
    cout << "]" << endl;
}

void DFS(int startVertex)
{
    if (startVertex >= numberOfVertices || startVertex < 0)
    {
        cout << "\n\t[Invalid starting vertex!]" << endl;
        return;
    }

    bool visited[20] = {false};
    push(startVertex);
    visited[startVertex] = true;
    cout << "\n\t[DFS Traversal: ";

    while (!isstackEmpty())
    {
        int vertex = pop();
        cout << vertex << " ";

        for (int i = 0; i < numberOfVertices; i++)
        {
            if (adjacencyMatrix[vertex][i] == 1 && !visited[i])
            {
                push(i);
                visited[i] = true;
            }
        }
    }
    cout << "]" << endl;
}

int main()
{
    int choice, source, destination, startVertex;
    bool askForMore = true;
    int response = -1;

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }

    do
    {
        askForMore = true;
        response = -1;
        cout << "\nMenu:\n";
        cout << "0. Exit\n";
        cout << "1. Add Vertex\n";
        cout << "2. Add Edge\n";
        cout << "3. BFS (Breadth-First Search)\n";
        cout << "4. DFS (Depth-First Search)\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Exiting the program." << endl;
            break;

        case 1:
            if (numberOfVertices < 20)
            {
                cout << "\n\t[Adding a new vertex. Vertex ID: " << numberOfVertices << "]" << endl;
                numberOfVertices++;
            }
            else
            {
                cout << "\n\t[Maximum vertices reached!]" << endl;
            }
            break;

        case 2:
            if (numberOfVertices == 0)
            {
                cout << "\n\t[No vertices to add an edge to!]" << endl;
                break;
            }
            while (askForMore)
            {
                cout << "Enter source and destinationination vertices for the edge: ";
                cin >> source >> destination;
                addEdge(source, destination);
                cout << "\nWant to add more edges? [Yes = 1 / No = 0]: ";
                cin >> response;
                if (response == 0)
                    askForMore = false;
            }
            break;

        case 3:
            cout << "Enter starting vertex for BFS: ";
            cin >> startVertex;
            BFS(startVertex);
            break;

        case 4:
            cout << "Enter starting vertex for DFS: ";
            cin >> startVertex;
            DFS(startVertex);
            break;

        default:
            cout << "\n\t[Invalid choice! Please try again.]" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
