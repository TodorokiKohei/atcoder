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
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    ll ba = 0, a = 0, b = 0, ans = 0;
    rep(i,n){
        string si = s[i];
        int sz = si.size();
        rep(j, sz-1){
            if (si.substr(j, 2) == "AB") ans++;
        }
        if (si[0] == 'B' && si[sz-1] == 'A') ba++;
        else if (si[0] == 'B') b++;
        else if (si[sz-1] == 'A') a++;
    }
    if (ba == 0){
        ans += min(a, b);
    }
    else{
        if (a + b == 0){
            ans += ba-1;
        }else{
            ans += ba + min(a, b);
        }
    }
    cout << ans << endl;
    return 0;
}