#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define RALL(e) e.rbegin(), e.rend()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define mid (l + r) / 2
#define fi first
#define sc second
#define N 1000

using namespace std;

typedef long long int lli;

vector <lli> st(N, 0);
vector <lli> la(N, 0);

lli query(lli l, lli r, lli al, lli ar, lli i){
	//cout << i << l << r << al << ar << endl;
    if(la[i]){
        st[i] += (r-l+1) * la[i];
        la[i*2] += la[i]; la[i*2+1] += la[i];
        la[i] = 0; 
    }

    if(l > ar || r < al){
    	
        return 0;
    }

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
	ios::sync_with_stdio(0);
	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		int x, y;
		cin >> x >> y;

		int left = (x < y ? 0 : x-y);
		int right = x+y;

		update(0, N, left, right, 1, 1);
	}

	lli res = LLONG_MIN;

	for(int i=2; i<N/2; i++){
		//cout << res << endl;
		res = max(res, query(0, N, i, i, 1));
	}

	cout << res;

	return 0;
}