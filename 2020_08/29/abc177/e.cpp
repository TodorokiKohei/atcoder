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

vector<pair<ll, int>> factorize(ll n){
    vector<pair<ll, int>> res;
    for (ll i = 2; i*i <= n; ++i){
        if (n%i) continue;
        res.emplace_back(i, 0);
        while (n%i == 0){
            n /= i;
            res.back().second++;
        }
    }
    if(n != 1) res.emplace_back(n, 1);
    return res;
}

const int MAX = 1e6+5;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> d(MAX);
    rep(i,n){
        cin >> a[i];
        d[a[i]]++;
    }

    bool p = true;
    for(int i = 2; i <= MAX; i++){
        int cnt = 0;
        for(int j = i; j <= MAX; j += i){
            cnt += d[j];
        }
        if (cnt > 1) p = false;
    }

    if (p){
        cout << "pairwise coprime" << endl;
        return 0;
    }

    int g = a[0];
    for(int i = 1; i < n; i++){
        g = __gcd(g, a[i]);
    }

    if (g == 1){
        cout << "setwise coprime" << endl;
        return 0;
    }

    cout << "not coprime" << endl;
    return 0;
}