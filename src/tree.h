#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct ax {
    int key;
    struct ax * left, * right;
} Node;

Node * tree(int key) {
    Node * tmp = (Node *) malloc(sizeof(Node));
    tmp->key = key;

    return tmp;
}

Node * node(int key) {
    Node * tmp = (Node *) malloc(sizeof(Node));
    tmp->key = key;

    return tmp;
}

Node * insert(Node * root, Node * newNode) {
    if (root == NULL) return(newNode);
    
    if (newNode->key < root->key) {
        root->left = insert(root->left, newNode);
    } else {
        root->right = insert(root->right, newNode);
    }
}

Node * search(int element, Node * root) {
    if (root == NULL) return NULL;
    if (root->key == element) return root;

    if (root->key > element) return search(element, root->left);
    else return search(element, root->right);
}

void preorder(Node * root) {
    printf("%d\n", root->key);
    
    if (root->left != NULL) {
        preorder(root->left);
    }

    if (root->right != NULL) {
        preorder(root->right);
    }
}

void inorder(Node * root) {
    if (root->left != NULL) {
        inorder(root->left);
    }
    printf("%d\n", root->key);

    if (root->right != NULL) {
        inorder(root->right);
    }
}

/**
 * Function: height
 * -----------------
 * Função para calcular a altura de uma árvore binária. A altura 
 * 
 * root: Ponteiro para o Node que representa a raiz do projeto
 * 
 * returns: Inteiro representando a altura da árvore binária
 * 
 */
int height(Node * root) {
    int hleft = 0;
    int hright = 0;

    if (root->left != NULL) {
        hleft = height(root->left);
    }

    if (root->right != NULL) {
        hright = height(root->right);
    }

    if (hright > hleft) return hright + 1;
    return hleft + 1;
}

int count(Node * root, int (*fncp)(Node *)) {
    return fncp(root);
}

int by_preorder(Node * root) {
    if (!root) return 0;

    return (
        1 + by_preorder(root->left) + by_preorder(root->right)
    );
}

int by_inorder(Node * root) {
    if (!root) return 0;

    return ( 
        by_inorder(root->left) + 1 + by_inorder(root->right)
    );
}

int by_posorder(Node * root) {
    if (!root) return 0;

    return (
        by_posorder(root->left) + by_posorder(root->right) + 1
    );
}

#endif
