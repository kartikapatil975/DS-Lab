#include <stdio.h>
            return temp;
        }
        // Two children case
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
    
    
}

// Search for a key in the BST.
bool search(Node *root, int key) {
    
    
    if (root == NULL) return false;
    if (root->data == key) return true;
    return (key < root->data) ? search(root->left, key) : search(root->right, key);

    //code here..
    
    
}

int main() {
    int opCount;
    scanf("%d", &opCount);
    
    Node *root = NULL;
    
    char outputs[MAX_OPS][50];
    int outIndex = 0;
    
    int op, key;
    for (int i = 0; i < opCount; i++) {
        scanf("%d", &op);
        if(op == 1 || op == 2 || op == 3)
            scanf("%d", &key);
            
        switch(op) {
            case 1: // Insert
                root = insert(root, key);
                break;
            case 2: // Delete
                if(search(root, key))
                    root = deleteNode(root, key);
                break;
            case 3: { // Search
                if(search(root, key))
                    strcpy(outputs[outIndex++], "found");
                else
                    strcpy(outputs[outIndex++], "not found");
                break;
}
