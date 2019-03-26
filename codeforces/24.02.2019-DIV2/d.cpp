#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define mid (l + r) / 2
#define fi first
#define sc second
#define N 1000000009

using namespace std;

typedef long long int lli;

int main(){


	priority_queue <pair <int, node>> pq; // -distance, 
	vector <vector <bool>> visited(n+5, vector <bool>(n+5, 0));
	vector <vector <int>> distance(n+5, vector <int>(n+5, INT_MAX));

	vector <pair <int, int>> init_path;
	init_path.pb({rs, cs});


	distance[rs][cs] = 0;
	pq.push({0, node{rs, cs, init_path}});

	vector <pair <int, int>> fp;

	while(!pq.empty()){
		node no = pq.top().sc; pq.pop();
		auto p = no.path;
		if(visited[no.r][no.c])
			continue;

		visited[no.r][no.c] = true;

		if(no.r == re and no.c == ce){
			fp = p;
		}

		// go down
		if(no.r < n){
			int w = 0;
			if(matrix[no.r+1][no.c] == 1)
				w = 1;

			if(distance[no.r][no.c] + w < distance[no.r+1][no.c]){
				distance[no.r+1][no.c] = distance[no.r][no.c] + w;

				vector <pair <int, int>> np = p;
				np.pb({no.r+1, no.c});
				node cn = {no.r+1, no.c, np};
				pq.push({-distance[no.r+1][no.c], cn});
			}
		}

		// go up
		if(no.r > 1){
			int w = 0;
			if(matrix[no.r-1][no.c] == 1)
				w = 1;

			if(distance[no.r][no.c] + w < distance[no.r-1][no.c]){
				distance[no.r-1][no.c] = distance[no.r][no.c] + w;

				vector <pair <int, int>> np = p;
				np.pb({no.r-1, no.c});
				node cn = {no.r-1, no.c, np};
				pq.push({-distance[no.r-1][no.c], cn});
			}
		}

		// go left
		if(no.c > 1){
			int w = 0;
			if(matrix[no.r][no.c-1] == 1)
				w = 1;

			if(distance[no.r][no.c] + w < distance[no.r][no.c-1]){
				distance[no.r][no.c-1] = distance[no.r][no.c] + w;

				vector <pair <int, int>> np = p;
				np.pb({no.r, no.c-1});
				node cn = {no.r, no.c-1, np};
				pq.push({-distance[no.r][no.c-1], cn});
			}
		}

		// go right
		if(no.c < n){
			int w = 0;
			if(matrix[no.r][no.c+1] == 1)
				w = 1;

			if(distance[no.r][no.c] + w < distance[no.r][no.c+1]){
				distance[no.r][no.c+1] = distance[no.r][no.c] + w;

				vector <pair <int, int>> np = p;
				np.pb({no.r, no.c+1});
				node cn = {no.r, no.c+1, np};
				pq.push({-distance[no.r][no.c+1], cn});
			}
		}


	}

	for(auto a: fp){
		cout << a.fi << " " << a.sc << endl;
	}

	return 0;
}