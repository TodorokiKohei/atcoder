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
    int m;
    cin >> m;
    vector<P> seiza(m);
    rep(i,m){
        int x, y;
        cin >> x >> y;
        seiza[i] = make_pair(x, y);
    }

    int n;
    cin >> n;
    vector<P> sora(n);
    rep(i,n){
        int x, y;
        cin >> x >> y;
        sora[i] = make_pair(x, y);
    }

    set<P> st;
    rep(i,n) st.insert(sora[i]);
    rep(i,n){
        int xDis, yDis;
        xDis = sora[i].first - seiza[0].first;
        yDis = sora[i].second - seiza[0].second;
        int cnt = 0;
        rep(j,m){
            int xd, yd;
            xd = seiza[j].first + xDis;
            yd = seiza[j].second + yDis;
            if (st.find(make_pair(xd, yd)) != st.end()) cnt++;
        }
        if (cnt == m){
            printf("%d %d\n", xDis, yDis);
            return 0;
        }
    }
    return 0;
}