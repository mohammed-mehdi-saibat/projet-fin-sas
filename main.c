#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



typedef struct {
  int id;
  char nom[30];
  char prenom[30];
  int numeroMaillot;
  char poste[30];
  int age;
  int buts;
} joueur;

void afficherMenu();
void afficherListe(joueur J[], int taille);
void afficherIDs(joueur J[], int IDs[], int taille);


int main() {
  joueur J[100];
  int choix;
  int taille = 0;
  int IDs[100];

  do {
    afficherMenu();
    printf("Vous choisissez: ");
    scanf("%d", &choix);
    getchar();

    switch(choix) {
      case 1: //--------------------Ajout d'un joueur
      {
        int choixAffichage;
        do {
          if (taille >= 100) {
            printf("Liste pleine ! Impossible d'ajouter plus de joueurs.\n");
            break;
          }
          printf("************INFORMATIONS*************\n");
          printf("Entrez l'ID du joueur: ");
          scanf("%d", &J[taille].id);
          IDs[taille] = J[taille].id;
          getchar();
          printf("Entrez son nom: ");
          fgets(J[taille].nom, 30, stdin); strtok(J[taille].nom, "\n");
          printf("Entrez le prenom: ");
          fgets(J[taille].prenom, 30, stdin); strtok(J[taille].prenom, "\n");
          printf("Entrez le numero du maillot: ");
          scanf("%d", &J[taille].numeroMaillot);
          getchar();
          printf("Entrez son poste [gardien, defenseur, milieu ou attaquant]\n");
          printf("Poste: ");
          fgets(J[taille].poste , 30, stdin); strtok(J[taille].poste, "\n");
          printf("Entrez son age: ");
          scanf("%d", &J[taille].age);
          getchar();
          printf("Combien de buts il a marques: ");
          scanf("%d", &J[taille].buts);
          getchar();
          taille++;
          printf("Voulez-vous ajouter un autre joueur? oui => 1 / non => 0\n");
          printf("Vous choisissez: ");
          scanf("%d", &choixAffichage);
          printf("*************************\n");
          getchar();
        } while (choixAffichage != 0 && taille < 100);
      }
      break;
      case 2: //-----------------------Affichage de liste de joueurs
      afficherListe(J, taille);
      break;
      case 3: //-----------------------Affichage des IDs
      afficherIDs(J, IDs, taille);
      break;
    }
  } while (choix != 0);

}

void afficherMenu() {
  printf("*******Gestion D'une Equipe De Football*******\n");
  printf("1. Ajouter un joueur\n");
  printf("2. Afficher la liste de tous les joueurs\n");
  printf("3. Affiches les ID's\n");
  printf("0. Quitter!\n");
  printf("**********************************************\n");
}

void afficherListe(joueur J[], int taille) {
   printf("*******Liste Des Joueurs*******\n");
   for(int i = 0; i < taille; i++) {
     printf("\n----Joueur N %d-----\n", i + 1);
     printf("ID: %d | Nom: %s | Prenom: %s | Numero du maillot: %d | Poste: %s | Age: %d | Nombre de buts: %d\n", J[i].id, J[i].nom, J[i].prenom, J[i].numeroMaillot, J[i].poste, J[i].age, J[i].buts);
     printf("---------------------\n");
    };
    printf("*******************************\n");
}
  
void afficherIDs(joueur J[], int IDs[], int taille) {
    printf("*******IDs*******\n");
    for(int i = 0; i < taille; i++) {
      printf("------------\n");
      printf("%s's id: %d\n", J[i].nom, IDs[i]);
      printf("------------\n");
    }
    printf("*******************************\n");
}