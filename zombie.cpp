#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.second < b.second;
}

int main(){
	int n;
	cin>>n;
	pair<int,int> a[n+1];
	for(int i = 1; i <= n; ++i){
		cin>>a[i].first>>a[i].second;
	}
	sort(a+1,a+1+n, comp);
	queue<int> q;
	ll l=1,r=INT_MAX, ans = -1;
	while(l<=r){
		bool val = 1;
		ll m = (l+r)/2, t = m;
		for(int i = 1; i <= n && t >= 0; ++i){
			if(t < a[i].first){
				val = 0;
				//q.push(i);
			}else{
				t -= a[i].second;
			}
		}
		
		// while(!q.empty()){
		// 	cerr<<q.front()<<endl;
		// 	if(t >= a[q.front()].first){
		// 		t -= a[q.front()].second;
		// 		val = 1;
		// 	}
		// 	q.pop();
		// }
		
		if(val){
			ans = m;
			r = m-1;
		}else{
			l = m+1;
		}
	}
	
	cout<<ans<<endl;
}
