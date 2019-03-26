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

	bool matrix[n+100][n+100];
	vector <vector <lli>> adj(n+100);
	bool ex[n+100];
	
	memset(matrix, 1, sizeof(matrix));
	memset(ex, 0, sizeof(ex));

	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;

		matrix[a][b] = 0;
		matrix[b][a] = 0;
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i == j) continue;

			if(matrix[i][j]){
				adj[i].pb(j);
				adj[j].pb(i);
				ex[i] = 1;
				ex[j] = 1;
 			}
		}
	}

	vector <bool> visited(n+100, false);
	queue <pair <lli, lli>> q;
	vector <lli> color(n+100, -1);

	for(int i=1; i<=n; i++){
		if(ex[i]){
			ex[i] = 0;
			q.push({i, 1});

			while(!q.empty()){
				lli node = q.front().fi, c = q.front().sc; 
				q.pop();

				for(auto chi: adj[node]){
					if(visited[chi]) continue;
					visited[chi] = 1;

					color[chi] = 1-c;
					q.push({chi, 1-c});
				}
			}

			for(int j=1; j<=n; j++){
				for(auto chi: adj[j]){
					if(color[j] == color[chi]){
						cout << "NO";
						return 0;
					}
				}
			}
		}
	}

	string s;


	for(int i=1; i<=n; i++){

		if(color[i] == -1)
			s.append("b");
		else if(color[i] == 1)
			s.append("a");
		else if(color[i] == 0)
			s.append("c");
	}

	for(int i=0; i<s.size(); i++){
		for(int j=0; j<s.size(); j++){
			if(i == j) continue;

			if(!matrix[i+1][j+1]){
				if(s[i] == 'a'){
					if(s[j] == 'c'){
						cout << "NO";
						return 0;
					}
				}else if(s[i] == 'c'){
					if(s[j] == 'a'){
						cout << "NO";
						return 0;
					}
				}
			}
		}
	}

	cout << "YES" << endl << s;


	return 0;
}