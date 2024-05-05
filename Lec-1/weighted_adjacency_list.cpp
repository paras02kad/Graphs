#include <iostream>
#include <vector>
#include <list>

using namespace std;

/*
! The following code is the implementation of weighted graphs(directed as well as bi-directed)
* It works on adjacency list implementation.
*/

vector<list<pair<int,int>>> graph;

int v; //! Shows no of vertices

void add_edge(int src, int dest, int wt, bool bi_dir = true)
{
    graph[src].push_back({dest, wt});
    if (bi_dir)
        graph[dest].push_back({src, wt});
}

void display()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";
        for (auto el : graph[i])
        {
            cout << "(" << el.first << "  " << el.second << ")"
                 << " , ";
        }
        cout << endl;
    }
}
int main()
{
    cout << "Enter no of vertices" << endl;
    cin >> v;
    graph.resize(v, list<pair<int, int>>()); //! ---> Here we have made some changes
    int e;
    cout << "Enter no of edges" << endl;
    cin >> e;
    while (e--)
    {
        int s, d, wt; //! ---> Here we have made some changes
        cout << "enter source,destination value and weight" << endl;
        cin >> s >> d >> wt;
        add_edge(s, d, wt, false);
    }
    display();
    return 0;
}