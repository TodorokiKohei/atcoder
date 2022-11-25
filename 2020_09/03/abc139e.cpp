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
    vector<vector<int>> a(n, vector<int>(n-1));
    rep(i,n){
        rep(j,n-1){
            cin >>  a[i][j];
            a[i][j]--;
        }
        reverse(all(a[i]));
    }


    queue<P> q;
    auto check = [&](int i){
        if (a[i].size() == 0) return;
        int j = a[i].back();
        int k = a[j].back();
        if (i == k) q.push(P(min(i,j), max(i,j)));
    };

    rep(i,n) check(i);
    int ans = 0;
    while(!q.empty()){
        ans++;
        set<P> st;
        while(!q.empty()){
            st.insert(q.front()); q.pop();
        }

        for(P p: st){
            int i = p.first, j = p.second;
            a[i].pop_back();
            a[j].pop_back();
        }
        for(P p: st){
            int i = p.first, j = p.second;
            check(i);
            check(j);
        }
    }

    rep(i,n){
        if (a[i].size() != 0){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}