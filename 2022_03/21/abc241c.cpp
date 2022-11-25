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
    int n;
    cin >> n;
    VVI s(n, VI(n));
    rep(i,n){
        string si;
        cin >> si;
        rep(j,n){
            if (si[j] == '#') s[i][j] = 1;
            else s[i][j] = 0;
        }
    }
    rep(i,n) rep(j,n){
        VI x = {0, 1, 1, 1, 0, -1, -1, -1};
        VI y = {1, 1, 0, -1, -1, -1, 0, 1};
        rep(k, 8){
            int xi = i, yi = j;
            int cnt = s[xi][yi];
            bool ng = false;
            rep(l, 5){
                xi += x[k];
                yi += y[k];
                if (xi < 0 || xi >= n) ng = true;
                if (yi < 0 || yi >= n) ng = true;
                if (ng) break;
                cnt += s[xi][yi];
            }
            if (!ng && cnt >= 4){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}