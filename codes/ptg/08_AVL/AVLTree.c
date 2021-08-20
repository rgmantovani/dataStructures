#include "AVLTree.h"

//---------------------------------------------------------------------
// A utility function to get maximum of two integers
//---------------------------------------------------------------------
int max(int a, int b) {
    return (a > b)? a : b;
}

//---------------------------------------------------------------------
// A utility function to get height of the tree
//---------------------------------------------------------------------
int height(PtrAVLNode N){
  if (N == NULL) return (0);
  else           return (N->height);
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
void PreOrdemArvoreAVL(PtrAVLNode node) {
  if(node != NULL) {
    printf("%d ", node->key);
    PreOrdemArvoreAVL(node->left);
    PreOrdemArvoreAVL(node->right);
  }
}

//---------------------------------------------------------------------
/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
//---------------------------------------------------------------------
PtrAVLNode newNode(int key) {
  PtrAVLNode node = (PtrAVLNode)malloc(sizeof(AVLNode));
  node->key    = key;
  node->left   = NULL;
  node->right  = NULL;
  node->height = 1;  // new node is initially added at leaf
  return(node);
}

//---------------------------------------------------------------------
// A utility function to right rotate subtree rooted with y
// See the diagram given above.
//---------------------------------------------------------------------
PtrAVLNode rightRotate(PtrAVLNode y) {
  
  PtrAVLNode x  = y->left;
  PtrAVLNode T2 = x->right;

  // Perform rotation
  x->right = y;
  y->left = T2;

  // Update heights
  y->height = max(height(y->left), height(y->right))+1;
  x->height = max(height(x->left), height(x->right))+1;

  // Return new root
  return x;
}

//---------------------------------------------------------------------
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
//---------------------------------------------------------------------
PtrAVLNode leftRotate(PtrAVLNode x){
  
  PtrAVLNode y = x->right;
  PtrAVLNode T2 = y->left;

  // Perform rotation
  y->left = x;
  x->right = T2;

  //  Update heights
  x->height = max(height(x->left), height(x->right))+1;
  y->height = max(height(y->left), height(y->right))+1;

  // Return new root
  return y;
}

//---------------------------------------------------------------------
// Get Balance factor of node N
//---------------------------------------------------------------------
int getBalance(PtrAVLNode N) {
  if (N == NULL) return 0;
  return height(N->left) - height(N->right);
}

//---------------------------------------------------------------------
// Inserting new element
//---------------------------------------------------------------------
PtrAVLNode insert(PtrAVLNode node, int key) {
  /* 1.  Perform the normal BST rotation */
  if (node == NULL) {
    return(newNode(key));
  }
  
  if (key < node->key) {
    node->left  = insert(node->left, key);
  } else if (key > node->key) {
    node->right = insert(node->right, key);
  } else { // Equal keys not allowed
    return node;
  }
  
  /* 2. Update height of this ancestor node */
  node->height = 1 + max(height(node->left), height(node->right));

  /* 3. Get the balance factor of this ancestor node to
   check whether this node became unbalanced */
    int balance = getBalance(node);

  // If this node becomes unbalanced, then there are 4 cases
  // Left Left Case - simple left rotation
  if (balance > 1 && key < node->left->key) {
    return rightRotate(node);
  }
  
  // Right Right Case - simple right rotation
  if (balance < -1 && key > node->right->key) {
    return leftRotate(node);
  }

  // Left Right Case - double right rotation
  if (balance > 1 && key > node->left->key) {
    node->left =  leftRotate(node->left);
    return rightRotate(node);
  }

  // Right Left Case - double left rotation
  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  /* return the (unchanged) node pointer */
  return node;
}

//---------------------------------------------------------------------
/* Given a non-empty binary search tree, return the
   node with minimum key value found in that tree.
   Note that the entire tree does not need to be
   searched. */
//---------------------------------------------------------------------

PtrAVLNode minValueNode(PtrAVLNode node) {
  PtrAVLNode current = node;
  /* loop down to find the leftmost leaf */
  while (current->left != NULL) {
    current = current->left;
  }
  return current;
}

//TODO: tentar fazer recursiva
PtrAVLNode maxValueNode(PtrAVLNode node) {
  PtrAVLNode current = node;
  /* loop down to find the rightmost leaf */
  while (current->right != NULL) {
    current = current->right;
  }
  return current;
}

//---------------------------------------------------------------------
// Recursive function to delete a node with given key
// from subtree with given root. It returns root of
// the modified subtree.
//---------------------------------------------------------------------
PtrAVLNode deleteNode(PtrAVLNode root, int key) {
    
  // STEP 1: PERFORM STANDARD BST DELETE

  if (root == NULL) {
    return root;
  }
  
  // If the key to be deleted is smaller than the
  // root's key, then it lies in left subtree
  if ( key < root->key ) {
    root->left = deleteNode(root->left, key);
  }
  // If the key to be deleted is greater than the
  // root's key, then it lies in right subtree
  else if( key > root->key ) {
    root->right = deleteNode(root->right, key);
  }
  // if key is same as root's key, then This is
  // the node to be deleted
  else { // node with only one child or no child
   
    if( (root->left == NULL) || (root->right == NULL) ) {
      PtrAVLNode temp = root->left ? root->left : root->right;
      
      // No child case
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else { // One child case
        *root = *temp; // Copy the contents of the non-empty child
      }
    
      free(temp);
    
    } else {

      // node with two children: Get the inorder
      // successor (smallest in the right subtree)
      // PtrAVLNode temp = minValueNode(root->right);

      // node with two children: Get the inorder
      // successor (smallest in the right subtree)
      PtrAVLNode temp = maxValueNode(root->left);

      // Copy the inorder successor's data to this node
      root->key = temp->key;

      // Delete the inorder successor
      root->right = deleteNode(root->right, temp->key);
    }
  }

  // If the tree had only one node then return
  if (root == NULL) return root;

  /* STEP 2: UPDATE HEIGHT OF THE CURRENT NODE */
  root->height = 1 + max(height(root->left), height(root->right));

  /* STEP 3: GET THE BALANCE FACTOR OF THIS NODE
   (to check whether this node became unbalanced) */
  int balance = getBalance(root);

  // If this node becomes unbalanced, then there are 4 cases

  // Left Left Case
  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  // Left Right Case
  if (balance > 1 && getBalance(root->left) < 0) {
    root->left =  leftRotate(root->left);
    return rightRotate(root);
  }

  // Right Right Case
  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  // Right Left Case
  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
