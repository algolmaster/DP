#include <iostream>
#include <limits.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int in = 0;
    int notIn = INT_MIN;
    int input;

    cin >> in;

    for (int i = 1; i < n; i++) {
        cin >> input;

        notIn = (notIn > in ? notIn : in);

        if (in < 0) in = input;
        else in += input;
    }

    notIn = (notIn > in ? notIn : in);
    cout << (notIn > in ? notIn : in);
}
