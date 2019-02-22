#include <bits/stdc++.h>
#define ALL(e) (e.begin(), e.end())
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define fi first
#define sc second
#define N 10000007

typedef long long int lli;

using namespace std;

vector <pair <lli, lli>> ar(N); // value, dp val
vector <lli> last_index(N, 0);
vector <lli> st(N, INT_MIN);

void build(lli l, lli r, lli i){
    if(l == r){
        st[i] = ar[l].first;
        return;
    }

    lli mid = (l+r)/2;
    build(l, mid, i*2);
    build(mid+1, r, i*2+1);

    st[i] = max(st[i*2], st[i*2+1]);
    return;
}

lli query(lli l, lli r, lli al, lli ar, lli i){
    if(l > ar || r < al)
        return INT_MIN;

    if(l >= al && r <= ar)
        return st[i];

    lli mid = (r+l)/2;
    return max(query(l, mid, al, ar, i*2), 
        query(mid+1, r, al, ar, i*2+1));
}

int main(int argc, char const *argv[])
{
    lli n;
    scanf("%lld", &n);

    for(int i=1; i<=n; i++) scanf("%lld", &ar[i].first);

    build(1, n, 1);

    for(lli i=1; i<=n; i++){
        if(last_index[ar[i].first] == 0){
            ar[i].second = 0;
        }else{
            lli li = last_index[ar[i].first];
            if(query(1, n, li, i, 1) == ar[i].first){
                ar[i].second = ar[li].second+1;
            }
            else
                ar[i].second = 0;
        }
        last_index[ar[i].first] = i;
    }

    lli res = 0;
    for(lli i=1; i<=n; i++)
        res += ar[i].second;

    res *= 2;

    printf("%lld", res);

    return 0;
}