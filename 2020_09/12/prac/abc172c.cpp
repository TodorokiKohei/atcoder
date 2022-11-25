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
    int n, m, k;
    cin >> n >> m >> k;
    VL a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    VL sumA(n+1), sumB(m+1);
    rep(i,n) sumA[i+1] = sumA[i] + a[i];
    rep(i,m) sumB[i+1] = sumB[i] + b[i];


    int ans = 0, right = m;
    for(int i = 0; i <= n; i++){
        if (sumA[i] > k) break;
        while(right >= 0){
            if (sumA[i] + sumB[right] <= k) break;
            right--;
        }
        ans = max(ans, i + right);
    }
    cout << ans << endl;
    return 0;
}