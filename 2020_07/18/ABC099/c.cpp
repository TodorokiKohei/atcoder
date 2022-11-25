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
    int n;
    cin >> n;
    vector<int> m;
    m.push_back(1);
    int x = 6;
    while(x <= n){
        m.push_back(x);
        x *= 6;
    }
    x = 9;
    while(x <= n){
        m.push_back(x);
        x *= 9;
    }
    sort(all(m));

    // vector<int> dp(n+1, INF);
    // dp[0] = 0;
    // for(int i = 0; i < m.size(); i++){
    //     int x = m[i];
    //     for(int j = 0; j <= n; j++){
    //         if (j+x > n) break;
    //         dp[j+x] = min(dp[j+x], dp[j]+1);
    //     }
    // }
    // cout << dp[n] << endl;

    vector<vector<int>> dp(m.size()+1, vector<int>(n+1, INF));
    dp[0][0] = 0;
    for(int i = 0; i < m.size(); i++){
        int x = m[i];
        for(int j = 0; j <= n; j++){
            dp[i+1][j] = min(dp[i][j], dp[i+1][j]);
            if (j + x <= n){
                dp[i+1][j+x] = min(dp[i+1][j+x], dp[i+1][j]+1);
            }
        }
    }
    cout << dp[m.size()][n] << endl;
}