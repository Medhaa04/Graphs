#include<bits/stdc++.h>
using namespace std;
class Graph{
    void dfs(int node,int V,vector<int>adj[],int vis[],stack<int>&s){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,V,adj,vis,s);
        }
        s.push(node);

    }
    public:
    vector<int>topoSort(int V,vector<int>adj[]){
        int vis[V]={0};
        stack<int>s;
        for(int i=0;i<V;++i){
            if(!vis[i]){
                dfs(i,V,adj,vis,s);
            }
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};