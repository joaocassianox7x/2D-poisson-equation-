#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string.h>
#include <cstdio>
#include <omp.h>

#define ARMA_USE_SUPERLU
#define ARMA_USE_OPENMP

using namespace arma;
//omp_set_max_threads(4);

extern void omp_get_thread_num(int);


void charge_distribution(double *A,int n, double a, double t) //FUNCTION TO FILL THE CHARGE DISTRIBUTION FOR EACH TIME STEP
{
    //let's fill the function vector

    double delta = a/(double)n; //X AND Y PLACE IN SPACE
    int count = 0; // AUXILIAR VARIABLE
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {

            A[i+n*j] = exp(-pow((t-0.5),10))*exp(-(pow(delta*i-a/2.,2)+pow(delta*j-a/2.,2)));

            count+=1;
        }
    }
}

void time_sol(double *vect, double t, int n, double a, sp_mat Laplaciano, int inter) //FUNCTION FOR EACH TIME STEP
{
    charge_distribution(vect,n,a,t);
    vec b = vec(vect,n*n);
    vec x1 = spsolve(Laplaciano, b, "superlu");

    char nome1[64]; 
    snprintf(nome1, sizeof(char) * 64, "charge/file%i.txt", inter);

    char nome2[64]; 
    snprintf(nome2, sizeof(char) * 64, "poisson/file%i.txt", inter);


    FILE *fc = fopen(nome1,"w");
    FILE *fp = fopen(nome2,"w");

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            fprintf(fp,"%f ",x1[j+n*i]);
            fprintf(fc,"%f ",b[j+n*i]);
        }
        fprintf(fp,"\n");
        fprintf(fc,"\n");
    }
    fclose(fc);
    fclose(fp);

}


int main()
{
    int n = 500; //discretization for x and y
    double a = 50.; //X AND Y GOES FROM "0" TO "A"
    double deltaxy = a/(double)n; // XY STEP, ARE THE SAME FOR X AND Y
    int m = n*n; //DIMENSION OF LAPLACIAN 
    double *q=(double *)calloc(pow(n,2),sizeof(double)); //VECTOR FOR POTENTIAL
    int N_THREADS = 4; //NUMBER OF THREADS FOR OPENMP
    double t0 = 0.; //FIRST TIME STEP
    double tf = 10.; //FINAL TIME
    int ptst = 50; //NUMBER OF TIME STEPS


    sp_mat M2(m,m); //SPARSE MATRIX

    M2.diag(-n).fill( -1./(pow(deltaxy,2))); //FILLING THE LAPLACIAN EFFECTIVELY
    M2.diag(-1).fill(-1./(pow(deltaxy,2)));
    M2.diag(+1).fill( -1./(pow(deltaxy,2)));
    M2.diag(+n).fill(-1./(pow(deltaxy,2)));
    M2.diag(0).fill(4./(pow(deltaxy,2)));


    double deltat = (tf-t0)/ptst;
    
    omp_set_num_threads(N_THREADS);
    #pragma omp parallel for default(none)  shared(ptst,q,t0,deltat,n,a,M2)
    for(int i=0; i<ptst; i++)
    {
        time_sol(q,t0+i*deltat,n,a, M2, i); //EFFECTIVELY LAPLACIAN FILL
    }

    return 0;
}
