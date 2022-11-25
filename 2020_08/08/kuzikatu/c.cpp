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
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    ll lcm = n / __gcd(n, m) * m;
    map<ll, char> mp;
    for(int i = 0; i < s.size(); i++){
        ll j = i * (lcm/n) + 1;
        mp[j] = s[i];
    }
    for(int i = 0; i < t.size(); i++){
        ll j = i * (lcm/m) + 1;
        if (mp.find(j) != mp.end()){
            if (mp[j] != t[i]){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << lcm << endl;
    return 0;
}