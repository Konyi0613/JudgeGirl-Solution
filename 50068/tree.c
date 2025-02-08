#include <stdio.h>
#include <stdlib.h>
// #define MAIN
#define MAX 1000
typedef struct Node {
    int label;
    struct Node *left, *right;
} Node;

void print_label(Node *root)
{
    printf("%d\n", root->label);
    return;
}

void traversal(Node *root, int N, int command[])
{
    Node* track[1000];
    int pos = 0;
    Node* now = root;
    for (int i = 0; i < N; i++)
    {
        if (command[i] == 0)
        {
            print_label(now);
            break;
        }
        else if (command[i] == 1)
            print_label(now);
        else if (command[i] == 2)
        {
            if (pos == 0)
            {
                print_label(now);
                break;
            }
            else
            {
                pos--;
                now = track[pos];
            }
        }
        else if (command[i] == 3)
        {
            if (now->left == NULL)
            {
                print_label(now);
                break;   
            }
            track[pos] = now;
            pos++;
            now = now->left;
        }
        else if (command[i] == 4)
        {
            if (now->right == NULL)
            {
                print_label(now);
                break;   
            }
            track[pos] = now;
            pos++;
            now = now->right;
        }
        else
        {
            if (pos == 0)
            {
                print_label(now);
                break;
            }
            Node* parent = track[pos - 1];
            int valid = 1;
            if (parent->left == now)
            {
                if (parent->right == NULL)
                    valid = 0;
                else
                    now = parent->right;
            }
            else
            {
                if (parent->left == NULL)
                    valid = 0;
                else
                    now = parent->left;
            }
            if (valid == 0)
            {
                print_label(now);
                break;
            }
        }
    }
}

#ifdef MAIN
Node* newNode(int label, Node *l, Node *r) {
    Node *u = (Node *) malloc(sizeof(Node));
    u->label = label, u->left = l, u->right = r;
    return u;
}
 
int main() {
    Node *root = newNode(
            6,
            newNode(
                3,
                newNode(1,
                        NULL,
                        newNode(2, NULL, NULL)
                        ),
                newNode(5,
                        newNode(4, NULL, NULL),
                        NULL
                        )               
            ),
            newNode(
                7,
                NULL,
                NULL               
            )
    );
 
    int N, command[MAX];
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &command[i]);       
    }
    traversal(root, N, command);
    return 0;
}
#endif