#include <bits/stdc++.h>

using namespace std;

int main() {
  string text, in;
  cin >> text;
  cin >> in;

  for (int i = 0; i < text.length(); i++) {
    bool flag = true;
    for (int j = 0; j < in.length(); j++) {
      if (i + j > text.length() || in[j] != text[i+j])
        flag = false;
    }
    if (flag)
      cout << "Match found" << endl;
  }

  return 0;
}
