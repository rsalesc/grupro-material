int uf[MAX_N+1];
int sz[MAX_N+1];
void init() {
    for (int i = 1; i <= MAX_N; ++i) {
        uf[i] = i;
        sz[i] = 1;
    }
}
