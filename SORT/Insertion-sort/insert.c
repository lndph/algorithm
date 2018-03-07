#include <stdio.h>

typedef unsigned int ELEMENT_TYPE;//数组的元素类型
//数组非降序排序
static int insertSotrAscending(ELEMENT_TYPE arry[], int len)
{
    int i, j;
    ELEMENT_TYPE key;

    for (i = 1; i < len; i++) {
        key = arry[i];
        j = i - 1;
        while (j >= 0 &&  arry[j] > key) {
            arry[j + 1] = arry[j];
            j--;
        }
        arry[j + 1] = key;
    }
}
//数组非升序排序
static int insertSotrDescending(ELEMENT_TYPE arry[], int len)
{
    int i, j;
    ELEMENT_TYPE key;

    for (i = 1; i < len; i++) {
        key = arry[i];
        j = i - 1;
        while (j >= 0 &&  arry[j] < key) {
            arry[j + 1] = arry[j];
            j--;
        }
        arry[j + 1] = key;
    }
}
static void printArry(ELEMENT_TYPE arry[],  int len)
{
    unsigned int i;

    for (i = 0; i < len; i++) {
        printf("%d ", arry[i]);
    }
    printf("\n");
}
int main()
{
    ELEMENT_TYPE a[] = {31, 41, 59, 26, 41, 58};

    printArry(a, sizeof(a) / sizeof(ELEMENT_TYPE));
    insertSotrAscending(a, sizeof(a) / sizeof(ELEMENT_TYPE));
    printArry(a, sizeof(a) / sizeof(ELEMENT_TYPE));
    insertSotrDescending(a, sizeof(a) / sizeof(ELEMENT_TYPE));
    printArry(a, sizeof(a) / sizeof(ELEMENT_TYPE));
    return (0);
}
