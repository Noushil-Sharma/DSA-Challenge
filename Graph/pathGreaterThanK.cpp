
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ans = false;
    void dfs(unordered_map<int,vector<pair<int,int>>>&adj,int node,vector<int>&vis,int k){
        if(k<=0){
            ans = true;
        }
        
        vis[node]=1;
        
        for(auto nbr: adj[node]){
            if(!vis[nbr.first]){
                dfs(adj,nbr.first,vis,k-nbr.second);
                
                
            }
        }
        vis[node]=0;
    }
    bool pathMoreThanK(int V, int E, int k, int *a) 
    { 
        unordered_map<int,vector<pair<int,int>>>adj;
        
        for(int i=0;i<E*3;i+=3){
            
           adj[a[i]].push_back({a[i+1],a[i+2]});
           adj[a[i+1]].push_back({a[i],a[i+2]});
       }
       vector<int>vis(V,0);
       
       int dist = 0;
       
       dfs(adj,0,vis,k);
       
       return ans;
       //  Code Here
    } 
};

