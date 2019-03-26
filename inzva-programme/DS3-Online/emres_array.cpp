#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define fi first
#define sc second
#define N 1000006

using namespace std;

typedef long long int lli;

vector <lli> st(N);
vector <lli> ar(N);
vector <lli> la1(N, 0); // holds the descending updates (1, 2, 3, 4 ... n-1)
vector <lli> la2(N, 0); // holds the stabled updates (+4 etc.)

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

void update(lli l, lli r, lli al, lli ar, lli i){
	if(la1[i] != 0){
		lli mid = (r+l) / 2;
		st[i] += la1[i] * (r-l+1) * (r-l+2) / 2;

		la1[i*2]++;
		la1[i*2+1]++;
		la2[i*2+1] += mid + 1 - al;
	}

	if(la2[i] != 0){
		lli mid = (r+l) / 2;
		st[i] += (r-l+1) * (r-l+2) / 2;
		la1[i*2]++;
		la1[i*2+1]++;
		la2[i*2+1] += mid + 1 - al;
	}

	if(l > ar || r < al)
		return 0;

	if(l >= al && r <= ar){
		lli mid = (r+l) / 2;
		st[i] += (r-l+1) * (r-l+2) / 2;
		la1[i*2]++;
		la1[i*2+1]++;
		la2[i*2+1] += mid + 1 - al;
	}
}

int main(){

	return 0;
}