#ifndef TREE_H
#define TREE_H

typedef struct ax {
    int key;
    struct ax * left, * right;
} Node;

/**
 * Function: tree
 * -----------------
 * Function for Creating a Root Node (Semantic Separation Only)
 * 
 * key: Value entered on created node
 * 
 * returns: Created node
 */
Node * tree(int key) {
    Node * tmp = (Node *) malloc(sizeof(Node));
    tmp->key = key;

    return tmp;
}

/**
 * Function: node
 * -----------------
 * Function to create a tree node
 * 
 * key: Value entered on created node
 * 
 * returns: Created node
 */
Node * node(int key) {
    Node * tmp = (Node *) malloc(sizeof(Node));
    tmp->key = key;

    return tmp;
}

/**
 * Function: insert
 * -----------------
 * Function to insert a node in binary tree
 * 
 * root: Pointer to node representing tree root
 * newNode: Pointer to the new node that will be inserted
 * 
 * returns: Returns the node inserted in the tree.
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
 * Function to perform search in a binary tree. Pre-order sweep operation is considered
 * 
 * element: Integer searched in binary tree
 * root: Pointer to node representing tree root
 * 
 * returns: Node with the found element, if not found returns NULL.
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
 * Function to view a binary tree, making the display path in preorder
 * 
 * root: Pointer to node representing tree root
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
 * Function to view a binary tree, making the display path in symmetrical order (in-order)
 * 
 * root: Pointer to node representing tree root
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
 * Function to calculate the height of a binary tree. 
 * The tree height is displayed by the maximum level node, 
 * where the level represents the distance between the node and the root.
 * Pos-order sweep operation is considered
 * 
 * root: Pointer to node representing tree root
 * 
 * returns: Integer representing the height of the binary tree
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
 * Function to count the number of nodes in a tree
 * 
 * root: Pointer to node representing tree root
 * fncp: Pointer to a function that takes a node and returns an integer value. 
 * This function will be used to perform the calculation. 
 * Functions such as by_preorder, by_inorder or by_posorder can be applied in this context.
 * 
 * returns: Integer representing the number of nodes in the tree
 * 
 */
int count(Node * root, int (*fncp)(Node *)) {
    return fncp(root);
}

/**
 * Function: by_preorder
 * -----------------------
 * Helper function for counting elements in any binary tree. 
 * Uses the preorder method to sweep the tree
 * 
 * root: Pointer to node representing tree root
 * 
 * returns: Integer representing the number of nodes in the tree
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
 * Helper function for counting elements in any binary tree. 
 * Uses in-order (symmetric) method to sweep tree
 * 
 * root: Pointer to node representing tree root
 * 
 * returns: Integer representing the number of nodes in the tree
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
 * Helper function for counting elements in any binary tree. 
 * Uses depth-first method to sweep tree
 * 
 * root: Pointer to node representing tree root
 * 
 * returns: Integer representing the number of nodes in the tree
 */
int by_posorder(Node * root) {
    if (!root) return 0;

    return (
        by_posorder(root->left) + by_posorder(root->right) + 1
    );
}

#endif
