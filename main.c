#include <stdio.h>
#include <stdlib.h>

int primo(int n){
	int i;
    int flag = 1;
	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			flag = 0;
			break;
		}
	}
    return flag;
}


int main(){
    int* v=(int*)malloc(sizeof(int));
    int i;
    int c=0;
    for(i=0;i<100;i++){
        if(primo(i)){
           v[c]=i;
           c++;
        }
    }
    int j;
    for(j=0;j<c;j++){
        printf("%d, ", v[j]);
    }
    printf("\n");
    return 0;
}
