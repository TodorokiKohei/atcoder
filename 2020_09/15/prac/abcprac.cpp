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

int main(){
    int n, m;
    ll x, y;
    cin >> n >> m >> x >> y;
    VL a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];

    ll t = 0;
    int ai = 0, bi = 0, ans = 0;
    bool nowA = true;
    while(true){
        if (nowA){
            while(ai < n){
                if (t <= a[ai]) {
                    t = a[ai] + x;
                    break;
                }
                ai++;
            }
        }else{
            while(bi < m){
                if (t <= b[bi]){
                    t = b[bi] + y;
                    break;
                } 
                bi++;
            }
        }
        if (ai == n || bi == m) break;

        ans++;
        nowA = !nowA;
    }
    cout << ans/2 << endl;
    return 0;
}