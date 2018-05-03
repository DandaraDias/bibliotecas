#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <linalg.h>

#define E 1e-3

void main(int argc, char **argv)
{
	double **M, **MI, **I, **P;
	double *a, *x1, *x2;
	double erro;
	int NL, NC, i;
	int cont = 0;
	
	M = ler(argv[1], &NL, &NC);
	
	printf("\nMatriz lida:\n");
	imprime(M,NL,NC);	
	
	printf("\nTriangularização:\n");
	triang(M,NL,NC);
	imprime(M,NL,NC);
	
	printf("\nDeterminante: %lf\n", det(M,NL,NC));

	M = ler(argv[1],&NL,&NC);
	printf("\nResolvendo o sistema pelo Método da Eliminação de Gauss com pivotamento:\n");
	gauss(M,NL,NC);
	subsreversa(M, a, NL); 
	imprime(M,NL,NC);

	M = ler(argv[1],&NL,&NC);
	x1 = malloc( NL *sizeof(double *));
	x2 = malloc( NL *sizeof(double *));

	for(i=0; i<NL; i++)
	{
		x1[i] = 0;
	}
	
	do
	{	
		cont++;
		if( cont%2 == 1)
		{
			erro = jacobi(M,x1,x2,NL,NC);
		}
		else
		{
			erro = jacobi(M,x2,x1,NL,NC);
		}
	}while(erro > E);
	
	printf("\nMétodo de Jacobi:\n");
	if( cont%2 == 1 )
	{	
		for(i=NL-1; i>=0; i--)
		{
			printf("a%d = %lf\n", i, x2[i]);
		}
	}	
	else
	{	
		for(i=NL-1; i>=0; i--)
		{
			printf("a%d = %lf\n", i, x1[i]);
		}
	}
	
	M = ler(argv[1],&NL,&NC);
	printf("\nMatriz inversa\n");
	MI = inversa(M,NL,NC);
	imprime(MI,NL,NC);
	
	printf("\nMultiplicando duas matrizes:\n");
	P = multiplicar(M,MI,NL,NC,NC);
	imprime(P,NL,NC);
}
