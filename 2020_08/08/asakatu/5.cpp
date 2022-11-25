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

int main(){
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    a1 *= t1; 
    a2 *= t2;
    b1 *= t1;
    b2 *= t2;
    if (a1 + a2 == b1 + b2){
        cout << "infinity" << endl;
        return 0;
    }else if (a1 + a2 < b1 + b2){
        swap(a1, b1);
        swap(a2, b2);
    }

    if (a1 < b1){
        ll c = b1 - a1;
        ll d = (a1 + a2) - (b1 + b2);
        ll ans = (c / d) * 2;
        if (c % d != 0) ans++;
        cout << ans << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}