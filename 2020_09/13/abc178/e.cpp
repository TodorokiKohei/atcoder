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

const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    VL dis1, dis2;
    rep(i,n){
        ll x, y;
        cin >> x >> y;
        ll xx = x - y;
        ll yy = x + y;
        dis1.push_back(xx);
        dis2.push_back(yy);
    }
    sort(all(dis1));
    sort(all(dis2));
    ll ans = 0;
    ans = max(ans, dis1[n-1] - dis1[0]);
    ans = max(ans, dis2[n-1] - dis2[0]);
    cout << ans << endl;
    return 0;
}