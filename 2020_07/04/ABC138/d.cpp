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

vector<vector<int>> g;
vector<ll> px;
vector<bool> visited;

void dfs(int p){
    visited[p] = true;
    for(int v: g[p]){
        if (visited[v]) continue;
        px[v] += px[p];
        dfs(v);
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    g.resize(n);
    px.resize(n, 0);
    visited.resize(n, false);
    rep(i,n-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i,q){
        ll p, x;
        cin >> p >> x;
        p--;
        px[p] += x;
    }
    dfs(0);
    rep(i,n){
        cout << px[i] << " ";
    }
    cout << endl;
}