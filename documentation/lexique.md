# Lexique :

** Little endian ** : inversion de l'ordre de lecture des octets

** EIP ** : registre qui contient l'adresse courrante

- la valeur de EIP (soit l'adresse de l'instruction) est chargée vers le bus d'adresse de la mémoire
- le contenu d'adresse indiquée par ce bus est copié dans I
- les bits de I sont envoyés vers l'ALU, qui se charge se faire des opérations, calculs etc
- EIP est incrémenté.