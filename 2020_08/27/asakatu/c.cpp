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
    int loop = (n / 5) % 6;
    int r = n % 5;
    string ans;
    if (loop == 0) ans = "123456";
    else if (loop == 1) ans = "234561";
    else if (loop == 2) ans = "345612";
    else if (loop == 3) ans = "456123";
    else if (loop == 4) ans = "561234";
    else if (loop == 5) ans = "612345";
    rep(i,r){
        swap(ans[i], ans[i+1]);
    }
    cout << ans << endl;
    return 0;
}