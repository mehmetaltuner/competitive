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

int parent[1000];

int find_parent(int a, vector <bool> &vis, int before=0){
	//cout << (char)a << endl;
	if(parent[a] == a)
		return a;

	if(vis[a])
		return a;

	vis[a] = 1;

	return find_parent(parent[a], vis, a);
}

void unite(int a, int b){
	vector <bool> vis(1000, 0);
	int par1 = find_parent(a, vis);
	int par2 = b;
	
	parent[par1] = par2;
}

int main(){
	ios::sync_with_stdio(0);

	for(int i=0; i<1000; i++) parent[i] = i;

	string s;
	getline(cin, s);

	vector <pair <char, char>> q;

	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		char a, b;
		cin >> a >> b;
		q.pb({a, b});
	}

	vector <bool> proc(1000, 0);

	for(int i=n-1; i>=0; i--){
		//cout << q[i].sc << q[i].fi;
		if(!proc[q[i].sc]){
			unite(q[i].sc, q[i].fi);
			proc[q[i].sc] = 1;
		}
	}


	for(int i=0; i<s.size(); i++){
		vector <bool> visited(1000, 0);
		cout << (char)find_parent((int)s[i], visited);
	}

	return 0;
}
