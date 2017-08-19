void merge(int u, int v) {
    int a = find(u);
    int b = find(v);
    if (sz[a] > sz[b]) swap(a, b);
    old_uf.emplace(a, uf[a]);
    old_sz.emplace(b, sz[b]);
    uf[a] = b;
    sz[b] += sz[a];
}
void rollback() {
    uf[old_uf.top().first] = old_uf.top().second;
    sz[old_sz.top().first] = old_sz.top().second;
    old_uf.pop();
    old_sz.pop();
}
