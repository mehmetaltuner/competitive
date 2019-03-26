//https://codeforces.com/problemset/problem/337/A
#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define RALL(e) e.rbegin(), e.rend()
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
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;

	vector <int> ar(n+m+50, INT_MAX/2);

	for(int i=0; i<m; i++){
		int x;
		cin >> x;
		ar.pb(x);
	}

	sort(ALL(ar));
	int res = INT_MAX;

	for(int i=0; i<m; i++){
		res = min(res, ar[i+n-1]-ar[i]);
	}

	cout << res;

	return 0;
}