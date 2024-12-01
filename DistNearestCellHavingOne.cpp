#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>nearestOne(vector<vector<int>>grid){
    int n=grid.size();
    int m=grid[0].size();

    vector<vector<int>>dist(n,(vector<int>(m,0)));
    vector<vector<int>>visited(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j]==1){
                q.push({{i,j},0});
                visited[i][j]=1;
            }
            else{
                visited[i][j]=0;
            }
        }
    }
    int delrow[]={};
    int delcol[]={};
    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int step=q.front().second;
        q.pop();
        dist[r][c]=step;
        for(int i=0;i<4;++i){
            int nrow=r+delrow[i];
            int ncol=c+delcol[i];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and visited[nrow][ncol]==0){
                visited[nrow][ncol]=1;
                q.push({{nrow,ncol},step+1});
            }
        }
    }
    return dist;


}