# Mesure Sanitaire

L'ISEN doit mettre en place des mesures sanitaire. Pour ce faire, chaque élève doit être testé négatif au COVID-19. L'ISEN à une liste des élèves de chaque classe et doit avoir au moins 90% de la classe vaccinée. A vous de trouver une solution pour optimiser la recherche des classes récalcitrante.

Pour ce faire vous aurez le nombre de classe, puis une liste pour chaque classe avec si un élève est vacciné 1 et s'il ne l'est pas 0. Vous devrez retourné le nombre de classes qui ont moins de 90% de vaccinés (si c'est exactement 90% de vaccinés alors la classe passe).

## Input
Ligne *1* : un entier **N** compris entre *3* et *30* représentant le nombre de classe présentent à l'ISEN.

Ligne *2* : une liste de **N** entier représentant le nombre d'élèves dans chaque classe.

Lignes *3* à **N**+*2* : les lignes représentent les élèves des **N** classes avec un *1* si l'élève est vacciné et *0* si ne l'est pas.

## Output
Un entier représentant le nombre de classe ayant moins de 90% de non-vaccinés.

## Sample
| Input                                                                                       | Output                     |
|---------------------------------------------------------------------------------------------|----------------------------|
|3<br/>10 13 7<br/>1 1 1 0 1 1 1 1 1 1<br/>1 1 1 1 1 1 0 1 1 0 1 1 1<br/>1 1 1 1 1 1 1        |1<br/><br/><br/><br/><br/>  |
