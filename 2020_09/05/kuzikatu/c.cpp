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
    string s;
    cin >> s;
    int r = 0;
    rep(i,n){
        if (s[i] == 'R') r++;
    } 

    int a = 0, b = r;
    int ans = 2e6;
    rep(i,n+1){
        int sum = max(a, b);
        ans = min(ans, sum);
        if (i == n) break;
        if (s[i] == 'W') a++;
        else b--;
    }
    cout << ans << endl;
    return 0;
}