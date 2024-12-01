#include<bits/stdc++.h>
using namespace std;
class Graph{
    vector<int> topoSort(int v,vector<int>adj[]){
        
		//calc indegree
		int indegree[]={0};
		for(int i=0;i<v;++i){
			for(auto it:adj[i]){
				indegree[it]++;
			}
		}
		//make a queue and push the one with 0 indegree
		queue<int>q;
		for(int i=0;i<v;++i){
			if(indegree[i]==0) q.push(i);
		}
		//make answer vector and start traversing queue bfs
		vector<int>topo;
		while(!q.empty()){
			int node=q.front();
			q.pop();
			for(auto it:adj[node]){                  //reduce indegree by one and push if indegree becomes zero
				indegree[it]--;
				if(indegree[it]==0) q.push(it);
			}
		}
		return topo;
	


    }
    public:
    string findOrder(string dict[],int n,int k){
        vector<int>adj[k];
        for(int i=0;i<n-1;++i){
            string s1=dict[i];
            string s2=dict[i+1];
            int len=min(s1.length(),s2.length());
            for(int p=0;p<len;++p){
                if(s1[p]!=s2[p]){
                    adj[s1[p]-'a'].push_back(s2[p]-'a');    //s1[p] and s2[p] are char so subtract a to save as nodes
                    break;
                }
                

            }
        }
        vector<int>topo=topoSort(k,adj);
        string ans="";
        for(auto it:topo){
            ans=ans+char(it+'a');
        }
        return ans;

    }

};