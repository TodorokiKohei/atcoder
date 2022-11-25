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
    int n;
    cin >> n;
    vector<int> a(n), l(n), r(n), m(n);
    rep(i,n) cin >> a[i];
    
    l[0] = a[0];
    for(int i = 1; i < n; i++){
        l[i] = gcd(l[i-1], a[i]);
    }
    r[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--){
        r[i] = gcd(r[i+1], a[i]);
    }

    m[0] = r[1];
    m[n-1] = l[n-2];
    for(int i = 1; i < n-1; i++){
        m[i] = gcd(l[i-1], r[i+1]);
    }
    int ans = 0;
    rep(i,n) ans = max(ans, m[i]);
    cout << ans << endl;
    return 0;
}