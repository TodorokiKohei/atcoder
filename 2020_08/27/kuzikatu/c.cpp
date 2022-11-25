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
    map<ll, ll> mp;
    rep(i,n){
        ll a;
        cin >> a;
        mp[a]++;
    }

    if (mp.find(0) != mp.end()){
        if (mp.size() == 1){
            cout << "Yes" << endl;
            return 0;
        }else if (mp.size() == 2 && mp[0] * 3 == n){
            cout << "Yes" << endl;
            return 0;
        }else{
            cout << "No" << endl;
            return 0;
        }
    }else{
        if (mp.size() == 3){
            int ans = 0;
            for(auto m: mp){
                if (m.second * 3 != n){
                    cout << "No" << endl;
                    return 0;
                }
                ans ^= m.first;
            }
            if (ans == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
            return 0;
        }else{
            cout << "No" << endl;
            return 0;
        }
    }
    return 0;
}