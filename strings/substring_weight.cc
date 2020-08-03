#include <bits/stdc++.h>
using namespace std;
unordered_set<int> us;

void process(string s) {
  int score = 0, l = 0, c = 0;
  while (c < s.length()) {
    us.insert(s[c] - 'a' + 1);
    if (s[c] == s[l]) {
      score += s[c] - 'a' + 1;
      us.insert(score);
    } else {
      us.insert(score);
      score = 0;
      score += s[c] - 'a' + 1;
      l = c;
    }
    c++;
  }
}

int main() {
  int n = 0;
  string s;
  cin >> s;
  process(s);
  cin >> n;
  while (n--) {
    int k = 0;
    cin >> k;
    if (us.find(k) != us.end())
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
