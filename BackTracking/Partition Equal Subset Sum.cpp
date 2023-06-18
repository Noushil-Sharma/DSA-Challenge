#include<bits/stdc++.h>
using namespace std;

int solve(int index, int arr[],int N,int target,vector<vector<int>>&dp){
    if(index>N)  return 0;
    if(target<0) return 0;
    if(target == 0){
        return 1;
    }
    if(dp[index][target]!=-1){
        return dp[index][target];
    }
    bool incl = solve(index+1,arr,N,target-arr[index],dp);
    bool excl = solve(index+1,arr,N,target-0,dp);
    
    dp[index][target] = incl or excl;
    return dp[index][target];
    
}

int main(){

    return 0;
}