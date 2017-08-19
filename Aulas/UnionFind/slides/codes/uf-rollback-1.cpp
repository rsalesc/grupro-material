int uf[MAX_N+1];
int sz[MAX_N+1];
stack<pair<int, int>> old_uf;
stack<pair<int, int>> old_sz;
void init() {
    for (int i = 1; i <= MAX_N; ++i) {
        uf[i] = i;
        sz[i] = 1;
    }
}
int find(int x) {
    if (uf[x] == x) return x;
    else            return find(uf[x]);
}
