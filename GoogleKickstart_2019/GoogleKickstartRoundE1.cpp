#include <bits/stdc++.h>
using namespace std;

int par[100001];

int find(int x) {
  if(x != par[x]) {
    par[x] = find(par[x]);
  }
  return par[x];
}

int merge(int x, int y) {
  int px = find(x);
  int py = find(y);
  par[py] = px;
  return px;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n, m;
    cin >> t;
    for(int c=1;c <= t;c++) {
      cout << "Case #"<<c<<": ";
      long long int ans = 0LL;
      cin >> n >> m;
      for(int i=1;i<=n;i++) {
        par[i] = i;
      }
      for(int i=0;i<m;i++) {
        int x, y;
        cin >> x;
        cin >> y;
        int px = find(x);
        int py = find(y);
        if(px != py) {
          ans++;
          merge(px,py);
        }
      }
      
      unordered_map<int, int> mp;
      for(int i=1;i<=n;i++) {
        mp[find(i)] = 1;
      }
        /*for(auto i:mp)
        {
            cout<<i.first<<" "<<i.second<<" ";
        }*/
        
      ans = ans + (mp.size()-1)*2LL;
      cout << ans << endl;
    }
    
}