#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		int x;
		scanf("%d", &x);
		if(x<10){
			printf("%d\n", x);
		}else{
			stack<int> st;
			for(int i = 9; i >= 2 && x > 1; --i){
				while(x%i == 0){
					st.push(i);
					x /= i;
				}
			}
			if(x <= 1){
				int ans = 0;
				while(!st.empty()){
					ans = 10*ans+ st.top();
					st.pop();
				}
				printf("%d\n", ans);
			}else{
				printf("-1\n");
			}
		}
	}
}