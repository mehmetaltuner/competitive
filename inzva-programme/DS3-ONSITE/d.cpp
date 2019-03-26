#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define mid (l + r) / 2
#define mod 1000000007
#define fi first
#define sc second
#define N 1000006

using namespace std;

typedef long long int lli;

vector <vector <lli>> st(N, vector <lli>(15, 0));
vector <lli> ar(N);

void update(lli l, lli r, lli ai, lli std, lli i, lli val){
    if(l > ai or r < ai)
        return;

    if(l == ai and r == ai){
        st[i][std] += val;
        return;
    }

    update(l, mid, ai, std, i*2, val);
    update(mid+1, r, ai, std, i*2+1, val);

    st[i][std] = (st[i*2][std] + st[i*2+1][std]) % mod;
}

lli query(lli l, lli r, lli al, lli ar, lli std, lli i){
    if(l > ar or r < al)
        return 0;

    if(l >= al and r <= ar)
        return st[i][std];

    return (query(l, mid, al, ar, std, i*2) +
            query(mid+1, r, al, ar, std, i*2+1)) % mod;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i=1; i<=n; i++) scanf("%lld", &ar[i]);
    
    //cerr << query(1, n, ar[1], ar[2], 1, 1) << endl;

    for(int i=n; i>=1; i--){
        for(int j=k; j>=2; j--){
            update(1, n, ar[i], j, 1, 
                   query(1, n, ar[i], n, j-1, 1));
        }
        update(1, n, ar[i], 1, 1, 1);
    }

    printf("%lld", query(1, n, 1, n, k, 1) % mod);

    return 0;
}