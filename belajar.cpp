#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int N = 100005;
map<LL,int>cnt;
LL ar[N];
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &ar[i]);
		cnt[ar[i]]++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int val = 0;
		for (int j = 0; j < 32 && !val; j++) {
			int tmp = cnt.find( (1ll<<j) - ar[i] )->second;
			if ( (1ll<<j) == ar[i] * 2 ) {
				tmp--;
			}
			if (tmp > 0) {
				val = 1;
			}
		}
		if (!val){
			ans++;
		}
	}
	printf("%d\n", ans);
}
