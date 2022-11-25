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
    int n;
    cin >> n;
    vector<P> c(n);
    rep(i,n) cin >> c[i].first >> c[i].second;
    set<P> st;
    rep(i,n) st.insert(c[i]);
    int ans = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i == j) continue;
            int p = c[j].first - c[i].first;
            int q = c[j].second - c[i].second;
            int sum = n;
            for(int k = 0; k < n; k++){
                P point = make_pair(c[k].first - p, c[k].second - q);
                if (st.find(point) != st.end()) sum--;
            }
            ans = min(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}