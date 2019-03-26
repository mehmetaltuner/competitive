// https://codeforces.com/problemset/problem/189/A
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

int n, a, b, c;
vector <lli> dp(5000, INT_MIN);

int main(){
	ios::sync_with_stdio(0);

	cin >> n >> a >> b >> c;
		
	dp[0] = 0;
	for(int i=a; i<=n; i++) dp[i] = max(dp[i], dp[i-a]+1);
	for(int i=b; i<=n; i++) dp[i] = max(dp[i], dp[i-b]+1);
	for(int i=c; i<=n; i++) dp[i] = max(dp[i], dp[i-c]+1);

	cout << dp[n];
	
	return 0;
}