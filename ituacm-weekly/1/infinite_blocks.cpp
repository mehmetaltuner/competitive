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

lli n;
lli grev;
vector <lli> ar(50004);
lli dp[50004][50004]; // dp[x][y] sells y amount of stock at x
// buys if y is 0

void profit(lli i, bool b, lli rev, lli stocks){
	if(i > n){
		grev = max(grev, rev);
		return;
	}

	if(b){
		rev -= ar[i];
		stocks++;
		profit(i+1, 1, rev, stocks);
		profit(i+1, 0, rev, stocks);
	}else{
		for(int s=1; s<=stocks; s++){
			rev += stocks * ar[i];
			stocks -= s;
			profit(i+1, 1, rev, stocks);
			profit(i+1, 0, rev, stocks);
		}
	}

}

int main(){
	ios::sync_with_stdio(0);
	cin >> n;

	for(int i=0; i<n; i++) cin >> ar[i];

	cout << grev << endl;


	return 0;
}