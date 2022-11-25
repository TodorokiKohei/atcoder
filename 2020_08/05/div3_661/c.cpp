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
    int t;
    cin >> t;
    rep(i,t){
        int n;
        cin >> n;
        vector<int> w(51);
        rep(j,n){
            int wi;
            cin >> wi;
            w[wi]++;
        }

        vector<int> teamW(101);
        rep(j,51) rep(k,51){
            if (j == k) teamW[j+k] += w[j];
            else teamW[j+k] += min(w[j], w[k]);
        }
        int ans = 0;
        rep(j, 101){
            ans = max(ans, teamW[j]/2);
        }
        cout << ans << endl;
    }
    return 0;
}