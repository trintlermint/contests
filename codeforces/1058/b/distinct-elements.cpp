#include <iostream>
#include <vector>
using namespace std;

void test() {
    int n;
    cin >> n;
    vector<long long> b(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        a[i] = n - i + 1;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
        int t;
        while(--t+1)
        {
                test();
        }
}
