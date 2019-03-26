// https://codeforces.com/problemset/problem/320/B

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

vector <pair <int, int>> inter(1000);
map <pair <int, int>, vector <pair <int, int>>> adj;
map <pair <int, int>, bool> visited;

bool dfs(pair <int, int> n1, pair <int, int> n2){
	if(visited[n1])
		return false;

	visited[n1] = true;

	if(n1 == n2)
		return true;

	for(auto c: adj[n1]){
		if(dfs(c, n2))
			return true;
	}

	return false;
}

void free_visited(){
	for(auto it=visited.begin(); it!=visited.end(); it++){
		it->second = false;
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);
	int n, inter_counter = 0;
	cin >> n;

	for(int i=0; i<n; i++){
		lli c, a, b;
		cin >> c >> a >> b;
		if(c == 1){
			inter[++inter_counter] = mp(a, b);
			
			if(adj.find(mp(a, b)) == adj.end()){
				adj[mp(a, b)] = vector <pair <int, int>>();
				visited[mp(a, b)] = false;
			}

			for(int j=1; j<inter_counter; j++){
				pair <int, int> i = inter[j];
				if(adj.find(i) == adj.end()){
					adj[i] = vector <pair <int, int>>();
					visited[i] = false;
				}
				
				if(i.first < a and a < i.second){
					//cerr << "bindinga " << a << ", " << b << " to " << i.fi << ", " << i.sc << endl;
					adj[mp(a, b)].pb(i);
				}
				if(i.first < b and b < i.second){
					//cerr << "bindingb " << a << ", " << b << " to " << i.fi << ", " << i.sc << endl;
					adj[mp(a, b)].pb(i);
				}
				if(a < i.first and i.first < b){
					//cerr << "bindingc " << a << ", " << b << " to " << i.fi << ", " << i.sc << endl;
					adj[i].pb(mp(a, b));
				}
				if(a < i.second and i.second < b){
					//cerr << "bindingd " << a << ", " << b << " to " << i.fi << ", " << i.sc << endl;
					adj[i].pb(mp(a, b));
					
				}
			}
		}else{
			free_visited();
			if(dfs(inter[a], inter[b]))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	return 0;
}