//https://codeforces.com/problemset/problem/476/B
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

vector <int> prob;
string s1, s2;

void traverse(int i, int loc){
	if(i == s2.length()){
		prob.pb(loc);
		return;
	}

	if(s2[i] == '?'){
		traverse(i+1, loc+1);
		traverse(i+1, loc-1);
	}else{
		if(s2[i] == '+')
			traverse(i+1, loc+1);
		else
			traverse(i+1, loc-1);
	}

	return;
}

int main(){
	ios::sync_with_stdio(0);

	cin >> s1;
	cin >> s2;

	int loc1=0;
	for(int i=0; i<s1.length(); i++){
		if(s1[i] == '+')
			loc1++;
		else
			loc1--;
	}

	traverse(0, 0);
	float match = 0;

	for(auto p: prob){
		if(p == loc1)
			match++;
	}

	printf("%.10f", match / float(prob.size()));

	return 0;
}