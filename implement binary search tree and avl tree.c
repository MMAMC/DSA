#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* left;
struct Node* right;
int height;
};


int max(int a, int b) {
return (a > b) ? a : b;
}

int height(struct Node* node) {
if (node == NULL) {
return 0;
}
return node->height;
}
int getBalance(struct Node* node) {
if (node == NULL) {
return 0;
}
return height(node->left) - height(node->right);
}
struct Node* createNode(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->left = NULL;
newNode->right = NULL;
newNode->height = 1;
return newNode;
}
struct Node* insertBST(struct Node* root, int value) {
if (root == NULL) {
return createNode(value);
}
if (value < root->data) {
root->left = insertBST(root->left, value);
} else if (value > root->data) {
root->right = insertBST(root->right, value);
}
return root;
}
struct Node* rightRotate(struct Node* y) {
struct Node* x = y->left;
struct Node* T2 = x->right;
x->right = y;
y->left = T2;
y->height = max(height(y->left), height(y->right)) + 1;
x->height = max(height(x->left), height(x->right)) + 1;
return x;
}

struct Node* leftRotate(struct Node* x) {
struct Node* y = x->right;
struct Node* T2 = y->left;
y->left = x;
x->right = T2;
x->height = max(height(x->left), height(x->right)) + 1;
y->height = max(height(y->left), height(y->right)) + 1;
return y;
}
struct Node* insertAVL(struct Node* node, int value) {
if (node == NULL) {
return createNode(value);
}
if (value < node->data) {
node->left = insertAVL(node->left, value);
} else if (value > node->data) {
node->right = insertAVL(node->right, value);
} else {
return node;
}
node->height = 1 + max(height(node->left), height(node->right));
int balance = getBalance(node);
if (balance > 1 && value < node->left->data) {
return rightRotate(node);
}
if (balance < -1 && value > node->right->data) {
return leftRotate(node);
}
if (balance > 1 && value > node->left->data) {
node->left = leftRotate(node->left);
return rightRotate(node);
}
if (balance < -1 && value < node->right->data) {
node->right = rightRotate(node->right);
return leftRotate(node);
}
return node;
}
void inorder(struct Node* root) {
if (root != NULL) {
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}

int main() {
struct Node* rootBST = NULL;
rootBST = insertBST(rootBST, 50);
insertBST(rootBST, 30);
insertBST(rootBST, 20);
insertBST(rootBST, 40);
insertBST(rootBST, 70);
insertBST(rootBST, 60);
insertBST(rootBST, 80);
printf("Binary Search Tree: ");
inorder(rootBST);
printf("\n");
struct Node* rootAVL = NULL;
rootAVL = insertAVL(rootAVL, 10);
rootAVL = insertAVL(rootAVL, 20);
rootAVL = insertAVL(rootAVL, 30);
rootAVL = insertAVL(rootAVL, 40);
rootAVL = insertAVL(rootAVL, 50);
rootAVL = insertAVL(rootAVL, 25);
printf("AVL Tree: ");
inorder(rootAVL);
printf("\n");
return 0;
}
