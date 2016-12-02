//chi truy cap duoc dia chi tren cung , first in last out , last out first in
#include <stdio.h>

int MAXSIZE = 2;
int stack[2];
int top = -1;

int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}

int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() {
   return stack[top];
}


int pop() {
   int data;

   if(!isempty()) {
      data = stack[top];
      top = top - 1;
      return data;
   }else {
      printf("Khong the thu thap du lieu, ngan xep (Stack) la trong.\n");
   }
}

int push(int data) {

   if(!isfull()) {
      top = top + 1;
      stack[top] = data;
   }else {
      printf("Khong the chen du lieu, ngan xep (Stack) da day.\n");
   }
}

int main() {
   // chen cac phan tu vao ngan xep
   printf("Max=2,tong=3,chen 6,2,9");
   push(6);
   push(2);
   push(9);

   printf("\nMAX=2,tong=3,chen them 14, 11 se bao day`\n\n");
   push(14);// bao day` vi het ngan xep
   push(11); // bao day`

   printf("Phan tu tai vi tri tren cung cua ngan xep: %d\n" ,peek());
   printf("Cac phan tu: \n");

   // in cac phan tu trong ngan xep
   while(!isempty()) {
      int data = pop();
      printf("%d\n",data);
   }

   printf("Ngan xep da day: %s\n" , isfull()?"true":"false");
   printf("Ngan xep la trong: %s\n" , isempty()?"true":"false");

   return 0;
}
