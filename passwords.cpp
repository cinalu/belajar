#include <bits/stdc++.h>
#include <string>
#define mp make_pair
#define pb push_back
#define ll long long
using namespace std;

string s[105], dig[10];
string ans,rule;

void generate(int cur){
	if(cur==rule.size()){
		cout<<ans<<"\n";
		return;
	}
	
	if(rule[cur]=='#'){
		for(int i = 0; i < sizeof(s); i++){
			// if(!visStr[i]){
				// visStr[i] = 1;
				ans += s[i];
				generate(cur+1);
				// visStr[i] = 0;
				// ans = ans.substr(0,ans.size()-s[i].size());
			// }
		}
	}
	else{
		for(int i = 0; i < sizeof(dig); i++){
			// if(!visDig[i]){
				// visDig[i] = 1;
				ans += dig[i];
				generate(cur+1);
				// visDig[i] = 0;
				// ans = ans.substr(0, ans.size()-1);
			// }
		}
	}
}

int main(){
	int n, r;
	for(int i = 0; i < 10; i++){
		dig[i] = i;
	}
	
	while(cin>>n){
		// memset(visDig, 0, sizeof(visDig));
		// memset(visStr, 0, sizeof(visStr));
		
		for(int i = 0; i < n; i++) cin>>s[i];
		
		cout<<"--\n";
		cin>>r;
		while(r--){
			cin>>rule;
			ans = "";
			generate(0);
		}
				
	}
}
