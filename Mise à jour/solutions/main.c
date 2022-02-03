//Code issue d'une épreuve de BattleDev

/****************************************************************
/***/
/***/
/** SOLUTION BY Solunis*/
/***/
/***/
/********************************************************************/
/*******
 * Read input from STDIN
 * Use printf(...) or fprintf( stdout, ...) to output your result.
 * ***/
#include <stdlib.h>
#include <stdio.h>

int main() {
   int N,z,i,j,total=0;
   char c;
   z=scanf("%d",&N);
   int g[200][200] = {{0}};

	for(i=1;i<=N;i++){
	    for(j=1;j<=N;j++){
	        z=scanf("%c",&c);
	        if(c=='\n')
	            j--;
	        if(c=='X'){
	            g[i][j]=-10000;
	            if(g[i+1][j]>=0)
	                g[i+1][j]=1;
	            if(g[i+1][j+1]>=0)
	                g[i+1][j+1]=1;
	            if(g[i+1][j-1]>=0)
	                g[i+1][j-1]=1;
	            if(g[i-1][j]>=0)
	                g[i-1][j]=1;
	            if(g[i-1][j+1]>=0)
	                g[i-1][j+1]=1;
	            if(g[i-1][j-1]>=0)
	                g[i-1][j-1]=1;
	            if(g[i][j+1]>=0)
	                g[i][j+1]=1;
	            if(g[i][j-1]>=0)
	                g[i][j-1]=1;
	        }
	    }
	}
	
	for(i=1;i<=N;i++){
	    for(j=1;j<=N;j++){
	        z=scanf("%c",&c);
	        if(g[i][j]>0){
	            total+=g[i][j];
	        }
	    }
	}

	printf("%d", total);
	return 0;
}

