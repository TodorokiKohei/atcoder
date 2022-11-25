#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int mod = 2019;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    ll d = 1, r = 0;
    vector<ll> cnts(mod);
    cnts[r]++;
    rep(i,n){
        r += (s[i]-'0')*d;
        r %= mod;
        cnts[r]++;
        d = d*10%mod;
    }

    ll ans = 0;
    rep(i,mod){
        ans += (cnts[i]*(cnts[i]-1)) / 2;
    }
    cout << ans << endl;
    return 0;
}
