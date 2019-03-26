//https://codeforces.com/problemset/problem/217/A
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

lli parent[150];
pair <lli, lli> matrix[1500][1500];
vector <pair <lli ,lli>> nodes(150);
lli n;

void init(){
	for(lli i=0; i<n; i++)
		parent[i] = i;
}

lli find_parent(lli i){
	if(parent[i] == i){
		return i;
	}

	return parent[i] = find_parent(parent[i]);
}

void unite(lli a, lli b){
	lli pa = find_parent(a);
	lli pb = find_parent(b);

	parent[pa] = pb;
}

int main(){
	ios::sync_with_stdio(0);

	cin >> n;

	for(lli i=0; i<n; i++){
		lli a, b;
		cin >> a >> b;
		nodes[i] = {a, b};
		matrix[a][b].fi = 1;
		matrix[a][b].sc = i;
	}

	init();

	for(lli i=0; i<n; i++){
		pair <lli, lli> node = nodes[i];
		// unite its y axis neighbours
		for(lli j=1; j<=1000; j++){
			if(matrix[node.fi][j].fi){
				unite(matrix[node.fi][j].sc, i);
			}

			if(matrix[j][node.sc].fi){
				unite(matrix[j][node.sc].sc, i);
			}
		}
	}

	set <int> difpar;
	lli res = 0;

	for(lli i=0; i<n; i++){
		int par = find_parent(i);
		if(difpar.count(par) == 0){
			difpar.insert(par);
			res++;
		}
	}

	cout << res-1;

	return 0;
}