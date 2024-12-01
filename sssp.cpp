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
    void SSSP(T src,T des){
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
        cout<<"Distance from "<<src<<"to "<<des<<" : "<<dist[des]<<endl;
        while(des !=src){
            cout<<des<<"<--";
            des=parent[des];
        }
        cout<<des<<endl;
    }
};
