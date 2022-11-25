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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    deque<int> dq;
    set<int> st;
    int left = 0, ans = 0;
    rep(i,n){
        int j = a[i];
        if (st.find(j) == st.end()){
            st.insert(j);
            dq.push_back(j);
        }else{
            ans = max(ans, static_cast<int>(dq.size()));
            while(dq.front() != j){
                st.erase(dq.front());
                dq.pop_front();
                left++;
            }
            dq.pop_front();
            dq.push_back(j);
        }
    }
    ans = max(ans, static_cast<int>(dq.size()));
    cout << ans << endl;
    return 0;
}