#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define mid (l + r) / 2
#define fi first
#define sc second

using namespace std;

typedef long long int lli;


vector <int> vectorize(int number, int n){
	vector <int> res(n+5, 0);
	int i = n;
	while (number > 0)
	{
    	int digit = number%10;
    	number /= 10;
    	res[i--] = digit;
	}
	return res;
}

vector <vector <int>> matrix;

struct node{
	int r, c;
};

int res;
int rs, cs, re, ce, lim;

vector <vector <bool>> visited(1000, vector <bool>(1000, false));
 
void dfs(node n, vector <pair <int, int>> pa){
	if(n.r == re and n.c == ce){
		bool started = false, ended = false;
		pair <int, int> s, e, before;
		
		for(auto p: pa){
			if(matrix[p.fi][p.sc] == 1){ // water
				if(ended == true){
					// already got one tunnel
					return;
				}

				if(!started){
					started = true;
					s = p;
				}
			}else{ // land
				if(started and !ended){
					ended = true;
					e = before; 
				}
			}

			before = p;
		}

		cout << " came came " << endl;
		int result = (e.sc - s.sc) * (e.sc - s.sc) + (e.fi - s.fi) * (e.fi - s.fi);
		cout << " askdhj " << e.sc << " " << s.sc << " " << e.fi << " " << s.fi << endl;
		res = min(res, result);
		return;
	}




	if(visited[n.r][n.c])
		return;

	visited[n.r][n.c] = true;

	// go down
	if(n.r < lim){
		pa.pb({n.r+1, n.c});
		dfs(node{n.r+1, n.c}, pa);
	}

	if(n.r > 1){
		pa.pb({n.r-1, n.c});
		dfs(node{n.r-1, n.c}, pa);
	}

	if(n.c < lim){
		pa.pb({n.r, n.c+1});
		dfs(node{n.r, n.c+1}, pa);
	}

	if(n.c > 0){
		pa.pb({n.r, n.c-1});
		dfs(node{n.r, n.c-1}, pa);
	}

}

int main(){
	res = INT_MAX;
	scanf("%d", &lim);

	matrix.resize(lim+5, vector<int>(lim+5, 0));

	scanf("%d %d", &rs, &cs);
	scanf("%d %d", &re, &ce);

	for(int i=1; i<=lim; i++){
		int x;
		scanf("%d", &x);
		matrix[i] = vectorize(x, lim);
	}

	vector <pair <int, int>> path;
	path.pb({rs, cs});

	dfs(node{rs, cs}, path);

	printf("%d\n", res);

	return 0;
}