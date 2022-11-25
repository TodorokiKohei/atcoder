#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    string s, t;
    cin >> s >> t;
    int insertI = -1;
    rep(i,s.size()){
        int j = i + t.size() - 1;
        if (j >= s.size()) break;
        bool ok = true;
        int cnt = 0;
        for(int k = i; k <= j; k++){
            if (s[k] != t[cnt] && s[k] != '?') ok = false;
            cnt++;
        }
        if (ok) insertI = i;
    }
    if (insertI == -1){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }else{
        rep(i,s.size()){
            if (i == insertI){
                int j = i + t.size() - 1;
                int cnt = 0;
                for(int k = i; k <= j; k++){
                    s[k] = t[cnt];
                    cnt++;
                } 
            }
            if (s[i] == '?') s[i] = 'a';
        }
    }
    cout << s << endl;
    return 0;
}