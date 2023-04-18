#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) ((int)(x).size())
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<typename T> void view(T e){std::cout << e << std::endl;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

const int inf = 1 << 29;
const ll INF = 1LL << 60;

int main(){
    ll n, m;
    cin >> n >> m;
    VVI g(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> q;
    vector<bool> color(n);
    vector<bool> visited(n);

    VVL lcn;
    rep(i,n) {
        if (visited[i]) continue;
        q.push(i);
        visited[i] = true;
        lcn.push_back(VL(2));
        while(!q.empty()){
            int u = q.front(); q.pop();
            lcn.back()[color[u]]++;
            for(int v: g[u]){
                if (visited[v]) continue;
                color[v] = !color[u];
                visited[v] = true;
                q.push(v);
            }
        }
    }
    rep(i,n) rep(j, sz(g[i])) {
        if (color[i] == color[g[i][j]]) {
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = (n*(n-1)) / 2;
    ans -= m;
    rep(i,sz(lcn)) {
        ll black = (lcn[i][0]*(lcn[i][0]-1))/2;
        ll white = (lcn[i][1]*(lcn[i][1]-1))/2;
        ans -= black + white;
    }   
    cout << ans << endl;
}