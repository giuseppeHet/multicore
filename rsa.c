#include <stdio.h>
#include <stdlib.h>
#include "math.h"

//SIZE
int size(int* a){
    int i=1;
    while(a[i]!=0){
        i++;
    }
    return i;
}

//PRINT
void myPrint(int* a){
    int s=size(a);
    int i;
    for(i=0; i<=s; i++){
        printf("%d ", a[i]);
    }
}

//PRIMO
int primo(int n){
    int primo=0;
    int i;
    int c=0;
    for (i = 1; i <= n; i++) {
        if (n % i == 0) {
            //printf("%d\n", i);
            c++;
        }
    }
    //printf("C: %d\n", c);
    if(c==2) primo=1;
    return primo;
    //PRIMO=0
}

//FACT
int* fact(int n){
    int* v=(int*)malloc(sizeof(int)*n);

    int i, c=0;
    for(i=3;i<n;i+=2){
        if(n%i==0){
            if(primo(i)){
                //printf("%d\n", i);
                v[c]=i;
                c++;
            }
        }
    }
    return v;
}

//MAIN
int main(int argc, char** argv){
    int n=atoi(argv[1]);
    //int n=111;
    int* res=fact(n);
    int s=size(res);
    //printf("res: "); myPrint(res);            //TEST

    if(s!=2){
      printf("il numero non e' rsa\n");
        //myPrint(res);
    }
    else{
        if(primo(res[0]) && primo(res[1])){
            printf("fact: %d, %d\n", res[0], res[1]);
        }
        else printf("il numero non e' rsa\n");
    }
    //printf("size: %d\n", s);
    return 0;
}
