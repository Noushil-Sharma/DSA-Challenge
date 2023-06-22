#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x,int y,int n){
        if(x>=1&&x<=n&&y>=1&&y<=n){
            return true;
        }
        return false;
        
        
    }
    



    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&K,vector<int>&T,int N)
	{
	    vector<vector<bool>>vis(N+1,vector<bool>(N+1,false));
	    queue<pair<int,int>>q;
	    int ax[]={1,1,-1,-1,2,2,-2,-2};
        int ay[]={2,-2,2,-2,1,-1,1,-1};
	    int fx = T[0];
	    int fy = T[1];
	    
	    
	    if(K==T){
	        return 0;
	    }
	    int ans = 0;
	    
	    q.push({K[0],K[1]});
	    vis[K[0]][K[1]]=true;
	    
	    while(!q.empty()){
	        
	        int sz = q.size();
	        
	        for(int i =0; i<sz; i++){
	        
	        
	        
	        
	        int x1 = q.front().first;
	        int x2 = q.front().second;
	        
	        q.pop();
	        
	        for(int i =0; i<8; i++){
	            int nx = x1+ax[i];
	            int ny = x2+ay[i];
	            
	            if(isSafe(nx,ny,N) && !vis[nx][ny]){
	            
	            q.push({nx,ny});
	            vis[nx][ny]=true;
	            
	            }
	            if(nx==T[0]&&ny==T[1]){
	                return ans+1;
	            }
	            
	            
	        }
	        
	        
	        }
	        
	        
	        ans++;
	        
	        
	    }
	    
	    return -1;
	}