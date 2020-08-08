#include <iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *adjList;
    public:
    Graph(int v){
        V=v;
        adjList = new list<int>[V];
    }
    
    void addEdge(int u, int v, bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    
    void dfs(int v,bool visited[])
    {
        visited[v]=true;
        cout<<v<<"->";
        
        for(auto itr=adjList[v].begin();itr!=adjList[v].end();itr++)
        {
            if(!visited[*itr])
                dfs(*itr,visited);
        }
        
    }
    
    void DFS(int src)
    {
        bool *visited = new bool[V]{0};
        dfs(src,visited);
    }
};



int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.DFS(0);

    return 0;
}

