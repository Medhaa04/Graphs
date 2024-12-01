#include<iostream>
#include<set>
#include<vector>
#include<list>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
template<typename T>
/*
class Graph {
public:
	unordered_map<T, list<pair<T, int> > > adj;

	void addEdge(T u, T v, int d, bool bidir = true) {
		adj[u].push_back({v, d});
		if (bidir) adj[v].push_back({u, d});
	}

	void print() {
		for (auto p : adj) {
			cout << p.first << "-->";
			for (auto ch : p.second) {
				cout << "(" << ch.first << "," << ch.second << ") ";
			}
			cout << endl;
		}
	}

	void dijkstra(T src, T des) {
		set<pair<int, T> > s;
		s.insert({0, src});
		unordered_map<T, T> parent;
		unordered_map<T, int> distance;
		parent[src] = src;
		for (auto n : adj) {
			distance[n.first] = INT_MAX;
		}

		distance[src] = 0;

		while (!s.empty()) {
			auto f = *s.begin();
			T baap = f.second;
			int baap_dist = f.first;
			s.erase(s.begin());
			for (auto n : adj[baap]) {
				T ngh = n.first;
				int road_dist = n.second;

				if (distance[ngh] > baap_dist + road_dist) {
					auto x = s.find({distance[ngh], ngh});
					if (x != s.end()) s.erase(x);
					parent[ngh] = baap;
					distance[ngh] = baap_dist + road_dist;
					s.insert({distance[ngh], ngh});
				}
			}
		}


		for (auto p : distance) {
			cout << "Distance of " << p.first << " from " << src << " : "
			     << p.second << endl;
		}

		while (des != parent[des]) {
			cout << des << "<--";
			des = parent[des];
		}
		cout << des << endl;
	}

};
*/

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
   
    //prepare adj list
  unordered_map<int,list<pair<int,int>>> adj;
  for(int i=0; i<edges; i++){
    int u=vec[i][0];
    int v=vec[i][1];
    int w=vec[i][2];
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
  }

  //creation of distance arr with infinity value
  vector<int>dist(vertices);
  for(int i=0;i<vertices;++i)
    dist [i]=INT_MAX;

  //creation of set on basis(dist,node)
  set<pair<int,int>> st;

  //initailising wrt source node
  dist[source]=0;
  st.insert(make_pair(0,source));
  
  while(!st.empty()){
    // fetch top
    auto top=*(st.begin());
    int topdist=top.first;
    int topnode=top.second;
    
    //remove top record now
    st.erase(st.begin());
    
    // trvaserse nbr
    for(auto nbr: adj[topnode]){
      if(topdist+nbr.second<dis[nbr.first]){
        auto record=st.find(make_pair(dis[nbr.first],nbr.first));
        
        //if record found then erase it
        if(record!=st.end()) st.erase(record);
        
        // distance update
        dis[nbr.first]=topdist+nbr.second;
        
        // record push in set
        st.insert(make_pair(dis[nbr.first],nbr.first));
      }
    }
  }
return dis;
    
}
class Solution{
  public:
  vector<int>DijkstraAlgo(int v,vector<vector<int>>adj[],int src){
    set<pair<int,int>>s;  //{dist,node}
    vector<int>dist(v,INT_MAX);
    dist[src]=0;
    s.insert({0,src});
    while(!s.empty()){
      auto it=*(s.begin()); //gives value of first element
      int dis=it.first;
      int node=it.second;
      s.erase(it);
      for(auto it:adj[node]){
        int adjNode=it[0];
        int edgeW=it[1];
        if(dis+edgeW<dist[adjNode]){
          if(dist[adjNode]!=INT_MAX) s.erase({dist[adjNode],adjNode});
          dist[adjNode]=dis+edgeW;
          s.insert({dist[adjNode],adjNode});
        }
      }

    }
    return dist;
  }

};



int main(){
    set<pair<int, char>> s;
    s.insert({1,'A'});
    s.insert({0,'B'});
    s.insert({4,'D'});
    s.insert({3,'c'});
    s.insert({1,'A'});

    while(!s.empty()){
        auto f=(*s.begin());
        cout<<"("<<f.first<<","<<f.second<< ")";
        s.erase(s.begin());
    }
    cout<<endl;



  return 0;
}