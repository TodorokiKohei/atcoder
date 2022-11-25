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

const int INF = 1<<30;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = INF;
    vector<string> com = {"A", "B", "X", "Y"};
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                for(int l = 0; l < 4; l++){
                    string s1 = com[i] + com[j];
                    string s2 = com[k] + com[l];
                    if (s1 == s2) continue;
                    int m = 0, sum = 0;
                    while(m < n){
                        if (s.substr(m,2) == s1 || s.substr(m,2) == s2){
                            sum++;
                            m+=2;
                        }else{
                            sum++;
                            m++;
                        }
                    }
                    ans = min(ans, sum);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}