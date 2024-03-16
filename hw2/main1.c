#include <stdio.h>
#include <string.h>
#include <time.h>
int main()
{
    FILE *fp;
    fp = fopen("lotto.txt", "w+");
    time_t curtime;
    time(&curtime);
    char *timed=ctime(&curtime);
    timed[strlen(timed)-1]=0;
    int lotto[5][7];
    int num;
    srand((unsigned)time(NULL));
    printf("歡迎光臨長庚樂透彩購買機台\n請問您要買幾組樂透彩：");
    scanf("%d",&num);
    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n",num);
    for(int j=0;j<num;j++){
        for(int i=0;i<6;i++)
            lotto[j][i]=(rand()%69+1);
        lotto[j][6]=(rand()%10+1);
    }
    for(int j=0;j<num;j++){
        for(int i=0;i<6;i++){
            for(int k=i+1;k<6;k++){
                if(lotto[j][i]>lotto[j][k]) {
                     int swap;
                    swap=lotto[j][i];
                    lotto[j][i]=lotto[j][k];
                    lotto[j][k]=swap;
                }
            }
        }   
    }
    fprintf(fp,"======== lotto649 ========\n");
    fprintf(fp,"=%s=\n",timed);         
    for(int j=0;j<5;j++){
        fprintf(fp,"[%d]: ",j+1);
        for(int i=0;i<7;i++){
            if(lotto[j][i]>=70 || lotto[j][i]==0)
                fprintf(fp,"-- ");
            else if (lotto[j][i]<10 )
                fprintf(fp,"0%d ",lotto[j][i]);
            else
                fprintf(fp,"%d ",lotto[j][i]);
        }
        fprintf(fp,"\n");
    }
    fprintf(fp,"======== csie@CGU ========\n");
    fclose(fp);
    return(0);
}
