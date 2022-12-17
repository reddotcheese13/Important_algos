//886. Possible Bipartition leetcode
class Solution {
public:
    bool is_bip;
    void dfs(int val,vector<int> adj[],int col,vector<int> &vis){
        vis[val]=col;
        for(auto i:adj[val]){
            if(!vis[i]){
                dfs(i,adj,3-col,vis);
            }else if(vis[val]==vis[i]){
                is_bip=false;
            }
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        is_bip=true;
        vector<int> vis(n+1,0);
        vector<int> adj[n+1];
        for(auto i:dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=1;i<=n;i++)if(!vis[i])dfs(i,adj,1,vis);
        return is_bip;
    }
};
