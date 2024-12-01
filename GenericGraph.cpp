#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
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
    void BFS(T src,T des){
        unordered_map<T,bool>visited;
        unordered_map<T,T>parent;
        unordered_map<T,int>dist;

        queue<T>q;
        q.push(src);
        visited[src]=true;
        parent[src]=true;
        dist[src]=0;
        while(!q.empty()){
            T f=q.front();
            q.pop();
            cout<<f<<" ";
            for(auto ch:adj[f]){
                if(!visited[ch]){
                    visited[ch]=true;
                    dist[ch]=dist[f]+1;
                    parent[ch]=f;
                    q.push(ch);
                }
            }

        }
        cout<<"Distance from "
    }
    void dfsHelper(T src,unordered_map<T,bool>&visited){
        visited[src]=true;
        cout<<src<<" ";
        for(autovch:adj[src]){
            if(!visited[ch])  dfsHelper(ch,visited);
        }
    }
    void dfs(T src){
        unordered_map<T,bool>visited;
        dfsHelper(src,visited);
    }

};

int main(){
    Graph<string> g;
    g.addEdge("Putin","Trump",false);
    g.addEdge("Putin","Modi",false);
    g.addEdge("Trump","Modi",true);
    g.addEdge("Yogi","Modi",true);
    g.addEdge("Yogi","Prabhu",false);
    g.addEdge("Prabhu","Modi",false);
    g.addEdge("Putin","Pope",false);
    g.print();

    Graph<string>g;
    g.addEdge("A","B");
    g.addEdge("C","B");
    g.addEdge("A","B");
    g.addEdge("A","B");
    g.addEdge("A","B");
    g.addEdge("A","B");




}