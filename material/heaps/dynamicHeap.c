struct Node {
    Node *parent;
    Node *link[2];
};

struct Heap {
    Node *root;
    Node *last;
};

void init (Heap *h)
{
    h->root = NULL;
    h->last = NULL;
}

void insert (Heap *h, Node *node)
{
    // If the heap is empty, insert root node.
    if (h->root == NULL) {
        h->root = node;
        h->last = node;
        node->parent = NULL;
        node->link[0] = NULL;
        node->link[1] = NULL;
        return;
    }

    // We will be finding the node to insert below.

    // Start with the current last node and move up as long as the
    // parent exists and the current node is its right child.
    Node *cur = h->last;
    while (cur->parent != NULL && cur == cur->parent->link[1]) {
        cur = cur->parent;
    }

    if (cur->parent != NULL) {
        if (cur->parent->link[1] != NULL) {
            // The parent has a right child. Attach the new node to
            // the leftmost node of the parent's right subtree.
            cur = cur->parent->link[1];
            while (cur->link[0] != NULL) {
                cur = cur->link[0];
            }
        } else {
            // The parent has no right child. This can only happen when
            // the last node is a right child. The new node can become
            // the right child.
            cur = cur->parent;
        }
    } else {
        // We have reached the root. The new node will be at a new level,
        // the left child of the current leftmost node.
        while (cur->link[0] != NULL) {
            cur = cur->link[0];
        }
    }

    // This is the node below which we will insert. It has either no
    // children or only a left child.
    assert(cur->link[1] == NULL);

    // Insert the new node, which becomes the new last node.
    h->last = node;
    cur->link[cur->link[0] != NULL] = node;
    node->parent = cur;
    node->link[0] = NULL;
    node->link[1] = NULL;

    // Restore the heap property.
    while (node->parent != NULL && value(node->parent) > value(node)) {
        move_one_up(h, node);
    }
}

void remove (Heap *h, Node *node)
{
    // If this is the only node left, remove it.
    if (node->parent == NULL && node->link[0] == NULL && node->link[1] == NULL) {
        h->root = NULL;
        h->last = NULL;
        return;
    }

    // Locate the node before the last node.
    Node *cur = h->last;
    while (cur->parent != NULL && cur == cur->parent->link[0]) {
        cur = cur->parent;
    }
    if (cur->parent != NULL) {
        assert(cur->parent->link[0] != NULL);
        cur = cur->parent->link[0];
    }
    while (cur->link[1] != NULL) {
        cur = cur->link[1];
    }

    // Disconnect the last node.
    assert(h->last->parent != NULL);
    h->last->parent->link[h->last == h->last->parent->link[1]] = NULL;

    if (node == h->last) {
        // Deleting last, set new last.
        h->last = cur;
    } else {
        // Not deleting last, move last to node's place.
        Node *srcnode = h->last;
        replace_node(h, node, srcnode);
        // Set new last unless node=cur; in this case it stays the same.
        if (node != cur) {
            h->last = cur;
        }

        // Restore the heap property.
        if (srcnode->parent != NULL && value(srcnode) < value(srcnode->parent)) {
            do {
                move_one_up(h, srcnode);
            } while (srcnode->parent != NULL && value(srcnode) < value(srcnode->parent));
        } else {
            while (srcnode->link[0] != NULL || srcnode->link[1] != NULL) {
                bool side = srcnode->link[1] != NULL && value(srcnode->link[0]) >= value(srcnode->link[1]);
                if (value(srcnode) > value(srcnode->link[side])) {
                    move_one_up(h, srcnode->link[side]);
                } else {
                    break;
                }
            }
        }
    }
}
