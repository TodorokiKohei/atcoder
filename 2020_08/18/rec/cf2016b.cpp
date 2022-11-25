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
    int k, t;
    cin >> k >> t;
    priority_queue<int> pq;
    rep(i,t){
        int a;
        cin >> a;
        pq.push(a);
    }

    ll ans;
    if (t == 1){
        ans = pq.top() - 1;
    }else{
        while(true){
            int a1 = pq.top(); pq.pop();
            int a2 = pq.top(); pq.pop();
            if (a2 == 0){
                ans = max(a1-1, 0);
                break;
            }else{
                a1--; a2--;
                pq.push(a1);
                pq.push(a2);
            }
        }
    }
    cout << ans << endl;
    return 0;
}