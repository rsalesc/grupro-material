#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define int long long
#define pii pair<int,int>
#define ieps (int) 1e6




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0) , cout.tie(0);
	int q;
	cin>>q;
	while(q--){
		int n ;
		cin>>n;
		vector<int> v(n);
		for(int i = 0;i<n;i++) cin>>v[i];
		sort(v.begin() , v.end());
		int m;
		cin>>m;
		vector<pii> seg(m);
		for(int i = 0;i<m;i++){
			cin>>seg[i].F>>seg[i].S;
		}
		sort(seg.begin() , seg.end());
		vector<pii> finalseg;
		pii currseg = mp(-1 ,  -1);
		for(int i = 0;i<m;i++){
			pii t = mp(-1 , -1);
			if(currseg ==  t){
				currseg = seg[i];
			}
			else{
				if(seg[i].F < currseg.S){
					currseg.S = max(seg[i].S , currseg.S);
					currseg.F = min(seg[i].F ,  currseg.F);
				}
				else{
					finalseg.pb(currseg);
					currseg = seg[i];
				}
			}
			if(i == m - 1 && currseg != t){
				finalseg.pb(currseg);
			}
		}
		int resp = 0;
		for(auto p : finalseg){
			int t = lower_bound(v.begin() , v.end() , p.F) - v.begin();
			int l = upper_bound(v.begin() , v.end() , p.S) - v.begin();
			resp+=l-t;
		}
		cout<<resp<<endl;
	}
}