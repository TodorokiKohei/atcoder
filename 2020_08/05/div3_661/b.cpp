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

const ll INF = 1e9+5;

int main(){
    int t;
    cin >> t;
    rep(i,t){
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        rep(i,n) cin >> a[i];
        rep(i,n) cin >> b[i];
        ll minNumA = INF;
        ll minNumB = INF;
        rep(i,n){
            minNumA = min(minNumA, a[i]);
            minNumB = min(minNumB, b[i]);
        }
        ll ans = 0;
        rep(i,n){
            ans += max(a[i]-minNumA, b[i]-minNumB);
        }
        cout << ans << endl;
    }
    return 0;
}