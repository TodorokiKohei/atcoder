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
    vector<P> ps(n);
    rep(i,n){
        int x, y;
        cin >> x >> y;
        ps[i] = make_pair(x, y);
    }
    set<P> st;
    rep(i,n) st.insert(ps[i]);
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int xDis, yDis;
            xDis = ps[j].first - ps[i].first;
            yDis = ps[j].second - ps[i].second;
            P p1, p2;
            p1 = make_pair(ps[i].first-yDis, ps[i].second+xDis);
            p2 = make_pair(ps[j].first-yDis, ps[j].second+xDis);
            if (st.find(p1) != st.end() && st.find(p2) != st.end()){
                ans = max(ans, xDis*xDis + yDis*yDis);
                continue;
            }
            p1 = make_pair(ps[i].first+yDis, ps[i].second-xDis);
            p2 = make_pair(ps[j].first+yDis, ps[j].second-xDis);
            if (st.find(p1) != st.end() && st.find(p2) != st.end()){
                ans = max(ans, xDis*xDis + yDis*yDis);
                continue;
            }
        }
    }
    cout << ans << endl;
    return 0;
}