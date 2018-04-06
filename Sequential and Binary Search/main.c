
/*
 * N값과 Q값을받아서malloc를통한N사이즈의동적메모리할당.
 * 배열을선택정렬을통해서오름차순으로정렬한다.
 * 그리고선택정렬을한배열을가지고binarysearch을진행한다.
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool binary_search(int *p, int test, int low, int high);
int main(){
        int num, q;
        int *number_array;
        scanf("%d%d", &num, &q);

        number_array = (int*)malloc(sizeof(int)*num);
        for(int i = 0; i < num; i++){
            scanf("%d", &number_array[i]);
        }
        int min;
        int temp;
        for(int i = 0; i < num-1; i++){
            min=i;
            for(int j = i; j < num; j++){
                    if(number_array[min] > number_array[j])
                        min = j;
            }
            if(min != i){
                    temp = number_array[min];
                    number_array[min] = number_array[i];
                    number_array[i] = temp;
            }
        }

        int test;
        bool disc;
        for(int i = 0; i < q; i++){
            scanf("%d", &test);
            disc = binary_search(number_array, test, 0, num-1);
            if(disc == true)
                    printf("YES\n");
            else
                    printf("NO\n");

        }
        free(number_array);
        return 0;
}


bool binary_search(int *p, int test, int low, int high){        //binary search
        int mid;
        while(low <= high){
                mid=(low+high) / 2;
                if(p[mid] < test)
                        low = mid+1;
                else if(p[mid] > test)
                        high = mid-1;
                else
                        return true;
        }
        return false;
}
