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
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    vector<vector<int>> s(h, vector<int>(w));
    rep(i,h){
        int num;
        if (i < b) num = 0;
        else num = 1;
        rep(j,w){
            if (j < a) s[i][j] = num;
            else s[i][j] = !num;
        }
    }

    rep(i,h){
        rep(j,w) cout << s[i][j];
        cout << endl;
    }
    return 0;
}