#include <stdio.h>
#include <string.h>
#include "Prototypes.h"


int main() {
    int temps, *ptemps;
    int difficulte[10];
    char choixMenu[30], Jouer[30]="JOUER", Dictionnaire[30]="DICTIONNAIRE", Quitter[30]="QUITTER";
    int condition = 1;
    char id_categorie[8][6];
    // tableau qui stocke les noms des catégories
    char Categories[8][30];
    // tableau qui stocke les réponses de chaque joueurs sans se soucier du nom de la catégorie
    char Reponses[4][8][30];
    // pointeurs vers les différentes valeurs demandé à l'utilisateur
    int *pnombre_joueurs, *pnombre_categories, nombre_joueurs, nombre_categories;
    // association des différents pointeurs à leurs variables
    ptemps = &temps;
    pnombre_joueurs = &nombre_joueurs;
    pnombre_categories = &nombre_categories;

    while (condition != 0) {
        printf("  ==== Bienvenue dans le jeu du Petit Bac ====\n");
        printf("\t\t   > Jouer <\n\t\t> Dictionnaire <\n\t\t  > Quitter <\n");
        printf("Que voulez vous faire ?\n");
        condition = 1;

        gets(choixMenu);
        strupr(choixMenu);

        if ( strncmp(choixMenu , Jouer,5)==0) {
            demarrage(Reponses, Categories, pnombre_joueurs,pnombre_categories, ptemps,id_categorie);
            deroulement_partie(Reponses, Categories, ptemps, pnombre_joueurs, pnombre_categories,id_categorie);
            condition = continuer (condition);
        } else if (strncmp(choixMenu , Dictionnaire,12)==0) {
            MenuDico();
            condition = continuer (condition);
        } else if ( strncmp(choixMenu , Quitter,7)==0) {
            return 0;
        } else {
            printf("Saisi incorrecte, veuillez recommencer.\n");
        }
    }return 0;
}