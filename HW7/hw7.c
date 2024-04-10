#include <stdio.h>
#include <stdlib.h>
int fname[30], fsize[30], array1[21], k, m, Choose[22] = {0}, choose[22] = {0}, sum = 0, best = 0;
void checkf(int c){
        for(int i = 0;i<21;i++){
            if(array1[i] == c){
            printf("YES\n");
            return;
            }
        }
        printf("NO\n");
        return;
}
void solve(int idx,int count,int sum)
{
    if (idx == 21) {
        if (count == k){
            if (abs(sum - m) < abs(best - m)) {
                best = sum;
                for (int i = 0; i <= 20; ++i) {
                    Choose[i] = choose[i];
                }
            }
        }
        return;
    }

    choose[idx] = 1;
    solve(idx + 1,count+1, sum+fsize[idx]);

    choose[idx] = 0;
    solve(idx + 1,count,sum);
}

int main()
{   int opt, i = 0, j = 0, c, best;
        for(;;){
        here:
        printf("Options: ");
        scanf("%d", &opt);
        if( opt == 1){
                for(int i = 0;i<21;i++){
                    if(array1[i]==0){
                            printf("Please input file name and file size: ");
                            scanf("%d%d", &fname[i], &fsize[i]);
                            array1[i] = fname[i];
                            int check = 0;
                            for (;check<21;++check)if(!array1[check])break;
                            if(check!=21)goto here;
                        }

                }
                del:
                printf("Hard drive exceeds its capacity, please enter the number of files to be deleted: ");
                scanf("%d%d", &k, &m);
                choose[0]=0;
                solve(1,0,0);
                choose[0]=1;
                solve(1,1,fsize[0]);
                for(int i = 0;i<22;i++){
                    if(Choose[i] == 1){
                        if(j == k-1){
                        printf("%d\n",fname[i]);
                        fname[i] = 0;
                        array1[i] = 0;
                        fsize[i] = 0;
                        j++;
                        break;
                        }else{
                        printf("%d ",fname[i]);
                        fname[i] = 0;
                        array1[i] = 0;
                        fsize[i] = 0;
                        j++;
                        }
                    }

                }
                j=0;
                }

        else if( opt == 2){
                printf("Please input the file name: ");
                scanf("%d", &c);
                checkf(c);
        }
        else if( opt == 3)return 0;
        }
            return 0;
}
