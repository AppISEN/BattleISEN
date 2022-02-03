//Code issue d'une épreuve de BattleDev

/****************************************************************
/***/
/***/
/** SOLUTION BY heckaa*/
/***/
/***/
/********************************************************************/
/*******
 * Read input from STDIN
 * Use printf(...) or fprintf( stdout, ...) to output your result.
 * Use:
 *  localPrint( char* mystring)
 * to display variable in a dedicated area.
 * ***/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int minintab(int *tab, int nbamis){
	int i = 1;
	int min = 0;
	while(i<nbamis){
		if(tab[i] < tab[min])
			min = i;
		i++;
	}
	tab[min]=100;
	return(min);
}

int main() {
	char s[1024];
	int mesnotes[5];
	int nbamis=0;
	int bff=0;
	int manote=0;
    if(scanf("%s", s) != EOF)
    	mesnotes[0] = atoi(s);
    if(scanf("%s", s) != EOF)
    	mesnotes[1] = atoi(s);
    if(scanf("%s", s) != EOF)
    	mesnotes[2] = atoi(s);
    if(scanf("%s", s) != EOF)
    	mesnotes[3] = atoi(s);
    if(scanf("%s", s) != EOF)
    	mesnotes[4] = atoi(s);
    if(scanf("%s", s) != EOF)
    	nbamis = atoi(s);
    if(scanf("%s", s) != EOF)
    	bff = atoi(s);
    int *tabamis = (int*)malloc(sizeof(int)*nbamis);
    int *tabsix = (int*)malloc(sizeof(int)*nbamis);
    int i = 0;
    int j = 0;
	while (i < nbamis) {
		j = 0;
		tabamis[i] = 0;
		while(j < 6){
			if(scanf("%s", s) != EOF){
				if(j==5){
					tabsix[i] = atoi(s);
				} else {
					if(atoi(s)>mesnotes[j])
						tabamis[i] += (atoi(s) - mesnotes[j]);
					else
						tabamis[i] += (mesnotes[j] - atoi(s));
				}
				j++;
			}
		}
		i++;
	}
	i = 0;
	while(i < bff){
		j = minintab(tabamis, nbamis);
		manote += tabsix[j];
		i++;
	}
	printf("%d\n", ((int)(manote/bff)));
	return 0;
}

