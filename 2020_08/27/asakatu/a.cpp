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
    rep(i,2){
        string t1 = s;
        if (i) t1 = "A" + t1;
        rep(j,2){
            string t2 = t1;
            if (t2.size() < 4) continue;
            if (j) t2.insert(4, "A");
            rep(k,2){
                string t3 = t2;
                if (t3.size() < 6) continue;
                if (k) t3.insert(6, "A");
                rep(l, 2){
                    string t4 = t3;
                    if (t4.size() < 8) continue;
                    if (l) t4.insert(8, "A");
                    if (t4 == "AKIHABARA"){
                        cout << "YES" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}