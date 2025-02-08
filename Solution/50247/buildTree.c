#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Node{
    char* val;
    struct Node *left, *right;
} Node;
 
Node* buildTree2(char* expr, int l, int r){
    if(expr[l] == '!'){
 
        Node* ans = (Node*)malloc(sizeof(*ans));
 
        ans->val = "!";
        ans->left = buildTree2(expr, l + 2, r);
        ans->right = NULL;
        return ans;
 
    }else if(expr[l] == '('){
        int level = 0;
        int ptr = l + 1;
        while(!(level == 0 && (expr[ptr] == '|' || expr[ptr] == '&'))){
            ptr++;
            if(expr[ptr] == '(') level++;
            if(expr[ptr] == ')') level--;
        }
 
        Node* ans = (Node*)malloc(sizeof(*ans));
 
        if(expr[ptr] == '|'){
            ans->val = "||";
        }else{
            ans->val = "&&";
        }
        ans->left = buildTree2(expr, l+2, ptr-2);
        ans->right = buildTree2(expr, ptr+3, r-2);
 
        return ans;
    }else{
 
        Node* ans = (Node*)malloc(sizeof(*ans));
 
        char* c = (char*)malloc(sizeof(char*));
        *c = expr[l];
        *(c+1) = '\0';
 
        ans->val = c;
        ans->left = NULL;
        ans->right = NULL;
        return ans;
    }
}
 
Node* buildTree(char* expr){
    int sz = 0;
    while((expr[sz]) && expr[sz] != '\n' ){
        sz++;
    }
    return buildTree2(expr, 0, sz);
}
/*
void printtree(Node *root){
    if(root == NULL)
        return;
    printf("%s\n",root->val);
    printtree(root->left);
    printtree(root->right);
    return;
}
 
int main(){
    Node *root = buildTree("! ( ( ( ! M && ( H && D ) ) && R ) || ! ! K )");
    printtree(root);
    return 0;
}*/