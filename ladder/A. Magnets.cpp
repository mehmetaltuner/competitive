// https://codeforces.com/problemset/problem/344/A

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
	int n, r = 0;
	cin >> n;

	int latest;
	cin >> latest;

	for(int i=1; i<n; i++){
		int x;
		cin >> x;
		if(x != latest){
			r++;
		}
		latest = x;
	}

	cout << r + 1;

	return 0;
}