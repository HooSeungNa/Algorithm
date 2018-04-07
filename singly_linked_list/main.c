#include <stdio.h>
#include <stdlib.h>
typedef struct _NODE{
        int data;
        struct _NODE *next;
}NODE;
NODE *head;
void insert(NODE *prev, int item){
        NODE *new;
        new = (NODE *)malloc(sizeof(NODE)); // 노드에 메모리 할당
        new->data = item; // 데이터 멤버에 데이터 저장
        if(prev)
        {
                new->next= prev->next; //마지막 노드 next 멤버에 null저장
                prev->next = new; //다음노드의 메모리 주소 저장
        }
        else
        {
                head = new;
                new->next = NULL; //마지막 노드 next 멤버에 null저장
        }
}
void delete(NODE *prev){
        NODE *del;
        if(prev){
                del= prev->next;
                prev->next=del->next;
        }
        else{
                del=head;
                head=del->next;
        }
        free(del);
}

int main(int argc, char *argv[])
{
        NODE *ptr;
        head=NULL;

        insert(head,10);
        insert(head,20);
        insert(head,30);
        insert(head,40);
        insert(head,50);
        delete(head);
        for(ptr=head;ptr;ptr=ptr->next)
                printf("%d ",ptr->data);
        printf("\n");
        return 0;
}
