// https://codeforces.com/problemset/problem/236/A

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

bool exists[30];

int main(){
	string s;
	cin >> s;

	int r=0;

	for(int i=0; i<s.length(); i++){
		if(!exists[s[i]]){
			r++;
			exists[s[i]] = true;
		}
	}

	if(r % 2 == 0)
		cout << "CHAT WITH HER!";
	else
		cout << "IGNORE HIM!";

	return 0;
}