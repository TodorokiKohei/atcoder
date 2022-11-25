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
    int h, w, m;
    cin >> h >> w >> m;
    map<int, int> mpRow, mpCol;
    set<P> target;
    rep(i,m){
        int hi, wi;
        cin >> hi >> wi;
        hi--; wi--;
        mpCol[wi]++;
        mpRow[hi]++;
        target.insert(make_pair(hi, wi));
    }
    int mxRowCnt = 0, mxColCnt = 0;
    for(auto mp : mpRow) mxRowCnt = max(mxRowCnt, mp.second);
    for(auto mp : mpCol) mxColCnt = max(mxColCnt, mp.second);
    set<int> stRow, stCol;
    for(auto mp : mpRow) if (mxRowCnt == mp.second) stRow.insert(mp.first);
    for(auto mp : mpCol) if (mxColCnt == mp.second) stCol.insert(mp.first);
    int ans = mxRowCnt + mxColCnt;
    bool ok = false;
    for(int sr : stRow){
        for(int sc: stCol){
            if (target.find(make_pair(sr, sc)) == target.end()){
                ok = true;
                break;
            }
        }
    }
    if (ok) cout << ans << endl;
    else cout << ans-1 << endl;
    return 0;
}