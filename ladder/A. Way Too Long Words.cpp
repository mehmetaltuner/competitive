// https://codeforces.com/problemset/problem/71/A

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

	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		if(s.length() <= 10)
			cout << s << endl;
		else{
			cout << s[0] << s.length() - 2  << s[s.length()-1] << endl;
		}
	}

	return 0;
}