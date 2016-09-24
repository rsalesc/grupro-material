bool vis[];
queue<int> q;

q.push(source);
vis[source] = true;

while(!q.empty()){
    int u = q.front(); q.pop();
    for(int v : adj[u]) if(!vis[v]){
        vis[v] = true;
        q.push(v);
    }
}