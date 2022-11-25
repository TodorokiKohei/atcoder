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

const int inf = 1 << 29;
const ll INF = 1LL << 60;

int main(){
    int n, k;
    cin >> n >> k;
    VI a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    vector<vector<bool>> dp(2, vector<bool>(n));
    dp[0][0] = true; dp[1][0] = true;
    for(int i = 1; i < n; i++){
        if (dp[0][i-1]){
            if (abs(a[i] - a[i-1]) <= k) dp[0][i] = true;
            if (abs(b[i] - a[i-1]) <= k) dp[1][i] = true;
        }
        if (dp[1][i-1]){
            if (abs(a[i] - b[i-1]) <= k) dp[0][i] = true;
            if (abs(b[i] - b[i-1]) <= k) dp[1][i] = true;
        }
    }
    rep(i,2){
        if (dp[i][n-1]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}