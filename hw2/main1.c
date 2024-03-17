#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    FILE *fp;
    fp = fopen("lotto.txt", "w");
    time_t curtime;
    time(&curtime);
    char *timed=ctime(&curtime);
    timed[strlen(timed)-1]=0;
    srand(time(NULL));
    int lotto[5][7];
    int num;
    int scanf_OK=0;
    printf("歡迎光臨長庚樂透彩購買機台\n請問您要買幾組樂透彩：");
    scanf("%d",&num);
    while(scanf_OK==0){
        if(num<6 && num>0){
            printf("已為您購買的 %d 組樂透組合輸出至 lotto.txt\n",num);
            scanf_OK=1;
        }
        else {
            printf("請輸入1~5的數字\n請問您要買幾組樂透彩：");
            scanf("%d",&num);
        }
    }
    for(int j=0;j<num;j++){
        for(int i=0;i<6;i++){
            int random=rand()%69+1;
            int k=0;
            while(k<i){
                if(lotto[j][k]!=random){
                    k++;
                }
                else{
                    random=rand()%69+1;
                    k=0;
                }
            }
            lotto[j][i]=random;
        }
        lotto[j][6]=(rand()%10+1);
    }
    for(int j=0;j<num;j++){
        for(int i=0;i<6;i++){
            for(int k=i+1;k<6;k++){
                if(lotto[j][i]>lotto[j][k]) {
                    int swap=lotto[j][i];
                    lotto[j][i]=lotto[j][k];
                    lotto[j][k]=swap;
                }
            }
        }   
    }
     
    fprintf(fp,"======== lotto649 ========\n");
    fprintf(fp,"=%s=\n",timed);         
    for(int j=0;j<num;j++){
        fprintf(fp,"[%d]: ",j+1);
        for(int i=0;i<7;i++){
            if (lotto[j][i]<10 )
                fprintf(fp,"0%d ",lotto[j][i]);
            else
                fprintf(fp,"%d ",lotto[j][i]);
        }
        fprintf(fp,"\n");
    }
    for(int j=num;j<5;j++){
        fprintf(fp,"[%d]: ",j+1);
        for(int i=0;i<7;i++){
                fprintf(fp,"-- ",lotto[j][i]);
        }
        fprintf(fp,"\n");
    }
    fprintf(fp,"======== csie@CGU ========\n");
    fclose(fp);
    return 0;
}
