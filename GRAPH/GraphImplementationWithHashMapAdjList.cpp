#include <iostream>
#include<list>
#include<unordered_map>
#include<cstring>
using namespace std;

// template<typename T>
class Graph{
    unordered_map<string,list<string>>adjList;
    public:
    Graph(){
        
    }
    void addEdge(string u,string v,bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
            adjList[v].push_back(u);
    }
    void printadjList()
    {
        for(auto row:adjList)
        {
            cout<<row.first<<" -> ";
            for(auto element:row.second)
            {
                cout<<element<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge("Amritsar","Delhi");
    g.addEdge("Amritsar","Jaipur");
    g.addEdge("Amritsar","Banglore");
    g.addEdge("Jaipur","Banglore");
    g.addEdge("Delhi","Agra");
    g.printadjList();
    return 0;
}

