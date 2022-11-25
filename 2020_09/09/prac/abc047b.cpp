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

int main(){
    int w, h, n;
    cin >> w >> h >> n;
    VVI mp(h, VI(w));
    rep(i,n){
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1){
            for(int j = 0; j < h; j++){
                for(int k = 0; k < x; k++){
                    mp[j][k] = 1;
                }
            }
        }else if (a == 2){
            for(int j = 0; j < h; j++){
                for(int k = x; k < w; k++){
                    mp[j][k] = 1;
                }
            }
        }else if (a == 3){
            for(int j = 0; j < y; j++){
                for(int k = 0; k < w; k++){
                    mp[j][k] = 1;
                }
            }
        }else{
            for(int j = y; j < h; j++){
                for(int k = 0; k < w; k++){
                    mp[j][k] = 1;
                }
            }
        }
    }
    int ans = 0;
    rep(i, h) rep(j, w){
        if (mp[i][j] == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}