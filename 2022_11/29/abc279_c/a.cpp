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
    int h, w;
    cin >> h >> w;
    vector<string> s(h), t(h);
    rep(i,h) cin >> s[i];
    rep(i,h) cin >> t[i];
    unordered_map<string, int> cnt;
    rep(col, w) {
        string tLine = "";
        rep(row, h) {
            tLine += t[row][col];
        }
        cnt[tLine]++;
    }
    rep(col, w) {
        string sLine = "";
        rep(row, h) {
            sLine += s[row][col];
        }
        if (cnt.find(sLine) == cnt.end() || cnt[sLine] == 0) {
            cout << "No" << endl;
            return 0;
        } 
        cnt[sLine]--;
    }
    cout << "Yes" << endl;
    return 0;
}