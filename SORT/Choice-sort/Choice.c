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

static void choiceSortAscending(ELEMENT_TYPE arry[],  int len)
{
    int i,j,t;
    ELEMENT_TYPE min;

    for (i = 0; i < len - 1; i++) {
        min = arry[i];
        t = i;
        for (j = i; j < len; j++) {
            if (arry[j] < min) {
                min = arry[j];
                t=j;
            }
        }
        arry[t] = arry[i];
        arry[i] = min;        
    }    
}

static void choiceSortDescending(ELEMENT_TYPE arry[],  int len)
{
    int i,j,t;
    ELEMENT_TYPE max;

    for (i = 0; i < len - 1; i++) {
        max = arry[i];
        t = i;
        for (j = i; j < len; j++) {
            if (arry[j] > max) {
                max = arry[j];
                t=j;
            }
        }
        arry[t] = arry[i];
        arry[i] = max;        
    }    
}

int main()
{
    ELEMENT_TYPE a[] = {31, 41, 59, 26, 41, 58};

    printArry(a, sizeof(a) / sizeof(ELEMENT_TYPE));
    choiceSortAscending(a, sizeof(a) / sizeof(ELEMENT_TYPE));
    printArry(a, sizeof(a) / sizeof(ELEMENT_TYPE));
    choiceSortDescending(a, sizeof(a) / sizeof(ELEMENT_TYPE));
    printArry(a, sizeof(a) / sizeof(ELEMENT_TYPE));
    return (0);
}

