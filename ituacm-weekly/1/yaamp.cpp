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

typedef long long int lli;

struct trie{
    lli val;
    bool ends;
    trie *children[2];
};

trie *new_trie(){
    trie *t = new trie;
    t->val=0;
    t->ends = false;
    t->children[0] = NULL;
    t->children[1] = NULL;
    return t;
}

void add(trie *r, lli val){
    trie *traverse = r;
    for(lli i=63; i>=0; --i){
        int index = (1 == ( (val >> i) & 1));
        if(!traverse->children[index]){
            traverse->children[index] = new_trie();
        }
        traverse = traverse->children[index];
    }

    traverse->val = val;
    traverse->ends = true;
}

void get(trie *r, vector <lli> &v){
    if(r->ends){
        v.pb(r->val);
    }

    if(r->children[0]){
        get(r->children[0], v);
    }

    if(r->children[1]){
        get(r->children[1], v);
    }
}

void find(trie *r, vector <lli> &v1, vector <lli> &v2){
    if(r->children[0] and r->children[1]){
        get(r->children[0], v1);
        get(r->children[1], v2);
        return;
    }

    if(r->children[0]){
        find(r->children[0], v1, v2);
    }else if(r->children[1]){
        find(r->children[1], v1, v2);
    }
}

int main(){   
    ios::sync_with_stdio(0);
    
    lli n;
    cin >> n;
    
    trie *r = new_trie();
    
    for(lli i=0; i<n; i++){
        lli x;
        cin >> x;
        add(r, x);
    }
    
    vector <lli> v1, v2;
    find(r, v1, v2);
    
    lli mn = LLONG_MAX;
    
    for(lli a: v1){
        for(lli b: v2){
            mn = min(mn, a^b);
        }
    }

    if(v1.empty() and v2.empty()){
        cout << 0;
        return 0;
    }
    
    cout << mn;
    
    return 0;
}