#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k, m;
	scanf("%d %d %d", &n, &k, &m);
	vector<int> ans(k+1);
	fill(ans.begin(), ans.end(), 0);
	ans[0] = 1;
	for(int i=1; i <= n; ++i){
		for(int j=min(i,k); j>0; --j){
			ans[j] = (ans[j]+ans[j-1])%m;
		}
	}
	printf("%d\n", ans[k]);
}