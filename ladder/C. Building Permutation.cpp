//https://codeforces.com/problemset/problem/285/C
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
	int n;
	cin >> n;
	vector <lli> ar;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		ar.pb(x);
	}

	sort(ALL(ar));
	lli res = 0;

	for(int i=1; i<=n; i++){
		res += abs(i - ar[i-1]);
	}

	cout << res;

	return 0;
}