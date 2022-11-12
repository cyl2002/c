#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
#define OVERFLOW -2
#define OK 1
#define ERROR 0
typedef int Status;
typedef int StudentId;


typedef struct 
{
  StudentId *data;
  int lenght;
}Student;


//初始化一个线性表
Status InitList(Student *L){
    L->data = (StudentId *)malloc(sizeof(StudentId)*MaxSize);
    if (!L->data) exit(OVERFLOW);
    L->lenght = 0;
    return OK;
}

//顺序表获取数据
Status getStu(Student S,int i){
  if (i<1 || i>S.lenght) return ERROR;
  StudentId e;
  e = S.data[i-1];
  printf("%d\n",e);
  return OK;
}


//顺序表插入
Status Insert(Student *S,int i,StudentId e){
  /*
  参数i：插入的位置
  参数e：插入元素
  */
 int j;

 if (i<1||i>(S->lenght+1)) return OVERFLOW; //判断序号是否合理、是否溢出，不合理返回ERROR
 if (S->lenght>MaxSize)  return ERROR; //判断空间是否已满
 for (j=S->lenght-1;j>=i-1;j--){
      S->data[j+1]=S->data[j];
      printf("%d",j);
 }
 S->data[i-1]=e;
 S->lenght +=1;
 return OK;
}



//顺序表的查找
Status FindStu(Student S,StudentId p){
  int j;
  for (j=0;j<S.lenght;j++){
    if (p==S.data[j]) {
      printf("找到元素，位置：%d\n",j+1);
      return OK;
    }
  }
  return ERROR;
}


//顺序表的删除
Status DeleteStu(Student *s,int i){
  int j;
  if (i<1||i>s->lenght) return OVERFLOW;
  if (!s->lenght) return ERROR;
  for (j=i-1;j<s->lenght-1;j++){
    s->data[j]=s->data[j+1];
  }
  s->lenght -=1;
  return OK;
}


int main(){
  Student S;
  int h;
  InitList(&S);
  int a,b;
  Insert(&S,1,3);
  printf("%d\n",S.lenght);
  Insert(&S,2,9);
  printf("%d\n",S.lenght);
  getStu(S,2);
  FindStu(S,3);
  DeleteStu(&S,1);
  return 1;
}