int uf[MAX_N+1];
void init() {
    for (int i = 1; i <= MAX_N; ++i)
        uf[i] = i;
}
int find(int x) {
    if (uf[x] == x)
        return x;
    else
        return find(uf[x]);
}
void merge(int u, int v) {
    int a = find(u);
    int b = find(v);
    uf[a] = b;
}
