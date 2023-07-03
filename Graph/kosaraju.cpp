#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
    
	public:
   void topo(vector<vector<int>>& adj, int src, vector<int>& vis,stack<int>& st){
	    vis[src] = 1;
	    for(auto it : adj[src]){
	        if(!vis[it]){
	            topo(adj,it,vis,st);
	        }
	    }
	    st.push(src);
	}
	
	void dfs(vector<vector<int>>& adj,int src,vector<int>&vis){
	    vis[src]=1;
	    
	    for(auto nbr: adj[src]){
	        if(!vis[nbr]){
	           // vis[nbr]=1;
	            dfs(adj,nbr,vis);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        
        stack<int>st;
        // unordered_map<int,vector<int>>adj;
        
        // for(int i = 0; i<adj.)
        //code here
        vector<int>vis(V,0);
        for(int i =0;i<V;i++){
             if(!vis[i]){
                 topo(adj,i,vis,st);
             }
        }
        
        vector<vector<int>> adjR(V);
    
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                adjR[it].push_back(i);
            }
        }
        
        vis.resize(V,0);
        for(int i = 0; i<V; i++){
            vis[i]=0;
        }
        int ans = 0;
        
    //   cout<<st.size();
        
        
        
        while(!st.empty()){
            int n = st.top();
            // cout<<st.top();
            st.pop();
            if(!vis[n]){
                dfs(adjR,n,vis);
                ans++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}
