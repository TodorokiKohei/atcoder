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

const int mod = 1e9+7;

int main(){
    int n;
    string s;
    cin >> n >> s;
    map<char, ll> mp;
    rep(i,n) mp[s[i]]++;
    ll ans = 1;
    for(auto m: mp){
        ans = (ans * (m.second+1)) % mod;
    }
    ans = ((ans - 1) + mod) % mod;
    cout << ans << endl;
    return 0;
}