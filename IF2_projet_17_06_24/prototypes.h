//
// Created by heric on 26/05/2024.
//

#ifndef IF2_PROJET_PROTOTYPES_H
#define IF2_PROJET_PROTOTYPES_H

void demarrage(char Reponses[4][8][30], char Categories[8][30], int *pnombre_joueurs, int *pnombre_categories, int *ptemps,char id_categorie[8][6]);
void MenuDico();
void deroulement_partie (char Reponses [4][8][30], char Categories[8][30], int *ptemps, int *pnombre_joueurs, int *pnombre_categories,char id_categorie[8][6]);
void affichage (char Reponses [4][8][30], int *pnombre_joueurs, int *pnombre_categories, char Categories[8][30],char lettre,char id_categorie[8][6]);
void ecriture (char Reponses [4][8][30],int m, int n, char lettre,char id_categorie[8][6] );
void comptagePoint (int validite[4][8], int refus[4][8], int *pnombre_joueurs, int *pnombre_categories, char Reponses [4][8][30], char lettre, char id_categorie[8][6] );
int continuer (int condition);

#endif //IF2_PROJET_PROTOTYPES_H