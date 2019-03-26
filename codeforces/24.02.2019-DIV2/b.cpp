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
	lli n;
	scanf("%lld", &n);

	vector <vector<lli>> ar(n+5, vector <lli>(2, 0)); // first index, second index


	for(int i=1; i<=2*n; i++){
		lli x;
		scanf("%lld", &x);

		if(ar[x][0] == 0){
			ar[x][0] = i;
		}else{
			ar[x][1] = i;
		}
	}

	lli res = 0;
	lli d = 1;
	lli s = 1;

	for(int i=1; i<=n; i++){
		res += abs(ar[i][0] - d);
		res += abs(ar[i][1] - s); 
		d = ar[i][0];
		s = ar[i][1];
	}

	printf("%lld\n", res);


	return 0;
}