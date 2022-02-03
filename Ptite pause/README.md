# P'tite pause ?

Cela fait maintenant un certain moment que vous êtes à l'ISEN et vous commencez à vous rendre compte que vous dépensez trop dans les différentes machines présentent à la cafétéria pendant vos pauses. Vous décidez donc de vous fixer un plafond journalier de dépense à ne pas dépasser et avec lequel vous aller acheter de la nourriture et des boissons pour avoir le maximum de calories possible.

Pour cela, on vous donne 2 types d'éléments : les achats au distributeurs pour lequels on vous donne leurs prix et leurs apport en calories indivisibles, mais aussi les achats à la machine à café pour lequels vous avez la quantité disponible en centimes d'euros et le nombre de calories par centimes. Vous devez donc indiquer quel nourriture prendre pour maximiser la valeur en calories apportée.

## Input
Ligne *1* : *3* entiers séparés par des espaces : **N** le nombre de nourriture dans le distributeur, **M** le nombre de types de café, **C** la valeur (en centimes d'euro) du plafond que vous avez fixé.

Lignes *2* à **N** + *1* : 2 entiers séparés par des espaces, respectivement la valeur (en calories) et le prix (en centimes d'euro) de chaque nourriture, compris respectivement entre *1* et *1000* et *1* et **C**.

Lignes **N** + *2* à **N** + **M** + *2* : 2 entiers séparés par des espaces, respectivement le nombre de calories par centimes d'euros (en calories par centimes d'euros) et la quantité disponible (en centimes d'euros) de chaque cafés, compris respectivement entre *1* et *100*, *1* et **C**.

## Output
La valeur maximale de calories que vous pouvez acheter !

## Sample
| Input                                                                                       | Output                     |
|---------------------------------------------------------------------------------------------|----------------------------|
|2 2 320<br/>450 300<br/>580 200<br/>15 60<br/>24 80 |3100<br/><br/><br/><br/><br/> |

## Notes

Dans cet exemple l'optimal est de prendre la nouorriture de valeur 580, puis 80 centimes d'euros de café à 24 calories par centimes, puis 40 centimes de café à 15 calories par centilitre. On arrive alors à une valeur de 580 + 1920 + 600 = 3100