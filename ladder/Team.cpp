// https://codeforces.com/problemset/problem/231/A

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
	int n, r = 0;
	cin >> n;

	vector <vector <int>> ar(3, vector <int>(n, 0));

	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			int x;
			cin >> x;
			ar[j][i] = x;
		}
	}	 

	for(int i=0; i<n; i++){
		int sure = 0;
		for(int j=0; j<3; j++){
			sure += ar[j][i];
		}

		if(sure >= 2)
			r++;
	}

	cout << r;

	return 0;
}