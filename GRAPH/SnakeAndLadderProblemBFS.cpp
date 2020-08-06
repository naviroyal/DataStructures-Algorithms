#include <iostream>
#include<queue>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *adjList ;
    public:
    
    Graph(int v){
        V=v;
        adjList=new list<int>[V];
    }
    
    void addEdge(int u,int v,bool bidir)
    {
        adjList[u].push_back(v);
        if(bidir)
            adjList[v].push_back(u);
    }
    
    void bfs(int src,int des)
    {
        queue<int>q;
        bool *visited = new bool[V+1]{0};
        int *parent = new int[V+1]{-1};
        int *distance = new int[V+1]{0};
        q.push(src);
        visited[src]=true;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto neighbour:adjList[node])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour]=true;
                    parent[neighbour]=node;
                    distance[neighbour]=node+1;
                }
            }
        }
        
        cout<<"Shortest Distance is "<<distance[des]<<endl;
        int temp=des;
        while(temp!=-1)
        {
            cout<<temp<<"<--";
            temp=parent[temp];
        }
    }
};


int main()
{
    int board[50]={0};
    Graph g(50);
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=-10;
    board[32]=-2;
    board[34]=-22;
    
    for(int u=0;u<36;u++)
    {
        for(int dice=1;dice<=6;dice++)
        {
            int v=u+dice+board[u+dice];
            g.addEdge(u,v,false);
        }
    }
    g.bfs(0,36);

    return 0;
}

