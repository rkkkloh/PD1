#include <stdio.h>
#include <stdlib.h>

int main()
{
    char d;
    int option, i, j, opened = 0, Kirby_A = 0, kirby_A = 0, Kirby_B = 0, kirby_B = 0, Kirby_C = 0, kirby_C = 0,Kirby = 0, kirby = Kirby_A + Kirby_B + Kirby_C, Money = 0, money = 0, t = 1, s = 1, a, b, c, gcd;
    printf("//////////Welcome to NCKU-PD1-Kirby-Shop\\\\\\\\\\\\\\\\\\\\");
    printf("\n");
    start:
    printf("Options: (1)Openning (2)List (3)Adding (4)Exit\n");
    i = scanf("%d",&option);

    if(i !=1 ||(option != 1&&option !=2&&option !=3&&option !=4)|| (d =getchar()!='\n')){
        while ((d = getchar()) != '\n' && d != EOF);
    printf("Error: Please try again!\n");
    goto start;
    //printf("Options: (1)Openning (2)List (3)Adding (4)Exit\n");
    //i = scanf("%d",&option);
    }

    if (option == 1){
            for(opened = opened;opened == 0;){
                printf("Your shop is openning!\n");
                opened++;
                goto start;
                }

            for(;opened>0;){
                printf("Your Kirby shop has already opened :(\n");
                goto start;
                }



    }else if (option == 2){
        printf("===================================\n");
        printf("Kirby-A: %d\n",Kirby_A );
        printf("Kirby-B: %d\n",Kirby_B );
        printf("Kirby-C: %d\n",Kirby_C );
        printf("Kirby: %d, Money: %d\n", Kirby , Money );
        printf("===================================\n");
        goto start;
    }else if (option == 3){
        for(;opened == 0;){
            printf("Your Kirby shop has not opened\n");
            goto start;
        }
        printf("Please enter three numbers: ");
        j = scanf("%d %d %d",&kirby_A,&kirby_B,&kirby_C);

        if(j = 3 && (kirby_A > 0 && kirby_B >0 && kirby_C > 0)){
        if(d=getchar()!='\n'){
        while ((d = getchar()) != '\n' && d != EOF);
        goto WA;
        }
        here:
        a = kirby_A ;
        b = kirby_B ;
        c = kirby_C ;
        while(t != 0) {
            t = a % b;
            a = b;
            b = t;
            }
        while(s != 0) {
            s = a % c;
            a = c;
            c = s;
            }
        gcd = a;
        kirby = kirby_A + kirby_B + kirby_C;
        money = kirby - 2*gcd;
        printf("Divide these Kirbys into %d boxes, with the number of Kirby in each box being %d, %d, and %d\n", gcd, kirby_A/gcd, kirby_B/gcd, kirby_C/gcd);
        printf("Price: %d\n",money);
        Kirby_A += kirby_A;
        Kirby_B += kirby_B;
        Kirby_C += kirby_C;
        Money += money;
        Kirby += kirby;
        t=1;
        s=1;
        kirby_A = 0;
        kirby_B = 0;
        kirby_C = 0;
        goto start;
        }else{

                for(;j != 3 || (kirby_A <= 0 || kirby_B <= 0 || kirby_C <= 0);){
                    while ((d = getchar()) != '\n' && d != EOF);
                    WA:
                    printf("Error: Please try again or enter '-1 -1 -1' to make a new options: ");
                    scanf("%d%d%d",&kirby_A,&kirby_B,&kirby_C);
                    if(d=getchar()!='\n'){
                            while ((d = getchar()) != '\n' && d != EOF);
                            goto WA;
                        }
                    if((kirby_A == -1 && kirby_B == -1 && kirby_C == -1)){
                        kirby_A = 0;
                        kirby_B = 0;
                        kirby_C = 0;
                        goto start;
                        }
                    if (j = 3 && (kirby_A > 0 && kirby_B >0 && kirby_C > 0)){
                        goto here;
                    }
                    if (kirby_A <= 0 || kirby_B <= 0 || kirby_C <= 0){
                        goto WA;
                    }
                    kirby_A = 0;
                    kirby_B = 0;
                    kirby_C = 0;
                }
        }
    }else if (option == 4){
        return 0;

    }
    return 0;
}

