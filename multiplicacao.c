#include <stdio.h>

double** multiplicar(double **M1, double **M2, int NL1, int NC1, int NC2)
{
	double **M;
	double soma;
	int i, j, k;
	
	M = malloc(NL1*sizeof(double *));
	
	for(i=0; i<NL1; i++)
	{
		M[i] = malloc((NC2)*sizeof(double));
	}
	
	for(i=0; i<NL1; i++)
	{	
		for(j=0; j<NC2; j++)
		{	
			soma = 0;
			
			for(k=0; k<NC1; k++)
			{
				soma += M1[i][k]*M2[k][j];
			}
			M[i][j] = soma;
		}
	}
	
	return M;
}
