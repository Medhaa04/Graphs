#include<iostream>
#include<list>
#include<vector>
#include<bits/stdc++.h>
#include<queue>
#include<unordered_map>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int>>adj;

    void addEdge(int u,int v,bool bidirectional){
        adj[u].push_back(v);
        if(bidirectional==0){
            adj[v].push_back(u);
        }
    }

    


};
vector<int> shortest(vector<pair<int,int>>edges,int n,int m,int src,int des){
    //s-1 adj list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<m;++i){
        int u=edges[i].first;
        int v=edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    //bfs
    unordered_map<int,bool>visited;
    unordered_map<int,int>parent;
    visited[src]=true;
    parent[src]=-1;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto ch:adj[front]){
            if(!visited[ch]){
                visited[ch]=true;
                parent[ch]=front;
                q.push(ch);
            }
        }
    }

    vector<int>ans;
    int currNode=des;
    ans.push_back(des);
    while(currNode != des){
        currNode=parent[currNode];
        ans.push_back(currNode);

    }
    reverse(ans.begin(),ans.end());
    return ans;
    
    
}