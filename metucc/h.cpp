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

struct trie{
    lli val;
    int bit;
    trie *children[2];
};

struct trie* new_trie(){
    trie *ntrie = new trie;
    ntrie->val = 0;
    ntrie->children[0] = ntrie->children[1] = NULL;
    return ntrie;
}

void insert(trie *root, lli val){
    trie *traverse = root;
    for(lli i=30; i>=0; i--){
        int index = (1 == ( (val >> i) & 1));
        if(!traverse->children[index]){
            traverse->children[index] = new_trie();
            traverse->children[index]->bit = index;
        }
        traverse = traverse->children[index];
    }
    traverse->val = val;
}

int gmin;

void dfs(trie *t, int val, int dep, int cmin, int cbit){
	if(cmin > gmin)
		return;

	if(dep == 0 and cmin == gmin)
		return;

	if(dep == -1){
		gmin = min(gmin, cmin);
		return;
	}

	int bit = (1 == ( (val >> dep) & 1));
	cmin = cmin + (bit != cbit);

	if(t->children[0])
		dfs(t->children[0], val, dep-1, cmin, 0);

	if(t->children[1])
		dfs(t->children[1], val, dep-1, cmin, 1);

}

int main(){	
	ios::sync_with_stdio(0);
	trie *root = new_trie();

	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		int t, a;
		cin >> t >> a;

		if(t == 1){
			insert(root, a);
		}else{
			gmin = INT_MAX;
			
			dfs(root, a, 30, 0, 0);
			
			/*if(root->children[0])
				dfs(root->children[0], a, 30, 0);

			if(root->children[1])
				dfs(root->children[1], a, 30, 0);*/

			cout << gmin << endl;
		}

	}

	return 0;
}








/*lli find(trie *root, lli val){
    trie *traverse = root;
    for(lli i=30; i>=0; i--){
        lli index = (1 == ( (val >> i) & 1));
        if(traverse->children[1-index]){
            traverse = traverse->children[1-index];
        }else{
            traverse = traverse->children[index];
        }
    }

	return traverse->val ^ val;
}*/