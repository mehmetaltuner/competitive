#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define fi first
#define sc second
#define N 1000006
#define mid (l+r)/2

using namespace std;

typedef long long int lli;

vector <lli> st(N, 0);
vector <lli> la(N, 0);

lli query(lli l, lli r, lli al, lli ar, lli i){
    if(la[i]){
        st[i] += (r-l+1) * la[i];
        la[i*2] += la[i]; la[i*2+1] += la[i];
        la[i] = 0; 
    }

    if(l > ar || r < al)
        return 0;

    if(l >= al && r <= ar)
        return st[i];

    return query(l, mid, al, ar, i*2) + query(mid+1, r, al, ar, i*2+1);
}

void update(lli l, lli r, lli al, lli ar, lli val, lli i){
    if(la[i]){
        st[i] += (r-l+1) * la[i];
        la[i*2] += la[i]; la[i*2+1] += la[i];
        la[i] = 0;
    }

    if(l > ar || r < al){
        return;
    }

    if(l >= al && r <= ar){
        st[i] += (r-l+1) * val;
        la[i*2] += val; la[i*2+1] += val;
        return;
    }

    update(l, mid, al, ar, val, i*2);
    update(mid+1, r, al, ar, val, i*2+1);

    st[i] = st[i*2] + st[i*2+1];
}

int main(){
    lli n, m;
    scanf("%lld %lld", &n, &m);

    while(m--){
        int c;
        scanf("%d", &c);
        if(c == 1){
            lli x, y;
            scanf("%lld %lld", &x, &y);
            update(1, n, x, y, 1, 1);
        }else{
            lli x, y;
            scanf("%lld %lld", &x, &y);
            printf("%lld\n", query(1, n, x, y, 1));
        }
    }

    return 0;
}