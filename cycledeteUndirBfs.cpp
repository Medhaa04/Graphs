#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

bool isCyclic(int src,unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited){
    unordered_map<int,int>parent;
    parent[src]=-1;
    visited[src]=1;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int front=q.front();
        q.pop();

        for(auto neighbour:adj[front]){
            if(visited[neighbour]==true && neighbour!=parent[front]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=1;
                parent[neighbour]=front;

            }
        }
    }
    return false;
}

bool detect(int src,int vis[],vector<int>adj[]){
    vis[src]=1;
    queue<pair<int,int>>q; //node and parent
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto ngh:adj[node]){
            if(!vis[ngh]){         //not visited yet
                vis[ngh]=1;
                q.push({ngh,node});

            }
            else if(parent!=ngh){         //visited but again being visited and not by parent rather by adj node 
                return true;
            }

        }
    }
    return false;


}
string cycleDetection(vector<vector<int>>& edges,int n,int m){
    //create adjacency list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<m;++i){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //to handle disconnected components
    unordered_map<int,bool>visited;
    for(int i=0;i<n;++i){
        if(!visited[i]){
            bool ans=isCyclic(i,adj,visited);
            if(ans==1){
                return "Yes";
            }
        }
        return "No";
    }
}


//tc=n+2e
//n
int main(){

}

