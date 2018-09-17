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
		if (rem[0] == 'a'){	//klo add
			int a;
			scanf("%d", &a);
			st.push(a);
			cont = 0;	//klo add kita gabisa terus asumsi bahwa sudah sorted
		}
		else{
			cur++;
			if (!cont && st.top() != cur){	//klo ga sesuai Wengki
				cont = 1;	//asumsi kita sort semuanya sesuai
				ans++;
			}
			mark[cur] = 1;	//tandain dibuang
		}
		while(!st.empty() && mark[st.top()] == 1){	//yg ditanda dibuang beneran dibuang supaya gak ngacauin checking
			st.pop();	// !st.empty() berarti stack not empty, klo kita akses stack kosong bisa RTE
		}
	}
	printf("%d\n", ans);
}
