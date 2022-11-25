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
    ll ans = 0;
    int i = 0;
    int cnt1 = 0;
    while(i < s.size()){
        if (s[i] == '<'){
            int j = i;
            cnt1 = 0;
            while(j < s.size()){
                if (s[j] == '>') break;
                ans += cnt1;
                cnt1++;
                j++;
            }
            if (j >= s.size()) ans += cnt1;
            i = j;
        }
        else{
            int j = i;
            int cnt2 = 0;
            while(j < s.size()){
                if (s[j] == '<') break;
                cnt2++;
                j++;
            }
            for(int k = cnt2; k > 0; k--) ans+=k;
            if (cnt1 > cnt2) ans += cnt1 - cnt2;
            i = j;
        }
    }
    cout << ans << endl;
    return 0;
}