#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define fi first
#define sc second
#define N 10000007

using namespace std;

typedef long long int lli;

vector <lli> ar(N); // value, dp val
vector <lli> st(N);

void build(lli l, lli r, lli i){
    if(l == r){
        st[i] = ar[l];
        return;
    }

    lli mid = (l+r)/2;
    build(l, mid, i*2);
    build(mid+1, r, i*2+1);

    st[i] = st[i*2] ^ st[i*2+1];
    return;
}

lli query(lli l, lli r, lli al, lli ar, lli i){
    if(l > ar || r < al)
        return 0;

    if(l >= al && r <= ar)
        return st[i];

    lli mid = (r+l)/2;
    return query(l, mid, al, ar, i*2) ^ query(mid+1, r, al, ar, i*2+1);
}

struct trie{
    lli val, index;
    trie *children[2];
};

struct trie* new_trie(){
    trie *ntrie = new trie;
    ntrie->val = 0;
    ntrie->children[0] = ntrie->children[1] = NULL;
    return ntrie;
}

void insert(trie *root, lli val, lli index){
    trie *traverse = root;
    for(lli i=30; i>=0; i--){
        lli index = (1 == ( (val >> i) & 1));
        if(!traverse->children[index]){
            traverse->children[index] = new_trie();
        }
        traverse = traverse->children[index];
    }
    traverse->val = val;
    traverse->index = index;
}

lli find(trie *root, lli val){
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
}


int main(){
    int n;
    cin >> n;

    for(int i=1; i<=n; i++) cin >> ar[i];

    build(1, n, 1);

    lli res = 0;
    lli index = 0;
    
    trie *root = new_trie();

    for(int i=1; i<=n; i++){
        lli q = query(1, n, 1, i, 1);
        insert(root, q, i);
    }

    
    for(int i=n; i>0; i--){
        lli q = query(1, n, i, n, 1);
        res = max(res, find(root, q));
    }

    printf("%lld", res);

    return 0;
}