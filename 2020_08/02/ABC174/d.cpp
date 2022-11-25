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
    int left = 0, right = n-1;
    int ans = 0;
    while(left < right){
        while (right >= 0 && s[right] != 'R') right--;
        while (left < n && s[left] != 'W') left++;
        if (left >= right) break;
        ans++;
        s[left] = 'R';
        s[right] = 'W';
        left++;
        right--;
    }
    int wNum = 0;
    rep(i,n){
        if (s[i] == 'W') wNum++;
    }
    cout << min(ans, wNum) << endl;
    return 0;
}