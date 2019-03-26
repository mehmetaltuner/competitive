// https://codeforces.com/problemset/problem/432/A

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

int main(){
	int n, m, r = 0;
	cin >> n >> m;

	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		if(x >= 5 - m)
			r++;
	}

	cout << r / 3;

	return 0;
}