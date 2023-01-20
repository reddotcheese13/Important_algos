//V - no of nodes,adj - adjacency list(node,weight), s-> Source    
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V,1e9);
        dist[S]=0;
        pq.push({dist[S],S});
        while(!pq.empty()){
            int curnode=pq.top().second;
            int curweight=pq.top().first;
            pq.pop();
            for(auto i:adj[curnode]){
                int node=i[0];
                int weight=i[1];
                if(weight+curweight<dist[node]){
                    dist[node]=weight+curweight;
                    pq.push({dist[node],node});
                }
            }
        }
        return dist;
    }
