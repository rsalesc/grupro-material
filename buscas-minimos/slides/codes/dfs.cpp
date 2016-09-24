bool vis[];
vector<int> adj[];

void dfs(int u){
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v]) dfs(v);
}

// no caso de várias componentes
for(int i = 0; i < n; i++)
    if(!vis[i]) dfs(i);