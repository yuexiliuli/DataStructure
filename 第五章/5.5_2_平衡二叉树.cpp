#include <iostream>
using namespace std;

#define MAX_TREE_SIZE 100  //树中最多节点数
#define ElemType int

//二叉排序树节点
typedef struct AVLNode{
    int key;
    int balance;
    struct AVLNode *lchild,*rchild;
}AVLNode,*AVLTree;








