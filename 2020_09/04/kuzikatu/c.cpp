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
    string s;
    cin >> s;
    deque<char> dq;
    rep(i, s.size()) dq.push_back(s[i]);
    int q;
    cin >> q;
    bool rev = false;
    rep(i,q){
        int t;
        cin >> t;
        if (t == 1){
            rev = !rev;
        }else {
            int f;
            char c;
            cin >> f >> c;
            if (f == 1){
                if (rev) dq.push_back(c);
                else dq.push_front(c);
            }else{
                if (rev) dq.push_front(c);
                else dq.push_back(c);   
            }
        }
    }
    string ans = "";
    if (rev) {
        while(!dq.empty()){
            ans += dq.back(); dq.pop_back();
        } 
    }else{
        while(!dq.empty()){
            ans += dq.front(); dq.pop_front();
        } 
    }
    cout << ans << endl;
    return 0;
}