#include <stdio.h>
#define MAXN 10001
#define SRC 1
#define QSIZE 9999

typedef struct _NODE{
        int data;
        struct _NODE *next;
}NODE;
NODE *head = NULL;
NODE *tail = NULL;
int is_empty(){
        return (head == NULL);
}
void enqueue(int item){
        NODE *new;
        new = (NODE*)malloc(sizeof(NODE));
        new->data = item;
        new->next = NULL;
        if(is_empty())
                head = tail = new;
        else{
                tail->next = new;
                tail = tail->next;
        }
}
int dequeue(){
        NODE *del;
        int item;
        if(is_empty()){
                printf("Stack underflow \n");
                exit(1);
        }else{
                item = head->data;
                del = head;
                head = head->next;
                free(del);
        }
        return item;
}

int queue[QSIZE + 1];
int name[MAXN] = {0};
int adj_mat[MAXN][MAXN] = {0};
int main(int argc, char *argv[])
{
        freopen("test.txt","r",stdin);
        int n, i, t, m, v1, v2;
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d%d", &n, &m);
                for(i = 1; i <= m; i++)
                {
                        scanf("%d%d", &v1, &v2);
                        adj_mat[v1][v2] = 1;
                        adj_mat[v2][v1] = 1;

                }
                int distance[MAXN];
                int discovered[MAXN] = {0};

                head = tail = 0;
                enqueue(SRC);
                distance[SRC] = 1;

                while (!is_empty())
                {
                        i = dequeue();
                        for(int j = 1; 1 <= n; j++){
                                if(adj_mat[i][j] == 1 && discovered[i] == 0){
                                        enqueue(j);
                                        discovered[j] = 1;
                                        distance[j] = distance[i]+1;
                                        printf("%d\n",distance[j]);
                                }
                        }
                }
        }
        return 0;
}
