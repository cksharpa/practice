/*
    balanced: check if a binary tree is balanced.
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/* standard tree node */
struct treenode {
        struct treenode *left;
        struct treenode *right;
};


/* max of two integers */
int
max(int a, int b)
{
        return (a > b) ? a : b;
}


/* start by assuming tree rooted at node is balanced.  Recurse
   to find left and right subtree heights.  Set balanced to false
   if tree rooted at node is not balanced.  Leaf height is 0
   and leaf is balanced.

   Note that balanced is untouched or set to false.
 */
int
height(struct treenode *node, int *balanced)
{
        if (!node)
                return 0;
        int leftheight = height(node->left, balanced);
        int rightheight = height(node->right, balanced);
        if (abs(leftheight - rightheight) > 1)
                *balanced = 0;
        return max(leftheight, rightheight) + 1;
}


int
main(void)
{
        struct treenode rightrightleaf = {
                .left = NULL,
                .right = NULL
        };
        struct treenode right = {
                .left = NULL,
                .right = &rightrightleaf
        };
        struct treenode root = {
                .left = NULL,
                .right = &right
        };
        int balanced = 1;
        height(&root, &balanced);
        printf("Tree is %s\n", balanced ? "balanced" : "not balanced");
        return 0;
}
