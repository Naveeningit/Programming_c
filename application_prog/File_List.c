#include<stdio.h>
#include<stdlib.h>
struct node{
	char c;
	struct node * next;
};
struct node * headAlpha = NULL;
struct node * headNum = NULL;
void insert(struct node **head,char character){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode -> c = character;
	newnode -> next= NULL;
	if(*head==NULL){
		*head=newnode;	
	}
	else{
		struct node * temp=*head;
		while(temp->next!=NULL)
		temp=temp->next;
		temp->next=newnode;	
	}
}
void displayVowels(struct node* head){
	struct node * temp=head;
	int count=0;
	while(temp!=NULL){
		if(temp->c=='a'||temp->c=='e'||temp->c=='i'||temp->c=='o'||temp->c=='u'||
		temp->c=='I'||temp->c=='A'||temp->c=='E'||temp->c=='O'||temp->c=='U'){
			printf("%c ",temp->c);
			count++;
		}		
		temp=temp->next;
	}
	printf("\nVowel count = %d\n",count);
}
void fileRead(char * filename){
	FILE * fp =fopen(filename,"r");
	char ch;
	while((ch=fgetc(fp))!=EOF){
		if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
			insert(&headAlpha,ch);
		else if(ch>='0'&&ch<='9')	
			insert(&headNum,ch);		
	}
}
int main(){
	fileRead("text.txt");
	displayVowels(headAlpha);
}
