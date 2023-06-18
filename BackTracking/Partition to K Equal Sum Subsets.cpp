#include<bits/stdc++.h>
using namespace std;
    bool solve(vector<int>& nums,int k,int i,int val,int target,vector<int>&visited){
        if(k==1){
            return true;
        }
        if(val==target){
            return solve(nums,k-1,0,0,target,visited);
        }

        for(int j = i; j<nums.size(); j++){
            if(visited[j]==1 || val + nums[j]>target){
                continue;
            }
            visited[j]=true;
            solve(nums,k,j+1,val+nums[i],target,visited);
            visited[j]=0;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto it: nums){
            sum = sum+it;
        }
        if(sum%k!=0){
            return false;
        }
        if(nums.size()<k){
            return false;
        }
        int target = sum/k;
        if(k==1){
            return true;
        }
        vector<int>visited(nums.size(),0);
        return solve(nums,k,0,0,target,visited);
    }
int main(){

    return 0;
}