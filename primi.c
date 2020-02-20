#include <stdio.h>
#include <stdlib.h>
#include "BigInt.h"

int primo(int n){
	int i, flag = 1;
	for (i=2; i<=n; i++) {
		if (n % i == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}

int* rsa(int n){
    int* vf=0;
    int* v=(int*)malloc(sizeof(int));
    int i;
    int c=0;
    for(i=2;i<n;i++){
        if((n%i)==0){
           v[c]=i;
           c++;
        }
    }
    if(c!=2){
        return vf;
    }
    else{
        if(primo(v[0]) && primo(v[1])){
        return v;
        }
        else return vf;
    }
}

int main(){
    int x=15226050279225333605356183781326374297180681149613
          80688657908494580122963258952897654000350692006139;
    int* r=rsa(x);

    printf("%d, %d\n", r[0], r[1]);
    return 0;
}

