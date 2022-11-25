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

vector<ll> enumerate_num(ll x){
    vector<ll> res;
    for(ll i = 1; i * i <= x; i++){
        if (x % i == 0){
            res.push_back(i);
            if (i * i != x) res.push_back(x / i);
        }
    }
    sort(all(res));
    return res;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> res = enumerate_num(n);
    int ans = 10, sz = res.size();
    int left = 0, right = sz-1;
    while(left <= right){
        string s1 = to_string(res[left]);
        string s2 = to_string(res[right]);
        ans = min(ans, (int)max(s1.size(), s2.size()));
        left++; right--;
    }
    cout << ans << endl;
    return 0;
}