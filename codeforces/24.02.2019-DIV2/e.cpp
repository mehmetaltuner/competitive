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
	int n, m;
	cin >> n >> m;

	vector <vector <int>> sta(n+1);

	for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;
		sta[x].pb(y);
	}

	int res = 0;

	for(int i=1; i<=n; i++){
		int delivered = 0;
		int at = i;
		vector <int> carrying(m+1, 0);
		while(delivered < m){
			if(carrying[at]){
				delivered += carrying[at];
				carrying[at] = 0;
			}

			auto take = upper_bound(sta[i].begin(), 
				sta[i].end(), i);

			carrying[sta[i].begin() + take]

		}		
	}	

	return 0;
}