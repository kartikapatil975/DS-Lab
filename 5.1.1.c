#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODE;

// Create a new node with given data
NODE createNodeInCLL(int data) {
    NODE temp = (NODE) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Create CLL with n nodes
NODE createCLL(  int n     ) {
	
// write your code here...
if(n <= 0)
        return NULL;
    NODE first = NULL, last = NULL;
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        NODE temp = createNodeInCLL(x);
        if(first == NULL) {
            first = temp;
            last = temp;
            last->next = first;
        }
        else {
            last->next = temp;
            last = temp;
            last->next = first;
        }
	}
    return first;

}

// Traverse CLL
void traverseListInCLL( NODE first     ) {

// write your code here...

if(first == NULL) {
        printf("CLL is empty\n");
        return;
    }

    NODE temp = first;

    printf("");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != first);

    printf("\n");
}

// Insert at given position in CLL
NODE insertAtPositionInCLL(  NODE first, int pos, int x       ) {
	
//write your code here..
NODE temp = createNodeInCLL(x);

    if(first == NULL && pos == 1) {
        temp->next = temp;
        return temp;
    }

    NODE curr = first;
    int count = 1;

    if(pos == 1) {

        while(curr->next != first)
            curr = curr->next;

        temp->next = first;
        curr->next = temp;
        first = temp;

        return first;
    }

    curr = first;
    count = 1;

    while(count < pos-1 && curr->next != first) {
        curr = curr->next;
        count++;
    }

    if(count != pos-1) {
        printf("Position not found\n");
        return first;
    }

    temp->next = curr->next;
    curr->next = temp;

    return first;

	
}

// Delete node at given position in CLL
NODE deleteAtPositionInCLL( NODE first, int pos      ) {
if(first == NULL) {
        printf("CLL is empty\n");
        return first;
    }

    NODE curr = first;
    NODE prev = NULL;
    int count = 1;

    if(pos == 1) {

        if(first->next == first) {
            printf("Deleted element: %d\n", first->data);
            free(first);
            return NULL;
        }

        while(curr->next != first)
            curr = curr->next;

        NODE temp = first;
        curr->next = first->next;
        first = first->next;

        printf("Deleted element: %d\n", temp->data);

        free(temp);

        return first;
    }

    curr = first;
    prev = NULL;
    count = 1;

    while(count < pos && curr->next != first) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if(count != pos) {
        printf("Position not found\n");
        return first;
    }

    prev->next = curr->next;

    printf("Deleted element: %d\n", curr->data);

    free(curr);

    return first;


	
	
}

// Reverse CLL
NODE reverseCLL(   NODE first     ) {
	
//write your code here...
if(first == NULL || first->next == first)
        return first;

    NODE prev = NULL;
    NODE current = first;
    NODE next = NULL;
    NODE last = first;

    while(last->next != first)
        last = last->next;

    prev = last;
    current = first;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;

    } while(current != first);

    first = prev;

    return first;



}

// Concatenate two CLLs
NODE concatCLL(  NODE first, NODE second         ) {

//write your code here..
if(first == NULL)
        return second;

    if(second == NULL)
        return first;

    NODE last1 = first;
    NODE last2 = second;

    while(last1->next != first)
        last1 = last1->next;

    while(last2->next != second)
        last2 = last2->next;

    last1->next = second;
    last2->next = first;

    return first;




}

int main() {
    NODE first = NULL, second = NULL;
    int x, pos, op, n;

    while (1) {
        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                first = createCLL(n);
                break;
            case 2:
                printf("Position: ");
                scanf("%d", &pos);
                if (pos <= 0) {
                    printf("Position not found\n");
                } else {
                    printf("Element: ");
                    scanf("%d", &x);
                    first = insertAtPositionInCLL(first, pos, x);
                }
                break;
            case 3:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Position: ");
                    scanf("%d", &pos);
                    first = deleteAtPositionInCLL(first, pos);
                }
                break;
            case 4:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Elements in CLL are: ");
                    traverseListInCLL(first);
                }
                break;
            case 5:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                    traverseListInCLL(first);   // <-- display reversed list
                }
                break;
            case 6:
                printf("Creating second CLL to concatenate...\n");
                printf("How many nodes in second CLL? ");
                scanf("%d", &n);
                second = createCLL(n);
                first = concatCLL(first, second);
                printf("Concatenated CLL:\n");
                traverseListInCLL(first);
                break;
            case 7:
                exit(0);
        }
    }
}
