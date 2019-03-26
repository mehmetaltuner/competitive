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
bool flag[1000][1000];
int mat1[1000][1000];
int mat2[1000][1000];

int main(){
	ios::sync_with_stdio(0);


	int n, m;
	cin >> n >> m;

	int s = min(n, m);




	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> mat1[i][j];
		}
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> mat2[i][j];
		}
	}


	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			
			bool ok = false;
			for(int k=max(0, i-s); k<=min(n,i+s); k++){
				for(int a=max(0, j-s); a<=min(m, j+s); j++){
					if(mat2[k][a] == mat1[i][j] and !flag[k][a]){
						ok = true;
						flag[k][a] = true;
						break;
					}
				}
			}
			if(!ok){
				cout << "NO";
				return 0;
			}
		}
	}

	if(mat1[1][1] == mat2[1][1] and mat1[n][m] == mat2[n][m])
		cout << "YES";
	else cout << "NO";
	
		

	return 0;
}