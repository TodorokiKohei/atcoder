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
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    int ans = 0;
    rep(i, 1<<h){
        rep(j,1<<w){
            vector<int> hb(h);
            rep(r, h) if (i>>r & 1) hb[r] = 1;
            vector<int> wb(w);
            rep(c, w) if (j>>c & 1) wb[c] = 1;

            int kuro = 0;
            rep(row, h){
                rep(col, w){
                    if (hb[row] == 0 && wb[col] == 0 && s[row][col] == '#') kuro++;
                }
            }
            if (kuro == k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}