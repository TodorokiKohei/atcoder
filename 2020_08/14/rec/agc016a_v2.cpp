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
    int ans = 100;
    for(char c = 'a'; c <= 'z'; c++){
        string t = s;
        int num = 0;
        while(true){
            string t_d = "";
            rep(i,t.size()-1){
                if (t[i] == c && t[i+1] == c) continue;
                else if (t[i] == c || t[i+1] == c) t_d.push_back(c);
                else t_d.push_back(t[i]);
            }
            if (t_d.size() == 0) break;
            t = t_d;
            num++;
        }
        ans = min(ans, num);
    }
    cout << ans << endl;
    return 0;
}