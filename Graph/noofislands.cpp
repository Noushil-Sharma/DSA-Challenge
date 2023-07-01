#include<bits/stdc++.h>
using namespace std;

bool isSafe(int n,int m,int x,int y){
      if(x>=0&&x<n&&y>=0&&y<m){
          return true;
      }
      return false;
  }
  
    
    void BFS(vector<vector<char>>& grid,int n,int m,int n1,int n2,vector<vector<int>>&vis){
        queue<pair<int,int>>q;
        q.push({n1,n2});
        vis[n1][n2]=1;
        
        int dx[] = {1,0,-1,0,1,1,-1,-1};
        int dy[] = {0,1,0,-1,1,-1,1,-1};
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i =0; i<8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(isSafe(n,m,nx,ny) && grid[nx][ny]=='1'){
                    if(!vis[nx][ny]){
                        vis[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
            }
        }
        
        
        
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]=='1'){
                    if(!vis[i][j]){
                        ans++;
                        BFS(grid,n,m,i,j,vis);
                    }
                }
            }
        }
        return ans;
        // Code here
    }