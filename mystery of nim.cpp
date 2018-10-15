#include<bits/stdc++.h>
using namespace std;
vector<int> lis[26];
int vis[26];
int deg[26];
char str[101][101];
int val;
queue<char>ans;
void dfs(int x, int iter) {
	vis[x] = iter;
	for (int i = 0; i < lis[x].size(); i++) {
		if (vis[lis[x][i]] == 0) {
			dfs(lis[x][i], iter);
		}
		else if (vis[lis[x][i]] == iter) {
			val = 0;
			break;
		}
	}
	ans.push(x + 'a');
	return;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			str[i][j] = '\0';
		}
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}
	for (int i = 1; i < n; i++) {
		int l = min(strlen(str[i]), strlen(str[i-1]));
		int a = -1, b;
		for (int j = 0; j < l; j++) {
			if (str[i][j] != str[i-1][j]) {
				a = str[i][j] - 'a';
				b = str[i - 1][j] - 'a';
				break;
			}
		}
		if (a != -1) {
			lis[a].push_back(b);
		}
	}
	val = 1;
	int iter = 1;
	for (int i = 0; i < 26; i++) {
		if (deg[i] == 0 && vis[i] == 0) {
			dfs(i, iter);
			iter++;
		}
	}
	if (val) {
		while (!ans.empty()) {
			printf("%c", ans.front());
			ans.pop();
		}
		printf("\n");
	}
	else {
		printf("Impossible\n");
	}
	return 0;
}
