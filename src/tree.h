#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct ax {
    int key;
    struct ax * left, * right;
} Node;

/**
 * Function: tree
 * -----------------
 * Função para criar um nó raiz (Separação apenas semântica)
 * 
 * key: Valor inserido no nó criado
 * 
 * returns: Nó criado
 */
Node * tree(int key) {
    Node * tmp = (Node *) malloc(sizeof(Node));
    tmp->key = key;

    return tmp;
}

/**
 * Function: node
 * -----------------
 * Função para criar um nó na árvore
 * 
 * key: Valor inserido no nó criado
 * 
 * returns: Nó criado
 */
Node * node(int key) {
    Node * tmp = (Node *) malloc(sizeof(Node));
    tmp->key = key;

    return tmp;
}

/**
 * Function: insert
 * -----------------
 * Função para inserir um nó na árvore binária
 * 
 * root: Ponteiro para o Node que representa a raiz da árvore
 * newNode: Ponteiro para o novo nó que será inserido
 * 
 * returns: Devolve o nó inserido na árvore
 */
Node * insert(Node * root, Node * newNode) {
    if (root == NULL) return(newNode);
    
    if (newNode->key < root->key) {
        root->left = insert(root->left, newNode);
    } else {
        root->right = insert(root->right, newNode);
    }
}

/**
 * Function: search
 * -----------------
 * Função para realizar pesquisa em uma árvore binária
 * 
 * element: Número inteiro pesquisado na árvore binária
 * root: Ponteiro para o Node que representa a raiz da árvore
 * 
 * returns: Nó com o elemento encontrado, caso não encontre retorna NULL.
 */
Node * search(int element, Node * root) {
    if (root == NULL) return NULL;
    if (root->key == element) return root;

    if (root->key > element) return search(element, root->left);
    else return search(element, root->right);
}

/**
 * Function: preorder
 * -----------------
 * Função para visualizar uma árvore binária, fazendo o percurso de exibição 
 * em pré-ordem
 * 
 * root: Ponteiro para o Node que representa a raiz da árvore
 * 
 * returns: void
 */
void preorder(Node * root) {
    printf("%d\n", root->key);
    
    if (root->left != NULL) {
        preorder(root->left);
    }

    if (root->right != NULL) {
        preorder(root->right);
    }
}

/**
 * Function: inorder
 * -----------------
 * Função para visualizar uma árvore binária, fazendo o percurso de exibição 
 * em ordem simétrica (in-ordem)
 * 
 * root: Ponteiro para o Node que representa a raiz da árvore
 * 
 * returns: void
 * 
 */
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
 * Função para calcular a altura de uma árvore binária. A altura da árvore
 * é apresentada pelo nó de nível máximo, onde o nível representa a distância
 * entre o nó e a raiz.
 * 
 * root: Ponteiro para o Node que representa a raiz da árvore
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

/**
 * Function: count
 * -----------------
 * Função para contar a quantidade de nós em uma árvore
 * 
 * root: Ponteiro para o Node que representa a raiz da árvore
 * fncp: Ponteiro para uma função que recebe um nó e devolve um valor inteiro.
 * Esta função será utilizada para realizar o cálculo. Funções como by_preorder, 
 * by_inorder ou by_posorder podem ser aplicadas neste contexto.
 * 
 * returns: Inteiro representando a quantidade de nós na árvore
 * 
 */
int count(Node * root, int (*fncp)(Node *)) {
    return fncp(root);
}

/**
 * Function: by_preorder
 * -----------------------
 * Função auxiliar para a contagem de elementos em uma árvore binária qualquer.
 * Utiliza o método pré-ordem para percorrer a árvore
 * 
 * root: Ponteiro para o Node que representa a raiz da árvore
 * 
 * returns: Inteiro representando a quantidade de nós na árvore
 * 
 */
int by_preorder(Node * root) {
    if (!root) return 0;

    return (
        1 + by_preorder(root->left) + by_preorder(root->right)
    );
}

/**
 * Function: by_inorder
 * ----------------------
 * Função auxiliar para a contagem de elementos em uma árvore binária qualquer.
 * Utiliza o método in-ordem (Simétrica) para percorrer a árvore
 * 
 * root: Ponteiro para o Node que representa a raiz da árvore
 * 
 * returns: Inteiro representando a quantidade de nós na árvore
 */
int by_inorder(Node * root) {
    if (!root) return 0;

    return ( 
        by_inorder(root->left) + 1 + by_inorder(root->right)
    );
}

/**
 * Function: by_posorder
 * ----------------------
 * Função auxiliar para a contagem de elementos em uma árvore binária qualquer.
 * Utiliza o método pós-ordem (depth-first) para percorrer a árvore
 * 
 * root: Ponteiro para o Node que representa a raiz da árvore
 * 
 * returns: Inteiro representando a quantidade de nós na árvore
 */
int by_posorder(Node * root) {
    if (!root) return 0;

    return (
        by_posorder(root->left) + by_posorder(root->right) + 1
    );
}

#endif
