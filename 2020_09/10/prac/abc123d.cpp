#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int x, y, z, K;
    cin >> x >> y >> z >> K;
    VL a(x), b(y), c(z);
    rep(i,x) cin >> a[i];
    rep(i,y) cin >> b[i];
    rep(i,z) cin >> c[i];

    sort(rall(a));
    sort(rall(b));
    sort(rall(c));

    priority_queue<pair<ll, tuple<int, int, int>>> pq;
    VL ans;
    set<tuple<int, int, int>> st;
    st.insert(tuple(0, 0, 0));
    pq.push(pair(a[0] + b[0] + c[0], tuple(0, 0, 0)));
    while((int)ans.size() <= K){
        auto p = pq.top(); pq.pop();
        int i = get<0>(p.second);
        int j = get<1>(p.second);
        int k = get<2>(p.second);
        ans.push_back(p.first);

        if (i + 1 < x && st.find(tuple(i+1, j, k)) == st.end()){
            pq.push(pair(a[i+1] + b[j] + c[k], tuple(i+1, j, k)));
            st.insert(tuple(i+1, j, k));
        }
        if (j + 1 < y && st.find(tuple(i, j+1, k)) == st.end()){
            pq.push(pair(a[i] + b[j+1] + c[k], tuple(i, j+1, k)));
            st.insert(tuple(i, j+1, k));
        }
        if (k + 1 < z && st.find(tuple(i, j, k+1)) == st.end()){
            pq.push(pair(a[i] + b[j] + c[k+1], tuple(i, j, k+1)));
            st.insert(tuple(i, j, k+1));
        }
    }

    rep(i,K) cout << ans[i] << endl;
    return 0;
}