#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
//data structure combination of nodes and edges
//degree- edges connected yo node
//indegree(in directed)-edges coming in

class graph{
    public:
    unordered_map<int,list<int>>adj;

    void addEdge(int u,int v,bool bidirectional){
        adj[u].push_back(v);
        if(bidirectional==0){
            adj[v].push_back(u);
        }
    }

    void printAdj(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }


};
int main(){

    int n;
    cout<<"number of nodes:";
    cin>>n;

    int m;
    cout<<"Number of edges:";
    cin>>m;
    graph g;
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    g.printAdj();
    return 0;

}