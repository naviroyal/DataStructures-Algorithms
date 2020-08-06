#include <iostream>
#include<list>
#include<queue>
using namespace std;


class Graph{
    int V;
    list<int>*adjList;
    public:
    Graph(int v){
        V=v;
        adjList= new list<int>[V];
    }
    void addEdge(int u,int v ,bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
            adjList[v].push_back(u);
    }
    void printadjList(){
        for(int i=0;i<V;i++)
        {
            cout<<i<<"->";
            for(auto node:adjList[i])
            {
                cout<<node<<" ,";
            }
            cout<<endl;
        }
    }
    
    void bfs(int src)
    {
        queue<int>q;
        bool *visited=new bool[V+1]{0};
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            int node=q.front();
            cout<<node<<" ";
            q.pop();
            for(auto neighbour:adjList[node])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour]=true;
                }
            }
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,4);
    g.addEdge(2,4);
    g.addEdge(3,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    // g.printadjList();
    g.bfs(0);
    return 0;
}
