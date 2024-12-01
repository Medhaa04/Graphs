#include<bits/stdc++.h>
using namespace std;
class solution{
    void dfs(vector<vector<int>>&image,int row,int col,int color,vector<vector<int>>ans,int initialColor,int delrow[],int delcol[]){
        image[row][col]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;++i){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and image[nrow][col]==initialColor and ans[nrow][ncol]!=color){
                dfs(image,nrow,ncol,color,ans,initialColor,delrow,delcol);

            }
        }

    }
    public:
    vector<vector<int>>floodFill(vector<vector<int>>image,int sr,int sc,int color){
        int initialColor=image[sr][sc];
        vector<vector<int>>ans=image;
        int delrow[]={};
        int delcol[]={};
        dfs(image,sr,sc,color,ans,initialColor,delrow,delcol);
        return ans;
        

    }

};