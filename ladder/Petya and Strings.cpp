// https://codeforces.com/problemset/problem/112/A

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
	string s1, s2;
	cin >> s1; 
	cin >> s2;

	for(int i=0; i<s1.length(); i++){
		int l1 = s1[i] - 'a';
		if(l1 < 0)
			l1 = s1[i] - 'A';

		int l2 = s2[i] - 'a';
		if(l2 < 0)
			l2 = s2[i] - 'A';

		if(l1 < l2){
			cout << -1;
			return 0;
		}else if(l2 < l1){
			cout << 1;
			return 0;
		}
	}

	cout << 0;

	return 0;
}
