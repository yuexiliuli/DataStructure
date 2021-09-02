#include <iostream>
using namespace std;

#define MAX_TREE_SIZE 100  //树中最多节点数
#define ElemType int

//二叉排序树节点
typedef struct BSTNode{
    int key;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

//在二叉排序树中查找值为 key 的节点
BSTNode *BST_Search(BSTree T,int key){
    while(T!=NULL && key!=T->key){ //若树空或等于根节点值，则结束循环
        if(key<T->key) T=T->lchild;  //小于，则在左子树查找
        else T=T->rchild;  //大于，则在右子树查找
    }
    return T;
}

//在二叉排序树中查找值为 key 的节点（递归）
BSTNode *BSTSearch(BSTree T,int key){
    if(T==NULL)
        return NULL;  //查找失败
    if(key==T->key)
        return T;     //查找成功
    else if(key < T->key)
        return BSTSearch(T->lchild,key);
    else
        return BSTSearch(T->rchild,key);
    
}
//在二叉树插入关键字为 k 的新节点（递归实现）
int BST_Insert(BSTree &T,int k){
    if(T==NULL){    //原树为空，新插入的节点为根结点
        T=(BSTree)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = T->rchild = NULL;
        return 1;  //返回1，插入成功
    }
    else if(k == T->key)  //树中存在相同关键字的节点，插入失败
        return 0;
    else if(k<T->key)  //插入到T的左子树
        return BST_Insert(T->lchild,k);  
    else   //插入到T的右子树
        return BST_Insert(T->rchild,k);
}

//按照 str[] 中的关键字序列建立二叉排序树
void Creat_BST(BSTree &T,int str[],int n){
    T = NULL;  //初始为空
    int i=0;
    while(i<n){  //依次将每个关键字插入到二叉排序树中
        BST_Insert(T,str[i]);
        i++;
    }
}






