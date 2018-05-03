#include<stdio.h>

FILE *leitura;

double** ler(char *nome, int *NL, int *NC)
{	
	double **L;
	double a;
	int i, j, dim;
	
	leitura = fopen(nome, "r");
	i = fscanf(leitura, "%d, %d", NL, NC);
	
	L = malloc(*NL*sizeof(double *));
	
	for(i=0; i<*NL; i++)
	{
		L[i] = (double *)malloc((*NC)*sizeof(double));
	}
	
	for(i=0; i<*NL; i++)
	{
		for(j=0; j<*NC; j++)
		{
			fscanf(leitura, "%lf", &a);
			L[i][j] = a;
		}
	}
	
	return L;
}
