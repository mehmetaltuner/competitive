//https://www.hackerrank.com/contests/inzva-09-data-structures-3-online-2019/challenges/buraks-array/submissions/code/1312951560
#include <bits/stdc++.h>
#define ALL(e) (e.begin(), e.end())
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define fi first
#define sc second
#define N 10000007

using namespace std;

typedef long long int lli;

struct trie{
	lli val;
	trie *children[2];
};

struct trie* new_trie(){
	trie *ntrie = new trie;
	ntrie->val = 0;
	ntrie->children[0] = ntrie->children[1] = NULL;
	return ntrie;
}

void insert(trie *root, int val){
	trie *traverse = root;
	for(int i=30; i>=0; i--){
		int index = (1 == ( (val >> i) & 1));
		if(!traverse->children[index]){
			traverse->children[index] = new_trie();
		}
		traverse = traverse->children[index];
	}
	traverse->val = val;
}

int find(trie *root, int val){
	trie *traverse = root;
	for(int i=30; i>=0; i--){
		int index = (1 == ( (val >> i) & 1));
		if(traverse->children[1-index]){
			traverse = traverse->children[1-index];
		}else{
			traverse = traverse->children[index];
		}
	}

	return traverse->val ^ val;
}

int main(int argc, char const *argv[])
{
	trie *root = new_trie();
	lli n;
	scanf("%lli", &n);

	vector <lli> ar(n+5);

	for(int i=0; i<n; i++){
		scanf("%lli", &ar[i]);
		insert(root, ar[i]);
	}

	int res = INT_MIN/2;
	for(int i=0; i<n; i++){
		res = max(res, find(root, ar[i]));
	}

	printf("%d", res);

	return 0;
}