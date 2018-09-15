#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	priority_queue<int> pq;
	for(int i=0; i<n; ++i){
		int a;
		scanf("%d", &a);
		pq.push(-a);
	}
	
	int sum=0;
	while(pq.size()!=1){
		int tmp = -pq.top();
		pq.pop();
		tmp -= pq.top();
		pq.pop();
		sum += tmp;
		pq.push(-tmp);
	}
	
	printf("%d\n", sum);
	return 0;
}
