#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 1
#define OVERFLOW -2
#define ERROR 0
typedef int Status;
typedef struct stu
{
    int id;
    char name[50];
    int score;
}Student;


typedef struct Lnode
{
    Student data;
    struct Lnode *next;
}Lnode,*LinkList;

//单链表的初始化
Status InitStu(LinkList *L){
    //LinkList *L ： 二级指针
    (*L) = (LinkList)malloc(sizeof(Lnode));
    (*L)->next = NULL;
    return OK;
}

//单链表的取值
Status getStu(LinkList L,int i,Student *stu){
    LinkList p;
    p = L->next;
    int j=1;
    while (p&&j<i){
        p=p->next;
        ++j;
    }
    stu->id = p->data.id;
    strcpy(stu->name,p->data.name);
    stu->score = p->data.score;
    return 1;
}


//单链表元素的查找
Lnode *FindStu(LinkList L,Student data){
    LinkList p;
    p = L->next;
    while (p && p->data.id==data.id)
    {
       p= p->next;
    }
    return p;
}


//单链表的表长
Status getlenght(LinkList L){
    LinkList p =L->next;
    int j=0;
    while (p)
    {
        p=p->next;
        ++j;
    }
    printf("单链表长度：%d\n",j);
    return 1;
}


//单链表的插入
Status Insert(LinkList *L,int i,Student data){
    LinkList p;
    p= (*L);
    int j=0;
    while (p&&j<i-1)
    {
       p=p->next;
       ++j;
    }
    if (!p ||j>i-1) return ERROR;
    LinkList pnew=(LinkList)malloc(sizeof(Lnode));
    pnew->data =data;
    pnew->next = p->next;
    p->next=pnew;
    return OK;
}


//单链表的删除
Status DeleteStu(LinkList *L,int i){
    LinkList p;
    p= (*L);
    printf("[");
    int j=0;
    while ( p->next &&j<i-1)
    {
        p = p->next;
        ++j;
    }

    if (!p||j>i-1||!p->next) return ERROR;
    LinkList pnew = p->next;
    p->next = pnew->next;
    free(pnew); //释放内存地址
    return OK;

}

int main(){
    LinkList L;
    Student data={123,"chenyinglin",87};
    InitStu(&L);
    Insert(&L,1,data);
    
    Student data2;
    getStu(L,1,&data2);
    DeleteStu(&L,1);
    getlenght(L);
    printf("data2:name:%s\n",data2.name);
    return 1;
}