#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define fi first
#define sc second
#define N 1000000009

typedef long long int lli;

using namespace std;

int main(int argc, char const *argv[])
{
	lli n;
	scanf("%lli", &n);
	vector <lli> ar;
	lli maxn=LLONG_MIN;

	for(lli i=0; i<n; i++){
		lli x;
		scanf("%lli", &x);
		ar.push_back(x);
		maxn = max(maxn, x);
	}

	lli res = 1;
	lli counter = 1;

	for(lli i=1; i<n; i++){
		if(ar[i] == maxn){
			if(ar[i] == ar[i-1]){
				counter++;
			}
		}else if(ar[i-1] == maxn){
			res = max(counter, res);
			counter = 1;
		}
	}

	if(ar[n-1] == maxn){
		res = max(res, counter);
	}


	printf("%lli", res);


	return 0;
}