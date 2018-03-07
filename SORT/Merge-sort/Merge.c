#include <stdio.h>

typedef unsigned int ELEMENT_TYPE;//数组的元素类型

static void printArry(ELEMENT_TYPE arry[],  int len)
{
    unsigned int i;

    for (i = 0; i < len; i++) {
        printf("%d ", arry[i]);
    }

    printf("\n");
}
#if 1 //使用哨兵
static void merge(ELEMENT_TYPE arry[],  int p, int q, int r)
{
    ELEMENT_TYPE L[q - p + 2], R[r - q + 1];
    int i, j, k;

    for ( i = 0; i < (q - p + 1); i++) {
        L[i] = arry[i + p];
    }

    L[i] = 0xffffffff;

    for ( i = 0; i < (r - q); i++) {
        R[i] = arry[i + q + 1];
    }

    R[i] = 0xffffffff;
    i = 0;
    j = 0;

    for (k = p; k < r + 1; k++) {
        if (L[i] >= R[j]) {
            arry[k] = R[j];
            j++;
        } else {
            arry[k] = L[i];
            i++;
        }
    }
}
#else
static void merge(ELEMENT_TYPE arry[],  int p, int q, int r)
{
    ELEMENT_TYPE L[q - p + 1], R[r - q];
    int i, j, k;

     for ( i = 0; i < (q - p + 1); i++) {
        L[i] = arry[i + p];
    }

    for ( i = 0; i < (r - q); i++) {
        R[i] = arry[i + q + 1];
    }

    i = 0;
    j = 0;
    k = p;
    while (i < (q - p+ 1) && j < (r - q)) {
        if (L[i] > R[j]) {
            arry[k++] = R[j];
            j++;
        } else {
            arry[k++] = L[i];
            i++;
        }
    }
    while (i < (q - p+ 1)) {
        arry[k++] = L[i];
        i++;
    }
    while (j < (r - q)) {
        arry[k++] = R[j];
        j++;
    }    
}
#endif

static void mergeSort(ELEMENT_TYPE arry[],  int p, int r)
{
    int q;

    if (p < r) {
        q = (r + p) / 2;
        mergeSort(arry, p, q);
        mergeSort(arry, q + 1, r);
        merge(arry, p, q, r);
    }
}

int main()
{
    ELEMENT_TYPE a[] = {31, 41, 59, 26, 41, 58,3};

    printArry(a, sizeof(a) / sizeof(ELEMENT_TYPE));
    mergeSort(a, 0, (sizeof(a) / sizeof(ELEMENT_TYPE)));
    printArry(a, sizeof(a) / sizeof(ELEMENT_TYPE));
    mergeSort(a, 0, sizeof(a) / sizeof(ELEMENT_TYPE));
    printArry(a, sizeof(a) / sizeof(ELEMENT_TYPE));
    return (0);
}

