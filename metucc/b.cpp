#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define RALL(e) e.rbegin(), e.rend()
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
	lli l, n, t;
	double res = 1;

	cin >> l >> n;
	vector <double> v(n);


	for(int i=0; i<n; i++){
		cin >> v[i];
	}

	cin >> t;

	for(int i=0; i<n; i++){
		if(v[i] > 0){
			res *= (l - t*v[i] + 1) / l;
		}else if(v[i] < 0){
			res *= (-t*v[i] + 1) / l;
		}
	}

	cout << res;

	return 0;
}
