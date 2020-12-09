#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct node{
	int data;
	struct node *next;
};
void sil(struct node **head){
  struct node *temp = (*head);
  int count = 0;
  while(temp != NULL){
  	temp = temp->next;
  	count  = count + 1; // Toplam Eleman Sayýsýný buluyoruz
  }
  printf("\nListenin eleman sayisi:  %d\n ",count);
  temp = (*head);
  if(count%2 == 0){ // eleman sayýsýnýn tek mi çift mi olduðunu kontrol ediyoruz
  	printf("Listenin eleman sayisi cifttir\n");
  	while(temp->next->next != NULL){
  		temp =temp->next;
	  }
	  free(temp -> next);
	  temp -> next =NULL;
  }
  else{
  	printf("Listenin eleman sayisi tektir\n");
  	(*head)= temp->next;
  	free(temp);
  }
}
void push(struct node **head,int veri){
  struct node *dugum=(struct node*)malloc(sizeof(struct node));
  dugum->data=veri;
  dugum->next=(*head);
  (*head)=dugum;
    
}
void printList(struct node *head){
    struct node *gecici=head;
    while(gecici!=NULL)
    {
        printf("%d\t",gecici->data);
        gecici=gecici->next;
    }
}
int main() {
    struct node *list=NULL;
    push(&list,5);
    push(&list,1);
    push(&list,1);
    push(&list,1);
    push(&list,1);
    push(&list,2);
    printf("Listedeki elemanlar ");
    printList(list);
    sil(&list);
    printf("Silme iþleminden sonraki elemanlar ");
    printList(list);
    return 0;
}
