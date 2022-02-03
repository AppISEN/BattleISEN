# Mise à jour

Vous jouez depuis un moment sur un monde minecraft où vous avez pu vous développer. Récemment, une nouvelle mise à jour du jeu à eu lieu et les développeurs ont décidés de changer le fonctionnement de la culture. Désormais, chaque bloc d'eau irrigue et rend ainsi cultivables les 8 cases qui lui sont adjacentes (on ne peut rien cultiver sur une case contenant l'eau).

Le but de ce challenge est de déterminer le nombre de cases cultivables de votre exploitation après cette mise à jour.

## Input
Ligne *1* : un entier **N** compris entre *3* et *200* représentant la taille de votre ferme (une grille carrée de dimension **N** x **N**)

Lignes *2* à **N**+*1* : les lignes de la carte représentées par des chaînes de N caractères. Les caractères de la ligne sont soit X (un bloc d'eau) soit . (une case vide).

## Output
Un entier représentant le nombre de cases cultivables de votre ferme.

## Sample
| Input                                                                                       | Output                     |
|---------------------------------------------------------------------------------------------|----------------------------|
|6<br/>.....X<br/>....X.<br/>......<br/>......<br/>.XX...<br/>......  |17<br/><br/><br/><br/><br/><br/><br/>|