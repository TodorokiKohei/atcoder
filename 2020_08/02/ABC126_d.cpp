#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

vector<vector<P>> g;
vector<int> ans;

void dfs(int v, int p, int o){
    for(auto d : g[v]){
        if (d.first == p) continue;
        if (d.second % 2 != 0) o++;
        if (o % 2 == 0) ans[d.first] = 0;
        else ans[d.first] = 1;
        dfs(d.first, v, o);
        if (d.second %2 != 0) o--;
    }
}

int main(){
    int n;
    cin >> n;
    g.resize(n);
    ans.resize(n);
    rep(i,n-1){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    dfs(0, -1, 0);
    rep(i,n) cout << ans[i] << endl;
    return 0;
}