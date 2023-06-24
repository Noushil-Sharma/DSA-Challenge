#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool Safe(int x, int y,vector<vector<int>>& image){
        int m = image.size();
        int n = image[0].size();

        if(x>=0&&x<m&&y>=0&&y<n){
            return true;
        }
        return false;
    }
    void bfs(vector<vector<int>>& image, int sr, int sc, int color,vector<vector<int>>&ans){
        int m = image.size();
        int n = image[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        q.push({sr,sc});
        vis[sr][sc]=1;
        ans[sr][sc]=color;
        int val = image[sr][sc];

        int z = 0;

        while(!q.empty()){
            pair<int,int>p=q.front();

            q.pop();
            for(int i =0; i<4; i++){
                int x1 = p.first + dx[i];
                int y1 = p.second + dy[i];

                if(Safe(x1,y1,image)){
                    // cout<<x1<<" "<<y1<<" ";
                    if(image[x1][y1]==val){
                        q.push({x1,y1});
                        // cout<<x1<<" "<<y1;
                        z++;
                        vis[x1][y1]=1;
                        ans[x1][y1]=color;

                    }
                }

                // cout<<q.size();
                if(z>=5000){
                    break;
                }


            }
        }
        
    

        

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<vector<int>>ans = image;
        bfs(image,sr,sc,color,ans);
        


        return ans;
    }
};

int main(){
    

    return 0;
}