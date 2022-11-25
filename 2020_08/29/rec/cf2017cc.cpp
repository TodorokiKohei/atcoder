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

bool check(string t){
    int left = 0, right = t.size()-1;
    while(left < right){
        if (t[left++] != t[right--]) return false;
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    if (check(s)){
        cout << 0 << endl;
        return 0;
    }
    string t = "";
    rep(i, s.size()){
        if (s[i] != 'x') t += s[i];
    }
    if (!check(t)){
        cout << -1 << endl;
        return 0;
    }

    string t_half = "";
    rep(i, (t.size()+1)/2) t_half += t[i];
    int i = 0, left = -1;
    while(i < t_half.size()){
        left++;
        if (s[left] == t_half[i]) i++;
    }
    int right;
    if (t.size() % 2 == 0){
        right = left+1;
        while(s[right] == 'x'){
            right++;
        }
    } 
    else{
        right = left;
    } 
    int ans = 0;
    while(true){
        if (left < 0) break;
        if (right >= s.size()) break;
        if (s[left] == s[right]){
            left--; right++;
        }else if (s[left] == 'x'){
            ans++;
            left--;
        }else if (s[right] == 'x'){
            ans++;
            right++;
        }
    }
    if (left >= 0) ans += left+1;
    if (right < s.size()) ans += s.size() - right;
    cout << ans << endl;
    return 0;
}