// Lab-4 , HW - que -2

struct node{
int data; 
struct node *prev; 
struct node *next;
}; 
typedef struct node *NODE; 

NODE createnode(int element){
NODE temp; 
temp=(NODE) malloc(sizeof (struct node)); 
temp->prev=NULL; 
temp->data=element; 
temp->next=NULL; 
return temp;
}

void traverseListInDCLL(NODE first){
NODE lastNode=first;
do{
printf("%d <--> ",lastNode -> data); 
lastNode = lastNode -> next;
} 
while( lastNode != first); 
printf("\n");
}

NODE deleteAtPositionInDCLL(NODE first, int pos){
NODE ptr; 
ptr=first; 
int count=1; 
while( count!=pos ){
if(ptr->next != first){
ptr=ptr->next; 
count++;
} 
else{
printf("No such position in DCLL so deletion is not possible\n");
return first;
}
} 
ptr->prev->next=ptr->next;
if(ptr==first)
first=first->next; 
printf("The deleted element from DCLL : %d\n",ptr->data);
free(ptr); 
return first;
}

NODE insertAtEndInDCLL(NODE first , int x){
    NODE temp; 
    temp=createnode(x); 
    if(first==NULL){
   first=temp; 
    temp->prev=first; 
temp->next=first; 
return first;
} 
else{
NODE ptr; 
ptr=first; 
while(ptr->next != first)
ptr=ptr->next; 
temp->prev=ptr;
ptr->next=temp; 
temp->next=first; 
first->prev=temp; 
return first;
}
}