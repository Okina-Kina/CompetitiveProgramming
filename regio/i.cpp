#include <iostream>
using namespace std;
int main(){
    int v[5];
    for (int i = 0; i < 5; ++i) cin >> v[i];

    for (int i = 0; i < 5; ++i) {
        bool ok = true;
        for (int j = 0; j < 5; ++j) {
            if (j == i) continue;
            int i1 = (i + 1) % 5;
            int i2 = (i + 2) % 5;

            cout << "il(i+1)/%5: " << i1 << endl;
            cout << "i2(i+2)/%5: " << i2 << endl;
            cout << "v[j]: " << v[j] << endl;
            cout << "(v[j] - v[i2]) * (i1 - i2): " << (v[j] - v[i2]) * (i1 - i2) << endl;
            cout << "(v[i1] - v[i2]) * (j - i2): " << (v[i1] - v[i2]) * (j - i2) << endl;

            // Check whether values[j] and (values[i1] - values[i2]) * (j - i2) / (i1 - i2) + values[i2] are equal;
            if ((v[j] - v[i2]) * (i1 - i2) != (v[i1] - v[i2]) * (j - i2)) 
                ok = false;
        }
        if (ok) {
            cout << i + 1 << endl;
            break;
        }
    }
}
