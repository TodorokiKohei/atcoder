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

vector<pair<ll, ll>> factorize(ll n){
    vector<pair<ll, ll>> res;
    for (ll i = 2; i*i <= n; ++i){
        if (n%i) continue;
        res.emplace_back(i, 0);
        while (n%i == 0){
            n /= i;
            res.back().second++;
        }
    }
    if(n != 1) res.emplace_back(n, 1);
    return res;
}

int main(){
    ll k;
    cin >> k;
    vector<pair<ll, ll>> v = factorize(k);
    ll ans = 1;
    rep(i, sz(v)){
        ll cnt = 0;
        for (ll j = v[i].first; j <= v[i].first*v[i].second; j += v[i].first) {
            ll num = j;
            while(num >= v[i].first && num % v[i].first == 0) {
                cnt++;
                num /= v[i].first;
            }
            if (v[i].second <= cnt) {
                ans = max(ans, v[i].first * (j/v[i].first));
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}