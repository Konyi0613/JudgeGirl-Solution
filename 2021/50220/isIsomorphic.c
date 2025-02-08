#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #define MAIN
struct TreeNode {
    struct TreeNode *left;
    struct TreeNode *mid;
    struct TreeNode *right;
};
 
typedef struct TreeNode TreeNode;
 
bool isIsomorphic(TreeNode* root1, TreeNode* root2){
    if(root1 == NULL && root2 == NULL)
        return true;
    if(root1 == NULL || root2 == NULL)
        return false;
    
    bool ll,lm,lr,ml,mm,mr,rl,rm,rr;
    ll = isIsomorphic(root1->left,root2->left);
    lm = isIsomorphic(root1->left,root2->mid);
    lr = isIsomorphic(root1->left,root2->right);
    ml = isIsomorphic(root1->mid,root2->left);
    mm = isIsomorphic(root1->mid,root2->mid);
    mr = isIsomorphic(root1->mid,root2->right);
    rl = isIsomorphic(root1->right,root2->left);
    rm = isIsomorphic(root1->right,root2->mid);
    rr = isIsomorphic(root1->right,root2->right);

    if((ll && mm && rr) || (ll && mr && rm) || (lm && ml && rr) || (lm && mr && rl) || (lr && ml && rm) || (lr && mm && rl))
        return true;
    else
        return false;
}

#ifdef MAIN 
TreeNode *buildTree(TreeNode **roots) {
    int val;
    scanf("%d", &val);
    if(val == 0) return NULL;
 
    TreeNode *now = *roots;
 
    (*roots)++;
 
    now->left = buildTree(roots);
    now->mid = buildTree(roots);
    now->right = buildTree(roots);
 
    return now;
}

int main() {
    int T, size;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &size);
        TreeNode* root1 = (TreeNode*)calloc(size, sizeof(TreeNode));
        TreeNode* root2 = (TreeNode*)calloc(size, sizeof(TreeNode));
 
        TreeNode *nptr1 = root1, *nptr2 = root2;
 
        root1 = buildTree(&nptr1);
        root2 = buildTree(&nptr2);
 
        isIsomorphic(root1, root2) == true ? printf("True\n") : printf("False\n");
 
        free(root1);
        free(root2);
    }
    return 0;
}
#endif