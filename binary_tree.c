#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

// Agac düyümünü daximek üçün funksiya
struct TreeNode* insertNode(struct TreeNode *root, int value) {
    if (root == NULL) {
        struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->value = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Agacın hündürlüyünü hesablamaq üçüa
int calculateHeight(struct TreeNode *root) {
    if (root == NULL) {
        return -1;  // Hündürlük -1 olda agac bosdur 
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// In-order keçidi etek ve elementleri massive yazmaq ucun funksiya
void inOrderTraversal(struct TreeNode *root, int *arr, int *index) {
    if (root != NULL) {
        inOrderTraversal(root->left, arr, index);  // Sol alt agaca kec
        arr[*index] = root->value;  // Mövcud düyümdeyerini massive elave et
        (*index)++;  // Nöbeti indeksi artir
        inOrderTraversal(root->right, arr, index);  // Sag alt agaca kec
    }
}

// Yaddasi serbest buraxma funksiyası
void freeTree(struct TreeNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Massivi sıralama funksiyası Bubble Sort ie)
void sortArray(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Elementleri bir-biri ile evez et
                int temp = arr[j];  // temp deyisenini elan et
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

