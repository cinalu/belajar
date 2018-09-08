#include <bits/stdc++.h>
using namespace std;
//note to self
//8/9/18
//tugas prd blm selesai, jgn koding dulu :(((
int main(int argc, char const *argv[])
{
	int n;
	int compartments[5]={0};
	int ans=0;
	
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		int peeps;
		scanf("%d", &peeps);
		++compartments[peeps];
	}
	
	int c123=min(compartments[1], compartments[2]); //either 1+2 -> 3 or 2+1 ->3
	compartments[3] += c123;
	compartments[1] -= c123;
	compartments[2] -= c123;
	
	//2-2 biar salah satu jadi 3
	compartments[3] += 2*(compartments[2]/3);
	int c223 = 2*(compartments[2]/3);
	compartments[2] %= 3;
	
	//1-1 ampe 3
	compartments[3] += compartments[1]/3;
	int c113 = 2*(compartments[1]/3);
	compartments[1] %= 3;
	
	int c134=0;
	int c112=0;
	if(compartments[1]<=compartments[3]){
		c134=compartments[1];
		compartments[1]=0;
	}else{
		//1-1 jadi 2
		compartments[2] += compartments[1]/2;
		c112 = compartments[1]/2;
		compartments[1] %= 2;
	}
	
	int c413=0;
	if(compartments[1]){
		//4 - 1 jadi 3
		if(compartments[4]>=2*compartments[1]){
			c413 = 2*compartments[1];
		}else{
			ans=-1;
			printf("%d\n", ans);
			return 0;
		}
	}
	
	else if(compartments[2]){
		if(compartments[2]==2) ans+=2;
		else if(compartments[2]==1){
			if(compartments[4]) ++ans;
			else if(compartments[3]>=compartments[2]) ans += 2;
			else{
				ans=-1;
				printf("%d\n", ans);
				return 0;
			}
		}
	}
	
	ans = c123+c223+c113+c134+c112+c413;
	printf("%d\n", ans);
	return 0;
}
