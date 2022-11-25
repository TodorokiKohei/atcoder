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
    int k;
    cin >> s >> k;
    rep(i,s.size()){
        int num = 26 - (s[i] - 'a');
        if (i == s.size()-1){
            if (k == num) s[i] = 'a';
            else if (k < num) s[i] += k;
            else if (k > num){
                k -= num;
                k %= 26;
                s[i] = 'a';
                s[i] += k;
            }
        }else{
            if (num == 26) continue;
            if (k - num < 0) continue;
            k -= num;
            s[i] = 'a';
        }
        if (k == 0) break;
    }
    cout << s << endl;
    return 0;
}