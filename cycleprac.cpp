#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

bool IsCyclicDFS(int node,int parent,unordered_map<int,list<int>>&adj,unordered_map<int,bool>visited){
    visited[node]=true;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            bool isdetected=IsCyclicDFS(neighbour,node,adj,visited);
            if(isdetected){
                return true;
            }
            else if(neighbour!=parent){
                return true;
            }
        }
    }
    return false;
}


  
string cyclicgraph(vector<vector<int>>& edges,int n,int m){
    //adj
    unordered_map<int,list<int>>adj;
    for(int i=0;i<m;++i){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //disconnected
    unordered_map<int,bool>visited;
    for(int i=0;i<n;++i){
        if(!visited[i]){
            bool ans=IsCyclicDFS(i,-1,adj,visited);
            if(ans==1){
                return "Yes";
            }
        }
    }
    
}