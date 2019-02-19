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
	lli n;
	cin >> n;
	vector <lli> ar(n+5);
	lli esum = 0, osum = 0;

	vector <pair <lli, lli>> pre(n+5, pair <lli, lli>());

	for(int i=1; i<=n; i++){
		lli x;
		cin >> x;
		ar[i] = x;
		pre[i] = {esum, osum};
		if(i % 2 == 0){
			esum += x;
		}else{
			osum += x;
		}
	}

	lli res = 0;

	for(int i=1; i<=n; i++){
		lli nesum, nosum;
		if(i % 2 == 1){
			nesum = pre[i].first + (osum - pre[i].second - ar[i]);	
			nosum = pre[i].second + (esum - pre[i].first);
		}else{
			nesum = pre[i].first + (osum - pre[i].second);	
			nosum = pre[i].second + (esum - pre[i].first - ar[i]);
		}
		
		if(nesum == nosum){
			res++;
		}
		
	}

	cout << res;

	return 0;
}