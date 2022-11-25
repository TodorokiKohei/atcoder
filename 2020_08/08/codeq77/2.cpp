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
    vector<int> r(n);
    rep(i,n) cin >> r[i];
    vector<int> diff(n-1);
    rep(i,n-1) diff[i] = r[i+1] - r[i];
    int ans = 2, ope = 2;
    for(int i = 0; i < n-1; i++){
        if (ope == 2){
            if (diff[i] > 0) ope = 0;
            else if (diff[i] < 0) ope = 1;
        }
        else if (ope == 0){
            if (diff[i] < 0){
                ope = 1;
                ans++;
            }
        }
        else if (ope == 1){
            if (diff[i] > 0){
                ope = 0;
                ans++;
            }
        }
    }
    if (ans < 3) cout << 0 << endl;
    else cout << ans << endl;
    return 0;
}