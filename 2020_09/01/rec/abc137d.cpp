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
    vector<P> a(n);
    rep(i,n) cin >> a[i].first >> a[i].second;
    sort(all(a));

    priority_queue<int> pq;
    int left = 0;
    ll ans = 0;
    rep(i,m){
        int d = i + 1;
        while(left < n){
            if (a[left].first > d) break;
            pq.push(a[left].second);
            left++;
        }
        if (pq.size() == 0) continue;
        ans += pq.top(); pq.pop();
    }
    cout << ans << endl;
    return 0;
}