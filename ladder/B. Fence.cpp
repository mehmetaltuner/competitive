//https://codeforces.com/problemset/problem/363/B
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
	int n, k;
	cin >> n >> k;

	vector <lli> ar(n+k+1, 0);
	vector <lli> pre(n+k+1, 0);

	for(int i=1; i<=n; i++){
		cin >> ar[i];
		pre[i] = pre[i-1] + ar[i];
	}

	lli res = INT_MAX;
	int index = 1;
	for(int i=1; i<=n-k+1; i++){
		if(pre[i+k-1] - pre[i-1] <= res){
			res = pre[i+k-1] - pre[i-1];
			index = i;
		}
	}

	cout << index;

	return 0;
}