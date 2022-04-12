#include<stdio.h>
#include<stdlib.h>
struct Node{
   int data;
   struct Node *next;
};
struct Node *head = 0;
struct Node *tail = 0;
int count = 0;
void newNode(int value){
    count++;
    if(head==NULL){
      head = malloc(sizeof(struct Node));
      head->data = value;
      head->next = NULL;
      tail = head;
    }
    else{
      struct Node *t = malloc(sizeof(struct Node));
      t->data = value;
      t->next = NULL;
      tail->next = t;
      tail = t;
    }
}
void display(struct Node *p){
    if(p!=NULL){
      printf("%d ",p->data);
      display(p->next);
    }
}
void delete(int node){
    if(node==1){//Deleting the head node...
      struct Node *p = head;
      head = head->next;
      p->next = NULL;
      free(p);
    }
    else if(count==node){
      struct Node *q = 0;
      struct Node *p = head;
      for(int i=1;i<node;i++){
         q = p;
         p = p->next;
      }
      tail = q;
      tail->next = 0;
      free(p);
    }
    else{
      struct Node *q = 0;
      struct Node *p = head;
      for(int i=1;i<node;i++){
         q = p;
         p = p->next;
      }
      q->next = p->next;
      p->next = 0;
      free(p);
    }
    count--;
}
int size(){
  return count;
}
void insert(int index, int value){
  if(index==0){
     struct Node *t = malloc(sizeof(struct Node));
     t->data = value;
     t->next = head;
     head = t;
  }
  else if((index-1) == count){
     struct Node *t = malloc(sizeof(struct Node));
     t->data = value;
     t->next = 0;
     tail->next =t;
     tail = t;
  }
  else{
      struct Node *q = 0;
      struct Node *p = head;
      for(int i=1;i<index;i++){
         q = p;
         p = p->next;
      }
      struct Node *t = malloc(sizeof(struct Node));
      t->data  = value;
      q->next = t;
      t->next = p;
  }
  count++;
}
int main() {
  int n;
  scanf("%d",&n);
  int A[n];
  for(int i=0;i<n;i++){
    scanf("%d",&A[i]);
    newNode(A[i]);
  }
   display(head);
   printf("\n");
   insert(3,23);
   display(head);
 
}