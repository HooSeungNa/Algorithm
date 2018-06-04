
#include <stdio.h>
char dna[50][1000]={};
char result[1000]={};
int main(void)
{
    int total;
    int length=8;
    int number=5;
    int G_cnt=0,C_cnt=0,A_cnt=0,T_cnt=0;
    freopen("input.txt", "r", stdin);
    setbuf(stdout, NULL);
    scanf("%d",&total);
    int j,k,l=0;
    for(l=0;l<total;l++){
        scanf("%d",&number);//배열개수
        scanf("%d",&length);//배열길이
        for(int j=0;j<number;j++){
            scanf("%s",dna[j]);
        }

        int gcat[4]={0};
        int cnt=0;
        for(k=0;k<length;k++){//배열의 길이
            G_cnt=0,C_cnt=0,A_cnt=0,T_cnt=0;

            for(j=0;j<number;j++){//배열의 갯수
                //            printf("%c", dna[j][k]);
                switch (dna[j][k]) {
                case 'G':
                    G_cnt++;
                    break;
                case 'C':
                    C_cnt++;
                    break;
                case 'A':
                    A_cnt++;
                    break;
                case 'T':
                    T_cnt++;
                    break;

                default:
                    break;
                }

            }

            gcat[0]=A_cnt;
            gcat[1]=C_cnt;
            gcat[2]=G_cnt;
            gcat[3]=T_cnt;
            //        printf("\n A : %d, C : %d, G : %d, T : %d\n",gcat[0],gcat[1],gcat[2],gcat[3]);
            int max_int=0;
            char max_char[4]={'A','C','G','T'};

            for(int x=0;x<4;x++){
                if(gcat[max_int]<gcat[x]){
                    max_int=x;

                }
                //             printf("gcat[%d] : %d ,x: %d , max int : %d \n",x,gcat[x],x,gcat[max_int ]);
            }
            result[cnt]=max_char[max_int];

            //        printf("max int : %d ,%c\n\n",max_int,result[cnt]);
            cnt++;

        }
        int cnt_arr=0;
        printf("%s\n",result);

        for(int xx=0;xx<number;xx++){
            for(int yy=0;yy<length;yy++){
                if(result[yy]!=dna[xx][yy])
                    cnt_arr++;
            }
        }
        printf("%d\n",cnt_arr);
    }


    return 0;//Your program should return 0 on normal termination.
}
