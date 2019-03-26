#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define mid (r + l) / 2
#define dbg(x) (cerr << #x << ":" << x)
#define fi first
#define sc second
#define N 1000009

using namespace std;

typedef long long int lli;

vector <lli> la1(N, 0);
vector <lli> la2(N, 0);
vector <lli> st(N, 0);

void push(lli l, lli r, lli i){
    if(la1[i]){
        st[i*2] += (mid - l + 1) * la1[i];
        st[i*2+1] += (r - mid) * la1[i];

        la1[i*2] += la1[i];
        la1[i*2+1] += la1[i];

        la1[i] = 0;
    }
    if(la2[i]){
        st[i*2] += la2[i] * (mid - l + 1) * (mid - l + 2) / 2; 
        st[i*2 + 1] += la2[i] * (r - mid) * (r - mid + 1) / 2;
        st[i*2 + 1] += (r-mid) * (mid-l+1) * la2[i];

        la2[i*2] += la2[i];
        la2[i*2+1] += la2[i];
        la1[i*2+1] += la2[i] * (mid + 1 - l);

        la2[i] = 0;
    }
}

lli query(lli l, lli r, lli al, lli ar, lli i){
    if(l > ar or r < al)
        return 0;
    
    if(l >= al and r <= ar){
        return st[i];
    }
    
    push(l, r, i);

    return query(l, mid, al, ar, i*2) 
        + query(mid+1, r, al, ar, i*2+1);

}

void update(lli l, lli r, lli al, lli ar, lli i){
    if(l > ar or r < al)
        return;

    if(l >= al and r <= ar){
        la1[i] += l - al;
        la2[i] += 1;
        st[i] += ((r - l + 1) * (r - l + 2) / 2) + (l - al) * (r - l + 1);
        return;
    }

    push(l, r, i);

    update(l, mid, al, ar, i*2);
    update(mid+1, r, al, ar, i*2+1);
    st[i] = st[i*2] + st[i*2+1];
    return;
}

int main(){
    lli n, m, t, x, y;
    cin >> n >> m;

    for(int i=1 ; i<=m; i++){
        cin >> t >> x >> y;

        if(t == 1){
            update(1,n,x,y,1);
        }else{
            cout << query(1,n,x,y,1) << endl;
        }
            
    }
    return 0;
}