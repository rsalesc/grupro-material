#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define int long long
#define pii pair<int, int>
#define mp make_pair
#define ieps (int) 1e6
bool cmp(pair<pii ,int> a , pair<pii , int> b){
	if(a.F.F == b.F.F){
		return a.S > b.S;
	}
	else return a.F < b.F;
}

int32_t main(){
 	string s;
 	cin>>s;
 	int n, k;
 	cin>>n>>k;
 	vector<int> v(n) , p(n);
 	for(int i = 0;i<n;i++) cin>>v[i],  p[i] = v[i];
 	sort(p.begin() , p.end());
 	map<int, vector<int> > pos;
 	map<int, int> curr;
 	for(int i = 0;i<n;i++){
 		pos[v[i]].pb(i);
 		curr[v[i]] = 0;
 	}
 	vector<pair<pii, int > > vt;
 	for(int i = 0;i<n;i++){
 		int x = pos[p[i]][curr[p[i]]];
 		curr[p[i]]++;
 		vt.pb(mp(mp(min(x, i) , max(x, i)) , max(x,i) - min(x,i) + 1));
 	}
 	sort(vt.begin() , vt.end() , cmp);
 	vector<pair<pii, int >> final;
 	int pointer  = 0;
 	for(int i = 0;i<n;i++){
 		int x = vt[i].F.S;
 		if(x > pointer){
 			final.pb(vt[i]);
 			pointer = x;
 		}
 	}
 	int currv = 0;
 	vector<pair<pii, int> > vr;
 	for(int i = 0;i<final.size();i++){
 		if(final[i].S == 1) continue;
 		vr.pb(mp(mp(max(final[i].F.F , currv) , final[i].F.S) , final[i].F.S - max(final[i].F.F , currv) + 1));
 		currv = max(currv, final[i].F.S);
 	}
 	sort(vr.begin() , vr.end());
 	int t = 0LL;
 	for(auto r : vr){
 		t+=r.S;
 	}
 	if(vr.size() == k){
 		cout<<t;
 	}
 	else{
 		if(vr.size() < k){
 			int lol = k - vr.size();
 			cout<<t + lol;
 		}
 		else{
 			vector<int > vtt;
 			for(int i = 0;i<vr.size()-1;i++){
 				vtt.pb((vr[i+1].F.F - 1) - (vr[i].F.S +1) + 1);
 			}
 			sort(vtt.begin() , vtt.end());
 			int tot  = vr.size() - k;
 			int kek = 0;
 			int currata = 0;
 			while(tot--){
 				kek+=vtt[currata++];
 			}
 			cout<<t+kek;
 		}
 	}
 	cout<<endl;
}
