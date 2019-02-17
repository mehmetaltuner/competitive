//https://www.hackerrank.com/contests/inzva-09-data-structures-3-online-2019/challenges/contacts

#include <bits/stdc++.h>
#define ALL(e) (e.begin(), e.end())
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define fi first
#define sc second
#define N 1000000009

using namespace std;

struct trie{
	int counter;
	char val;
	trie *children[26];
};

void add(trie *root, string s){
	int s_n = s.length();
	trie *traverse = root;

	for(int i=0; i<s_n; i++){
		int index = s[i] - 'a';
		if(!traverse->children[index]){
			trie *n_trie = new trie;
			n_trie->val = s[i];
			traverse->children[index] = n_trie;
		}

		traverse->children[index]->counter++;
		traverse = traverse->children[index];
	}
}

int find(trie *root, string s){
	int s_n = s.length();
	int res = 0;
	trie *traverse = root;

	for(int i=0; i<s_n; i++){
		int index = s[i] - 'a';
		if(!traverse->children[index])
			return 0;

		traverse = traverse->children[index];
		if(i == s_n-1)
			res = traverse->counter;
	}

	return res;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	trie *root = new trie;

	for(int i=0; i<26; i++){
		root->children[i] = NULL;
	}

	while(n--){
		string s;
		cin >> s;

		string r;

		cin >> r;

		if(s == "add")
			add(root, r);
		else
			cout << find(root, r) << endl;
	}

	return 0;
}