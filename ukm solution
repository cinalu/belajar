#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

pair<LL,LL> egcd(LL a, LL b){	// extended euclidean algorithm to find multiplicative inverse
	if (a%b == 0){
		return pair<LL,LL>(0, 1);
	}
	pair<LL,LL> rec = egcd(b, a % b);
	pair<LL,LL> ret;
	ret.second = rec.first - (a / b) * rec.second;
	ret.first = rec.second;
	return ret;
}

int main(){
	LL n, k, m;
	scanf("%lld%lld%lld", &n, &k, &m);
	
	LL ans = 1;
	LL kfac = 1;
	for (int i = 0; i < k; i++) {
		ans = (ans * (n - i)) % m;
	}
	for (int i = 0; i < k; i++) {
		kfac = (kfac * (i + 1)) % m;
	}
	
	LL inv = egcd(kfac, m).first;
	inv = ((inv % m) + m ) % m;
	
	printf("%lld\n", (ans * inv) % m);
}

/*	penjelasan

jumlah cara milih ukm adalah (n)*(n-1)*(n-2)*...*(n-(k-1))
kita misalkan angka ini adalah B
ini bisa dihitung dalam O(k)

jumlah kombinasi pemilihan adalah permutasi dari k alias k!

tanda sama dengan maksudnya kongruen
maka jawaban adalah: ans * (k!) = B

tapi gaboleh sembarangan bagi klo bermain dalam modular arithmetic

untungnya soal menjamin bahwa gcd(k!, m) == 1

maka kita bisa cari multiplicative inverse
agar 		ans * (k!) = B
menjadi		ans * (k!) * inv = B * inv
menjadi		ans = B * inv

*/
