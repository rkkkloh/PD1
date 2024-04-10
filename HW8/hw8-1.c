#include <stdlib.h>
void init(int ***mp){

    for(int i = 0;i<130;i++){
        mp[i] = (int **)malloc( 91 * sizeof(int *) );
        for(int j = 0;j<91;j++){
            mp[i][j] = (int *)malloc( 91 * sizeof(int));
        }
    }
    for(int i = 0;i<130;i++){
        for(int j = 0;j<91;j++){
            for(int k = 0;k<91;k++){
                mp[i][j][k] = 1;
            }
        }
    }
}
void modify(int* a,int val){

    *a = val;

}
int query(int**** mp,char a[4],char b[4]){
    if((((*mp)[a[0]][a[1]][a[2]])+((*mp)[b[0]][b[1]][b[2]]))%2 == 0) return 0;
    else return 1;
    
}
