#include <iostream>
#include <vector>
#include <list>

using namespace std;

/*
! The following code is the implementation of graphs(directed as well as bi-directed)
* It works on adjacency list implementation.
*/

vector<list<int>> graph;

int v; //! Shows no of vertices

void add_edge(int src, int dest, bool bi_dir = true)
{
    graph[src].push_back(dest);
    if (bi_dir)
        graph[dest].push_back(src);
}

void display()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";
        for (auto el : graph[i])
        {
            cout << el << " , ";
        }
        cout << endl;
    }
}
int main()
{
    cout << "Enter no of vertices" << endl;
    cin >> v;
    graph.resize(v, list<int>());
    int e;
    cout << "Enter no of edges" << endl;
    cin >> e;
    while (e--)
    {
        int s, d;
        cout<<"enter source and destination value"<< endl;
        cin >> s >> d;
        add_edge(s, d,false);
    }
    display();
    return 0;
}