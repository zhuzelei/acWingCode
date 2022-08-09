#include <iostream>
using namespace std;

void quick_sort(int num[], int l, int r)
{
    if (l >= r) {
        return;
    }

    // 用i则不能取到左边界，把x取值改成向上取整
    // 用j则不能取到右边界，把x取值改成向下取整
    // 取到边界会导致递归死循环
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
    quick_sort(num, l, j);
    quick_sort(num, j + 1, r);
}

int main() {

    int n;
    scanf("%d", &n);
    int num[n];
    for (int i = 0 ; i < n; i++) {
        scanf("%d", &num[i]);
    }

    quick_sort(num, 0, n-1);

    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }

    return 0;
}
