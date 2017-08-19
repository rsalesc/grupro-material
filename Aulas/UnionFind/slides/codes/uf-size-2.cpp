int find(int x) {
    if (uf[x] == x) return x;
    else            return find(uf[x]);
}
void merge(int u, int v) {
    int a = find(u);
    int b = find(v);
    if (sz[a] < sz[b]) {
        uf[a] = b;
        sz[b] += sz[a];
    } else {
        uf[b] = a;
        sz[a] += sz[b];
    }
}
