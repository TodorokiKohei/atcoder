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

const int INF = 1<<30;

int main(){
    int n, m;
    cin >> n >> m;
    vector<P> s(n), p(m);
    vector<int> ans(n);
    rep(i,n) cin >> s[i].first >> s[i].second;
    rep(i,m) cin >> p[i].first >> p[i].second;
    rep(i,n){
        int x = s[i].first, y = s[i].second;
        int minDis = INF;
        rep(j,m){
            int dis = abs(p[j].first-x) + abs(p[j].second-y);
            if (chmin(minDis, dis)) ans[i] = j+1;
        }
    }
    rep(i,n) cout << ans[i] << endl;
    return 0;
}