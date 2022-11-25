#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int INF = 1<<30;

int main(){
    int h, n;
    cin >> h >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vector<vector<int>> dp(n+1, vector<int>(h+1, INF));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= h; j++){
            int next = min(h, j+a[i]);
            dp[i+1][j] = min(dp[i][j], dp[i+1][j]);
            dp[i+1][next] = min(dp[i+1][next], dp[i+1][j]+b[i]);
        }
    }
    cout << dp[n][h] << endl;
}