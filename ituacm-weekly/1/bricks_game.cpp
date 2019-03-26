#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define mid (l + r) / 2
#define fi first
#define sc second
#define N 1000009

using namespace std;

typedef long long int lli;

vector <lli> dp(N, 0);
vector <lli> ar(N, 0);
lli n;

int main(){
	int t;
	cin >> t;
	while(t--){
		dp.assign(N, 0);
		cin >> n;

		for(int i=1; i<=n; i++){
			cin >> ar[i];
		} 

		vector <lli> sum(n+5, 0);
		for(int i=n; i>=1; i--){
			sum[i] = ar[i] + sum[i+1];
		}


		//cout << endl;
		//cout << sum[1] << endl;

		dp[n] = sum[n];
		dp[n-1] = sum[n-1];
		dp[n-2] = sum[n-2];

		//cout << n << " : " << dp[n] << endl;
		//cout << n-1 << " : " << dp[n-1] << endl;
		//cout << n-2 << " : " << dp[n-2] << endl;

		for(int i=n-3; i>=1; i--){
			dp[i] = max({
				ar[i] + sum[i+1] - dp[i+1],
				ar[i] + ar[i+1] + sum[i+2] - dp[i+2],
				ar[i] + ar[i+1] + ar[i+2] + sum[i+3] - dp[i+3]
				});
			//cout << i << " : " << dp[i] << endl;
		}

		cout << dp[1] << endl;

	}
	return 0;
}