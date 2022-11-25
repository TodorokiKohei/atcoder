#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int n, m;
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

        if (d[u] < p.first) continue;
        visited[u] = 1;

        for(auto pp : g[u]){
            int v = pp.first;
            if (visited[v]) continue;
            if (d[v] > d[u] + pp.second){
                d[v] = d[u] + pp.second;
                pq.push(make_pair(d[v], v));
            }
        }
    }

    if (d[n-1] == 2){
        cout << "POSSIBLE" << endl; 
    }else {
        cout << "IMPOSSIBLE" << endl; 
    }
}

int main(){
    cin >> n >> m;
    g.resize(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(make_pair(b, 1));
    }
    dijkstra();
}