#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	vector<int> rock(n);
	for(int i=0; i<n; ++i){
		scanf("%d", &rock[i]);
	}
	
	int sum=0;
	while(rock.size()!=0){
		sort(rock.begin(), rock.end());
		rock[0]+=rock[1];
		sum+=rock[0];
		rock.erase(rock.begin()+1);
	}
	
	printf("%d\n", sum);
	return 0;
}
