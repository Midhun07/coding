#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 0, a[26] = {0}, ans = 0;
  map<char, int> mp;
  string s;
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) {
    mp[s[i]]++;
  }
  for (auto it : mp)
    cout << it.first << it.second << endl;
  auto it = mp.begin();
  for (; it != mp.end(); it++) {
    for (auto it2 = next(it); it2 != mp.end(); it2++) {
      bool found = false;
      char l = it->first, r = it2->first, c = '.';
      bool flag = false;
      for (int i = 0; i < s.length(); i++) {
        if (s[i] == l && c == l) {
          flag = true;
          break;
        } else if (s[i] == r && c == r) {
          flag = true;
          break;
        } else if (s[i] == l || s[i] == r) {
          c = s[i];
        }
        if (flag)
          break;
        else if (i == s.length() - 1)
          found = true;
      }
      if (found) {
        ans = max(ans, (it->second + it2->second));
        cout << it->second << it2->second << endl;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
