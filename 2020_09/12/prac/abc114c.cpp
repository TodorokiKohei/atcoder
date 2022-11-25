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

int ans, n;

bool ok(ll x){
    vector<int> d(10);
    while(x){
        d[x%10]++;
        x /= 10;
    }
    if (d[3] >= 1 && d[5] >= 1 && d[7] >= 1) return true;
    else return false;
}

void dfs(ll x){
    if (x > n) return;
    if (ok(x)) ans++;
    x *= 10;
    for(int i =3; i <= 7; i += 2){
        dfs(x + i);
    }
}

int main(){
    cin >> n;
    ans = 0;
    dfs(0);
    cout << ans << endl;
    return 0;
}