#include <iostream>
using namespace std;

#define MAX 10  // Increase MAX for more nodes
int values[MAX];
bool visited[MAX];
int matrix[MAX][MAX];

// Function to add edges to the graph
void addEdges(int u, int v, int weight) {
    if (u < 0 || u >= MAX || v < 0 || v >= MAX) {
        return;
    }
    matrix[u][v] = weight; // Add edge u -> v
    matrix[v][u] = weight; // Add edge v -> u for undirected graph
}

// Function to initialize the visited array to false
void addFalse() {
    for (int i = 0; i < MAX; i++) {
        visited[i] = false;
    }
}

// Function to input values for the nodes
void addValues() {
    cout << "Provide node's value (10 values): ";
    for (int i = 0; i < MAX; i++) {
        cin >> values[i];
    }
}
int minDistance(int distance[], bool visited[]) {
    int MIN = 10000;
    int minIndex = -1;
    // ye function return krega the index of that node jiska distance is the lowest hai from the source node.
    for (int i = 0; i < MAX; i++) {
        if (!visited[i] && distance[i] < MIN) {
            MIN = distance[i];
            minIndex = i;
        }
    }
    return minIndex; 
}

// Function to implement Dijkstra's algorithm
void shortestPath(int source) {
    int distance[MAX];
    for (int i = 0; i < MAX; i++) {
        distance[i] = 10000;  
        visited[i] = false;  
    }
    // khud se distance 0 hi hoga.
    distance[source] = 0;
    for (int i = 0; i < MAX - 1; i++) {
        // mindistane wala function returns the index of smallest path index.
        int minDistanceIndex = minDistance(distance, visited);
        visited[minDistanceIndex] = true; // smallest distance wale ko hum visit kr chuke hai toh vahi set kr rhe hai.

        for (int j = 0; j < MAX; j++) {
            if (matrix[minDistanceIndex][j] && !visited[j] && distance[minDistanceIndex] != 10000) {
                if (distance[minDistanceIndex] + matrix[minDistanceIndex][j] < distance[j]) {
                    distance[j] = distance[minDistanceIndex] + matrix[minDistanceIndex][j];
                }
            }
        }
    }

    cout << "Vertex\tDistance from Source (" << values[source] << ")\n";
    for (int i = 0; i < MAX; i++) {
        if (distance[i] == 10000) {
            cout << values[i] << "\t\t" << "Infinity\n"; // If not reachable
        } else {
            cout << values[i] << "\t\t" << distance[i] << "\n"; // Distance
        }
    }
}

int main() {
    // Initialize the adjacency matrix
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            matrix[i][j] = 0;
        }
    }
    addFalse();
    addValues();
    // intiially, humare pass distance array jo hai usme [0, 10000, 10000,10000,...,10000] hai 
    // visited = [true, false, false,...., false]
    addEdges(0, 1, 2);  // 0 se connected hai toh distance will be updated from 10000 to 2
    addEdges(0, 2, 3); // 0 se connecteed hai toh distance will be updated from 10000 to 3
    // minimum distance would be 2 out of 2 and 3
    addEdges(1, 2, 1); 
    addEdges(1, 3, 4); 
    addEdges(2, 3, 2); 
    addEdges(3, 4, 3); 
    addEdges(4, 5, 1); 
    addEdges(5, 6, 5); 
    addEdges(6, 7, 2); 
    addEdges(7, 8, 1); 
    addEdges(8, 9, 3); 

    // Display the adjacency matrix
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    int source;
    cout << "Enter source node index (0 to " << MAX - 1 << "): ";
    cin >> source;
    shortestPath(source);

    return 0;
}