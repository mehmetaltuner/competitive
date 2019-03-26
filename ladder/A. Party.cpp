//https://codeforces.com/problemset/problem/115/A
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

vector <vector <int>> adj(2005);
vector <bool> visited(2005, 0);
int res;

void dfs(int i, int pcolor){
	if(visited[i])
		return;
	visited[i] = true;

	for(int chi: adj[i]){
		dfs(chi, pcolor+1);
	}	
	res = max(pcolor, res);
}

int main(){
	ios::sync_with_stdio(0);
	int n;
	vector <int> roots;
	cin >> n;

	for(int i=1; i<=n; i++){
		int x;
		cin >> x;
		if(x != -1){
			adj[x].pb(i);
		}else
			roots.pb(i);
	}

	for(auto r: roots)
		dfs(r, 1);

	cout << res;

	return 0;
}