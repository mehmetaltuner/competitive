//https://codeforces.com/problemset/problem/230/B
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
	ios::sync_with_stdio(false);
	lli n = 1000006;

	bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (lli p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p 
            for (lli i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    }

    lli x;
    cin >> x;
    vector <lli> ar;
    vector <lli> car;
    map <lli, lli> mar; // val, index
    set <lli> res;
    
    for(lli i=0; i<x; i++){
    	lli a;
    	cin >> a;
    	ar.pb(a);
    	mar[a] = i;
    }

    car = ar;

    sort(ALL(ar));

    for(lli i=2; i<1000006; i++){
    	if(prime[i]){
    		auto it = lower_bound(ALL(ar), i*i);
    		if(it != ar.end()){
    			lli k = *it;
    			if(k != i*i) continue;
    			res.insert(k);
    		}
    	}
    }

    for(lli i=0; i<x; i++){
    	if(res.count(car[i]) >= 1)
    		cout << "YES" << endl;
    	else
    		cout << "NO" << endl; 
    }

	return 0;
}