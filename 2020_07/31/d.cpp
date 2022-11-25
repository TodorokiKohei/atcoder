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
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                int cnt = 0;
                int l = 0;
                while(l < n){
                    if (cnt == 0 && s[l] == '0'+i) cnt++;
                    else if (cnt == 1 && s[l] == '0'+j) cnt++;
                    else if (cnt == 2 && s[l] == '0'+k) cnt++;
                    l++;
                }
                if (cnt == 3) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}