#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    vector<int> shortestPath(int v,vector<vector<int>>edges,int n, int m,int src){
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        //queue not pair as wt is in distance
        queue<int>q;
        int dist[n];
        for(int i=0;i<n;++i) dist[i]=INT_MAX;
        dist[src]=0;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(dist[node]+1<dist[it]){
                    dist[it]=dist[node]+1;
                    q.push(it);
                }
            }
        }
        vector<int>ans(n,-1);
        for(int i=0;i<m;++i){
            if(dist[i]!=INT_MAX){  //approachable node
                ans[i]=dist[i];
            }
        }
        return ans;



    }

};