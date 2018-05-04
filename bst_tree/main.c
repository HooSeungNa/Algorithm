#include <stdio.h>
#include <stdlib.h>
int a[10000]={0};
int n=0;
int fact=0;//postorder 체크 여부
typedef struct _NODE{
    int data;
    struct _NODE *left;
    struct _NODE *right;
    struct _NODE *parent;
}NODE;
NODE *root;
NODE *search(int item){
    NODE* x=root;
    while(x!=NULL&&x->data!=item){
        if(item<x->data)
            x=x->left;
        else
            x=x->right;
    }
    return x;
}
NODE *minimum(NODE* x){
    while(x->left!=NULL)
        x-x->left;
    return x;
}
NODE *maximum(NODE* x){
    while(x->right!=NULL)
        x-x->right;
    return x;
}
void postorder(NODE *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        if(a[n]==root->data)
            fact=1;
        else{
            fact=0;
            return ;
        }
        n++;

    }
}
void preorder(NODE *root){
    if(root){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void insert(int item)
{
    NODE *new, *x , *y;
    new=(NODE*)malloc(sizeof(NODE));
    new->data=item;
    new->left=new->right=NULL;
    y=NULL;
    x=root;
    while(x!=NULL){
        y=x;
        if(new->data<x->data)
            x=x->left;
        else
            x=x->right;
    }
    new->parent=y;
    if(y==NULL)
        root=new;
    else if(new->data<y->data)
        y->left=new;
    else
        y->right=new;
}
void transplant(NODE *u,NODE *v){
    if(u->parent==NULL)
        root=v;
    else if(u=u->parent->left)
        u->parent->left=v;
    else
        u->parent->right=v;
    if(v!=NULL)
        v->parent=u->parent;
}
void delete(NODE *target){
    NODE* min;
    if(target->left==NULL)
        transplant(target,target->right);
    else if(target->right==NULL)
        transplant(target,target->left);
    else{
        min=minimum(target->right);
        if(min->parent!=target){
            transplant(min,min->right);
            min->right=target->right;
            min->right->parent=min;
        }
        transplant(target,min);
        min->left=target->left;
        min->left->parent=min;
    }
    free(target);
}

int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);
    //순서 : 거꾸로 입력을 받아서 insert한후에 포스트 오더비교 -> preorder 출력 or wrong 출력-> delete로 전체 삭제
    root=NULL;
    int num=0;

    scanf("%d",&num);

    for(int j=0;j<num;j++){
        root=NULL;
        n=0;
        int arr_num; // 배열 scanf 를 통해서 입력
        scanf("%d",&arr_num);
        for(int i=0;i<arr_num;i++){ // 입력받은 배열
            scanf("%d",&a[i]);
        }
        for(int i=arr_num-1;i>=0;i--){ // 입력받은 배열을 거꾸로 입력하여 post order 형태로 만든다.
            insert(a[i]);
        }
        postorder(root); // postorder 를 진행해서 b배열 만든다.
        if(fact==1){ //postorder와 같으면
            preorder(root);
            printf("\n");
        }else{//postorder와 다르면
            printf("wrong\n");
        }
    }
    return 0;
}
