#include <bits/stdc++.h>
using namespace std;

int compare(string a, string b){
	string ab=a.append(b);
	string ba=b.append(a);
	return (int)ab.compare(ba)>0;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	vector<string> num(n);
	int nn=n;
	while(nn--){
		string numm;
		cin>>numm;
		num.push_back(numm);
	}
	
	sort(num.begin(), num.end(), compare);
	//note: klo mau print out vector of strings use iterators(not c++11)
	vector<string>::iterator it;
	for(it = num.begin(); it != num.end(); ++it) {
    	cout << *it;
	}printf("\n");

	
}
