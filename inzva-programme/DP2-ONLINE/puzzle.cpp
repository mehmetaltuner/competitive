#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
#define dbg(x) (cerr << #x << ":" << x << endl)
#define mid (l + r) / 2
#define fi first
#define sc second
#define N 1000000009

using namespace std;

typedef long long int lli;

lli n;
vector <lli> dp(45, 0);

lli perf(lli i){
	if(dp[i]) return dp[i];
    if(i == n){
        dp[i] = 1;
        return dp[i];
    }else if(i > n){
        return 0;
    }

    return dp[i] += perf(i+1) + perf(i+4);
}

int main(){
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
    	dp.assign(45, 0);
        lli res = 0;
        cin >> n;
        perf(0);
        
        vector <bool> prime(dp[0]+1, 0);

        //dbg(dp[0]);

        for (int p=2; p*p<=n; p++) 
    	{ 
        	// If prime[p] is not changed, then it is a prime 
        	if (prime[p] == true) { 
           		// Update all multiples of p 
            	for (int i=p*2; i<=n; i += p) 
                	prime[i] = false; 
        	} 
    	} 
  
	    for (int p=2; p<=n; p++) 
	       if (prime[p]) 
	          	res++;

        cout << res << endl;
    }

    return 0;
}