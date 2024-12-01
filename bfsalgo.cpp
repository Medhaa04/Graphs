#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template<typename T>
class Graph{
    public:
    unordered_map<T,list<T>>adj;

    void addEdge(T u,T v,bool bidir=true){
        adj[u].push_back(v);
        if(bidir)  adj[v].push_back(u);
    }
    void print(){
        for(auto p:adj){
            cout<<p.first<<" : ";
            for(auto n:p.second){
                cout<<n<<",";
            }
            cout<<endl;
        }

    }
    void bfs(T src){
        unordered_map<T, bool> visited;

		queue<T> q;
		q.push(src);
		visited[src] = true;

		while (!q.empty()) {
			T f = q.front();
			q.pop();
			cout << f << " ";
			for (auto ch : adj[f]) {
				if (!visited[ch]) {
					visited[ch] = true;
					q.push(ch);
				}
			}
		}

       
    }
    

};

int main(){
    Graph<string> g;
    // g.addEdge("Putin","Trump",false);
    // g.addEdge("Putin","Modi",false);
    // g.addEdge("Trump","Modi",true);
    // g.addEdge("Yogi","Modi",true);
    // g.addEdge("Yogi","Prabhu",false);
    // g.addEdge("Prabhu","Modi",false);
    // g.addEdge("Putin","Pope",false);
    // g.print();

    g.addEdge("A","B");
    g.addEdge("C","B");
    g.addEdge("C","E");
    g.addEdge("A","E");
    g.addEdge("D","E");
    g.addEdge("D","C");
    g.addEdge("D","F");

    g.bfs("A");
    cout<<endl;





}