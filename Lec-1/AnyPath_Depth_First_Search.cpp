#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

using namespace std;

/*
! The following code is the implementation of graphs(directed as well as bi-directed)
* It works on adjacency list implementation.
*/

vector<list<int>> graph;
unordered_set<int> visited;

int v; //! Shows no of vertices

void add_edge(int src, int dest, bool bi_dir = true)
{
    graph[src].push_back(dest);
    if (bi_dir)
        graph[dest].push_back(src);
}

bool dfs(int curr, int end)
{
    if (curr == end)
        return true;      //! ---> our base case.
    visited.insert(curr); //* --> that is current node is mark visited
    for (auto neighbour : graph[curr])
    {
        //! --> that is if we found out that current vertex has some unvisited vertices.So we apply Dfs on those unvisited vertex.
        if (visited.count(neighbour) == 0) //! ---> visited.count(neighbour) shows has neighbour is present in set;
        {
            bool result = dfs(neighbour, end);
            if (result)
                return true;
        }
    }
    //! If even after Going through all the vertices we didn't find a path than return false.
    return false;
}

bool anyPath(int start, int dest)
{
    return dfs(start, dest);
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
    visited.clear();

    while (e--)
    {
        int s, d;
        cout << "enter Start and end vertex" << endl;
        cin >> s >> d;
        add_edge(s, d, false);
    }
    display();
    int x, y;
    cout<<"Enter Source vertex and destination vertex"<<endl;
    cin >> x >> y;
    cout << anyPath(x, y) << endl;
    return 0;
}