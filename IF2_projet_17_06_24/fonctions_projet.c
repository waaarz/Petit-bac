//
// Created by heric on 26/05/2024.
//
#include <stdio.h>
#include <string.h>
#include "Prototypes.h"
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

void demarrage(char Reponses[4][8][30], char Categories[8][30], int *pnombre_joueurs, int *pnombre_categories, int *ptemps,char id_categorie[8][6]){
    char difficulte[20],facile[20]="FACILE",moyen[20]="MOYEN",difficile[20]="DIFFICILE";
    int condition =1;

    FILE *fichier;
    srand(time(0));
// demande du nombre de joueurs
    printf("Combien y a t-il de joueurs ? (2-4) :\n");
    scanf("%d", &*pnombre_joueurs);
    while ( *pnombre_joueurs < 2 || *pnombre_joueurs > 4 ){
        printf("Votre saisie est incorrect, veuillez reessayez.\n");
        printf("Combien y a t-il de joueurs ? (2-4) :\n");
        scanf("%d", &*pnombre_joueurs);
    }
// demande du nombre de catégories
    printf("Combien de categories voulez-vous ? (4-8) :\n");
    scanf("%d", &*pnombre_categories);
    while ( *pnombre_categories < 4 || *pnombre_categories > 8 ) {
        printf("\nVotre saisie est incorrect, veuillez reessayez.\n");
        printf("Combien de categories voulez-vous ? (4-8) :\n");
        scanf("%d", &*pnombre_categories);
    }
// demande du niveau de difficulté
    printf(" ==== Niveau de difficulte ====\n");
    printf("\tFacile\n\tMoyen\n\tDifficile\n");
    printf("Quel difficulte choisissez-vous ?\n");

    int numero_categorie;
    srand(time(NULL));

    do {
        condition = 1;
        scanf("%s",& difficulte);
        strupr(difficulte);
        // pointeur pour enlever le saut de ligne recupere par les fgets
        char *correction;
        int Numero_Categorie[8];

        // //recupere les categorie de difficulté facile
        if (strncmp(difficulte , facile,6)==0) {
            for(int i = 0; i< *pnombre_categories;i++){
                char tempon[30]="1";
                Numero_Categorie[i] = rand()%9+1;
                // boucle qui empeche d'avoir 2  fois la meme catégorie
                for (int p = 0;p<i;p++){
                    if (Numero_Categorie[i]==Numero_Categorie[p]){
                        Numero_Categorie[i] = rand()%9+1;
                        p=0;
                    }
                }

                fichier = fopen("dico.txt", "r");
                if (fichier != NULL){
                    rewind(fichier);
                    while (tempon[0] != '1'){ // 1 pour difficulté 1 = facile
                        fgets(tempon,30,fichier);
                    }

                    for (int m=0; m<Numero_Categorie[i];m++){
                        fgets(id_categorie[i],6, fichier); // recupere l'id de la categorie choisis pour ecrire la reponse dans la base de donnée
                        fgets(Categories[i],30, fichier);
                        correction = strchr(Categories[i],'\n');
                        strcpy(correction,"\0");
                    }

                }else printf("Erreur lors de l'ouverture du fichier pour la recuperation des categories.\n");

            }fclose (fichier);
            //recupere les categorie de difficulté moyenne
        } else if (strncmp(difficulte , moyen,5)==0) {
            for(int i = 0; i< *pnombre_categories;i++){
                char tempon[30]="1";
                Numero_Categorie[i] = rand()%9+1;
                // boucle qui empeche d'avoir 2  fois la meme catégorie
                for (int p = 0;p<i;p++){
                    if (Numero_Categorie[i]==Numero_Categorie[p]){
                        Numero_Categorie[i] = rand()%9+1;
                        p=0;
                    }
                }

                fichier = fopen("dico.txt", "r");
                if (fichier != NULL){
                    rewind(fichier);
                    while (tempon[0] != '2'){ // 2 pour difficulté 2 = moyen
                        fgets(tempon,30,fichier);
                    }

                    for (int m=0; m<Numero_Categorie[i];m++){
                        fgets(id_categorie[i],6, fichier); // recupere l'id de la categorie choisis pour ecrire la reponse dans la base de donnée
                        fgets(Categories[i],30, fichier);
                        correction = strchr(Categories[i],'\n');
                        strcpy(correction,"\0");
                    }

                }else printf("Erreur lors de l'ouverture du fichier pour la recuperation des categories.\n");

            }fclose (fichier);
        //recupere les categorie de difficulté difficile
        } else if (strncmp(difficulte , difficile,9)==0) {

            for(int i = 0; i< *pnombre_categories;i++){
                char tempon[30]="3";
                Numero_Categorie[i] = rand()%9+1;
                // boucle qui empeche d'avoir 2  fois la meme catégorie
                for (int p = 0;p<i;p++){
                    if (Numero_Categorie[i]==Numero_Categorie[p]){
                        Numero_Categorie[i] = rand()%9+1;
                        p=0;
                    }
                }

                fichier = fopen("dico.txt", "r");
                if (fichier != NULL){
                    rewind(fichier);
                    while (tempon[0] != '3'){// 3 pour difficulté 3 =difficile
                        fgets(tempon,30,fichier);
                    }

                    for (int m=0; m<Numero_Categorie[i];m++){
                        fgets(id_categorie[i],6, fichier); // recupere l'id de la categorie choisis pour ecrire la reponse dans la base de donnée
                        fgets(Categories[i],30, fichier);
                        //permet de ne pas avoir de \n en trop lors de l'affichage des categories au demarrage de la partie
                        correction = strchr(Categories[i],'\n'); // cherche la position du caractère \n
                        strcpy(correction,"\0"); // change le carractere \n par \0
                    }

                }else printf("Erreur lors de l'ouverture du fichier pour la recuperation des categories.\n");

            }fclose (fichier);

        } else{
            printf("Saisi incorrecte, veuillez recommencer.\n");
            condition = 0;
        }
    }while (condition == 0);

// demande du temps pour une manche
    printf("Combien de temps voulez-vous pour chaques manches ? (en s)\n");
    scanf("%d", &*ptemps );

    while ( *ptemps < 20 ) {
        printf("Votre saisie est incorrect, veuillez reessayez.\n");
        printf("Combien de temps voulez-vous pour chaques manches ? (en s)\n");
        scanf("%d", &*ptemps );
    }
}
//===========================================
void deroulement_partie (char Reponses [4][8][30], char Categories[8][30], int *ptemps, int *pnombre_joueurs, int *pnombre_categories,char id_categorie[8][6]) {
    int categorie_actuel, indice_joueur ;
    char lettre;
    // Récupération d'une lettre aléatoire pour la partie
    srand(time(NULL));
    lettre = rand() % 26 + 65;


    // defini le tableau de reponses comme vide
    for (int l=0; l<*pnombre_joueurs;l++){
        for (int c=0 ; c<*pnombre_categories; c++){
                strcpy(Reponses[l][c], "\0");
        }
    }

    // affichage des catégories et de la lettre
    printf("==== Debut de la partie ====\n");

    for ( indice_joueur = 0; indice_joueur < *pnombre_joueurs; indice_joueur++) {
        int temps_ecoule = 0;
        time_t debut_tour = time(NULL);

        printf("Tour du joueur %d\n", indice_joueur + 1);
        printf("Vous jouer avec la lettre : %c\n", lettre);
        for (int i = 0; i < *pnombre_categories; i++) {
            printf("| %s |", Categories[i]);
        }
        printf("\n\n");

        while (temps_ecoule < *ptemps) {
            printf("Il vous reste %d secondes.\n", *ptemps - temps_ecoule);

            printf("Joueur %d, quelle categorie voulez-vous remplir ? (entrez un numero de 1 a %d)\n",indice_joueur + 1, *pnombre_categories);
            printf("Si vous voulez passer votre tour, alors entrez 9\n");
            scanf("%d", &categorie_actuel);
            if (categorie_actuel == 9){//permet de passer son tour
                temps_ecoule=*ptemps;
            }else{

                while (getchar() != '\n');
                // on passe du numéro de la case associer à la catégorie à son rang
                categorie_actuel = categorie_actuel - 1;

                if (categorie_actuel < 0 || categorie_actuel >= *pnombre_categories) {
                    printf("Categorie invalide. Veuillez reessayer.\n");
                    continue;
                }

                printf("Quelle est votre reponse ?\n");
                fgets(Reponses[indice_joueur][categorie_actuel], 30, stdin);
                //met la premiere lettre de chaque reponses en majuscule pour eviter des problemes
                Reponses[indice_joueur][categorie_actuel][0] = toupper(Reponses[indice_joueur][categorie_actuel][0]);

                time_t fin_reponse = time(NULL);
                temps_ecoule = difftime(fin_reponse, debut_tour);

                printf("Temps ecoule pour ce tour: %d secondes\n", temps_ecoule);

                if (temps_ecoule >= *ptemps) {
                    printf("Temps ecoule pour le joueur %d.\n", indice_joueur + 1);
                    printf("=====================\n");
                    break;
                }
            }
        }
    } //remplissage des cases vides par un "\n" pour afficher des cases vides et non des cases sans valeurs associées
    for (int l=0; l<*pnombre_joueurs;l++){
        for (int c=0 ; c<*pnombre_categories; c++){
            if (Reponses[l][c]==NULL){
                strcpy(Reponses[l][c], "\n\n\0");
            }
        }
    }
    printf("Fin de la partie !");
    affichage(Reponses, pnombre_joueurs, pnombre_categories,Categories,lettre, id_categorie);
}
//=========================
void comptagePoint (int validite[4][8], int refus[4][8], int *pnombre_joueurs, int *pnombre_categories, char Reponses [4][8][30], char lettre, char id_categorie[8][6] ){
    int Points[4]={0};

    // Calcul des points si la réponse a été validé
    for (int m = 0; m<*pnombre_joueurs;m++){
        for (int n=0; n<*pnombre_categories; n++){
            //accorde 2 si la reponse est validé par tout les joueurs
            if(validite[m][n]== *pnombre_joueurs-1){
                //compare les réponses des joueurs et accorde 1 point si au moins 2 joueurs ont a meme réponse
                if (Reponses[m][n] == Reponses[0][n] ||Reponses[m][n] == Reponses[1][n] ||Reponses[m][n] == Reponses[2][n] || Reponses[m][n] == Reponses[3][n] && Reponses[m][n] == Reponses[m][n]){
                    Points[m] = Points[m] +1;
                }// sinon accorde 2 points
                else Points[m] = Points[m] +2;
                ecriture (Reponses,m,n,lettre,id_categorie);

            }// n'accorde pas de points si aucun joueurs n'a accepté la réponse
            else if (validite[m][n]== 0){
                Points[m] = Points[m];
            }
            else if (validite[m][n]==*pnombre_joueurs){ // si le mot est retrouvé dans la base de données, il ne sera pas réécrit
                //compare les réponses des joueurs et accorde 1 point si au moins 2 joueurs ont a meme réponse
                if (Reponses[m][n] == Reponses[0][n] ||Reponses[m][n] == Reponses[1][n] ||Reponses[m][n] == Reponses[2][n] || Reponses[m][n] == Reponses[3][n] && Reponses[m][n] == Reponses[m][n]){
                    Points[m] = Points[m] +1;
                }// sinon accorde 2 points
                else Points[m] = Points[m] +2;
            }
            // enleve un point à celui qui refuse un mot accepter par les autres joueurs
            else if(validite[m][n]!= 0 &&validite[m][n]!= *pnombre_joueurs-1){
                Points[m] = Points[m] +1;
                for (int l=0; l<*pnombre_joueurs;l++){
                    if (refus[l][n] !=0){
                        Points[l]=Points[l]-1;
                    }
                }
            }
        }
    }
    int point_gagnant=0, numero_gagnant;
    printf("==== Scores ====\n");
    for (int j = 0; j < *pnombre_joueurs; j++) {
        printf("Le score du joueur%d est de : %d\n", j+1, Points[j]);
    }
    // boucle qui determine le joueur avec le plus de points et le designe comme gagnant
    for (int b=0; b<*pnombre_joueurs;b++){
        if (Points[b]>point_gagnant){
            point_gagnant = Points[b];
            numero_gagnant = b+1;
        }
    }
    printf("Le joueur %d gagne la partie avec %d points, bravo !\n", numero_gagnant, point_gagnant);
    // boucle qui determine s'il y a des egalités et désigne les autres gagnants
    for (int b = 0; b <*pnombre_joueurs; b++) {
        if (Points[b] == point_gagnant && b + 1 != numero_gagnant) {
            printf("Le joueur %d gagne aussi la partie avec %d points, bravo !\n", b + 1, point_gagnant);
        }
    }
}
//===================
void affichage (char Reponses [4][8][30], int *pnombre_joueurs, int *pnombre_categories, char Categories[8][30],char lettre,char id_categorie[8][6]) {
    char etat_reponse[10],accepter[10]="ACCEPTER", refuser[10]="REFUSER";
    int validite[4][8]={0};
    int refus[4][8]={0};
    char reponse_dictionnaire[30];
    FILE *fichier;

    int condition;
    printf("\n ==== Validation des reponses ====\n");

    for (int i =0 ; i<*pnombre_joueurs;i++){
        for (int q=0 ; q<*pnombre_categories;q++){

            int max=12; // max qui empeche une boucle if si il n'est pas changé
            // boucle qui compare la reponse du joueurs avec les reponses de la base de données
            if (Reponses[i][q][0] !='\0'){
                 max = strlen(Reponses[i][q]);
                fichier = fopen("dico.txt", "r");
                if (fichier != NULL ){
                    fgets(reponse_dictionnaire, 30, fichier);

                    while(fgetc(fichier) != EOF && strncmp(reponse_dictionnaire,Reponses[i][q],max)!=0){
                        fseek(fichier,6,1);
                        fgets(reponse_dictionnaire, 30, fichier);
                    }
                    if (fgetc(fichier) != EOF){
                        strcpy(reponse_dictionnaire,Reponses[i][q]);

                    }
                }else {
                    printf("Le fichier des réponse n'a pas pu etre ouvert\n");
                }
                fclose(fichier);
            }
            // boucle qui s'active si la reponse est deja dans la base de données
            if (strncmp(reponse_dictionnaire,Reponses[i][q],max)==0){ //
                validite[i][q]= *pnombre_joueurs;
            }else{// si la reponse n'est pas dans la base de données, demandera aux joueurs d'accepter la reponse ou non pour l'inscrire dans la base de données
                for (int p = 0; p<*pnombre_joueurs; p++){
                    if (Reponses[i][q][0]=='\0'){
                        printf("Le joueur%d n'a pas donner de reponse pour la categorie %s.\n",i+1,Categories[q]);
                        p++;
                    }else if (p!=i){ // if qui empeche les joueurs de valider leurs propres reponses
                        printf("Reponse du joueur%d pour la categorie %s : %s",i+1,Categories[q],Reponses[i][q]  );
                        printf("\tAccepter\n\tRefuser\n");
                        printf("Joueur %d, que voulez-vous faire ?\n", p+1);

                        do {// boucle qui demande aux joueurs d'accepter/refuser la réponses des autres
                            condition = 1;
                            gets(etat_reponse);
                            strupr(etat_reponse);

                            if (strncmp(etat_reponse, accepter, 8) == 0) {
                                validite[i][q]=validite[i][q]+1;
                            }else if (strncmp(etat_reponse, refuser, 7) == 0) {
                                //garde en mémoire qui a refuser quelle réponse
                                refus[i][q]=refus[i][q] +1;
                            } else { //message d'erreur en cas de saisi incorrecte
                                printf("Saisi incorrecte, veuillez recommencer.\n");
                                condition = 0;
                            }
                        } while (condition == 0);
                    }
                }
            }
        }
    }
    comptagePoint(validite, refus, pnombre_joueurs, pnombre_categories, Reponses, lettre, id_categorie);
}
//==============
void ecriture (char Reponses [4][8][30],int m, int n, char lettre,char id_categorie[8][6] ){
    FILE *fichier;

    fichier = fopen("dico.txt", "a+");
    if (fichier != NULL){
        fprintf(fichier,"%c.%s%s", lettre, id_categorie[n] ,Reponses[m][n]);
        fclose(fichier);
    }else printf("Erreur lors de l'ouverture du fichier, la reponse ne sera pas inscrit dans la base de donnees.\n");
}
//============
int continuer (int condition){ // fonction qui permet de retourner au menu ou de quitter le programme
    char reponse, oui ='O', non ='N';
    do{
        printf("Voulez-vous faire autre chose (O/N) ?\n");
        getchar();
        reponse = getchar();
        getchar();
        // toupper pour ne pas differentier le cas où o/n est en majuscule/minuscule
        reponse = toupper(reponse);
        if (reponse == oui){
            condition= 1;
            printf("retour au menu\n");
        }else if (reponse == non){
            condition = 0;
        }else{
            printf("Saisi incorrecte, veuillez recommencer.\n");
        }
    }while (reponse != oui && reponse != non);
    return condition;
}
//===========================================
void MenuDico() {
    char choix[20],Ajouter[20]="AJOUTER",Modifier[20]="MODIFIER",Supprimer[20]="SUPPRIMER";
    int condition =1;
    char mot[100];
    char mot_modif[100], mot_nouveau[100];
    char id_categorie[3], id_difficulte[2], lettre [2];
    FILE *fichier;
    FILE *fichier_modif;

    printf("Listes des mots du dictionnaire :\n");

    fichier = fopen("dico.txt", "r");
    if (fichier != NULL) {
        while (fgets(mot, 100, fichier)!= NULL){
            puts(mot);
        }
    }else printf("Erreur lors de l'ouverture du fichier.\n");
    printf("Les reponses sont indique par une lettre puis la difficulte (de 1 a 3) et le numero de la categorie.\n");
    printf(" ==== Edition du dictionnaire ====\n");
    printf("\t> Ajouter <\n\t> Modifier <\n\t> Supprimer <\n");

    while (condition != 0) {
        printf("Que voulez-vous faire ?\n");
        condition = 1;
        gets(choix);
        strupr(choix);

        if (strncmp(choix , Ajouter,7)==0) {
            fichier = fopen("dico.txt", "a+");
            if (fichier != NULL) {
                printf("Quel mot voulez-vous ajouter ?\n");
                gets (mot);
                mot[0]= toupper(mot[0]);
                printf("Pour quel lettre ?\n");
                gets (lettre);
                strupr(lettre);
                printf("Pour quel difficulte ?(entre 1 et 3)\n");
                gets(id_difficulte);
                printf("Pour quel categorie ?(entre 1 et 9)\n");
                gets(id_categorie);
                fprintf((fichier), "%s.%s.%s. %s\n",lettre,id_difficulte,id_categorie, mot);
                fclose(fichier);
            }else {
                printf("Erreur lors de l'ouverture du fichier.\n");
            }condition = 0;

        } else if (strncmp(choix , Modifier,8)==0) {
            fichier = fopen("dico.txt", "r+");
            if (fichier != NULL) {
                printf("Quel mot voulez-vous modifier ?\n");
                gets(mot);
                mot[0]= toupper(mot[0]);
                printf("Entrez sa lettre\n");
                gets (lettre);
                strupr(lettre);
                printf("Entrez sa difficulte\n");
                gets (id_difficulte);
                printf("Entrez sa categorie\n");
                gets (id_categorie);
                printf("Entrez le nouveau mot\n");
                gets (mot_nouveau);
                mot_nouveau[0]= toupper(mot_nouveau[0]);

                fichier_modif = fopen("nouveaudico.txt", "w+");
                if (fichier_modif!=NULL){
                    rewind(fichier);

                    fprintf((fichier_modif), "%s.%s.%s. %s\n",lettre,id_difficulte,id_categorie, mot);
                    rewind(fichier_modif);
                    fgets(mot, 30, fichier_modif);
                    fputs(mot,fichier_modif);
                    rewind(fichier_modif);

                    // boucle qui copie le contenue de l'ancien fichier vers le nouveau
                    while (strncmp(mot_modif,mot, strlen(mot))!=0){
                        fputs(mot_modif, fichier_modif);
                        fgets(mot_modif, 30, fichier);
                    }
                    fprintf((fichier_modif), "%s.%s.%s. %s\n",lettre,id_difficulte,id_categorie, mot_nouveau);
                    while (fgetc(fichier )!= EOF){
                        fseek(fichier, -1,1);
                        fgets(mot_modif, 30, fichier);
                        fputs(mot_modif, fichier_modif);
                    }
                    fclose(fichier);
                    fclose(fichier_modif);
                    // remplace l'ancien fichier par le nouveau
                    remove("dico.txt");
                    rename("nouveau.txt","dico.txt");
                }else printf("Erreur lors de l'ouverture du fichier.\n");
            }else {
                printf("Erreur lors de l'ouverture du fichier.\n");
            }condition = 0;


        } else if (strncmp(choix , Supprimer,9)==0) {
            fichier = fopen("dico.txt", "r+");
            if (fichier != NULL) { //on recupère toutes les informations pour la suite du programme
                printf("Quel mot voulez-vous supprimer ?\n");
                gets(mot);
                mot[0]= toupper(mot[0]);
                printf("Entrez sa lettre\n");
                gets (lettre);
                strupr(lettre);
                printf("Entrez sa difficulte\n");
                gets (id_difficulte);
                printf("Entrez sa categorie\n");
                gets (id_categorie);

                fichier_modif = fopen("nouveau.txt", "w+");
                if (fichier_modif!=NULL){
                    rewind(fichier);

                    //mise en place des variables à comparer
                    fprintf((fichier_modif), "%s.%s.%s. %s\n",lettre,id_difficulte,id_categorie, mot);
                    rewind(fichier_modif);
                    fgets(mot, 30, fichier_modif);
                    fputs(mot,fichier_modif);
                    rewind(fichier_modif);

                    // boucle qui copie le contenue de l'ancien fichier vers le nouveau
                    while (strncmp(mot_modif,mot, strlen(mot))!=0){
                        fputs(mot_modif, fichier_modif);
                        fgets(mot_modif, 30, fichier);
                    }// ecrit le reste du fichier apres le mot à supprimer
                    while (fgetc(fichier )!= EOF){
                        fseek(fichier, -1,1);
                        fgets(mot_modif, 30, fichier);
                        fputs(mot_modif, fichier_modif);
                    }
                    fclose(fichier);
                    fclose(fichier_modif);
                    if(remove("cmake-build-debug/dico.txt")!=0){
                        printf("erreur remove\n");
                    }
                    rename("nouveau.txt","dico.txt");

                }else printf("Erreur lors de l'ouverture du fichier.\n");

            }else printf("Erreur lors de l'ouverture du fichier.\n");

            condition = 0;



        } else{
            printf("Saisi incorrecte, veuillez recommencer.\n");
        }
    }
}