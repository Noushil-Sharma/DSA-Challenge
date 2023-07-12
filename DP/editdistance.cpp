#include<bits/stdc++.h>
using namespace std;

class Solution {
    
    int dp[1005][1005];
  public:
    
    int solve(string &s, string &t,int i,int j){
    if(i==0){
        return j;
    }
    if(j==0){
        return i;
    }
    
    if(dp[i][j]!=-1)  return dp[i][j];
    
    
        if(s[i-1]==t[j-1]){
            // cout<<i<<" "<<j<<endl;
            return dp[i][j] = solve(s,t,i-1,j-1);
            
        }
        
        int in = 1 + solve(s,t, i-1,j);
        int rem =1 + solve(s,t,i,j-1);
        int rep = 1 +  solve(s,t,i-1,j-1);
        
        return dp[i][j] = (min(in,min(rem,rep)));
        
    }
    int editDistance(string s, string t) {
       memset(dp,-1,sizeof(dp));
       return solve(s,t,s.size(),t.size());
    }
};