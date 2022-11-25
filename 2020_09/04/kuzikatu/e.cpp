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

ll D = 1e9;

int main(){
    int n;
    cin >> n;
    vector<double> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> b(n);
    rep(i,n) b[i] = a[i] * D + 0.5;
    map<P, ll> mp;
    rep(i, n){
        int x = 0, y = 0;
        ll bi = b[i];
        while(bi % 2 == 0 && x <19){
            x++;
            bi /= 2;
        }
        bi = b[i];
        while(bi % 5 == 0 && y < 19){
            y++;
            bi /= 5;
        }
        mp[P(x,y)]++;
    }

    ll ans = 0;
    for(auto m1: mp){
        for(auto m2: mp){
            P p1 = m1.first, p2 = m2.first;
            if (p1.first + p2.first < 18 || p1.second + p2.second < 18) continue;
            if (m1 == m2){
                ans += m1.second * (m2.second-1);
            }else{
                ans += m1.second * m2.second;
            }
        }
    }
    ans /= 2;
    cout << ans << endl;
    return 0;
}