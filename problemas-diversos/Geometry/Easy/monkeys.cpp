#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pb push_back
#define int long long
#define pii pair<int, int>
#ifndef M_PI
	static const long double M_PI = acos(-1.0);
#endif
vector<pii> v;
bool cross(pii a , pii b){
	return (a.F)*(b.S)  - (b.F)*(a.S) >= 0;
}
pii make_vector(pii a , pii b){
	return mp(b.F - a.F , b.S - a.S);
}
int32_t main(){
	//clock_t t = clock();
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int  y, x;
		cin>>x>>y;
		v.pb(mp(x,y));
	}
	sort(v.begin() , v.end());
	stack<pair<pii , int> > uhull;
	for(int i = 1;i<n;i++){
		while(uhull.empty() == false){
			if(cross(uhull.top().F , make_vector(v[uhull.top().S] , v[i])) == false) break;
			uhull.pop();
		}
		if(uhull.empty() == true){
			uhull.push(mp(make_vector(v[0] , v[i]) , i));
		}
		else{
			uhull.push(mp(make_vector(v[uhull.top().S] , v[i]), i));
		}
	}
	cout<<uhull.size();

  //  cout<<"TIME IS" <<( ( double ) (clock() - t) / CLOCKS_PER_SEC );
}
