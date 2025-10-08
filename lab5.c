#include<stdio.h>
#include<mpi.h>
int main(int argc,char *argv[]){
    int rank,size,num;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    if(size<2){
        if(rank==0){
            printf("This program requires atleast 2 processors");
        }
        MPI_Finalize();
        return 0;
    }
    if(rank==0){
        num=42;
        printf("Process 0 is sending %d to Process 1\n",num);
        MPI_Send(&num,1,MPI_INT,1,0,MPI_COMM_WORLD);
    }
    else if(rank==1){
        MPI_Recv(&num,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        printf("Process 1 received %d from Process 0\n",num);
    }
    MPI_Finalize();
    return 0;
}