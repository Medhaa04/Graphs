#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template<typename T>
class Graph{
    public:
    unordered_map<T,list<T>>adj;

    void addEdge(T u,T v,bool bidir=true){
        adj[u].push_back(v);
        if(bidir)  adj[v].push_back(u);
    }
    void print(){
        for(auto p:adj){
            cout<<p.first<<" : ";
            for(auto n:p.second){
                cout<<n<<",";
            }
            cout<<endl;
        }

    }
    
    void dfsHelper(T src,unordered_map<T,bool>&visited){
        visited[src]=true;
        cout<<src<<" ";
        for(auto ch:adj[src]){
            if(!visited[ch])  dfsHelper(ch,visited);
        }
        
    }
    void dfs(T src){
        unordered_map<T,bool>visited;
        dfsHelper(src,visited);
        // int component=1;
        // for(auto p:adj){
        //     if(!visited[p.first]){
        //         dfsHelper(p.first,visited);
        //         component++;
        //     }
        // }
        // cout<<"Components:"<<component<<endl;
    }
        
    


};

int main(){
    Graph<string> g;
    g.addEdge("A","B");
    g.addEdge("C","B");
    g.addEdge("C","E");
    g.addEdge("A","E");
    g.addEdge("D","E");
    g.addEdge("D","C");
    g.addEdge("D","F");
    
    // g.addEdge("X","Y");
    // g.addEdge("X","Z");
    // g.addEdge("T","Z");

    g.dfs("A");




}