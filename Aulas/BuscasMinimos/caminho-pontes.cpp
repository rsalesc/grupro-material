#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int oo = 1000000000;
const int N = 1003;
vector<ii> adj[N];
int dist[N];
bool vis[N];

struct State{
	int dist, vert;
};

bool operator<(const State & a, const State & b){
	return a.dist > b.dist;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	
	for(int i = 0; i < m; i++){
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		adj[a].push_back(ii(b, w));
		adj[b].push_back(ii(a, w));
	}
	
	for(int i = 0; i <= n+1; i++) dist[i] = oo;
	dist[0] = 0;
	
	//priority_queue<State, bool(*)(State, State)> pq(cmp);
	priority_queue<State> pq;
	pq.push({dist[0], 0});

	while(!pq.empty()){
		State st = pq.top();
		pq.pop();
		int u = st.vert;
		
		if(st.dist > dist[u]) continue; // duplicata
		
		for(ii e : adj[u]){
			int v = e.first;
			int cost = e.second;
			if(dist[u] + cost < dist[v]){
				dist[v] = dist[u] + cost;
				pq.push({dist[v], v});
			}
		}
	}

	
	printf("%d\n", dist[n+1]);
}
