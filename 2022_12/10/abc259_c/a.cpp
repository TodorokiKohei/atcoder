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

void rle(string s, vector<pair<char, int>> &vec) {
    int cnt = 1;
    for(int i = 1; i < sz(s); i++) {
        if (s[i] != s[i-1]) {
            vec.push_back({s[i-1], cnt});
            cnt = 0;
        }
        cnt++;
    }
    vec.push_back({s.back(), cnt});
}

int main(){
    string s, t;
    cin >> s >> t;
    vector<pair<char, int>> svec, tvec;
    rle(s, svec); rle(t, tvec);
    if (sz(svec) != sz(tvec)) {
        cout << "No" << endl;
        return 0;
    }
    rep(i, sz(svec)) {
        if (svec[i].first != tvec[i].first) {
            cout << "No" << endl;
            return 0;
        }
        if (svec[i].second == tvec[i].second) continue;
        if (svec[i].second > 1 && svec[i].second <= tvec[i].second) continue;
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}