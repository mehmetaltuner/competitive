// https://www.spoj.com/problems/SMILEY1807/

#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define mid (l + r) / 2
#define fi first
#define sc second
#define N 1000006

using namespace std;

typedef long long int lli;

//int dp[N][8];
vector <int> dp(8, 0);

int main(){
	string s;
	cin >> s;
	int n = s.length();

	for(int i=0; i<n; i++){
		int digit = s[i] - '0';
		if(digit == 1){
			dp[1]++;
		}else if(digit == 8){
			if(dp[8] or dp[1])
				dp[8] = max(dp[1], dp[8]) + 1;
		}else if(digit == 0){
			if(dp[0] or dp[8])
				dp[0] = max(dp[8], dp[0]) + 1;
		}else if(digit == 7){	
			if(dp[7] or dp[0])
				dp[7] = max(dp[0], dp[7]) + 1;
		}
	}

	cout << dp[7];

	return 0;
}