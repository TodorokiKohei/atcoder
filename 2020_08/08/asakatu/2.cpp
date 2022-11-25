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
    ll n, a, b;
    cin >> n >> a >> b;
    if ((b-a) % 2 == 0){
        cout << (b-a)/2 << endl;
    }
    else {
        ll ans = 0;
        if (b-1 < n-a){
            ans += a-1;
            ans++;
            b -= ans;
            ans += (b-1)/2;
        }else{
            ans += n-b;
            ans++;
            a += ans;
            ans += (n-a)/2;
        }
        cout << ans << endl;
    }
    return 0;
}