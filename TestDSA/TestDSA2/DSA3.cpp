#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isTwoDominant(int n) {
    string s = to_string(n);
    int count2 = count(s.begin(), s.end(), '2');
    return count2 > s.length() / 2;
}
void printTwoDominant(int N) {
    int count = 0, i = 0;
    while (count < N) {
        if (isTwoDominant(i)) {
            cout << i << " ";
            count++;
        }
        i++;
    }
    cout << endl;
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        printTwoDominant(N);
    }
    return 0;
}
