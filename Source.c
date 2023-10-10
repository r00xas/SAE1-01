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

typedef struct {
    int Identifiant; 
    char nom[MAX_CHAR];
    int IdEntreprise;
    float remuneration;
    int nvSousTraitance;
}Mission;


int traitementCommande(char *commande) {
    if (strcmp("exit", commande) == 0) {
        return 0;
    } else if (strcmp("inscription", commande) == 0) {
        return 1;
    } else if (strcmp("mission", commande) == 0) {
        return 2;
    } else if (strcmp("consulatation", commande) == 0) {
        return 3;
    } else {
        return -1;
    }
}

int existeEntreprise(Entreprise* entreprises, int *nbEntreprises, char* nom) {
    for (int i = 0; i < *nbEntreprises; ++i) {
        if (strcmp(entreprises[i].nom, nom) == 0) {
            return 1;
        }
    }
    return 0;
}

//Commande 0 - Finie
void quitter() {
    exit(0); 
}

//Commande 1 - Finie
int inscription(Entreprise *entreprises, int *nbEntreprises) {
    Entreprise nvEntreprise;
    char nom[MAX_CHAR];
    char role[MAX_CHAR_ROLE];
    scanf("%s %s", &role, &nom);

    if (!((strcmp(role, "OP") == 0) || (strcmp(role, "IN") == 0) || (strcmp(role, "AG") == 0))) {
        printf("Role incorrect\n");
        return 0;
    }
    else if (existeEntreprise(entreprises, nbEntreprises, nom) == 1) {
        printf("Nom incorrect\n");
        return 0;
    }
    else {
        nvEntreprise.Identifiant = *nbEntreprises + 1;
        strcpy(nvEntreprise.nom, nom);
        strcpy(nvEntreprise.role, role);
        entreprises[*nbEntreprises] = nvEntreprise;
        *nbEntreprises += 1;
        printf("Inscription realisee (%u)\n", *nbEntreprises);
        return 0;
    }
}

//Commande 2 - Finie
int publication(Mission* missions, int* nbMissions, Entreprise *entreprises, int *nbEntreprises) {
    Mission nvMission;
    int idEntreprise;
    char nom[MAX_CHAR];
    float remuneration;
    scanf("%u %s %f", &idEntreprise, &nom, &remuneration);

    if (idEntreprise > *nbEntreprises) {
        printf("Identifiant incorrect\n");
        return 0;
    }
    else if (strcmp(entreprises[idEntreprise - 1].role, "OP") != 0) {
        printf("Identifiant incorrect\n");
        return 0;
    }
    else if (remuneration < 0) {
        printf("Remuneration incorrecte\n");
        return 0;
    }
    else {
        nvMission.Identifiant = *nbMissions + 1;
        strcpy(nvMission.nom, nom);
        nvMission.IdEntreprise = idEntreprise;
        nvMission.remuneration = remuneration;
        nvMission.nvSousTraitance = 0;
        missions[*nbMissions] = nvMission;
        *nbMissions += 1;
        printf("Mission publiee (%u)\n", *nbMissions);
        return 0;
    }
}

//Commande 3
void consultation(Mission* missions, int nbMissions, Entreprise* entreprises) {

}


int main() {

    char commande[MAX_CHAR];
    Entreprise entreprises[MAX_ENTREPRISES];
    int nbEntreprises = 0;
    Mission missions[MAX_MISSIONS];
    int nbMissions = 0;

    while (1) {

        scanf("%s", &commande);

        switch (traitementCommande(commande)) {
        case 0:
            quitter();
            break;
        case 1:
            inscription(entreprises, &nbEntreprises);
            break;
        case 2:
            publication(missions, &nbMissions, entreprises, &nbEntreprises);
            break;
        case 3:
            consultation(missions, nbMissions, entreprises);
            break;
        }

    }
    return 0;
}