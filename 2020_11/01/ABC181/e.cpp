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

const int inf = 1 << 30;
const ll INF = 1LL << 60;

int main(){
    int n, m;
    cin >> n >> m;
    VL h(n), w(m);
    rep(i,n) cin >> h[i];
    rep(i,m) cin >> w[i];
    sort(all(h));
    VL diffHL(n), diffHR(n);
    for(int i = 0; i < n-1; i += 2) diffHL[i] += h[i+1] - h[i];
    for(int i = n-1; i > 0; i -= 2) diffHR[i] += h[i] - h[i-1];
    VL sumHL(n+1), sumHR(n+1);
    rep(i,n) sumHL[i+1] = sumHL[i] + diffHL[i];
    rrep(i,n) sumHR[i] = sumHR[i+1] + diffHR[i];
    ll ans = INF;
    rep(i,m){
        int j = lower_bound(all(h), w[i]) - h.begin();
        if (j % 2 == 1) j--;
        ll sum = 0;
        sum += sumHL[j] + sumHR[j+1];
        sum += abs(h[j] - w[i]);
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}