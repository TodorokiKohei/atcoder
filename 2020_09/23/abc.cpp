#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

vector<pair<ll, int>> factorize(ll n){
    vector<pair<ll, int>> res;
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
    int n;
    cin >> n;
    map<int, ll> mp;
    for(int i = 1; i <= n; i++){
        auto res = factorize(i);
        for(auto r : res){
            mp[r.first] += r.second;
        }
    }
    vector<pair<ll, int>> res;
    for(auto m: mp){
        res.push_back(make_pair(m.first, m.second));
    }

    int sz = res.size();
    VVL dp(sz+1, VL(77));
    dp[0][1] = 1;
    rep(i, sz){
        int num = res[i].second;
        rep(j, 76) {
            rep(k, num+1){
                int to = min(j * (k+1), 76);
                dp[i+1][to] += dp[i][j];
            }
        }
    }
    ll ans = dp[sz][75];
    cout << ans << endl;
    return 0;
}
