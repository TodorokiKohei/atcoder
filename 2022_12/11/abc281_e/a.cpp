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
    int n, m, k;
    cin >> n >> m >> k;
    VL a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    multiset<ll> small, large;

    auto push = [&] (ll x) {
        small.insert(x);
        ans += x;
        if (sz(small) > k) {
            auto it = --small.end();
            large.insert(*it);
            ans -= *it;
            small.erase(it);
        }
    };

    auto pop = [&] (ll x) {
        auto it = small.find(x);
        if (it != small.end()) {
            ans -= *it;
            small.erase(it);
            it = large.begin();
            ans += *it;
            small.insert(*it);
            large.erase(it);
        }else {
            it = large.find(x);
            large.erase(it);
        }
    };    

    rep(i,m) push(a[i]);
    cout << ans;

    for(int i = m; i < n; i++){
        push(a[i]);
        pop(a[i-m]);
        cout << " " << ans;
    }
    cout << endl;

    return 0;
}