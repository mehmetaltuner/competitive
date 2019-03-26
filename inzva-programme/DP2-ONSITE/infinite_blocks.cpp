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
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
    	int n;
        cin >> n;

        vector <lli> ar(50004);

        for(int i=0; i<n; i++) cin >> ar[i];

    	lli grev = 0;

        for(int mask=0; mask<(1<<n-1); mask++){
	        lli stock = 1;
    		lli rev = -ar[0];
        	for(int i=0; i<n-1; i++){
        		if(mask & (1 << i)){ // buys
        			stock++;
        			rev -= ar[i+1];
        		}else{ // sells
        			rev += stock * ar[i+1];
        			stock = 0;
        		}
        	}
        	grev = max(grev, rev);
        }


        cout << grev << endl;
    }



    return 0;
}