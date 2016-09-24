int color[]; // inicializado em -1
vector<int> adj[];
bool fail;

void dfs(int u, int c /* 0 ou 1 */){
    color[u] = c;
    for(int v : adj[u])
        if(color[v] == -1) dfs(v, c^1);
        else if(color[v] == c) fail = true;
}