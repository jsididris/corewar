# Assembler

** live ** [nb_champion (int)] : Informe que le champion est en vie.

** ld ** :  [first_parameter] [registre] : Charge la valeur du premier paramètre (un registre ou une adresse) dans le registre en deuxième argument. 

** st ** [registre] [second_parameter] : Stocke la valeur du premier registre dans le second paramètre (un registre ou une addresse)

** add ** [registre_1] [registre_2] [registre_3] : Additionne la valeur de registre_1 avec registre_2 et met le resultat dans registre_3

** sub ** [registre_1] [registre_2] [registre_3] : Soustrait la valeur de registre_1 avec registre_2 et met le resultat dans registre_3

** and ** [first_parameter] [second_parameter] [registre] Applique un **ET** logique et met le résultat dans le registre.

** or ** [first_parameter] [second_parameter] [registre] Applique un **OU** logique et met le résultat dans le registre.

** xor ** [first_parameter] [second_parameter] [registre] Applique un **XOR** logique et met le résultat dans le registre.

** zjmp ** [index] : 

** ldi ** *(Modifie le carry)*

** sti ** *(Modifie le carry)*

** fork ** [index] : Crée un nouveau programme qui hérite de l'état du parent. Le programme est éxécuté à l'adresse *PC + first_parameter % IDX_MOD*

** lld ** Pareil que **ld** sans le * %IDX_MOD* (Modifie le carry)

** lldi ** Pareil que **ldi** sans le * %IDX_MOD*. (Modifie le carry)

** lfork ** Pareil que **fork** sans le * %IDX_MOD*. (Modifie le carry)

** aff ** [registre] : Affiche dans la sortie standard le contenu ASCII du registre

