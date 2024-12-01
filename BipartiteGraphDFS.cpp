#include<bits/stdc++.h>
using namespace std;
class Solution{
    bool dfs(int start,int col,int color[],vector<int>adj[]){
        color[start]=col;
        // color[start]=0;
        for(auto it:adj[start]){
            if(color[it]==-1){
                dfs(it,!col,color,adj);
            }
            else if(color[it]==col) return false;
        }
        return true;

    }
    public:
    bool isBiPartite(int v,vector<int>adj[]){
        int color[v];
        for(int i=0;i<v;++i) color[i]=-1;

        for(int i=0;i<v;++i){
            if(color[i]==-1){
                if(dfs(i,0,color,adj)==false) return false;
            }
        }
        return true;
        
    }
};