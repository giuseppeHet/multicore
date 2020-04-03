#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

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
    for(i=0; i<s; i++){
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

//MAIN------------------------------------------------------------------
int main(int argc, char** argv){
    int num=atoi(argv[1]);
    int id;
    int n;
    //time_t t_start=time(0), t_end;
    //double t_time;

    MPI_Status status;

    int ris;
	ris=MPI_Init(&argc, &argv);
	if(ris!=MPI_SUCCESS){
		fprintf(stderr, "MPI_Init failed\n");
		exit(0);
	}

    MPI_Comm_size(MPI_COMM_WORLD, &n);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Barrier(MPI_COMM_WORLD);

    if(id==0){
		MPI_Bcast (&num,1,MPI_INT,0,MPI_COMM_WORLD);
		//MPI_Send(&num,1,MPI_INT,id+1,0,MPI_COMM_WORLD);
		//MPI_Send(&num,1,MPI_INT,id+2,0,MPI_COMM_WORLD);
		//MPI_Send(&num,1,MPI_INT,id+3,0,MPI_COMM_WORLD);
    }
    if(id==1){
		//MPI_Recv(&num,1,MPI_INT,id-1,0,MPI_COMM_WORLD,&status);
        if(primo(num)) 
			printf("il numero inserito è primo\n");
	}
    if(id==2){
        //MPI_Recv(&num,1,MPI_INT,0,0,MPI_COMM_WORLD,&status);
        int* res=fact(num);
        myPrint(res);
        printf("\n");
    }
    if(id==3){
        //MPI_Recv(&num,1,MPI_INT,0,0,MPI_COMM_WORLD,&status);
        int*res=fact(num);
        int s=size(res);
        if(s!=2){
            printf("il numero non è RSA\n");
        }
        else{
			printf("il numero è RSA\n");
		}
    }

    ris=MPI_Finalize(); 
	if(ris!=MPI_SUCCESS){
		fprintf(stderr, "MPI_Finalize failed\n");
		exit(0);
	}
	
    return 0;
}
