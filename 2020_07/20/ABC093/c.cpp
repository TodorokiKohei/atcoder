#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    vector<int> x(3);
    rep(i,3) cin >> x[i];
    sort(all(x));
    int e = 0, o = 0;
    rep(i,3){
        if (x[i] % 2 == 0) e++;
        else o++;
    }
    
    int ans = 0;
    if (e == 1 && o == 2){
        rep(i,3) if (x[i] % 2 != 0) x[i]++;
        ans++;
    }else if (e == 2 && o == 1){
        rep(i,3) if (x[i] % 2 == 0) x[i]++;
        ans++;
    }
    ans += (x[2]-x[0])/2;
    ans += (x[2]-x[1])/2;
    cout << ans << endl;
    return 0;
}