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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    for(int i = 0; i <= h+1; i++){
        if (i == 0 || i == h+1){
            for(int j = 0; j <= w+1; j++){
                cout << "#";
            }
        }else{
            for(int j = 0; j <= w+1; j++){
                if (j == 0 || j == w+1) cout << "#";
                else cout << s[i-1][j-1];
            }
        }
        cout << endl;
    }
    return 0;
}