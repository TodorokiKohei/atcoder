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
    string s, t;
    cin >> s >> t;
    int ans = 10000;
    rep(i, s.size()){
        if (i + t.size() - 1 >= s.size()) break;
        int cnt = 0;
        rep(j, t.size()){
            if (s[i+j] != t[j]) cnt++;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}