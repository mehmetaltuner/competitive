// https://codeforces.com/problemset/problem/69/A
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
	cin >> n;

	int x = 0, y = 0, z=0;

	for(int i=0; i<n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		x += a; 
		y += b;
		z += c;
	}

	if(x == 0 and y == 0 and z == 0)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}