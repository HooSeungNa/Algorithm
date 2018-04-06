#include <stdio.h>

int a[100000]={0};
int main(void)
{
    int tc,num,i;
    int cnt=0,min=0;
    freopen("D:\\Algorithm_folder\\homework1\\input.txt","r",stdin);
    scanf("%d",&tc);//전체 반복횟수 등록
    printf("all data : %d \n",tc);

    while(tc--){
        scanf("%d",&num);//배열의 길이 등록
        printf(num);
        for(i=0;i<num;i++){//배열의 길이만큼 숫자를 등록
            scanf("%d",&a[i]);

        }
    }
return 0;

}
