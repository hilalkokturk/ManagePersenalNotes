#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define ST_LENGTH 10000

struct tagNode{
int idTag;
char *tag;
struct tagNode *nextTag;
};

struct node {
   int id;
   char *note_consistent;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

struct tagNode *headTag = NULL;
struct tagNode *currentTag = NULL;

int main(){
char input_type[ST_LENGTH];
char consistent[ST_LENGTH];
char forTag[ST_LENGTH];
int id;
char con[3]="END";
while(scanf("%s ", input_type)!=EOF){

if(strcmp(input_type,"ADD")==0){
   scanf("%d", &id);
   scanf("%[^E]s", consistent);
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link ->note_consistent = malloc(strlen(consistent)+1);
   if(head==NULL){
   link -> id=id;
   strcpy(link->note_consistent, consistent);
   head = link;
   }

   else{
   
   link -> id=id;
   strcpy(link->note_consistent, consistent);
   link ->next = head;
   head = link;

   }

}

else if(strcmp(input_type,"DISPLAY")==0){
    scanf("%d", &id);
    struct node *ptr = head;

      while(ptr !=NULL){
      if(ptr ->id == id){
      printf("ID: %d %s \n",ptr->id,ptr->note_consistent);
}
      ptr = ptr->next;
   }

}

else if(strcmp(input_type,"TAG")==0){

    scanf ("%s", forTag);

 struct tagNode *linkTag = (struct tagNode*) malloc(sizeof(struct tagNode));
   linkTag ->tag = malloc(strlen(forTag)+1);
    while(scanf("%d", &id) && id!=-1){

   if(headTag==NULL){
   linkTag -> idTag=id;
   strcpy(linkTag->tag, forTag);
   headTag = linkTag;
   }
   else{
   
   linkTag -> idTag=id;
   strcpy(linkTag->tag, forTag);
   linkTag ->nextTag = headTag;
   headTag = linkTag;
   }
}
}

else if(strcmp(input_type,"FIND")==0){
char findParam[ST_LENGTH];
char tagForFind[ST_LENGTH];
char tagForNot[ST_LENGTH];
char tagForOr[ST_LENGTH];
scanf("%s", findParam);
if(strcmp(findParam,"AND(")==0){
while(scanf("%s", tagForFind)&&strcmp(tagForFind,")")!=0){

if(strcmp(tagForFind,"NOT(") == 0){

while(scanf("%s", tagForNot)&&strcmp(tagForNot,")")!=0){


}

printf("Andler: %s\n", tagForFind);
printf("Notlar: %s\n", tagForNot);
}//NOT gelirse yani AND NOT

else if(strcmp(tagForFind, "OR(")==0){

while(scanf("%s", tagForOr)&&strcmp(tagForOr,")")!=0){
printf("Orlar: %s\n", tagForOr);
}


}//OR gelirse yani AND OR

else{
printf("Results:\n");
struct tagNode *ptr = headTag;
while(ptr != NULL){
if(strcmp(ptr->tag,tagForFind)==0){
int compId;
compId = ptr->idTag;
struct node *poin = head;
while(poin !=NULL){
if(compId == poin->id){
printf("ID: %d %s", poin->id, poin ->note_consistent);
}
poin=poin->next;
}

}//tagla elindeki inputu karşılaştırdıgım yer.

ptr = ptr -> nextTag;
}

}//sadece find gelirse

}// genel and while parantezi

}//artık find and
else if(strcmp(findParam,"OR(")==0){
while(scanf("%s", tagForOr)&&strcmp(tagForOr,")")!=0){
if(strcmp(tagForOr,"NOT(") == 0){
while(scanf("%s", tagForNot)&&strcmp(tagForNot,")")!=0){
printf("Notlar: %s\n", tagForNot);
}
}//FİND OR NOT

else if(strcmp(tagForOr,"AND(") == 0){
while(scanf("%s", tagForFind)&&strcmp(tagForFind,")")!=0){
printf("Andler: %s\n", tagForFind);
}
}// FİND OR AND

else{
printf("Results:\n");
struct tagNode *ptr = headTag;
struct node *ptr2 = head;
while(ptr!=NULL){
if(strcmp(ptr->tag,tagForOr)==0){
int tmp = ptr->idTag;
while(ptr2 != NULL){
if(tmp == ptr2->id){
printf("ID:%d %s", ptr2->id, ptr2-> note_consistent);
}
ptr2 = ptr2 -> next;
}
}
ptr = ptr -> nextTag;
}


}//FİND OR ONLY


}


}//find or

else if(strcmp(findParam, "NOT(")==0){

while(scanf("%s", tagForNot)&&strcmp(tagForNot,")")!=0){

if(strcmp(tagForNot,"AND(")==0){
while(scanf("%s", tagForFind)&&strcmp(tagForFind,")")!=0){
printf("Andler: %s\n", tagForFind);
}

}//FIND NOT AND

else if(strcmp(tagForNot,"OR(")==0){

while(scanf("%s", tagForOr)&&strcmp(tagForOr,")")!=0){

}
//printf("Orlar: %s\n", tagForOr);
struct tagNode *ptr = headTag;
struct node *ptr2 = head;
while(ptr!=NULL){
if(strcmp(ptr->tag,tagForOr)!=0){
int tmp = ptr->idTag;
while(ptr2 != NULL){
if(tmp == ptr2->id){
printf("%s ", ptr2-> note_consistent);
}
ptr2 = ptr2 -> next;
}
}
ptr = ptr -> nextTag;
}


} //FIND NOT OR


else{


} //FIND NOT only



}


}//find not

}

}

return 0;
}

