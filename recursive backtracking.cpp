#include<bits/stdc++.h>

#define BETWEEN(x, y, z) (x > y && x < z)
typedef long long int LL;

using namespace std;

int vis[101][101];
char grid[101][101];
char check [7] = "BANANA";

int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

LL ans;
int r, c;

void serc(int x, int y, int p) {
	if (p == 6) {
		ans++;
		return;
	}
	
	for (int i = 0; i < 8; i++) {
		if (BETWEEN(x + dr[i], -1, r) && BETWEEN(y + dc[i], -1, c) &&
			vis[x + dr[i]][y + dc[i]] == 0 && grid[x + dr[i]][y + dc[i]] == check[p]) {
			vis[x + dr[i]][y + dc[i]] = 1;
			serc(x + dr[i], y + dc[i], p + 1);
			vis[x + dr[i]][y + dc[i]] = 0;
		}
	}
	return;
	
}
int main() {
	scanf("%d%d", &r, &c);
	
	for (int i = 0; i < r; i++) {
		scanf("%s", grid[i]);
	}
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (grid[i][j] == 'B') {
				vis[i][j] = 1;
				serc(i, j, 1);
				vis[i][j] = 0;
			}
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
