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
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 1; i < n; i++){
        set<char> s1, s2;
        for(int j = 0; j < i; j++){
            s1.insert(s[j]);
        }
        for(int k = i; k < n; k++){
            s2.insert(s[k]);
        }
        int sum = 0;
        for(auto ss : s1){
            if (s2.find(ss) != s2.end()) sum++;
        }
        ans = max(ans, sum);
    }
    cout << ans  << endl;
}