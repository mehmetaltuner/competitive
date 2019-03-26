//https://codeforces.com/problemset/problem/277/A
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

int parent[300];

int find_parent(int i){
	if(parent[i] == i)
		return i;

	return parent[i] = find_parent(parent[i]);
}

void unite(int a, int b){
	int pa = find_parent(a);
	int pb = find_parent(b);

	parent[pa] = pb;
}

int main(){
	ios::sync_with_stdio(0);
	int n, m, cahiller=0;

	cin >> n >> m;

	vector <vector <bool>> people(n+5, vector <bool>(m+5, 0));

	for(int i=0; i<n; i++) parent[i] = i;

	for(int i=0; i<n; i++){
		int k;
		cin >> k;

		if(!k)
			cahiller++;

		for(int j=0; j<k; j++){
			int l;
			cin >> l;
			people[i][l] = 1;
		}

	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i == j) continue;

			for(int l=1; l<=m; l++){
				if(people[i][l] and people[j][l])
					unite(i, j);
			}
		}
	}

	int dif_people = 0;
	set <int> dif_set;

	for(int i=0; i<n; i++){
		int p = find_parent(i);
		//cerr << p << endl;
		if(dif_set.count(p) == 0){
			dif_set.insert(p);
			dif_people++;
		}
	}

	if(cahiller == n){
		cout << cahiller;
	}else
		cout << dif_people-1;

	return 0;
}