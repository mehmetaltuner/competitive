#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define fi first
#define sc second
#define N 1000006

typedef long long int lli;

using namespace std;

int block_size;

struct Q{
	int l, r, id;
	bool operator<(Q other) const{
		return make_pair(l / block_size, r) < 
		make_pair(other.l / block_size, other.r);
	}
};

vector <int> mods(N, 0);
vector <int> ar(N, 0);

void add(int i, int &num){
	if(mods[ar[i]] == 0){
		num++;
	}
	mods[ar[i]]++;

}

void remove(int i, int &num){
	if(mods[ar[i]] == 1)
		num--;
	mods[ar[i]]--;
}

vector <Q> queries;

vector <int> mo(){
	vector <int> res(queries.size());
	sort(ALL(queries));

	int cl = 0, cr = -1, num = 0;

	for(Q q: queries){
		while(cl > q.l){
			cl--;
			add(cl, num);
		}
		while(cr < q.r){
			cr++;
			add(cr, num);
		}
		while(cl < q.l){
			remove(cl, num);
			cl++;
		}
		while(cr> q.r){
			remove(cr, num);
			cr--;
		}

		res[q.id] = num;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int n, q;
	scanf("%d %d", &n, &q);
	block_size = (int)sqrt(n);

	for(int i=1; i<=n; i++){
		scanf("%d", &ar[i]);
	}

	for(int i=0; i<q; i++){
		int x, y;
		scanf("%d %d", &x, &y);

		queries.pb(Q{x, y, i});
	}

	vector <int> res = mo();
	for(auto r: res){
		printf("%d\n", r);
	}

	return 0;
}