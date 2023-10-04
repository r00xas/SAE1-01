#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<math.h>

#pragma warning(disable : 4996 6031)


//Pour se simplifier la vie sur les unsigned int
typedef unsigned int uint;

//Fourni dans un des poly
enum {
    MAX_ENTREPRISES = 50,
    MAX_MISSIONS = 500,
    MAX_CHAR = 31,
    MAX_SOUSTRAITANCE = 5,
    MAX_CHAR_ROLE = 3,
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
int inscription(Entreprise *entreprises, int nbEntreprises) {
    Entreprise nvEntreprise;
    char nom[MAX_CHAR];
    char role[MAX_CHAR_ROLE];
    scanf("%s %s", &role, &nom);
    nvEntreprise.Identifiant = nbEntreprises + 1;
    strcpy(nvEntreprise.nom, nom);
    strcpy(nvEntreprise.role, role);
    entreprises[nbEntreprises] = nvEntreprise;
    nbEntreprises++;
    return 0;
}

int main() {

    char commande[MAX_CHAR];
    Entreprise entreprises[MAX_ENTREPRISES];
    int nbEntreprises = 0;

    scanf("%s", &commande);

    switch (traitementCommande(commande)) {
        case 0 :
            quitter();
            break;
        case 1 :
            inscription(entreprises, nbEntreprises);
            break;
    }
    return 0;
}