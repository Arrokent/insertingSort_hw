#include <iostream>

void insert(int *a, int *b) {
    if (a >= b)
        return;

    int temp = *b;

    for (int *p = b; p > a; p--)
        *p = *(p - 1);

    *a = temp;
}


/*
 * 传统插入排序
 */
void insertSort(int a[], const int count) {
    for (int i = 1; i < count; i++) {
        for (int j = 0; j <= i; j++) {
            if (a[i + 1] < a[j])
                //insert a[i + 1] between a[j - 1] and a[j]
                insert(a + j, a + i + 1);
        }
    }
}


/*
 * 用到二分法的插入排序
 */
void insertSort_BinarySearch(int a[], const int count) {
    for (int i = 1; i < count; i++) {
        // Use binary search to search where a[i] should be insert
        int low = 0;
        int high = i;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (a[i] <= a[mid]) {
                if (a[i] > a[mid - 1] || mid == 0) {
                    //insert a[i] in front of a[mid]
                    insert(a + mid, a + i);
                    break;
                } else
                    high = mid - 1;
            } else
                low = mid + 1;
        }
    }
}

void print(int a[], const int count) {
    for (int i = 0; i < count; i++)
        std::cout << a[i];
    std::cout << std::endl;
}

int main() {
    int a[] = {5, 4, 1, 6, 3, 2, 8, 9, 7, 0};
    int b[] = {5, 4, 1, 6, 3, 2, 8, 9, 7, 0};
    print(a, 10);

    //传统插入排序
    insertSort(a, 10);
    print(a, 10);

    //用到二分查找的插入排序
    insertSort_BinarySearch(b, 10);
    print(b, 10);
}
