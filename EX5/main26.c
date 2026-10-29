#include <stdio.h>
int multi(int i, int j){
    if (j == 1){
        printf("%d*%d\n", i, j, i*j);
        return 0;
    } else{
        multi(i, j-1);
        printf("%d*%d=%d\n", i, j, i*j);
    }
}

int main(){
    //用迴圈讓i從1到9，印出完整的每一列
    for (int i = 1; i <= 9; i++){
    multi(i,9);
    printf("\n");//每一列結束後換行
    }
    return 0;
}
