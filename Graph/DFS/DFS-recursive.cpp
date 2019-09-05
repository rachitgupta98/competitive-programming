#include <bits/stdc++.h> 
using namespace std;
#define MAX 20000
void addEdges(vector<vector<int>>&v,int s,int e){
    v[s].push_back(e);
    v[e].push_back(s);
}
vector<bool>visited(MAX,false);
void DFS(vector<vector<int>>&v,int s){

    visited[s] = true;
    
        for(int i=0;i<v[s].size();i++){
            if(visited[v[s][i]]==false)
            {
                cout<<v[s][i]<<" ";
                DFS(v,v[s][i]);
            }
           
        }
    }


int main(){
    
    int vertex,edges,source;
    cin>>vertex>>edges>>source; //no of vertex,no of edges, source from where BFS to start
    vector<vector<int>>v(MAX);
    for(int i=0;i<edges;i++){
         int p,q;
         cin>>p>>q;
         addEdges(v,p,q);
    }
//   cout<<v[2][0];
      cout<<source<<" ";
      DFS(v,source);
      
      return 0;
}
