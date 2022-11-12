#include <stdio.h>


typedef struct 
    {
        float Realpart;
        float Imagepart;
    }Comple;
Comple C;
int main(){
   void Create(Comple C,float real,float image);
   float getImage(Comple C );
   Create(C,3.0,4.9);
   float a = getImage(C);
   printf("%f\n",a);
   return 0;
}

void Create(Comple C,float real,float image){
    C.Realpart = real;
    C.Imagepart = image;
}

float getImage(Comple C){
    float image = C.Imagepart;
    printf("%f\n",image);
    return image;
}