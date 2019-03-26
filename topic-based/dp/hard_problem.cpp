// https://codeforces.com/problemset/problem/706/C

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
	int n;
	ios::sync_with_stdio(0);

	cin >> n;
	vector <lli> cost(n+5);

	for(int i=0; i<n; i++)
		cin >> cost[i];

	vector <string> ar(n+5);
	vector <string> rar(n+5);

	for(int i=0; i<n; i++){
		cin >> ar[i];
		rar[i] = ar[i];
		reverse(rar[i].begin(), rar[i].end());
	}

	vector <vector <lli>> dp(2, vector <lli>(n+5, LLONG_MAX/2));

	dp[0][0] = 0;
	dp[1][0] = cost[0];

	for(int i=1; i<n; i++){

		if(ar[i] >= ar[i-1]){ // normal
			dp[0][i] = min(dp[0][i], dp[0][i-1]);
		}
		if(ar[i] >= rar[i-1]){ // normal
			dp[0][i] = min(dp[0][i], dp[1][i-1]);
		}

		if(rar[i] >= ar[i-1]){ // normal
			dp[1][i] = min(dp[1][i], dp[0][i-1] + cost[i]);
		}

		if(rar[i] >= rar[i-1]){ // normal
			dp[1][i] = min(dp[1][i], dp[1][i-1]  + cost[i] );
		}

		if(dp[0][i] == dp[1][i] and dp[1][i] == LLONG_MAX/2){

			cout << -1;
			return 0;
		}
	}

	cout << min(dp[0][n-1], dp[1][n-1]) << endl;
 

	return 0;
}