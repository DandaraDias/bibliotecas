#include <stdio.h>

double** inversa(double **L, int NL, int NC)
{
	int i,j,k;
	double soma;
	double **aux, **LI, **C;

	//inicialização matriz combinada
	C = malloc(NL*sizeof(double*));
	
	for(i=0; i<NL; i++)
	{
		C[i] = malloc((2*NC)*sizeof(double));
	}
	
	//matriz combinada
	for(i=0; i<NL; i++)
	{	
		for(j=0; j<2*NC; j++)
		{	
			if(j < NC )
			{
				C[i][j] = L[i][j];
			}
			else
			{	
				if( j == (i+NC))
				{
					C[i][j] = 1;
				}
				else
				{
					C[i][j] = 0;
				}
			}
		}
	}
	
	gauss(C,NL,2*NC);

	//inicialização matriz aux
	aux = malloc(NL*sizeof(double *));
	
	for(i=0; i<NL; i++)
	{
		aux[i] = malloc((NC+1)*sizeof(double));
	}
	
	//inicialização matriz inversa
	LI = malloc(NL*sizeof(double *));

	for(i=0; i<NL; i++)
	{
		LI[i] = malloc((NC)*sizeof(double));
	}
	
	//matriz inversa
	for(k=0; k<NL; k++)
	{	//matrizes auxiliares
		for(i=0; i<NL; i++)
		{	
			for(j=0; j<NC+1; j++)
			{
				if( j < NC )
				{
					aux[i][j] = C[i][j];
				}
				else
				{
					aux[i][j] = C[i][k+j];
				}
			}
		}
		
		//substituição reversa
		for(i=NL-1; i>=0; i--)
		{
			soma = 0;
			
			for(j=i+1; j<NL; j++)
			{
				soma += aux[i][j]*LI[j][k];
			}

			LI[i][k] = (aux[i][NL] - soma)/aux[i][i];
		}
	}
	
	free(aux);
	free(C);
	
	return LI;
}
