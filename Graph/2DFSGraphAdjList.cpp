/**
 *  author:- piyushkumar96
 *  description:- DFS traversal of Graph
**/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int u, int v);
    void DFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::DFS(int s)
{
    bool visited[V] = {false};

    stack<int> st;
    visited[s] = true;
    st.push(s);

    while (!st.empty())
    {

        int s = st.top();
        cout << s << " ";
        st.pop();

        for (auto i = adj[s].begin(); i != adj[s].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                st.push(*i);
            }
        }
    }
}

int main()
{

    Graph g(5);

    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(1, 4); 

    cout << "Following is DFS (starting from vertex 0) \n";
    g.DFS(0);

    return 0;
}