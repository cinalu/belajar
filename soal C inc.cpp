#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int N = 100005;
LL tree[N*4];
vector<int> lis[N];
int par[18][N];
int cpar[N];
int W[N];
int vis[N];
int ntot[N];
int idx;
int depth[N];
int n, q;
void update(int k, int l, int r, int p, LL v) {
	if (l > p || r < p) return;
	if (l == r) {
		tree[k] += v;
		return;
	}
	else {
		update(k*2, l, (l+r)/2, p, v);
		update(k*2+1, (l+r)/2+1, r, p, v);
		tree[k] = tree[k*2] + tree[k*2+1];
	}
}
LL query(int k, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) {
		return tree[k];
	}
	else if (l > qr || r < ql) {
		return 0;
	}
	return query(k*2, l, (l+r)/2, ql, qr) + query(k*2+1, (l+r)/2+1, r, ql, qr);
}
void cleart(int k, int l, int r) {
	if (l == r) {
		tree[k] = 0;
		return;
	}
	else {
		cleart(k*2, l, (l+r)/2);
		cleart(k*2+1, (l+r)/2+1, r);
		tree[k] = 0;
	}
}
int dfs1(int x, int p, int d){
	vis[x] = 1;
	depth[x] = d;
	par[0][x] = p;
	W[x] = 1;
	for (int i = 0; i < lis[x].size(); i++) {
		if (vis[lis[x][i]] == 0)
			W[x] += dfs1(lis[x][i], x, d+1);
	}
	return W[x];
}
int dfs2(int x, int chainpar){
	vis[x] = 1;
	ntot[x] = idx++;
	cpar[x] = chainpar;
	int maxi = -1;
	for (int i = 0; i < lis[x].size(); i++) {
		if (vis[lis[x][i]] == 0)
			if (maxi == -1 || W[maxi] < W[lis[x][i]])
				maxi = lis[x][i];
	}
	if (maxi != -1){
		dfs2(maxi, chainpar);
	}
	for (int i = 0; i < lis[x].size(); i++) {
		if (vis[lis[x][i]] == 0 && lis[x][i] != maxi)
			dfs2(lis[x][i], lis[x][i]);
	}
}
int getord(int x){
	int ret = 0;
	while ((1<<ret) < x) {
		ret++;
	}
	return ret;
}
void buildlca(int n){
	int p = getord(n);
	for (int i = 1; i <= p; i++) {
		for (int j = 1; j <= n; j++) {
			par[i][j] = par[i-1][par[i-1][j]];
		}
	}
}
int getlca(int a, int b, int p){
	if (depth[a] < depth[b]){
		int tmp = b;
		b = a;
		a = tmp;
	}
	int delta = depth[a]-depth[b];
	for (int i = 0; i <= p; i++) {
		if ((delta&(1<<i))>0){
			a = par[i][a];
		}
	}
	if (a == b)return a;
	for (int i = p; i >= 0; i--) {
		if (par[i][a] != par[i][b]){
			a = par[i][a];
			b = par[i][b];
		}
	}
	return par[0][a];
}
LL queryhld(int a, int b){
	if (cpar[a] == cpar[b]){
		return query(1, 0, idx-1, ntot[a], ntot[b]);
	}
	else{
		return query(1, 0, idx-1, ntot[cpar[b]], ntot[b]) + queryhld(a, par[0][cpar[b]]);
	}
}
struct dat {
	int boy, girl, l, r, id;
	bool operator<(const dat& a){
		return r < a.r;
	}
};
struct dat2 {
	int boy, girl, l, r, id;
	bool operator<(const dat2& a){
		return l < a.l;
	}
};
vector<dat> bigger;
vector<dat2> smaller;
vector<pair<int,int> >sav;
void read1(){
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) {
		pair<int,int> rea;
		scanf("%d", &rea.first);
		rea.second = i + 1;
		sav.push_back(rea);
	}
	sort(sav.begin(), sav.end());
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		lis[a].push_back(b);
		lis[b].push_back(a);
	}
}
void read2(){
	dat dum;
	dat2 dum2;
	for (int i = 0; i < q; i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		dum.boy = a; dum.girl = b; dum.l = c; dum.r = d; dum.id = i;
		dum2.boy = a; dum2.girl = b; dum2.l = c; dum2.r = d; dum2.id = i;
		bigger.push_back(dum);
		smaller.push_back(dum2);
	}
	sort(bigger.begin(), bigger.end());
	sort(smaller.begin(), smaller.end());
}
void resetg(int n){
	for (int i = 0; i <= n; i++) {
		vis[i] = 0;
	}
}
LL ans[N];
LL ans2[N];
void goblog1(){
	int j = 0;
	int p = getord(n);
	for (int i = 0; i < n;) {
		if (j == q){
			i++;
			continue;
		}
		while (i < n) {
			if (i == n || sav[i].first > bigger[j].r) break;
			update(1, 0, idx-1, ntot[sav[i].second], sav[i].first);
			i++;
		}
		while (j < q && bigger[j].r < sav[i].first) {
			int anc = getlca(bigger[j].girl, bigger[j].boy, p);
			LL satu = queryhld(anc, bigger[j].girl);
			LL dua = queryhld(anc, bigger[j].boy);
			ans[bigger[j].id] = satu + dua - query(1, 0, idx-1, ntot[anc], ntot[anc]);
			j++;
		}
	}
	while (j < q) {
		int anc = getlca(bigger[j].girl, bigger[j].boy, p);
		ans[bigger[j].id] = queryhld(anc, bigger[j].girl) +
							queryhld(anc, bigger[j].boy) -
							query(1, 0, idx-1, ntot[anc], ntot[anc]);
		j++;
	}
}
void goblog2(){
	int j = 0;
	int p = getord(n);
	for (int i = 0; i < n;) {
		if (j == q){
			i++;
			continue;
		}
		while (i < n) {
			if (i == n || sav[i].first > smaller[j].l-1) break;
			update(1, 0, idx-1, ntot[sav[i].second], sav[i].first);
			i++;
		}
		while (j < q && smaller[j].l-1 < sav[i].first) {
			int anc = getlca(smaller[j].girl, smaller[j].boy, p);
			LL satu = queryhld(anc, smaller[j].girl);
			LL dua = queryhld(anc, smaller[j].boy);
			ans2[smaller[j].id] = satu + dua - query(1, 0, idx-1, ntot[anc], ntot[anc]);
			j++;
		}
	}
	while (j < q) {
		int anc = getlca(smaller[j].girl, smaller[j].boy, p);
		ans2[smaller[j].id] = queryhld(anc, smaller[j].girl) +
							queryhld(anc, smaller[j].boy) -
							query(1, 0, idx-1, ntot[anc], ntot[anc]);
		j++;
	}
}
int main(){
	read1();
	read2();
	dfs1(1, 1, 0);
	resetg(n);
	dfs2(1, 1);
	buildlca(n);
	goblog1();
	cleart(1, 0, idx-1);
	goblog2();
	for (int i = 0; i < q; i++) {
		printf("%lld\n", ans[i] - ans2[i]);
	}
	return 0;
}
