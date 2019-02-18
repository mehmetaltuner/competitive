#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define fi first
#define sc second
#define N 10000007
#define endl '\n'

using namespace std;

typedef long long int lli;

vector <lli> st(N);
vector <lli> ar(N);
vector <lli> la(N, 0);

void build(lli l, lli r, lli i){
    if(l == r){
        st[i] = ar[l];
        return;
    }

    lli mid = (l + r) / 2;
    build(l, mid, i*2); build(mid+1, r, i*2+1);
    st[i] = st[i*2] + st[i*2+1];
    return;
}

void update(lli l, lli r, lli al, lli ar, lli i, lli val){    
    if(l > ar || r < al)
        return;

    if(la[i] != 0){
        st[i] += (r-l+1) * la[i];
        if(l != r){
            la[i*2] += la[i]; la[i*2+1] += la[i];    
        }

        la[i] = 0;
    }

    if(l >= al && r <= ar){
        st[i] += (r-l+1) * val;
        if(l != r){
            la[i*2] += val; la[i*2+1] += val;
        }
        return;
    }

    lli mid = (l + r) / 2;
    update(l, mid, al, ar, i*2, val); 
    update(mid+1, r, al, ar, i*2+1, val);

    st[i] = st[i*2] + st[i*2+1];
}

lli query(lli l, lli r, lli al, lli ar, lli i){
    if(la[i] != 0){
        st[i] += (r-l+1) * la[i];
        if(l != r){
            la[i*2] += la[i]; la[i*2+1] += la[i];        
        }
        la[i] = 0;
    }

    if(l > ar || r < al)
        return 0;

    if(l >= al && r <= ar)
        return st[i];

    lli mid = (r + l) / 2;
    return query(l, mid, al, ar, i*2) +
            query(mid+1, r, al, ar, i*2+1);
}

int main(int argc, char const *argv[])
{
    lli n, m;
    cin >> n >> m;
    
    for(int i=1; i<=n; i++) cin >> ar[i];
    
    build(1, n, 1);

    while(m--){
        int c;
        cin >> c;
        if(c == 1){
            lli x, y, val;
            cin >> x >> y >> val;
            update(1, n, x, y, 1, val);
        }else if(c == 2){
            lli x, y;
            cin >> x >> y;
            cout << query(1, n, x, y, 1) << endl;
        }
    }

    return 0;
}