#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 2

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

int peek(){
   return intArray[front];
}

bool isEmpty(){
   return itemCount == 0;
}

bool isFull(){
   return itemCount == MAX;
}

int size(){
   return itemCount;
}

void insert(int data){

   if(!isFull()){

      if(rear == MAX-1){
         rear = -1;
      }

      intArray[++rear] = data;
      itemCount++;
   }
}

int removeData(){
   int data = intArray[front++];

   if(front == MAX){
      front = 0;
   }

   itemCount--;
   return data;
}

int main() {
   /* chen 5 phan tu */
   insert(9);

   // front : 0
   // rear  : 0
   // ------------------
   // index : 0
   // ------------------
   // queue : 9
   insert(12);

   // front : 0
   // rear  : 1
   // ---------------------
   // index : 0 1
   // ---------------------
   // queue : 9 12
   printf("Hang doi : ");
      while(!isEmpty()){
      int n = removeData();
      printf("%d  ",n);
   }
   printf("\nSo hang doi MAX = %d\n",MAX);

   if(isFull()){
      printf("Hang doi (Queue) da day!\n");
   }

   // xoa mot phan tu
   int num = removeData();

   printf("Phan tu bi xoa: %d\n",num);
   // front : 1
   // rear  : 1
   // -------------------
   // index : 1
   // -------------------
   // queue : 12

   // Chen them mot phan tu
   insert(16);

   // front : 0
   // rear  : 1
   // ----------------------
   // index : 0  1
   // ----------------------
   // queue : 16 12
   // neu hang doi la day thi phan tu se bi de`
   printf("\nneu hang doi la day thi phan tu se bi de` \n______________________________________\n");
   insert(17);
   insert(18);
   printf("Chen them 17 18\n");

   // ----------------------
   // index : 0  1
   // ----------------------
   // queue : 16 12
   printf("Phan tu tai vi tri front: %d\n",peek());

   printf("______________________________________\n");
   printf("Gia tri chi muc :  1  0\n");
   printf("______________________________________\n");
   printf("Hang doi (Queue):  ");

   while(!isEmpty()){
      int n = removeData();
      printf("%d ",n);
   }
}
