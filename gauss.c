#include <stdio.h>

void** gauss(double **M, int NL, int NC)
{
        double l, pivot, maior, aux;
        int i, j, k, m, n;
        
        for(j=0; j<NL-1; j++)
        {	
			pivot = M[j][j];
			maior = pivot;

			for(k=j; k<NL; k++)
			{	
				if(fabs(maior) < fabs(M[k][j]))
				{	
					maior = M[k][j];
					m = k;
				}
			}

			if( maior != pivot)
			{	
				for(n=0; n<NC; n++)
				{	
					aux = M[m][n];
					M[m][n] = M[j][n];
					M[j][n] = aux;
				}			
			}

			for(i=j+1; i<NL; i++)
			{
				l = M[i][j]/M[j][j];       
			
				for(k=0; k<NC; k++)
				{
					M[i][k] -= l*M[j][k]; 
				}
			}       
		}
}

void subsreversa(double **M, double *r, int dim)
{
	int i,j;
	double soma;

	r = malloc(dim*sizeof(double));
	
	for(i=dim-1; i>=0; i--)
	{
		soma=0;
		
		for(j=i+1; j<dim; j++)
		{
			soma += M[i][j]*r[j];
		}
		
		r[i] = (M[i][dim] - soma)/M[i][i];
		
		printf("a%d = %lf\n", i, r[i]);
	}
}
