#include<bits/stdc++.h>
using namespace std;
class Solution{
    private:
    bool check(int start,int v,vector<int>adj[],int color[]){
        queue<int>q;
        q.push(start);
        color[start]=0;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto ngh:adj[node]){
                if(color[ngh]==-1){
                    color[ngh]=!color[node];                   //coloring the node if not visited earlier and push in queue
                    q.push(ngh);

                }
                else if(color[ngh]==color[node]){                      //if adj nodes have same color then return false
                    return false;
                }
            }
        }
        return true;


    }
    public:
    bool isbiPartite(int v,vector<int>adj[]){
        int color[v];
        for(int i=0;i<v;++i) color[i]=-1;  //all cmpt get colored -1
        for(int i=0;i<v;++i){
            if(color[i]==-1){
                if(check(i,v,adj,color)==false) return false;

            }
        }
        return true;
    }


};