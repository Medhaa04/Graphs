#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    bool isCyclic(int v,vector<int>adj[]){
        //code for getting the toposort
        //get indegree
        int indegree[v]={0};
        for(int i=0;i<v;++i){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        //get element in q
        queue<int>q;
        for(int i=0;i<v;++i){
            if(indegree[i]==0) q.push(i);
        }

        //topo sort
        vector<int>topo;
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);

        }
        if(topo.size()<=v) return true;       //if size of sort is less than the size of graph then it is cyclic
        return false;

    }

};