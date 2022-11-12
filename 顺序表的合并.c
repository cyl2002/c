#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

typedef struct
{
    ElemType *data;
    int lenght;
}SqList;

//初始化顺序表
Status InitList(SqList *L){
    //为顺序分配存储空间
    L->data = (ElemType *)malloc(sizeof(ElemType)*MAXSIZE); 
    if (!L->data) exit(OVERFLOW);
    L->lenght = 0;
    return OK;
}

Status InitList_L(SqList *L,int n,ElemType *List){
    //为顺序分配存储空间
    L->data = (ElemType *)malloc(sizeof(ElemType)*MAXSIZE); 
    if (!L->data) exit(OVERFLOW);
    L->lenght = 0;
    for (int i=0;i<n;i++){
        L->data[i]=*(List+i);
        L->lenght+=1;
    }
    return OK;
} 

//获取顺序表中的元素
Status GetElem(SqList L,int i,ElemType *e){
    if (i<1||i>L.lenght) return ERROR;
    (*e) = L.data[i-1];
    return OK;
}

//顺序表的插入
Status ListInsert(SqList *L,int i,ElemType data){
    //判断序号是否合理，不合理返回ERROR
    if (i<1||i>L->lenght+1) return ERROR;
    //判断序号是否超出范围
    if (i>MAXSIZE) exit(OVERFLOW);
    int j;
    for (j=L->lenght-1;j>=i-1;j--){
        L->data[j+1]=L->data[j];
    }
    L->data[i-1]=data;
    L->lenght+=1;
    return OK;
}

//顺序表的删除
Status ListDelete(SqList *L,int i){
    int j;
    //判断序号是否合理，不合理返回ERROR
    if (i<1||i>L->lenght+1) return ERROR;
    for (j=i-1;j<L->lenght-1;j++){
        L->data[j] =L->data[j+1];
    }
    L->lenght -=1;
    return OK;
}

//顺序表的查找
Status FinkElem(SqList L,ElemType e){
    int i;
    for (i=0;i<L.lenght;i++){
        if (L.data[i]==e){
            return OK;
        }
    }
    return ERROR;
}


//合并两个顺序表
void merge(SqList *La,SqList *Lb){
    ElemType *e;
    int La_len,Lb_len;
    La_len = La->lenght;
    Lb_len = Lb->lenght;
    int i;
    for(i=0;i<Lb_len;i++){
        GetElem(*Lb,i+1,e);
        if(!FinkElem(*La,*e)){
            ListInsert(La,La_len+i+1,*e);
        }
    }
}
//输出顺序表
void Outputs(SqList L){
    if (!L.lenght) printf("顺序表为空!\n");
    else {
        int n=L.lenght;
        printf("顺序表长度为%d\n",n);
        for (int i=0;i<n;i++){
            printf("元素%d:%d\n",i+1,L.data[i]);
        }
    }
}


int main()
{
    SqList La;
    SqList Lb;
    ElemType LaList[4]={7,5,3,11};
    ElemType LbList[3]={2,6,3};
    InitList_L(&La,4,LaList);
    InitList_L(&Lb,3,LbList);
    merge(&La,&Lb);
    Outputs(La);
    return OK;
}
