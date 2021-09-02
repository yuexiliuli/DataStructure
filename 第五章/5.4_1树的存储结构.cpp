#include <iostream>
using namespace std;

#define MAX_TREE_SIZE 100  //树中最多节点数
#define ElemType int

typedef struct{ //树的节点定义
    ElemType data; //数据元素
    int parent;    //双亲位置域
}PTNode;

typedef struct{     //树的类型定义
    PTNode nodes[MAX_TREE_SIZE]; //顺序表 双亲表示
    int n;                       //节点数
}PTree;

//孩子表示法（顺序+链式存储）
struct CTNode{
    int child;  //孩子节点在数组中的位置
    struct CTNode *next;  //下一个孩子
};

typedef struct{
    ElemType data;
    struct CTNode *firstChild;  //第一个孩子
}CTBox;

typedef struct{
    CTBox nodes[MAX_TREE_SIZE];
    int n,r;  //结点数和根的位置
}CTree;

//孩子兄弟表示法（链式存储）
typedef struct CSNode{
    ElemType data;  //数据域
    struct CSNode *firstchild,*nextsibling;  //第一个孩子和右兄弟指针
}CSNode,*CSTree;



/*
树的先根遍历
void PreOrder(TreeNode *R){
    if(R!=NULL){
        visit(R);   //访问根节点
        while(R还有下一个子树T)
            PreOrder(T); //先根遍历下一棵子树
    }
}

树的后根遍历
void PostOrder(TreeNode *R){
    if(R!=NULL){
        while(R还有下一个子树T)
            PostOrder(T); //先根遍历下一棵子树
        visit(R);   //访问根节点
    }
}

树的层次遍历
...

*/






