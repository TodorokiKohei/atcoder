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

P f(int x){
    int a = x % 10;
    int b;
    while(x){
        b = x % 10;
        x /= 10;
    }
    return P(a, b);
}

int main(){
    int n;
    cin >> n;
    map<P, int> mp;
    for(int i = 1; i <= n; i++){
        P p = f(i);
        mp[p]++;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        P p = f(i);
        P to = P(p.second, p.first);
        ans += mp[to];
    }
    cout << ans << endl;
    return 0;
}