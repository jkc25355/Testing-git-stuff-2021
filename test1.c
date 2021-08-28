#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>


int main(){

    int n;
    int m = n;
    int *p;
    int o;
    int numlen = pow(n, 2);

    printf("Please enter an integer n that is between 1 and 100: ");
    scanf("%d", &n);

    if(n < 1 || n > 100){

        printf("Error, this is not a valid value for n.");
        return 1;

    }

    int **arr;
    arr = malloc(sizeof(int *) * m);
    for(int i = 0; i < m; i++){

        arr[i] = malloc(sizeof(int) * n);
    }

    int x = 0;
    int y = 0;
    int d = 0;
    int s = 1;
    int c = 1;


    if(n%2 == 0){

        x = (int)(floor(n/2.0)) - 1;
        y = (int)(floor(n/2.0)) - 1;
    }
    else{
        x = (int)(floor(n/2.0));
        y = (int)(floor(n/2.0));
    }

    for(int k = 0; k <= (n-1); k++){
        for(int j = 0; j < (k < (n-1) ?2:3); j++){
            for(int i = 0; i < s; i++){
                arr[x][y] = c;
                c++;
                switch(d){
                    case 0: y = y + 1; break;
                    case 1: x = x + 1; break;
                    case 2: y = y - 1; break;
                    case 3: x = x - 1; break;
                }
            }

            d = (d+1)%4;
        }
        s = s + 1;
    }

    FILE *pFile = fopen("ans.out", "w+");
    for(x = 0; x < n; x++){
        for(y = 0; y < n; y++){
            printf("%5d", arr[x][y]);
            fprintf(pFile, "%5d", arr[x][y]);
        }
        putchar('\n');
        fprintf(pFile, "\n");
    }
    putchar('\n');
    fprintf(pFile, "\n");

    fclose(pFile);

return 0;
}