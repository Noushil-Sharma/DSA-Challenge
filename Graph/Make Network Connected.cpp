#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int n, vector<int>m[],int src,int extra,vector<int>&vis){
        vis[src]=1;

        for(auto it: m[src]){
            if(vis[it]){
                extra++;
            }
            if(!vis[it]){
                vis[it]=1;
                dfs(n,m,it,extra,vis);
            }
        }

    }
    int makeConnected(int n, vector<vector<int>>&m1) {
        int ans=-1;
        int extra = 0;

        vector<int>m[n];
        for(auto v : m1)
        {
            m[v[0]].push_back(v[1]);
            m[v[1]].push_back(v[0]);
        }
        
        vector<int>vis(n+1,0);
        if(m1.size()<n-1){
            return ans;
        }

        for(int i =0; i<n; i++){
            if(!vis[i]){
                
                int x =0;
                dfs(n,m,i,x,vis);
                ans++;
                // extra = extra + x;
            }


        }
        // cout<<extra;

        return ans;
    }
};

int main(){
    
}