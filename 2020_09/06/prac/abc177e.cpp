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


struct osak{
    vector<int> d;
    osak(int n) :d(n+1, 1) {
        for(int i = 2; i <= n; i++){
            if (d[i] != 1) continue;
            for(int j = i; j <= n; j += i){
                if (d[j] == 1) d[j] = i;
            }
        }
    }
    vector<P> factorize(int x){
        vector<P> res;
        int y = d[x];
        int cnt = 1;
        while(x != 1){
            x /= y;
            if (d[x] != y){
                res.push_back(P(y, cnt));
                cnt = 0;
            }
            y = d[x];
            cnt++;
        }
        return res;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    
    osak o(1e6);
    set<int> st;
    bool pw = true;
    rep(i,n){
        if (a[i] == 1) continue;
        auto res = o.factorize(a[i]);
        for(P p: res){
            if (st.find(p.first) != st.end()){
                pw = false;
                break;
            }
            st.insert(p.first);
        }
        if (!pw) break;
    }

    if (pw){
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