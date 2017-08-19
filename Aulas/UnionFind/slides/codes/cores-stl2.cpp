set<int> dfs(int v) {
    set<int> colors;
    colors.insert(color[v]);
    for (int w : adj[v]) {
        set<int> colors2 = dfs(w);
        if (colors2.size() > colors.size())
            swap(colors, colors2);
        for (int c : colors2)
            colors.insert(c);
    }
    ans[v] = colors.size();
    return colors;
}
