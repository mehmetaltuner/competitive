// https://codeforces.com/contest/669/problem/E
#include <bits/stdc++.h>
#define ALL(e) (e.begin(), e.end())
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define fi first
#define sc second
#define N 1000000009

typedef long long int lli;

using namespace std;

map <pair <lli, lli>, lli> ft;

void add(lli i, lli num, lli val){
	while(i <= N){
		ft[{i, num}] += val;
		i += (i&-i);
	}
}

lli sum(lli i, lli num){
	lli res = 0;
	while(i > 0){
		res += ft[{i, num}];
		i -= (i&-i);
	}
	return res;
}

int main(int argc, char const *argv[]){
	lli n;
	scanf("%lli", &n);
	while(n--){
		int c;
		scanf("%d", &c);
		if(c == 1){
			lli x, y;
			scanf("%lli %lli", &x, &y);
			if(ft.find({x, y}) == ft.end()){
				ft[{x, y}] = 0;
			}
			add(x, y, 1);
		}else if(c == 2){
			lli x, y;
			scanf("%lli %lli", &x, &y);
			add(x, y, -1);
		}else{
			lli x, y;
			scanf("%lli %lli", &x, &y);
			printf("%lli\n", sum(x, y));
		}
	}
	return 0;
}