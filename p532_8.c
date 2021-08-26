#include <stdio.h>
#include <stdlib.h>
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

int count = 0; 
//AVL 트리 노드 정의
int maximum (int a, int b){
    if(a >= b)
        return a;
    else
        return b;
}

typedef struct AVLNode {
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
} AVLNode;

int get_height(AVLNode *node){
    int height = 0; 
    if(node != NULL)
        height = 1 + maximum(get_height(node->left), get_height(node -> right));

    return height; 
}

int get_balance(AVLNode* node){
    if (node == NULL) return 0;

    return get_height(node->left) - get_height(node->right);
}

AVLNode* create_node(int key){
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key; 
    node->left = NULL;
    node->right = NULL;
    return(node);
}

AVLNode* rotate_right(AVLNode *parent){
    AVLNode* child = parent ->left;
    parent->left = child->right; 
    child -> right = parent;

    return child;
}

AVLNode *rotate_left(AVLNode *parent){
    AVLNode *child = parent -> right;
    parent->right = child -> left; 
    child -> left = parent; 

    return child; 
}

AVLNode* insert(AVLNode* node, int key){
    if (node == NULL)
        return(create_node(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if(key > node-> key)
        node->right = insert(node->right, key);
    else
        return node;
    
    int balance = get_balance(node);
    
    if(balance > 1 && key < node->left->key)
        return rotate_right(node);

    if(balance < -1 && key > node->right->key)
        return rotate_left(node);
    
    if(balance > 1 && key < node->left->key){
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    if(balance < -1 && key < node-> right -> key){
        node-> right = rotate_right(node->right);
        return rotate_left(node);
    }
    return node; 
}

int inorder(AVLNode * root, int* a){
    if(root != NULL){
        inorder(root->left, a);
        a[count] = (root->key);
        count++; 
        inorder(root->right, a);
    }
}

void print_list(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
} 

int main(void){
    AVLNode *root = NULL; 
    int n; 
    scanf("%d", &n);
    int* a = malloc(sizeof(int) * n);
    for(int i = 0; i< n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++){
        root = insert(root, a[i]);
    }
    inorder(root, a);
    print_list(a, n);
    free(a);
}