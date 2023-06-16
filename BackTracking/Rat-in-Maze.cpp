#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x,int y,vector<vector<int>>&m,int n,vector<vector<int>>&vis){
        if(x>=0&&x<n&&y>=0&&y<n){
            if(vis[x][y]==0&&m[x][y]==1){
                return true;
            }
        }
        return false;
    }
    
void solve(int x,int y,vector<vector<int>>&m,int n,vector<vector<int>>&vis,vector<string>&ans,string p){
        if(x==(n-1)&&y==(n-1)){
            
            ans.push_back(p);
            
            return;
        }
        
        if(isSafe(x,y+1,m,n,vis)){
            // p.push_back('D');
            vis[x][y]=1;
            solve(x,y+1,m,n,vis,ans,p+'R');
            vis[x][y]=0;
            
        }
        if(isSafe(x,y-1,m,n,vis)){
            // p.push_back('U');
            vis[x][y]=1;
            solve(x,y-1,m,n,vis,ans,p+'L');
            vis[x][y]=0;
            
        }
        if(isSafe(x-1,y,m,n,vis)){
            // p.push_back('L');
            vis[x][y]=1;
            solve(x-1,y,m,n,vis,ans,p+'U');
            vis[x][y]=0;
            
        }
        if(isSafe(x+1,y,m,n,vis)){
            // p.push_back('R');
            vis[x][y]=1;
            solve(x+1,y,m,n,vis,ans,p+'D');
            vis[x][y]=0;
            
        }
        
}
    
    
vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<string>ans;
        string p;
        
        if(m[0][0]==0){
            return ans;
        }
        else{
            solve(0,0,m,n,vis,ans,p);
        }
}
int main(){

    
}