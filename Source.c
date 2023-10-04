#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<math.h>

#pragma warning(disable : 4996)


//Pour se simplifier la vie sur les unsigned int
typedef unsigned int uint;

//Fourni dans un des poly
enum {
    MAX_ENTREPRISES = 50,
    MAX_MISSIONS = 500,
    MAX_CHAR = 30,
    MAX_SOUSTRAITANCE = 5,
    MAX_CHAR_ROLE = 2,
};

typedef struct {
    int Identifiant;
    char nom[MAX_CHAR];
    char role[MAX_CHAR_ROLE];
}Entreprise;


int traitementCommande(char *commande) {
    if (strcmp("exit", commande) == 0) {
        return 0;
    } else if (strcmp("inscription", commande) == 0) {
        return 1;
    } else {
        return -1;
    }
}

//Commande 0 - Finie
void quitter() {
    exit(0); 
}

//Commande 1
int inscription(Entreprise *entreprises, int* nbEntreprises) {
    Entreprise nvEntreprise;
    scanf("%s %s", &nvEntreprise.role, &nvEntreprise.nom);
    entreprises[]
}

int main() {

    char commande[MAX_CHAR];
    Entreprise entreprises[MAX_ENTREPRISES];

    scanf("%s", &commande);

    switch (traitementCommande(commande)) {
        case 0 :
            quitter();
            break;
        case 1 :
            inscription(entreprises);
            break;

    }
    return 0;
}