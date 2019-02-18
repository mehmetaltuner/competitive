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
	lli n, m, k;
	scanf("%lli %lli %lli", &n, &m, &k);
	vector <lli> ar;
	for(int i=0; i<n; i++){
		lli x;
		scanf("%lli", &x);
		ar.push_back(x);
	}

	sort(ALL(ar), greater<lli>());

	lli max1 = ar[0], max2= ar[1];

	lli res = (m/(k+1)) * (k*max1 + max2) + (m%(k+1)) * max1;

	printf("%lli", res);

	return 0;
}