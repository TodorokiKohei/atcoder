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
    int n = 6;
    vector<vector<P>> g(n);
    VI dist(n, inf);
    g[0].emplace_back(1, 1);
    g[0].emplace_back(2, 5);
    g[1].emplace_back(3, 1);
    g[1].emplace_back(4, 3);
    g[2].emplace_back(3, -7);
    g[2].emplace_back(4, 4);
    g[3].emplace_back(2, 8);
    g[3].emplace_back(4, 1);
    g[3].emplace_back(5, 4);
    g[4].emplace_back(5, 1);
    dist[0] = 0;
    rep(i, n-1){
        VI dist_tmp = dist;
        rep(v, n){
            rep(m, sz(g[v])){
                int to = g[v][m].first, cost = g[v][m].second;
                if (dist_tmp[to] > dist[v] + cost && dist[v] != inf){
                    printf("%d → %d 更新\n", v+1, to+1);
                    dist_tmp[to] = dist[v] + cost;
                }
            }
        }
        dist = dist_tmp;
        printf("\n");
    }
    rep(i,n){
        printf("%dの最短距離は%d\n", i+1, dist[i]);
    }
    return 0;
}