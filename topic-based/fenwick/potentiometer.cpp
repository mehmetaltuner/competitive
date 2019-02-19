//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3238

#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define fi first
#define sc second
#define N 10000007

typedef long long int lli;

using namespace std;

vector <lli> fenwick;
vector <lli> ar;

void add(lli i, lli num, lli n){
	while(i <= n){
		fenwick[i] += num;
		i += (i&-i);
	}
	return;
}

lli sum(lli r){
	lli res = 0;
	while(r > 0){
		res += fenwick[r];
		r -= (r&-r);
	}
	return res;
}

lli query(lli l, lli r){
	return sum(r) - sum(l-1);
}

int main(int argc, char const *argv[]){
	vector <vector <lli>> queries(3, vector <lli>());
	int qn=0;

	while(true){
		lli n;
		scanf("%lli", &n);

		if(!n){
			break;
		}

		fenwick.assign(n+1, 0);
		ar.assign(n+1, 0);

		for(int i=1; i<=n; i++) scanf("%lli", &ar[i]);
		for(int i=1; i<=n; i++) add(i, ar[i], n);

		string s="A";
		while(s != "END"){
			cin >> s;
			if(s[0] == 'S'){
				lli x, r;
				scanf("%lli %lli", &x, &r);
				add(x, r-ar[x], n);
				ar[x] = r;
			}else if(s[0] == 'M'){
				lli x, y;
				scanf("%lli %lli", &x, &y);
				queries[qn].pb(query(x, y));
			}
		}
		qn++;
	}

	for(int i=0; i<qn; i++){
		printf("Case %d:\n", i+1);
		for(auto q: queries[i]){
			printf("%lli\n", q);
		}
		if(i < qn-1)
			printf("\n");
	}

	return 0;
}