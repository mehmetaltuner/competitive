//https://codeforces.com/problemset/problem/129/B

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
	ios::sync_with_stdio(0);

	vector <vector <int>> adj(150);
	vector <int> edges(101, 0);
	vector <int> cedges(101, 0);


	int n, m, res = 0;
	cin >> n >> m;

	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);

		edges[a]++; edges[b]++;
	}

	cedges = edges;

	while(true){
		bool removed = false;
		for(int i=1; i<=n; i++){
			if(edges[i]==1){
				cedges[i] = 0;
				removed = true;
				cerr << i << " slm " << endl; 
				for(int chi: adj[i]){
					cedges[chi]--;
				}
			}
		}
		edges = cedges;
		if(!removed){
			break;
		}
		res++;
	}

	cout << res;

	return 0;
}