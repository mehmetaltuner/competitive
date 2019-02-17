#include <bits/stdc++.h>
#define ALL(e) (e.begin(), e.end())
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define fi first
#define sc second
#define N 1000000009

using namespace std;

typedef long long int lli;

int main(int argc, char const *argv[])
{
	lli n, s=0;
	cin >> n;
	vector <lli> ar;
	for(int i=0; i<n; i++){
		lli x;
		cin >> x;
		ar.push_back(x);
		s += x;
	}

	sort(ar.begin(), ar.end(), greater<lli>());

	lli res = s;

	for(int i=0; i<n-1; i++){
		for(int j=2; j<ar[i]; j++){
			if(ar[i] % j == 0){
				res = min(res, 
				s - (ar[i] + ar[n-1]) + ((ar[i]/j) + ar[n-1] * j));
			}
		}
	}

	cout << res;

	return 0;
}