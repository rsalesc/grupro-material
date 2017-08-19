set<int> dfs(int v) {
    set<int> colors;
    colors.insert(color[v]);
    for (int w : adj[v])
        for (int c : dfs(w))
            colors.insert(c);
    ans[v] = colors.size();
    return colors;
}
