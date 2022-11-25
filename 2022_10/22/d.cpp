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

const int MX = 2*10000;

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    VVI dpX(n, VI(MX+1)), dpY(n+1, VI(MX+1));
    
    int ai;
    cin >> ai;
    dpX[0][(MX/2)+ai] = 1;
    dpY[0][MX/2] = 1;
    rep(i,n-1) {
        bool mvX;
        if (i % 2 == 0) mvX = false;
        else mvX = true;

        cin >> ai;
        for(int j = 0; j <= MX; j++){
            if (mvX){
                dpY[i+1][j] = dpY[i][j];
                if (dpX[i][j] != 1) continue;
                if (j+ai <= MX) dpX[i+1][j+ai] = dpX[i][j];
                if (j-ai >= 0) dpX[i+1][j-ai] = dpX[i][j];
            }
            else{
                dpX[i+1][j] = dpX[i][j];
                if (dpY[i][j] != 1) continue;
                if (j+ai <= MX) dpY[i+1][j+ai] = dpY[i][j];
                if (j-ai >= 0) dpY[i+1][j-ai] = dpY[i][j];
            }
        }
    }
    if (dpX[n-1][x+10000] == 1 && dpY[n-1][y+10000] == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}