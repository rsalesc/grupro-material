#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

struct State{
	vector<int> p;
	int dist;
	bool operator<(const State & rhs) const{
		return dist > rhs.dist;
	}
};

ii get_coord(int x){
	return {x/4, x%4};
}

bool valid(ii p){
	return p.first >= 0 && p.first < 2 && p.second >= 0 && p.second < 4;
}

int get_index(ii p){
	return p.first*4 + p.second;
}

int32_t main(){
	vector<int> ini(8), fim(8);
	for(int i = 0; i < 8; i++) cin >>ini[i];
	for(int i = 0; i < 8; i++) cin >> fim[i];

	map<vector<int>, int> dist;
	priority_queue<State> pq;

	pq.push({ini, 0});
	dist[ini] = 0;

	while(!pq.empty()){
		State st = pq.top();
		pq.pop();
	
		if(dist[st.p] != st.dist) continue;

		for(int i = 0; i < 8; i++){
			ii pt = get_coord(i);
			for(int k = 0; k < 4; k++){
				int x = pt.first+dx[k];
				int y = pt.second+dy[k];
				if(!valid({x, y})) continue;
				int idx = get_index({x, y});
				if(i > idx) continue;

				swap(st.p[i], st.p[idx]);

				int nw = st.dist+st.p[i]+st.p[idx];
				if(!dist.count(st.p) || nw < dist[st.p]){
					dist[st.p] = nw;
					pq.push({st.p, nw});
				}

				swap(st.p[i], st.p[idx]);
			}
		}
	}

	cout << dist[fim] << endl;
}
