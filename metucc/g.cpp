/*
 * C++ Program to Implement Max-Flow Min-Cut Theorem
 */
#include <iostream>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#define inf	1000000000000000LL

#define V 52
using namespace std;
 
typedef long long int lint;
/*
 * Returns true if there is a path from source 's' to sink 't' in
 * residual graph. Also fills parent[] to store the path
 */
lint bfs(lint rGraph[V][V], lint s, lint t, lint parent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        lint u = q.front();
        q.pop();
        for (int v = 0; v < V; v++)
        {
            if (visited[v] == false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}
 
/*
 *  A DFS based function to find all reachable vertices from s.
 */
void dfs(lint rGraph[V][V], lint s, bool visited[])
{
    visited[s] = true;
    for (int i = 0; i < V; i++)
    {
        if (rGraph[s][i] && !visited[i])
           dfs(rGraph, i, visited);
    }
}
 
/*
 * Prints the minimum s-t cut
 */
vector<pair<int, int>> minCut(lint graph[V][V], int s, int t)
{
    lint u, v;
    lint rGraph[V][V];
    for (u = 0; u < V; u++)
    {
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];
    }
    lint parent[V];
    while (bfs(rGraph, s, t, parent))
    {
        lint path_flow = inf;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
    }
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    dfs(rGraph, s, visited);
    vector<pair<int, int>> res;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (visited[i] && !visited[j] && graph[i][j])
                //cout << i << " - " << j << endl;
                res.push_back({i, j});
        }
    }
    return res;
}
/*
 * Main Contains Menu
 */ 
lint graph[V][V];
lint ResGraph[V][V];
lint T, B;
int main()
{
    ios::sync_with_stdio(0);
    memset(graph, 0, sizeof(graph));
    memset(ResGraph, 0, sizeof(ResGraph));
    
    cin>>T>>B;
    vector<lint> kuleCost(T+1);
    kuleCost[1] = inf;
    kuleCost[T] = inf;
    vector<pair<int, int>> cst;
    for(int i = 0; i< T - 2; i++)
    {
        lint x, y;
        cin>>x>>y;
        kuleCost[x] = y;
        cst.push_back({y, x});
    }
    sort(cst.begin(), cst.end());
    for(int i = 0; i < B; i++)
    {
        lint x, y, z;
        cin>>x>>y>>z;
        if(kuleCost[x] == 0 || kuleCost[y] == 0 || z == 0) continue;

        graph[x][y] = z;
        graph[y][x] = z;
    }
    int buNeAbi;
    cin>>buNeAbi>>buNeAbi;

    auto res = minCut(graph, 1, T);
    vector<bool> deleted(res.size());
    lint totCost = 0;
    bool silindi = true;
    while(silindi)
    {
        silindi = false;
        for(int i = 0; i < cst.size(); i++)
        {
            lint c = cst[i].first;
            lint nod = cst[i].second;
            lint tot = 0;
            for(int j = 0; j < res.size(); j++)
            {
                if (!deleted[j]) {
                    if(res[j].first == nod || res[j].second == nod)
                        tot += graph[res[j].first][res[j].second];
                }
            }
            if(tot > c)
            {
                totCost += c;

                for(int j = 0; j < res.size(); j++)
                {
                    if (!deleted[j]) {
                        if(res[j].first == nod || res[j].second == nod)
                            deleted[j] = true;
                    }
                }

                silindi = true;
            }
        }
    }
    for(int j = 0; j < res.size(); j++)
    {
        if (!deleted[j]) {
            totCost += graph[res[j].first][res[j].second];
        }
    }
    cout<<fixed<<totCost;
    return 0;
}
