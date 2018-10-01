#include <bits/stdc++.h>
using namespace std;
int a[300005];
int b[300005];

bool check(int l1, int r1, int l2, int r2){
	if( r1-l1 != r2-l2)	return false;
	if( l1 == r1 ){
		return a[r1] == b[r2];
	}
	
	bool val = true;
	for(int i = 0; i <= r1-l1 && val; ++i){
		if(a[l1+i] != b[l2+i]) val = false;
	}
	
	
	if(val) return true;
	bool v1 = check(l1, l1+(r1-l1)/2, l2, l2+(r2-l2)/2); //a1 to b1
	bool v2 = check(l1+(r1-l1)/2+1, r1, l2+(r2-l2)/2+1, r2); //a2 to b2
	bool j1 = check(l1, l1+(r1-l1)/2, l2+(r2-l2)/2+1, r2); //a1 to b2
	bool j2 = check(l1+(r1-l1)/2+1, r1, l2, l2+(r2-l2)/2); // a2 to b1
	if( (v1 && v2) || (j1 && j2) ) return true;
	
	return false;
} 

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	
	for(int i = 0; i < n; ++i){
		scanf("%d", &b[i]);
	}
	
	check(0, n-1, 0, n-1) ? printf("EQ\n") : printf("NEQ\n");
}