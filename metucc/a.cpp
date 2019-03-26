#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define RALL(e) e.rbegin(), e.rend()
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

	list <char> res;
	list <char>::iterator it = res.begin();

	string s;
	getline(cin, s);

	for(int i=0; i<s.size(); i++){
		char c = s[i];

		if(c == '['){
			it = res.begin();
			continue;
		}

		if(c == ']'){
			it = res.end();
			continue;
		}

		res.insert(it, c);
	}

	for(auto it2=res.begin(); it2!=res.end(); it2++){
		cout << *it2;
	}

	return 0;
}