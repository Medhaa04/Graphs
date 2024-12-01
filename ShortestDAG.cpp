#include<bits/stdc++.h>
using namespace std;
class Graph{
    void topoSort(int node,vector<pair<int,int>>adj[],int vis[],stack<int>&st){
        vis[node]=1;
        for(auto it:adj[node]){
            int v=it.first;
            if(!vis[v]){
                topoSort(v,adj,vis,st);
            }
        }
        st.push(node);

    }
    public:
    vector<int>shortestDist(int n,int m,vector<int>edges[]){
        vector<pair<int,int>>adj[n];
        //create adj
        for(int i=0;i<m;++i){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        //find topo sort
        int vis[n]={0};
        stack<int>st;
        for(int i=0;i<n;++i){
            if(!vis[i]){
                topoSort(i,adj,vis,st);
            }
        }

        //calc dist
        vector<int>dist;
        for(int i=0;i<n;++i) dist[i]=INT_MAX;
        dist[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto it:adj[node]){
                int v=it.first;  //list
                int wt=it.second;
                if(dist[v]>dist[node]+wt){        //int max (or if already value calc)>wt of edge+node dist
                    dist[v]=dist[node]+wt;
                }
            }
        }      
        for (int i = 0; i < n; ++i) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }  
        return dist;

    }

};