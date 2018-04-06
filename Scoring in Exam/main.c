#include <stdio.h>
#include <stdlib.h>

typedef struct time_score               // time and score
{
        int time;
        int score;
} time_score;

time_score a[100000];

void merge(int p, int q, int r);
void merge_sort( int p, int r);
int main(int argc, char *argv[])
{
        int n, q;
        int i, j;
        freopen("test.txt", "r", stdin);
        scanf("%d %d", &n, &q);         // read N, Q
        for(i = 1; i <= n; i++){         // read time and score
                scanf("%d", &a[i].time);
        }
        for(i = 1; i <= n; i++){
                scanf("%d", &a[i].score);
        }

        merge_sort(1, n);             // merge sort algorithm
        int input_val;
        for(i = 1; i <= n; i++)          // calculate time sum table
                a[i + 1].time = a[i].time + a[i + 1].time;
        for(i = 1; i <= q; i++){         // print time sum table
                scanf("%d", &input_val);
                printf("%d\n", a[input_val].time);
        }
        return 0;
}
void merge(int p, int q, int r){        // merge sort non-increasing algorithm
        int *left_time = (int *)malloc(sizeof(int) * (q - p + 2));      // dynamic memory allocation (time and score)
        int *left_score = (int *)malloc(sizeof(int) * (q - p + 2));
        int *right_time = (int *)malloc(sizeof(int) * (r - q + 1));
        int *right_score = (int *)malloc(sizeof(int) * (r - q + 1));
        int i, j, k;
        for(i = 0; i < q - p + 1; i++){                 // merge left array time and score
               left_score[i] = a[p + i].score;
               left_time[i] = a[p + i].time;
        }//end for
        for(i = 0; i < r - q; i++){                     // merge right array time and score
                right_score[i] = a[q + i + 1].score;
                right_time[i] = a[q + i + 1].time;
        }

        left_score[q - p + 1] = -1;                     // insert the sentinels
        left_time[q - p + 1] = -1;
        right_score[r - q] = -1;
        right_time[r - q] = -1;

        i = 0, j = 0;
        for(k = p; k <= r; k++){                        // non increasing merge
                if(left_score[i] > right_score[j]){
                        a[k].score = left_score[i];
                        a[k].time = left_time[i];

                        i = i + 1;
                }else {
                        a[k].score = right_score[j];
                        a[k].time = right_time[j];
                        j = j + 1;
            }
        }

        free(left_score);                               //disable dynamic memory
        free(left_time);
        free(right_score);
        free(right_time);

}

void merge_sort(int p, int r){                          //divide the array
        int q;
        if(p < r){
                q = (p + r)/2;
                merge_sort(p, q);
                merge_sort(q + 1, r);
                merge(p, q, r);
        }

}

