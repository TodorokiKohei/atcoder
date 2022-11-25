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
    vector<P> r(n);
    rep(i,n){
        int x, l;
        cin >> x >> l;
        r[i] = make_pair(x+l, x-l);
    }

    sort(all(r));
    int cur = -1e9;
    int ans = 0;
    rep(i,n){
        if (cur <= r[i].second){
            ans++;
            cur = r[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}