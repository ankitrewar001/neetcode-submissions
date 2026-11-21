class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, 1e9);
        vector<vector<pair<int,int>>> adj(n+1);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(auto it : times){
            adj[it[0]].push_back({it[2], it[1]});
        }

        pq.push({0,k});
        dist[0] = 0, dist[k] = 0;

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                int newdist = dis + it.first;
                if(newdist < dist[it.second]){
                    dist[it.second] = newdist;
                    pq.push({newdist, it.second});
                }
            }
        }

        int ans = *max_element(dist.begin(), dist.end());

        return ans >= 1e9 ? -1 : ans;
    }
};
