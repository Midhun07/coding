#include <bits/stdc++.h>
using namespace std;
int main() {
  string text, in("hackerrank");
  int n;
  cin >> n;
  while (n--) {
    cin >> text;

    int i = 0, j = 0;
    bool flag = false;
    while (i < text.length()) {
      if (text[i] == in[j])
        j++;
      if (j == in.length()) {
        flag = true;
        break;
      }
      i++;
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
