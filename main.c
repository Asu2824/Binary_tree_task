#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

int main() {
    struct TreeNode *root = NULL;
    int n;

    //Istifadeciden agac ucun duyumlerin sayini al
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Istifadeciden duyumlerin deyerini al ve agaca elave et
    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter node value: ");
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    // Agacin yuksekliyini hesabla
    int height = calculateHeight(root);
    printf("Height of the tree: %d\n", height);

    // Agacin elementleri in-order sirasiyla bir massive yaz
    int *arr = (int*)malloc(n * sizeof(int));  // Dinamik dizi oluştur
    int index = 0;
    inOrderTraversal(root, arr, &index);

    // Agaci sirala
    sortArray(arr, n);

    // Siralanmis listi yazdir
    printf("Sorted list: [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    // Yaddasi serbest burax
    free(arr);
    freeTree(root);

    return 0;
}

