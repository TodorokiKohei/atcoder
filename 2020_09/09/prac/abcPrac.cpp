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

ll dp1[19][2], dp2[19][2];

void f(string s, ll (&dp)[19][2]){
    int n = s.size();
    dp[0][0] = 1;
    rep(i, n){
        int num = s[i] - '0';
        rep(d, 10){
            int ni = i+1;
            if (d == 4 || d == 9) continue;
            if (d < num){
                dp[ni][1] += dp[i][0];
                dp[ni][1] += dp[i][1];
            }else if (d == num){
                dp[ni][1] += dp[i][1];
                dp[ni][0] += dp[i][0];
            }else{
                dp[ni][1] += dp[i][1];
            }
        }
    }
}

int main(){
    string a, b;
    cin >> a >> b;
    int na = a.size(), nb = b.size();

    f(a, dp1);
    f(b, dp2);

    ll numb = dp2[nb][0] + dp2[nb][1];
    ll numa = dp1[na][1];
    ll num = stoll(b) - stoll(a) + 1;
    cout << num - (numb - numa) << endl;
    return 0;
}