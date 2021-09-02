#include <iostream>
using namespace std;

#define MaxSize 100
#define ElemType int

//线索二叉树节点
typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag; //tag=0：指针指向孩子，tag=1：指针是“线索”
}ThreadNode,*ThreadTree;








