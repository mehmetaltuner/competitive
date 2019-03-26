#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define mid (l + r) / 2
#define fi first
#define sc second
#define N 1000000009

using namespace std;

typedef long long int lli;

int func(int n){
	if(n % 2 == 0)
		return n/2;
	return n/2 + 1;
}

int main(){
	int n;
	cin >> n;

	vector <int> ar(n);
	int pos = 0, neg = 0;

	for(int i=0; i<n; i++){
		cin >> ar[i];
		if(ar[i] > 0)
			pos++;
		else if(ar[i] < 0)
			neg++;
	}

	int half = func(n);

	if(pos >= half){
		cout << 1;
	}else if(neg >= half){
		cout << -1;
	}else{
		cout << 0;
	}


	return 0;
}