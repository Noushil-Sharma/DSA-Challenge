#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
// 	int BFS()
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int ans = 0;
        vector<int>vis(V,0);
        set<pair<int,int>>s;
        s.insert({0,0});
        // vis[0]=1;
        while(!s.empty()){
            auto p = s.begin();
            s.erase(*p);
            int node = (*p).second;
            int dist = (*p).first;
            if(vis[node]==1){
                continue;
            }
            ans = ans+dist;


            



            
            vis[node]=1;
            
            for(auto nbr: adj[node]){
                if(!vis[nbr[0]]){
                    
                    s.insert({nbr[1],nbr[0]});
                }
            }
        }
        
        return ans;
        
    }
};