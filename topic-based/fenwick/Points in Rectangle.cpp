//http://www.lightoj.com/volume_showproblem.php?problem=1112

#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define fi first
#define sc second
#define N 1003

typedef int lli;

using namespace std;

vector <vector <lli>> ar(N+1);
vector <vector <lli>> ft(N+1, vector <lli>(N+1, 0));

void add(lli x, lli y, lli val){
	int ycpy = y;
	while(x <= N){
		y=ycpy;
		while(y <= N){
			ft[x][y]++;
			y += (y&-y);
		}
		x += (x&-x);
	}
}

lli sum(lli x, lli y){
	lli res = 0;
	int ycpy = y;
	while(x > 0){
		y = ycpy;
		while(y > 0){
			res += ft[x][y];
			y -= (y&-y);
		}
		x -= (x&-x);
	}
	return res;
}

lli query(lli x1, lli y1, lli x2, lli y2){
	return sum(x2, y2) - sum(x2, y1-1) - sum(x1-1, y2) + sum(x1-1, y1-1);
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);

	vector <vector <lli>> queries(t, vector<lli>());

	for(int q=0; q<t; q++){
		int qt;
		scanf("%d", &qt);
		ft.assign(N, vector <lli>(N, 0));
		set <pair <lli, lli>> s;
		while(qt--){
			int c;
			scanf("%d", &c);
			
			if(c == 0){
				lli x, y;
				scanf("%d %d", &x, &y);
				x++; y++;
				if(s.find({x, y}) == s.end()){
					add(x, y, 1);
					s.insert({x, y});
				}
			}else{
				lli x1, y1, x2, y2;
				scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
				x1++; y1++; x2++; y2++;
				queries[q].pb(query(x1, y1, x2, y2));
			}
		}
	}

	for(int i=0; i<t; i++){
		printf("Case %d:\n", i+1);
		for(auto q: queries[i]){
			printf("%d\n", q);
		}
	}

	return 0;
}