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
    
    void addEdge(int u, int v, bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    
    bool isCyclic()
    {
        vector<int> degree(V,0);
        for(int u=0;u<V;u++)
        {
            for(auto neighbour:adjList[u])
                degree[neighbour]++;
        }
        
        vector<int>result;
        int cnt=0;
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(degree[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            result.push_back(node);
            for(auto neighbour:adjList[node])
            {
                if(--degree[neighbour]==0)
                    q.push(neighbour);
            }
            cnt++;
        }
        if(cnt!=V)
            return true;
        else
            return false;
        
    }
    
};



int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    // g.addEdge(2,4);
    // g.addEdge(3,4);
    g.addEdge(2,3);
    g.addEdge(3,5);
    if(g.isCyclic()){
        cout<<"Cycle exits";
    }
    else
        cout<<"Cycle not  Exists";

    return 0;
}

