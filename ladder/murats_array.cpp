#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define mid ((l + r) / 2)
#define mod 1000000007LL
#define fi first
#define sc second
#define N 100005

using namespace std;

typedef long long int lli;

vector <vector <lli>> st(4*N, vector <lli>(15, 0));
vector <lli> ar(N);

lli md(lli &a){
    while(a >= mod)
        a -= mod * a/mod;
    return a;
}

void update(lli l, lli r, lli ai, lli std, lli i, lli val){
    if(l > ai or r < ai)
        return;

    if(l == ai and r == ai){
        st[i][std] += val;
        md(st[i][std]);
        return;
    }

    update(l, mid, ai, std, i*2, val);
    update(mid+1, r, ai, std, i*2+1, val);
    lli subt = md(st[i*2][std]) + md(st[i*2+1][std]);

    st[i][std] = md(subt);
}

lli query(lli l, lli r, lli al, lli ar, lli std, lli i){
    if(l > ar or r < al)
        return 0;

    if(l >= al and r <= ar)
        return st[i][std];

    lli q1 = query(l, mid, al, ar, std, i*2);
    lli q2 = query(mid+1, r, al, ar, std, i*2+1);

    lli qs = md(q1) + md(q2);

    return md(qs);
}

int main(){
    lli n, m;
    scanf("%lld %lld", &n, &m);

    for(lli i=1; i<=n; i++) scanf("%lld", &ar[i]);
    
    //cerr << query(1, n, ar[1], ar[2], 1, 1) << endl;

    
    for(lli i=n ; i>=1 ; i--){
        for(lli j=m ; j>=2; j--){
            update(1, n, ar[i], j, 1, query(1, n, ar[i], n, j-1, 1));
        }
        update(1, n, ar[i], 1, 1, 1);

    }

    lli res = query(1, n, 1, n, m, 1);
    printf("%lld", md(res));

    return 0;
}