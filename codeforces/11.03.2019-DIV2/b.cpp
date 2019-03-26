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
	ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;

	if(n == 2){
		cout << 6;
		return 0;
	}

	if(k <= n / 2)
		cout << n*2 + 2 * (k-1) + n - k + 1;
	else 
		cout << n*2 + 2 * (n - k) + k;
	return 0;
}