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
    int n;
    cin >> n;
    VVI to(n);
    rep(i,n-1){
        int u, v;
        cin >> u >> v;
        u--;  v--;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    VI l(n), r(n);
    int x = 1;
    auto dfs = [&](auto f, int v, int p=-1) -> void{
        l[v] = x;
        for(int u: to[v]){
            if (u == p) continue;
            f(f, u, v);
        }
        if (to[v].size() == 1 && p != -1) x++;
        r[v] = x-1;
    };
    dfs(dfs, 0);
    rep(i,n) printf("%d %d\n", l[i], r[i]);
    return 0;
}