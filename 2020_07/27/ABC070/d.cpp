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

vector<vector<pair<int, ll>>> g;
vector<ll> cost;

void dfs(int d, int p){
    for(auto v : g[d]){
        if (v.first == p) continue;
        cost[v.first] = cost[d] + v.second;
        dfs(v.first, d);
    }
}

int main(){
    int n;
    cin >> n;
    g.resize(n);
    cost.resize(n);
    rep(i,n-1){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }

    int q, k;
    cin >> q >> k;
    k--;
    dfs(k, -1);
    rep(i, q){
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << cost[x] + cost[y] << endl;
    }
    return 0;
}