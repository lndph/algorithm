#include <stdio.h>

typedef unsigned int ELEMENT_TYPE;//数组的元素类型
//数组非降序排序
static int bubbleSotrAscending(ELEMENT_TYPE arry[], int len)
{
    int i, j;
    ELEMENT_TYPE key;

    for (i = 0; i < len; i++) {
        for ( j = (len - 1); j > i; j--) {
            if (arry[j] < arry[j - 1]) {
                key = arry[j];
                arry[j] = arry[j - 1];
                arry[j - 1] = key;                
            }
        }
    }
}
//数组非升序排序
static int bubbleSotrDescending(ELEMENT_TYPE arry[], int len)
{
    int i, j;
    ELEMENT_TYPE key;

    for (i = 0; i < len; i++) {
        for ( j = (len - 1); j > i; j--) {
            if (arry[j] > arry[j - 1]) {
                key = arry[j];
                arry[j] = arry[j - 1];
                arry[j - 1] = key;                
            }
        }
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
    bubbleSotrAscending(a, sizeof(a) / sizeof(ELEMENT_TYPE));
    printArry(a, sizeof(a) / sizeof(ELEMENT_TYPE));
    bubbleSotrDescending(a, sizeof(a) / sizeof(ELEMENT_TYPE));
    printArry(a, sizeof(a) / sizeof(ELEMENT_TYPE));
    return (0);
}
