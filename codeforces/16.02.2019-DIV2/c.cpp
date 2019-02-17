#include <bits/stdc++.h>
#define N 300000
#define ne 3000
using namespace std;

typedef unsigned long long int lli;

vector <lli> st(N);
vector <lli> ar(N);
vector <vector <lli>> dp(ne, vector <lli>(ne, 0));

void build(lli l, lli r, lli i){
    if(l == r){
        st[i] = ar[l];
        return;
    }
    
    lli mid = (l + r) / 2;
    build(l, mid, i*2); build(mid+1, r, i*2 + 1);
    
    st[i] = st[i*2] ^ st[i*2 + 1];
}

lli query(lli l, lli r, lli al, lli ar, lli i){
	if(dp[l][r])
		return dp[l][r];

    if(ar >= r && al <= l)
        return st[i];
    
    if(al > r || ar < l)
        return 0;
    
    lli mid = (l + r) / 2;
    return dp[l][r] = query(l, mid, al, ar, i*2) ^ query(mid+1, r, al, ar, i*2 + 1);
}


int main() {
    lli n, res = 0;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> ar[i];

    build(1, n, 1);

	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			if((j - i + 1) % 2 == 0){
				int mid = (i+j-1) / 2;
				if(query(1, n, i, mid, 1) == query(1, n, mid+1, j, 1)){
					res++;
				}
			}
		}
	}

	cout << res;

    return 0;
}
