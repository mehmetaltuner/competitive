#include <bits/stdc++.h>
#define ALL(e) (e.begin(), e.end())
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define fi first
#define sc second
#define N 1000000009

using namespace std;

int res, v, n;

int main(int argc, char const *argv[])
{
	cin >> n >> v;
	res = INT_MAX/2;

	if(v >= n-1){
		cout << n-1;
		return 0;
	}

	res = v;

	for(int i=2; i<=n-v; i++){
		res += i;
	}

	cout << res;

	return 0;
}