#include<bits/stdc++.h>
using namespace std;
const int N = 100005;

int L[N], R[N];
int ar[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
	}
	stack<int> st;
	
	//Right
	for (int i = 0; i < n; i++) {
		while (!st.empty() && ar[st.top()] <= ar[i]) {
			R[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()){
		R[st.top()] = n;
		st.pop();
	}
	
	//Left
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && ar[st.top()] <= ar[i]) {
			L[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) {
		L[st.top()] = -1;
		st.pop();
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d ", R[i] - L[i] - 2);
	}
}
