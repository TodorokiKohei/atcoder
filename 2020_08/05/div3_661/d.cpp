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

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        vector<int> ans(n);
        vector<int> pos0, pos1;
        rep(i,n){
            int b = pos0.size() + pos1.size() + 1;
            if (s[i] == '0'){
                if (pos1.empty()){
                    pos0.push_back(b);
                }else{
                    b = pos1.back();
                    pos1.pop_back();
                    pos0.push_back(b);
                }
            }else{
                if (pos0.empty()){
                    pos1.push_back(b);
                }else{
                    b = pos0.back();
                    pos0.pop_back();
                    pos1.push_back(b);
                }
            }
            ans[i] = b;
        }
        cout << pos0.size() + pos1.size() << endl;
        rep(i,n){
            printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');
        }
    }
	return 0;
}