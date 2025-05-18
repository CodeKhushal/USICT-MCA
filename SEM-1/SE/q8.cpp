#include <iostream>
#include <fstream>
using namespace std;

void analyzeCode(string &code, int &nodes, int &edges, int &components) {
    nodes = 1;
    edges = 0;
    components = 1;
    int pos = 0; 
    string keywords[] = {"if", "for", "while", "case", "&&", "||"};
    
    for (string &keyword : keywords) {
        pos = code.find(keyword);
        while (pos != string::npos) {
            nodes++;
            if (keyword == "if" || keyword == "case" || keyword == "for" || keyword == "while") {
                edges += 2; 
            } else if (keyword == "&&" || keyword == "||") {
                edges += 1; 
            }
            pos = code.find(keyword, pos + 1);
        }
    }
    edges += nodes - 1;
}

int calculateCyclomaticComplexityFormula(int nodes, int edges, int components) {
    return edges - nodes + 2 * components;
}

int main() {
    string filename;
    cout << "Enter the path of the file: ";
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string code, line;
    while (getline(file, line)) {
        code += line + "\n";
    }
    file.close();

    int nodes, edges, components;
    analyzeCode(code, nodes, edges, components);
    int cyclomaticComplexityFormula = calculateCyclomaticComplexityFormula(nodes, edges, components);

    cout << "Nodes (N): " << nodes << endl;
    cout << "Edges (E): " << edges << endl;
    cout << "Connected Components (P): " << components << endl;
    cout << "Cyclomatic Complexity (Formula M = E - N + 2P): " << cyclomaticComplexityFormula << endl;

    return 0;
}
