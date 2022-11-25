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
    int n, m;
    cin >> n >> m;
    set<P> st;
    rep(i,m){
        int x, y;
        cin >> x >> y;
        x--; y--;
        st.insert(make_pair(x,y));
    }

    int ans = 0;
    for(int i = 1; i < 1<<n; i++){
        vector<bool> sel(n);
        rep(j,n) if (i>>j &1) sel[j] = true;
        int sum = 0;
        for(int j = 0; j < n; j++){
            if (!sel[j]) continue;
            bool ok = true;
            for(int k = 0; k < n; k++){
                if (j == k) continue;
                if (sel[k]){
                    int x = j, y = k;
                    if (x > y) swap(x, y);
                    if (st.find(make_pair(x,y)) == st.end()){
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) sum++;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}