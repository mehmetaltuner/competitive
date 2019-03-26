// https://codeforces.com/problemset/problem/230/A

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
	lli s, n;
	cin >> s >> n;

	for(int i=0; i<n; i++){
		lli x, y;
		cin >> x >> y;

		if(s < x){
			cout << "NO";
			return 0;
		}

		s += y;

	}

	cout << "YES";

	return 0;
}


// dp[x][k] += sum(dp[y][k-1])
// y -> 1-x
