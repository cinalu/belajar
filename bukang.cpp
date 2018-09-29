#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	int org[40];
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i){
		scanf("%d", &org[i]);
		if(i){
			org[i] = (org[i] + org[i-1])%k;
		}
	}
	
	set<int> find; find.insert(-1);
	int ans = 0;
	for(int i = 0; i < n; ++i){
		ans = max(ans, org[i]);
		set<int>::iterator target = find.lower_bound(org[i]+1);
		if(target != find.end()){
			ans = max(ans, org[i] - *target + k);
		}
		find.insert(org[i]);
	}
	
	printf("%d\n", ans);
}