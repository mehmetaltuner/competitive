//https://www.hackerrank.com/contests/inzva-09-data-structures-3-online-2019/challenges

#include <bits/stdc++.h>
#define N 10000005
using namespace std;

typedef unsigned long long int lli;

vector <lli> st(N);
vector <lli> ar(N);

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
    if(ar >= r && al <= l)
        return st[i];
    
    if(al > r || ar < l)
        return 0;
    
    lli mid = (l + r) / 2;
    return query(l, mid, al, ar, i*2) ^ query(mid+1, r, al, ar, i*2 + 1);
}

void update(lli l, lli r, lli ai, lli uv, lli i){
    if(l == r && l == ai){
        st[i] = uv;
        ar[l] == uv;
        return;
    }

    if(ai > r || ai < l)
        return;
    
    lli mid = (r + l) / 2;
    update(l, mid, ai, uv, i*2); update(mid+1, r, ai, uv, i*2 + 1);
    st[i] = st[i*2] ^ st[i*2 + 1];
}


int main() {
    lli n, q;
    scanf("%lli %lli", &n, &q);
    
    for(int i=1; i<=n; i++) scanf("%lli", &ar[i]);
    
    build(1, n, 1);
    
    while(q--){
        int c; 
        cin >> c;
        if(c == 1){
            lli l, r; 
            scanf("%lli %lli", &l, &r);
            printf("%llu\n", query(1, n, l, r, 1));
        }else if(c == 2){
            lli i, u; 
            scanf("%lli %lli", &i, &u);
            update(1, n, i, u, 1);
        }
    }
    
    return 0;
}
