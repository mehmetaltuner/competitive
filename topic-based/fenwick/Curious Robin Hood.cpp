//http://www.lightoj.com/volume_showproblem.php?problem=1112

#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define fi first
#define sc second
#define N 1000006

typedef long long int lli;

using namespace std;

vector <lli> ar(N);
vector <lli> ft(N);

void add(lli i, lli num, lli n){
	while(i <= n){
		ft[i] += num;
		i += (i&-i);
	}
	return;
}

lli sum(lli r){
	lli res = 0;
	while(r > 0){
		res += ft[r];
		r -= (r&-r);
	}
	return res;
}

lli query(lli l, lli r){
	return sum(r) - sum(l-1);
}

int main(int argc, char const *argv[]){
	lli t;
	scanf("%lli", &t);
	vector <vector <lli>> queries(N, vector <lli>());
	lli qn=0;
	
	while(t--){
		lli n, q;
		scanf("%lli %lli", &n, &q);

		ft.assign(n+1, 0);
		ar.assign(n+1, 0);

		for(int i=1; i<=n; i++) scanf("%lli", &ar[i]);
		for(int i=1; i<=n; i++) add(i, ar[i], n);


		while(q--){
			int c;
			scanf("%d", &c);

			if(c == 1){
				lli i;
				scanf("%lli", &i);
				i++;
				add(i, -ar[i], n);
				queries[qn].pb(ar[i]);
				ar[i] = 0;
			}else if(c == 2){
				lli i, v;
				scanf("%lli %lli", &i, &v);
				i++;
				add(i, v, n);
				ar[i] += v;
			}else{
				lli i, j;
				scanf("%lli %lli", &i, &j);
				i++; j++;
				queries[qn].pb(query(i, j));
				//cout << sum(j) << " " << sum(i) << " şalsd " << endl;
			}
		}
		qn++;
	}

	for(int i=0; i<qn; i++){
		printf("Case %d:\n", i+1);
		for(auto q: queries[i]){
			printf("%lli\n", q);
		}
	}

	return 0;
}