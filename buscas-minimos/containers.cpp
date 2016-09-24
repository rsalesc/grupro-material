#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> matriz;

struct State{
	int dist;
	matriz vert;
};

bool operator<(const State & a, const State & b){
	return a.dist > b.dist;
}

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < 2 && j < 4);
}

int main(){
	matriz ini(2, vector<int>(4));
	matriz fim(2, vector<int>(4));
	
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 4; j++)
			cin >> ini[i][j];
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 4; j++)
			cin >> fim[i][j];
	
	map<matriz, int> dist;
	dist[ini] = 0;
	
	priority_queue<State> pq;
	pq.push({dist[ini], ini});
	
	const int dx[] = {-1, 0, 1, 0};
	const int dy[] = {0, 1, 0, -1};
	
	while(!pq.empty()){
		State st = pq.top();
		pq.pop();
		
		if(st.dist > dist[st.vert]) continue;
		
		// relax
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 4; j++){
				// testar trocar cada (i,j) com um vizinho deles
				for(int k = 0; k < 4; k++){
					int ni = i+dx[k];
					int nj = j+dy[k];
					if(!valid(ni, nj)) continue;
					swap(st.vert[i][j], st.vert[ni][nj]);
					
					// relaxo aqui
					int soma = st.vert[i][j] + st.vert[ni][nj];
					if(!dist.count(st.vert) || st.dist + soma < dist[st.vert]){
						dist[st.vert] = st.dist + soma;
						pq.push({dist[st.vert], st.vert});
					}
					
					swap(st.vert[i][j], st.vert[ni][nj]);
				}
			}
		}
	}
	
	cout << dist[fim] << endl;
}
