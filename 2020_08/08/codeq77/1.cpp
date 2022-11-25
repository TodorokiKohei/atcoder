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
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    ll cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= n; i++){
        if (i % k == 0) cnt1++;
        else if (k % 2 == 0 && i % (k/2) == 0) cnt2++;
    }
    ans += cnt1 * cnt1 * cnt1;
    ans += cnt2 * cnt2 * cnt2;
    cout << ans << endl;
    return 0;
}