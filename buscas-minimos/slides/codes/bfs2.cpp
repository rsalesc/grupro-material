int dist[]; // inicializado para inf
queue<int> q;

q.push(source);
dist[source] = 0;

while(!q.empty()){
    int u = q.front(); q.pop();
    for(int v : adj[u]) if(dist[u]+1 < dist[v]){
        dist[v] = dist[u]+1;
        q.push(v);
    }
}