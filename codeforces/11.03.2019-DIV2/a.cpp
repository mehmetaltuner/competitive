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
	ios::sync_with_stdio(0);
	vector <pair <int,int>> chapters;
	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		int a, b;
		cin >> a >> b;
		chapters.pb({a,b});
	}

	sort(ALL(chapters));

	int p;
	cin >> p;

	for(int i=0; i<n; i++){
		if(chapters[i].fi <= p and p <= chapters[i].sc){
			cout << n - i;
		}
	}

	return 0;
}