set<int> colors[MAX_N+1];
void dfs(int v) {
    colors[v].insert(color[v]);
    for (int w : adj[v]) {
        dfs(w);
        if (colors[w].size() > colors[v].size())
            swap(colors[v], colors[w]);
        for (int c : colors[w])
            colors[v].insert(c);
    }
    ans[v] = colors[v].size();
}
