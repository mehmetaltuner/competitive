#include <bits/stdc++.h>
#define ALL(e) (e.begin(), e.end())
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define fi first
#define sc second
#define N 1000000009

typedef long long int lli;

using namespace std;

int main(int argc, char const *argv[])
{
	lli q;
	cin >> q;

	while(q--){
		lli n, a, b;
		cin >> n >> a >> b;
		lli res = 0;

		if(2*a >= b){
			res = (n/2)*b + ((n%2) * a);
		}else{
			res = n*a;
		}

		cout << res << endl;

	}

	return 0;
}