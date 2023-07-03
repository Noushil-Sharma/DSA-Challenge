#include<bits/stdc++.h>
using namespace std;


bool checkCycleDFS(int node,vector<bool> &visited,unordered_map<int,int> &parent, vector<int> adj[]){
    visited[node] = true;
    parent[node]=-1;
    
    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected = checkCycleDFS(neighbour,visited,parent,adj);
            if(cycleDetected) return true;
        }

        
        else if(parent[neighbour]){
            return true;
            
        }
    }
     
    parent[node]=false;
    return false;

}
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        unordered_map<int,int>parent;
        
        vector<bool>visited(V,0);
        
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                if(checkCycleDFS(i,visited,parent,adj)) return 1;
            }
        }
        
        return false ;
        
    }