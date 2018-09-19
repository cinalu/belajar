#include <bits/stdc++.h>
using namespace std;

int a[100005];

bool binser(int a[], int l, int r, int x){
	if(r>=l){
		int mid= (l+r)/2;
		if(a[mid]==x) return true;
		if(a[mid]<x) binser(a, mid+1, r, x);
		if(a[mid]>x) binser(a, l, mid-1, x);
	}
	return false;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		scanf("%d", &a[i]);
	}
	
	sort(a, a+n);
	
	int ada=0;
	for(int i=0; i<n; ++i){
		int val = 0;
		for(int j=0; j<32; ++j){
			long long x = (1ll<<j)-a[i];
			if(binser(a, 0, n-1, x)){
				++ada;
			}
		}
	}
	
	printf("%d", n-ada);
	
}