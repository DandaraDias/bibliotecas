#include <stdio.h>

void imprime(double **M, int NL, int NC)
{
	int i, j;
	
	puts(" ");
	for(i=0; i<NL; i++)
	{
		for(j=0; j<NC; j++)
		{
			printf("%.2lf\t", M[i][j]);
		}
		
		puts(" ");
	}
}
