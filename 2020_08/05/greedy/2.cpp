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
    string s;
    cin >> s;
    P p = {0, 0};
    int q = 0;
    rep(i, s.size()){
        if (s[i] == 'L') p.first--;
        else if (s[i] == 'R') p.first++;
        else if (s[i] == 'U') p.second++;
        else if (s[i] == 'D') p.second--;
        else q++;
    }

    int ans = abs(p.first) + abs(p.second);
    int t;
    cin >> t;
    if (t == 2){
        ans -= q;
        if (ans % 2 == 0) cout << max(ans, 0) << endl;
        else cout << max(ans, 1) << endl;
    }
    else{
        ans += q;
        cout << ans << endl;
    }
    return 0;
}