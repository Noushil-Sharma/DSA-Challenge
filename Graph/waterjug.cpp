#include<bits/stdc++.h>
#using namespace std;

class Solution {
public:
    bool canMeasureWater(int j1, int j2, int c) {
        if(j1+j2<c){
            return false;
        }
        int t = j1+j2;
        vector<int>vis(t+1,0);

        int dx[] = {j1,j2,-j1,-j2};


        queue<int>q;
        q.push(0);
        vis[0]=1;

        while(!q.empty()){
            int fnode = q.front();
            q.pop();
            if(c == fnode) return true;

            for(int i =0; i<4; i++){
                int nn = fnode + dx[i];

                if(nn>=0&&nn<=t&&!vis[nn]){
                    q.push(nn);
                    vis[nn]=1;
                    cout<<nn<<" ";
                }
            }
        }


        return false;

    }
};