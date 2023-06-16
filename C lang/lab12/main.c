#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPACE "   "
#define BRT_OPEN 0
#define BRT_CLOSE 1
#define ADD 2
#define SUB 2
#define MUL 3
#define DIV 3
#define DGR 4
#define VAR 5
#define ZERO ('(' - 1)
#define IND(a) (a - '(' + 1)

typedef struct tree{
    char elem;
    struct tree *left;
    struct tree *right;
}tree;

typedef struct node{
    char symbol;
    struct node *next;
}node;

void printTree (tree *p, int n){
    if (p->right != NULL) {
        printTree(p->right, n + 1);
    }
    for (int i = 0; i < n - 1; i++)
        printf(SPACE);
    if (n)
        printf("|->");
    printf("%c\n", p->elem);
    if (p->left != NULL)
        printTree(p->left, n + 1);
}

void postorder(tree *ptr){
    if (ptr == NULL)
        return;
    postorder(ptr->left);
    postorder(ptr->right);
    printf("%c", ptr->elem);
}

node* push(node *ptr, char elem){
    node *tmp;
    tmp = (node*)malloc(sizeof(node));
    tmp->symbol = elem;
    tmp->next = ptr;
    return tmp;
}

node *pop(node *ptr, char *elem){
    *elem = ptr->symbol;
    ptr = ptr->next;
    return ptr;
}

void fillCodes(char *codes){
    for (int i = 'a'; i <= 'z'; i++){
        codes[IND(i)] = VAR;
    }
    codes[0] = -1;
    codes[IND('(')] = BRT_OPEN;
    codes[IND(')')] = BRT_CLOSE;
    codes[IND('+')] = ADD;
    codes[IND('-')] = SUB;
    codes[IND('*')] = MUL;
    codes[IND('/')] = DIV;
    codes[IND('^')] = DGR;
}

void revPolishNTN (char *src, char *dest){
    if (strlen(src) == 0)
        return;

    int i = 0, j = 0;
    char prev, buff;
    char priority[83] = {0};
    node *ptr = NULL;

    fillCodes(priority);

    prev = ZERO;
    while(src[i]){
        if (priority[IND(src[i])] == VAR)
            dest[j++] = src[i];
        else if (priority[IND(src[i])] == BRT_OPEN || priority[IND(src[i])] > priority[IND(prev)]){
            ptr = push(ptr, src[i]);
            prev = src[i];
        }
        else{
            while(priority[IND(src[i])] < priority[IND(prev)]){
                ptr = pop(ptr, &dest[j++]);
                prev = ptr->symbol;
            }
            if (ptr->symbol == '(' && src[i] == ')') {
                ptr = pop(ptr, &buff);
                if (ptr == NULL)
                    prev = ZERO;
                else
                    prev = ptr->symbol;
            }
            if (src[i] != ')')
                ptr = push(ptr, src[i]);
        }
        i++;
    }
    while (ptr != NULL)
        ptr = pop(ptr, &dest[j++]);
    dest[j] = 0;
}

tree *toTree(tree *ptr, char *str, int *i){
    *i = *i - 1;
    if (*i < 0)
        return ptr;
    ptr = (tree*)malloc(sizeof(tree));
    ptr->elem = str[*i];
    ptr->left = NULL;
    ptr->right = NULL;
    if (str[*i] >= 'a' && str[*i] <= 'z')
        return ptr;
    ptr->right = toTree(ptr->right, str, i);
    ptr->left = toTree(ptr->left, str, i);
    return ptr;
}

int main() {
    char *formula = "(a*b+c*(y-g*d))^n";
    char res[strlen(formula)];
    tree *head = NULL;
    printf("Formula: ");
    puts(formula);
    revPolishNTN(formula, res);
    printf("Reverse polish notation: ");
    puts(res);
    printf("\nTree:\n");
    int len = (int)strlen(res);
    head = toTree(head, res, &len);
    printTree(head, 0);
    printf("\nPostorder: ");
    postorder(head);
}