#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int ans[1000005]={0};
queue<int> q;

int main(){
	int f, s, g, u, d;
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	q.push(s);
	ans[s] = 1;
	while(!q.empty() && !ans[g]){
		int cur = q.front();
		q.pop();
		int next = cur+u;
		if(next<=f && !ans[next]){
			ans[next]=ans[cur]+1;
			q.push(next);
		}
		next = cur-d;
		if(next>=1 && !ans[next]){
			ans[next]=ans[cur]+1;
			q.push(next);
		}
	}
	printf("%d\n", ans[g]-1);
}
