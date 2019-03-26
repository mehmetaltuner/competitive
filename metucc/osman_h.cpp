#include <bits/stdc++.h>
#define bf(number,i) ((number>>i)&1)
#define inf 100000000;
using namespace std;

struct Node
{   
    bool bit;
    Node* ch[2]; 
    Node()
    {
        ch[0] = nullptr;
        ch[1] = nullptr;
    }
};

void add(int num, Node*& node, int depth)
{
    if(depth == 21) return;
    if(node == nullptr)
    {
        node = new Node();
        node->bit = bf(num, depth);
        //cout<<"new bit\n";
    }
    //cout<<"siradaki: "<<bf(num, depth + 1)<<'\n';
    add(num, node->ch[bf(num, depth + 1)], depth + 1);
}

int search(int num, Node* node, int depth)
{
    if(node == nullptr) return inf;
    if(node->ch[0] == nullptr && node->ch[1] == nullptr)
    {
        return bf(num, depth) ^ node->bit;
    }
    int x = inf;
    int y = inf;
    if(bf(num, depth + 1))
    {
        y = search(num, node->ch[1], depth + 1);
        if(y) x = search(num, node->ch[0], depth + 1);
    }
    else
    {
        x = search(num, node->ch[0], depth + 1);
        if(x) y = search(num, node->ch[1], depth + 1);
    }
    if(depth == -1) return  min(x, y);
    return (bf(num, depth) ^ node->bit) + min(x, y);

}
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    Node* root = new Node;
    while(n--)
    {
        int t, a;
        cin>>t>>a;
        if(t == 1)
        {
            add(a, root, -1);
        }
        else
        {
            cout<<search(a, root, -1)<<'\n';
        }
    }
    return 0;
}
