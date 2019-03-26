// https://codeforces.com/problemset/problem/263/A

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
	for(int i=1; i<=5; i++){
		for(int j=1; j<=5; j++){
			int x; cin >> x;
			if(x){
				cout << abs(3 - i) + abs(3 - j);
			}
		}
	}
	return 0;
}