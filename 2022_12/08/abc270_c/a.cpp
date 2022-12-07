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
    int n, x, y;
    cin >> n >> x >> y;
    x--; y--;
    VVI t(n);
    rep(i,n-1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }

    VI p(n, -1);
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(x);
    visited[x] = true;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v: t[u]) {
            if (visited[v]) continue;
            q.push(v);
            p[v] = u;
            visited[v] = true;
        }
    }
    VI ans;
    int nd = y;
    while(nd != -1) {
        ans.push_back(nd);
        nd = p[nd];
    }
    reverse(all(ans));
    rep(i, sz(ans)) {
        printf("%d", ans[i]+1);
        if (i+1 == sz(ans)) printf("\n");
        else printf(" ");
    }
    return 0;
}