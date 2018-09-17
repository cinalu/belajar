#include<bits/stdc++.h>
using namespace std;
int mark[100005];
stack<int> st;
int main(){
	int n;
	scanf("%d", &n);
	n *= 2;
	int ans = 0;
	int cur = 0;
	int cont = 0;
	for (int i = 0; i < n; i++) {
		char rem[50];
		scanf("%s", &rem);
		if (rem[0] == 'a'){
			int a;
			scanf("%d", &a);
			st.push(a);
			cont = 0;
		}
		else{
			cur++;
			if (!cont && st.top() != cur){
				cont = 1;
				ans++;
			}
			mark[cur] = 1;
		}
		while(!st.empty() && mark[st.top()] == 1){
			st.pop();
		}
	}
	printf("%d\n", ans);
}
