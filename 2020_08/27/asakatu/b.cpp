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
    int x;
    cin >> x;
    int ans = 0;
    for(int b = 1; b <= 100; b++){
        for(int p = 2; p <= 10; p++){
            int y = 1;
            rep(i,p) y *= b;
            if (y <= x) ans = max(ans, y);
            else break;
        }
    }
    cout << ans << endl;
    return 0;
}