#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int popcnt(int x){
    return __builtin_popcount(x);
}

int f(int x){
    if (x == 0) return 0;
    return f(x%popcnt(x))+1;
}

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> x(n);
    rep(i,n) x[i] = s[i] - '0';

    int pCnt = 0;
    rep(i,n) pCnt += x[i];
    vector<int> ans(n);
    rep(b, 2){
        // 探索するビットの値によってpopcountを変更
        int pc = pCnt;
        if (b == 0) pc++;   // 0→1なのでpopcountを+1
        else pc--;          // 1→0なのでpopcountを-1
        if (pc <= 0) continue;

        // popcountでの余りを計算
        int r0 = 0;
        rep(i,n){
            r0 = (r0*2)%pc;
            r0 += x[i];
        }

        // 探索ビットと一致したらその値を加算 or 減算して余りが0になるまでの回数を計算
        // 1回目以降は2*10^5以下なので愚直に計算しても間に合う
        int r = 1;
        for(int i = n-1; i >= 0; i--){
            if (x[i] == b){
                int tmp;
                if (b == 0) tmp = (r0+r)%pc;    // 0→1になるから加算した余り
                else tmp = (r0-r+pc)%pc;        // 1→0になるから減算した余り  
                ans[i] = f(tmp)+1;              // 1回目の分を+1
            }
            r = (r*2)%pc;
        }
    }
    rep(i,n) cout << ans[i] << endl;
}