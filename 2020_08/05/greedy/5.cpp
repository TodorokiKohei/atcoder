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
    int c;
    cin >> c;
    vector<int> n(c), m(c), l(c);
    rep(i,c) cin >> n[i] >> m[i] >> l[i];

    vector<int> maxV(3);
    rep(i,c){
        vector<int> v = {n[i], m[i], l[i]};
        sort(all(v));
        rep(j, 3){
            maxV[j] = max(maxV[j], v[j]);
        }
    }
    int ans = maxV[0] * maxV[1] * maxV[2];
    cout << ans << endl;    
    return 0;
}