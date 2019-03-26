//https://codeforces.com/problemset/problem/295/B
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

lli adj[511][511];
bool deleted[511];
int n;
lli res;

int main(){
	ios::sync_with_stdio(0);

	cin >> n;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> adj[i][j];
		}
	}

	vector <int> q(n+1);
	vector <lli> rv;

	for(int i=1; i<=n; i++){
		cin >> q[i];
	}

	memset(deleted, 1, sizeof(deleted));
	
	for (int t = n; t >= 1; t--) {
		deleted[q[t]] = 0;
		int k = q[t];
		res = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {

				adj[i][j] = min(adj[i][j],
					adj[i][k]+adj[k][j]);

				if(deleted[i] or deleted[j])
					continue;

				res += adj[i][j];
			}
		}
		rv.pb(res);
	}

	for(int i=n-1; i>=0; i--)
		cout << rv[i] << " ";

	return 0;
}