#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	queue<int> car_queue;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		car_queue.push(a);
	}
	stack<int> alley;
	int require = 1;
	while (!car_queue.empty()) {
		alley.push(car_queue.front());
		car_queue.pop();
		while (!alley.empty() && alley.top() == require) {
			require++;
			alley.pop();
		}
	}
	if (require == n+1){
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}
