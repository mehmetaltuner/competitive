//https://codeforces.com/problemset/problem/214/A

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
	int n, m;
	cin >> n >> m;

	int rgt = m+n, res = 0;

	for(int a=0; a<=2000; a++){
		for(int b=0; b<=2000; b++){
			if(a*a + b == n and b*b + a == m)
				res++;
		}
	}

	cout << res;

	return 0;
}