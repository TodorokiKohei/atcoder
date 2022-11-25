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
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    string ans = "";
    for(int i = sx; i < tx; i++){
        ans += "R";
    }
    for(int i = sy; i < ty; i++){
        ans += "U";
    }
    for(int i = sx; i < tx; i++){
        ans += "L";
    }
    for(int i = sy; i < ty; i++){
        ans += "D";
    }
    ans += "D";
    for(int i = sx; i <= tx; i++){
        ans += "R";
    }

    for(int i = sy; i <= ty; i++){
        ans += "U";
    }

    ans += "L";
    ans += "U";
    for(int i = sx; i <= tx; i++){
        ans += "L";
    }

    for(int i = sy; i <= ty; i++){
        ans += "D";
    }
    ans += "R";

    cout << ans << endl;
    return 0;
}