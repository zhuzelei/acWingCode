#include <iostream>
using namespace std;

int quick_sort(int num[], int l, int r, int k)
{
    if (l >= r) {
        return num[l];
    }

    int i = l - 1;
    int j = r + 1;
    int x = num[(l + r) / 2];

    while (i < j) {
        do {
            i++;
        } while (num[i] < x);

        do {
            j--;
        } while (num[j] > x);

        if (i < j) {
            swap(num[i], num[j]);
        }
    }
    int cntLeft = j - l + 1;
    if (k <= cntLeft) {
        return quick_sort(num, l, j, k);
    } else {
        return quick_sort(num, j + 1, r, k - cntLeft);
    }

}

int main() {

    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int num[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    int ret = quick_sort(num, 0, n - 1, k);
    printf("%d", ret);
    return 0;
}
