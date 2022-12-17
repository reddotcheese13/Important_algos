    bool is_bip=true;
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
