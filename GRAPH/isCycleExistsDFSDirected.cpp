#include <iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class Graph{
    int V;
    list<int> *adjList;
    public:
    Graph(int v){
        V=v;
        adjList = new list<int>[V];
    }
    
    void addEdge(int u, int v, bool bidir=false)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    
    bool iscycle(int v,bool visited[],bool *recStack)
    {
        if(!visited[v])
        {
            visited[v]=true;
            recStack[v]=true;
            for(auto neighbour:adjList[v])
            {
                if(!visited[neighbour] && iscycle(neighbour,visited,recStack))
                return true;
                else if(recStack[neighbour])
                return true;
            }
        }
        recStack[v]=false;
        return false;
    }
    
    bool isCyclic()
    {
        bool *visited = new bool[V]{0};
        bool *recStack = new bool[V]{0};
        
        for(int i=0;i<V;i++)
        {
            if(iscycle(i,visited,recStack))
                return true;
            else 
                return false;
        }
    }
    
};



int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    // g.addEdge(2,4);
    // g.addEdge(3,4);
    g.addEdge(4,3);
    g.addEdge(3,5);
    if(g.isCyclic()){
        cout<<"Cycle exits";
    }
    else
        cout<<"Cycle not  Exists";

    return 0;
}

