#include <iostream>
#include<list>
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
};

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(3,2);
    g.printadjList();
    return 0;
}
s
