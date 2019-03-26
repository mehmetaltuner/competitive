// https://codeforces.com/problemset/problem/332/B
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

	vector <lli> ar(n+1);
	vector <lli> pre(n+1);
	
	for(int i=0; i<n; i++)
		cin >> ar[i];

	pre[0] = ar[0];

	for(int i=1; i<n; i++)
		pre[i] = pre[i-1] + ar[i];

	lli max_seg = INT_MIN;
	lli a = 0;
	for(int i=0; i<n-k; i+=k){
		if(pre[i+k]-pre[i]+ar[i] > max_seg){
			max_seg = pre[i+k]-pre[i]+ar[i];
			a = i;
		}
	}

	vector <lli> ar2, ar3;

	cout << "slem" << endl;

	for(int i=0; i<a; i++){
		ar2.pb(ar[i]);
	}

	for(int i=a+k+1; i<n; i++){
		ar3.pb(ar[i]);
	}

	cout << ar2.size() << endl;

	cout << "slem2" << endl;

	vector <lli> pre2(n+1);
	pre2[0] = ar2[0];

	for(int i=1; i<ar2.size(); i++){
		pre2[i] = pre2[i-1] + ar2[i];
	}

	lli max_seg2 = INT_MIN;
	for(int i=0; i<ar2.size()-k; i+=k){
		if(pre2[i+k]-pre[i]+ar[i] > max_seg2)
			max_seg2 = pre2[i+k]-pre[i]+ar[i];
	}

	cout << " selam 3"  << endl;

	vector <lli> pre3(n+1);
	pre3[0] = ar3[0];

	for(int i=1; i<ar3.size(); i++){
		pre3[i] = pre3[i-1] + ar3[i];
	}

	lli max_seg3 = INT_MIN;
	for(int i=0; i<ar3.size()-k; i+=k){
		if(pre2[i+k]-pre[i]+ar[i] > max_seg3)
			max_seg3 = pre2[i+k]-pre[i]+ar[i];
	}

	cout << max_seg + max(max_seg2, max_seg3);

	return 0;
}