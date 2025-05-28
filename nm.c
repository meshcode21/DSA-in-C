#include <stdio.h> 
#include <math.h> 
#define MAX_SIZE 10 
#define MAX_ITER 100 
#define TOL 1e-6 
 void gaussSeidel(double A[MAX_SIZE][MAX_SIZE], double b[MAX_SIZE], double x[MAX_SIZE], int n) {     
    double x_new[MAX_SIZE], error;     
    int iter = 0;     
    do {        
        error = 0.0;        
        for (int i = 0; i < n; i++) {
            double sum = 0.0;            
            for (int j = 0; j < n; j++) {                 
                if (j != i) {                     sum += A[i][j] * x[j]; // Uses latest x[j] (already updated if j < i) 
                } }             x_new[i] = (b[i] - sum) / A[i][i];             error += fabs(x_new[i] - x[i]);             x[i] = x_new[i]; // Immediate update for Gauss-Seidel 
        }      iter++; 
    } while (error > TOL && iter < MAX_ITER); 
 
    printf("Converged in %d iterations.\n", iter); 
} int main() {     int n;     double A[MAX_SIZE][MAX_SIZE], b[MAX_SIZE], x[MAX_SIZE]; 
     printf("Enter the number of equations (n ≤ %d): ", MAX_SIZE);     scanf("%d", &n); 
     printf("Enter the coefficient matrix A:\n");     for (int i = 0; i < n; i++) {         for (int j = 0; j < n; j++) {             scanf("%lf", &A[i][j]); 
        } 
    }      printf("Enter the right-hand side vector b:\n");     for (int i = 0; i < n; i++) {         scanf("%lf", &b[i]); 
    }      printf("Enter the initial guess for x:\n");     for (int i = 0; i < n; i++) {         scanf("%lf", &x[i]); 
    }      gaussSeidel(A, b, x, n); 
     printf("Solution vector x:\n");     for (int i = 0; i < n; i++) {         printf("x[%d] = %.6f\n", i, x[i]); 
    }    return 0;} 