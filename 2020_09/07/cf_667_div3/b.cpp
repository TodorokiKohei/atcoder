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
    int t;
    cin >> t;
    while(t--){
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;

        ll a1 = a, b1 = b, x1 = x, y1 = y, n1 = n;
        ll a2 = a, b2 = b, x2 = x, y2 = y, n2 = n;

        if (a1 - x1 > n1){
            a1 -= n1;
        }else{
            n1 -= a1 - x1;
            a1 = x1;
            b1 = max(b1-n1, y1);
        }

        if (b2 - y2 > n2){
            b2 -= n2;
        }else{
            n2 -= b2 - y2;
            b2 = y2;
            a2 = max(a2-n2, x2);
        }
        ll ans = min(a1 * b1, a2 * b2);
        cout << ans << endl;
    }
    return 0;
}