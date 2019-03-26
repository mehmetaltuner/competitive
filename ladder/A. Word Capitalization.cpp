//https://codeforces.com/problemset/problem/281/A

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
	string s;
	cin >> s;
	if(s[0] - 'a' >= 0)
		s[0] = 'A' + s[0] - 'a';
	cout << s;
	return 0;
}