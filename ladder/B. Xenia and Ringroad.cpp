//https://codeforces.com/problemset/problem/339/B

#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define mid (l + r) / 2
#define fi first
#define sc second
#define N 1000000009
#define cur at % n

using namespace std;

typedef long long int lli;

int main(){
	lli n, m;

	cin >> n >> m;

	lli at = 1;
	lli res = 0;

	while(m--){
		lli x;
		cin >> x;
		if(at > x){
			res += n - at + x;
		}else{
			res += x - at;
		}
		at = x;
	}

	cout << res;

	return 0;
}