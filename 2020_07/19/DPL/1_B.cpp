#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define  all(x) (x).begin(),(x).end()
typedef long long ll;

int main(){
    int n, w;
    cin >> n >> w;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vector<vector<int>> dp(n+1, vector<int>(w+1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= w; j++){
            dp[i+1][j] = max(dp[i][j], dp[i+1][j]);
            if (j+b[i] <= w){
                dp[i+1][j+b[i]] = max(dp[i][j+b[i]], dp[i][j]+a[i]);
            }
        }
    }
    cout << dp[n][w] << endl;
}