#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) ((int)(x).size())
typedef long long ll;
using P = pair<ll,int>;
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
    int n, m;
    cin >> n >> m;
    VL h(n);
    rep(i,n) cin >> h[i];
    vector<vector<pair<int, ll>>> to(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        to[u].push_back({v, max((h[v]-h[u]), 0LL)});
        to[v].push_back({u, max((h[u]-h[v]), 0LL)});
    }

    VL dist(n, INF);
    dist[0] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        if (dist[p.second] != p.first) continue;
        for(auto cp : to[p.second]){
            if (dist[cp.first] > (p.first + cp.second) ){
                dist[cp.first] = p.first+cp.second;
                pq.push({dist[cp.first], cp.first});
            }
        }
    }
    ll ans = 0;
    rep(i,n) chmax(ans, (h[0]-h[i])-dist[i]);
    cout << ans << endl;
    return 0;
}