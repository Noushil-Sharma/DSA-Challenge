#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>d(V,1e9);
        d[S]=0;
        // vector<int>vis(V,0);
        
        set<pair<int,int>>st;
        
        st.insert({0,S});
        
        while(!st.empty()){
            auto top = *(st.begin());
            st.erase(top);
            int node = top.second;
            int dist = top.first;
            
            
            for(auto neighbour: adj[node]){
                
                int distance = neighbour[1];
                int neigh = neighbour[0];
                
                if(d[neigh]>dist+distance){
                    st.insert({dist+distance,neigh});
                    d[neigh] = dist+distance;
                }
            }
        }
        
        
        return d;
        
        
    }
};