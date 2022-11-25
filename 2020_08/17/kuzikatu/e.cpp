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

const ll INF = 1LL<<60;

int main(){
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a), t(b);
    rep(i, a) cin >> s[i];
    rep(i, b) cin >> t[i];
    vector<ll> ans;
    rep(i,q){
        ll x;
        cin >> x;
        int pos1 = lower_bound(all(s), x) - s.begin();
        int pos2 = lower_bound(all(t), x) - t.begin();
        vector<ll> s1, t1;
        if (pos1 != 0) s1.push_back(s[pos1-1]);
        if (pos1 != a) s1.push_back(s[pos1]);
        if (pos2 != 0) t1.push_back(t[pos2-1]);
        if (pos2 != b) t1.push_back(t[pos2]);

        ll dis = INF;
        rep(i, s1.size()) rep(j, t1.size()){
            dis = min(dis, abs(x-s1[i]) + abs(s1[i] - t1[j]));
            dis = min(dis, abs(x-t1[j]) + abs(s1[i] - t1[j]));
        }
        ans.push_back(dis);
    }
    rep(i,q) cout << ans[i] << endl;
    return 0;
}