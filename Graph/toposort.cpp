#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	void toposort(vector<int>adj[],vector<bool>&visited,vector<int>&ans,int node){
	    visited[node]=true;
	    
	    for(auto it: adj[node]){
	        if(!visited[it]){
	            visited[it]=true;
	            toposort(adj,visited,ans,it);
	        }
	    }
	    ans.push_back(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool>visited(V,false);
	    vector<int>ans;
	    
	    for(int i=0; i<V; i++){
	        if(!visited[i]){
	            toposort(adj,visited,ans,i);
	        }
	    }
	   // cout<<ans.size()<<endl;
	   // for(auto it: ans){
	   //     cout<<it<<" ";
	   // }
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
};