// vhttps://codeforces.com/problemset/problem/318/A

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
	lli n, k;
	cin >> n >> k;

	lli half = (n+1) / 2;

	if(k <= half){
		cout << 2*(k-1) + 1;
	}else{
		k-=half;
		cout << 2*(k);
	}

	return 0;
}
