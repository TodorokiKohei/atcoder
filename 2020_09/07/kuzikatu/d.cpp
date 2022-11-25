#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

void dfs(VVI &g, P np, int v, int p, VI &dist){
    for(int d: g[v]){
        if (d == p) continue;
        if (dist[d] != -1) continue;
        if (np.first == d && np.second == v) continue;
        if (np.first == v && np.second == d) continue;
        dist[d] = dist[v] + 1;
        dfs(g, np, d, v, dist);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    VVI g(n);
    VP np(m);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        np[i] = P(a, b);
    }

    int ans = 0;
    rep(i,m){
        int v = 0;
        while(np[i].first == v || np[i].second == v) v++;
        VI dist(n, -1);
        dist[v] = 0;
        dfs(g, np[i], v, -1, dist);
        rep(i,n) if (dist[i] == -1){
            ans++;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}