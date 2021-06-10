#include <iostream>
#include <string>

using namespace std;

void nwp(string x, string y) {
    int m = x.length();
    int n = y.length();

    int tab[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                tab[i][j] = 0;
            }
            else if (x[i - 1] == y[j - 1]) {
                tab[i][j] = tab[i - 1][j - 1] + 1;
            }
            else {
                if (tab[i - 1][j] > tab[i][j - 1]) {
                    tab[i][j] = tab[i - 1][j];
                }
                else {
                    tab[i][j] = tab[i][j - 1];
                }
            }
        }
    }

    int index = tab[m][n];

    char result[index + 1];
    result[index] = '\0';

    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {
            result[index - 1] = x[i - 1];
            i--;
            j--;
            index--;
        }

        else if (tab[i - 1][j] > tab[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    cout << "NWP wyrazów " << x << " oraz " << y << " jest: " << result;
}

int main()
{
    string w1 = "abbaac";
    string w2 = "bacbacba";

    nwp(w1, w2);

    return 0;
}