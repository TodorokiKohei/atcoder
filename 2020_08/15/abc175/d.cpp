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

const ll INF = 1LL<<60;

int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> c(n), p(n);
    rep(i,n){
        cin >> p[i];
        p[i]--;
    }
    rep(i,n) cin >> c[i];
    vector<P> loop(n);
    vector<ll> sums;
    vector<vector<ll>> g;
    int gi = 1;
    rep(i, n){
        if (loop[i].first != 0) continue;
        int j = i, s = 0;
        vector<ll> ten;
        ll sum = c[i];

        loop[j] = make_pair(gi, s);
        ten.push_back(c[j]);
        j = p[i];
        while(loop[j].first == 0){
            ten.push_back(c[j]);
            sum += c[j];
            loop[j] = make_pair(gi, ++s);
            j = p[j];
        }
        g.push_back(ten);
        sums.push_back(sum);
        gi++;
    }

    ll ans = -INF;
    rep(i,n){
        int lNum = loop[i].first-1, pos = loop[i].second;
        ll sum = 0;
        ll kk = k;
        if (sums[lNum] > 0 && kk > g[lNum].size()){
            sum += (kk / g[lNum].size() - 1) * sums[lNum];
            kk %= g[lNum].size();
            kk += g[lNum].size();
            ans = max(ans, sum);
        }else if (kk > g[lNum].size()){
            kk = g[lNum].size();
        }
        while(kk){
            pos = (pos+1) % g[lNum].size();
            sum += g[lNum][pos];
            ans = max(ans, sum);
            kk--;
        }
    }
    cout << ans << endl;
    return 0;
}