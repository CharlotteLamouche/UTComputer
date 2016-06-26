# UTComputer
LO21 - Printemps 2016 - Projet.
UTComputer



On souhaite développer l’application UTComputer, un calculateur scientifique permettant de faire des calculs, de stocker et de manipuler des variables et des programmes, et utilisant la notation RPN (Reverse Polish Notation, i.e. la notation polonaise inversée ou encore notation post-fixée). La notation polonaise inverse est en fait une méthode de notation mathématique permettant d’écrire une formule arithmétique de façon non ambiguë sans utiliser de parenthèse. Ainsi :
• L’expression en mode infixe ’1+1’ pourra s’écrire 1 1 + sur une ligne de commande; • ’2*2+1’ pourra s’écrire 2 2 * 1 + sur une ligne de commande;
• ’(2+3)*4’ pourra s’écrire 2 3 + 4 * sur une ligne de commande.
Pour plus d’information, vous pouvez consulter la page wikipédia dédiée.
La notation post-fixée implique l’utilisation d’une pile pour stocker les résultats intermédiaires lorque l’on évalue une formule arithmétique. Pour intéragir avec un calculateur utilisant cette notation l’utilisateur entre une suite d’opérandes, une opérande étant soit une littérale soit un opérateur. Cette suite d’opérandes est alors évaluée de la gauche vers la droite de la façon suivante :
• si l’opérande est une littérale, elle est empilée sur la pile;
• si l’opérande est un opérateur d’arité n, elle provoque le dépilement de la pile de n expressions, l’application
de l’opérateur sur ces expressions, et l’empilement du résultat.
Un des inconvénients est qu’un opérateur ne peut pas avoir plusieurs arités. En particulier, l’opérateur - ne peut pas être à la fois unaire (pour transformer un nombre en nombré négatif) et binaire (pour faire une soustraction). Il faut donc différencier l’opérateur binaire de soustraction (’10-2’ devient 10 2 -) de l’opérateur unaire de négation (’-2’ devient 2 NEG).
