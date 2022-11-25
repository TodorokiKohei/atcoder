#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define  all(x) (x).begin(),(x).end()
typedef long long ll;

int n;
vector<vector<pair<int, int>>> g;
const int INF = 1<<30;

void dijkstra(){
    vector<int> d(n), visited(n);
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    rep(i,n) d[i] = INF;

    pq.push(make_pair(0,0));
    d[0] = 0;
    visited[0] = 1;

    while(!pq.empty()){
        pair<int, int> p = pq.top(); pq.pop();
        int u = p.second;

        visited[u] = 1;
        if (d[u] < p.first) continue;

        for(auto pp: g[u]){
            int v = pp.first;
            if (visited[v] == 1) continue;
            if (d[v] > d[u] + pp.second){
                d[v] = d[u] + pp.second;
                pq.push(make_pair(d[v], v));
            }
        }
    }
    rep(i,n){
        printf("%d %d\n", i, d[i]);
    }
}

int main(){
    cin >> n;
    g.resize(n);
    rep(i,n){
        int u, k;
        cin >> u >> k;
        rep(j, k){
            int to, cost;
            cin >> to >> cost;
            g[u].push_back(make_pair(to, cost));
        }
    }
    dijkstra();
}