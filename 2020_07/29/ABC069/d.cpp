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

int main(){
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<int>> ans(h, vector<int>(w));
    int now = 0, cnt = 0;
    rep(row, h) rep(col, w){
        ans[row][col] = now+1;
        cnt++;
        if (a[now] == cnt){
            now++;
            cnt = 0;
        }
    }
    for(int i = 1; i < h; i+=2){
        reverse(all(ans[i]));
    }
    rep(row, h){
        rep(col, w){
            cout << ans[row][col] << " ";
        }
        cout << endl;
    }
    return 0;
}