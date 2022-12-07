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
    int n, s;
    cin >> n >> s;
    VP ab(n);
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        ab[i] = {a, b};
    }

    VVI dp(n+1, VI(s+1));
    dp[0][0] = 1;
    rep(i,n) {
        rep(j, s+1) {
            if (dp[i][j] == 1) {
                if (j + ab[i].first <= s ) dp[i+1][j+ab[i].first] = 1;
                if (j + ab[i].second <= s ) dp[i+1][j+ab[i].second] = 1;
            }
        }
    }
    if (dp[n][s] == 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    string ans(n, 'H');
    rrep(i, n) {
        if (s - ab[i].first >= 0 && dp[i][s-ab[i].first] == 1) {
            s -= ab[i].first;
            ans[i] = 'H';
        }else {
            s -= ab[i].second;
            ans[i] = 'T';
        }
    }
    rep(i,n) cout << ans[i];
    cout << endl;
    return 0;
}