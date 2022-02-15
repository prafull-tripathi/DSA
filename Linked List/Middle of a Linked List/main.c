#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>
int count,num;

struct node
{
 int data;
 struct node *next;
}*start=NULL,*ptr,*nn;

void create();
void display();
void insertb();
void deleteb();
void deletee();
void middle();

void main()
{
 int op;
 system("clr");
 do
 {
  printf("\tMenu\n");
  printf("0. Exit\n1. Display\n2. Insert at the End\n. ");
  printf("3. Delete at the Beginning\n4. Delete at the End\n5. Middle of a Linked List\n");

  create();
  scanf("%d",&op);
  switch(op)
  {
   //case 1: system("cls");create();break;
   case 1: system("cls");display();break;

   case 2: system("cls");inserte();break;

   case 3: system("cls");deleteb();break;
   case 4: system("cls");deletee();break;

   case 5: system("cls");middle();break;



   case 0: exit(0);break;

  default: printf("Wrong Option\n");
  }
 }while(op!=16);
 getch();
}

//Function Defination

//Create a Linked List
void create()
{
 nn=(struct node*)malloc(sizeof(struct node));
 if(nn==NULL)
 {
  printf("Sorry\n");
  return;
 }
}

//Display Linked List
void display()
{
  system("cls");
  if(start==NULL)
  {
   printf("List is empty\n");
   return;
  }
  ptr=start;
  printf("List is\n");
  while(ptr!=NULL)
  {
   if(ptr->next==NULL)
	printf("%d",ptr->data);
   else
	printf("%d->",ptr->data);
   ptr=ptr->next;
  }
  printf("\nTotal nodes: %d",count);
  printf("\n");
}

//Insert at the End of Linked List
void inserte()
{
 nn=(struct node*)malloc(sizeof(struct node));
 if(nn==NULL)
 {
  printf("Sorry\n");
  return;
 }
 printf("Val?\n");
 scanf("%d",&num);
 nn->data=num;
 if(start==NULL)
 {
  start=nn;
  nn->next=NULL;
  count++;
 }
 else
 {
  ptr=start;
  while(ptr->next!=NULL)
   ptr=ptr->next;
  ptr->next=nn;
  nn->next=NULL;
  count++;
 }
}

//Delete from the beginning of the linked List
void deleteb()
{
 if(start==NULL)
 {
  printf("List is empty\n");
  return;
 }
 ptr=start;
 start=start->next;
 printf("delete element is: %d",ptr->data);
 printf("\n");
 free(ptr);
 count--;
}

//Delete from the end of a Linked List
void deletee()
{
 struct node *pptr;
 if(start==NULL)
 {
  printf("List is empty\n");
  return;
 }
 ptr=start;
 while(ptr->next!=NULL)
 {
  pptr=ptr;
  ptr=ptr->next;
 }
 pptr->next=NULL;
 printf("Deleted element is: %d",ptr->data);
 printf("\n");
 free(ptr);
 count--;
}

void middle()
{
    struct node *slow_ptr, *fast_ptr;

    slow_ptr=start;
    fast_ptr=start;
    while(slow_ptr && fast_ptr && fast_ptr->next!=NULL)
    {
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next->next;
    }
    printf("Middle Element of Linked List is: ");
    printf("%d", slow_ptr->data);

}

