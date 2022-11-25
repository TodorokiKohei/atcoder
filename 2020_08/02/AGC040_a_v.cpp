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
    string s; 
    cin >> s;
    vector<ll> a(s.size()+1);
    rep(i, s.size()){
        if (s[i] == '<'){
            chmax(a[i+1], a[i]+1);
        }
    }
    for(int i = s.size()-1; i >= 0; i--){
        if (s[i] == '>'){
            chmax(a[i], a[i+1]+1);
        }
    }
    ll ans = 0;
    rep(i, s.size()+1) ans += a[i];
    cout << ans << endl;
    return 0;
}