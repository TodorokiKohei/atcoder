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
    int n;
    cin >> n;
    VI d(n);
    rep(i,n) cin >> d[i];
    int m;
    cin >> m;
    VI t(m);
    rep(i,m) cin >> t[i];

    sort(all(d));
    sort(all(t));
    int left = 0;
    rep(i,m){
        while (left < n) {
            if (t[i] == d[left]) break;
            left++;
        }
        if (left >= n){
            cout << "NO" << endl;
            return 0;
        }
        left++;
    }
    cout << "YES" << endl;
    return 0;
}