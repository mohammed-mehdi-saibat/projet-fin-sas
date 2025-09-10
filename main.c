#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// #define POSTE1 "GARDIEN";
// #define POSTE2 "ATTAQUANT";
// #define POSTE3 "DEFENSEUR";
// #define POSTE4 "MILIEU";

typedef struct
{
  int id;
  char nom[30];
  char prenom[30];
  int numeroMaillot;
  char poste[30];
  int age;
  int buts;
} joueur;

void afficherMenu();                            //---------------------------------------------------------------MENU
void questions(joueur J[], int taille);         //------------------------------------------INFO
void ajouterUnJoueur(joueur J[], int taille);   //-------------------------------------AJOUT
void afficherListe(joueur J[], int taille);     //--------------------------------------AFFICHAGE
void toUpperCase(char mot[]);                   //----------------------------------------------------UPPERCASE
void triParNom(joueur J[], int taille);         //----------------------------------------------------TRI PAR NOM
void triParAge(joueur J[], int taille);         //----------------------------------------------------TRI PAR AGE
void affichageParPoste(joueur J[], int taille); //----------------------------------------------------AFFICHER PAR AGE

int main()
{
  joueur J[100];
  int choix;
  int taille = 0;
  do
  {
    afficherMenu();
    printf("Vous choisissez: ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1: //------------------------------------------------------------------------------------------Ajout d'un joueur
      ajouterUnJoueur(J, taille);
      taille++;
      break;
    case 2: //-------------------------------------------------------------------------------------Affichage de liste de joueurs
      afficherListe(J, taille);
      break;
    case 0:
      printf("Merci!\n");
      break;
    default:
      printf("Entrez un choix valide!\n");
      break;
    }
  } while (choix != 0);
}

void ajouterUnJoueur(joueur J[], int taille) //-----------------------------------------------------------------AJOUT
{
  int choixAffichage;
  int joueurID = 0;
  int choixDajout;
  printf("1. Ajouter un joueur.\n");
  printf("2. Ajouter plusieurs joueur.\n");
  printf("Vous choisissez: ");
  scanf("%d", &choixDajout);
  switch (choixDajout)
  {
  case 1:
    if (taille >= 100)
    {
      printf("Liste pleine ! Impossible d'ajouter plus de joueurs.\n");
      break;
    }
    questions(J, taille);
    J[taille].id = ++joueurID;
    break;
  case 2:
    do
    {
      if (taille >= 100)
      {
        printf("Liste pleine ! Impossible d'ajouter plus de joueurs.\n");
        break;
      }
      questions(J, taille);
      J[taille].id = ++joueurID;
      printf("Voulez-vous ajouter un autre joueur? oui => 1 / non => 0\n");
      printf("Vous choisissez: ");
      scanf("%d", &choixAffichage);
    } while (choixAffichage != 0 && taille < 100);
    break;
  }
}

void afficherMenu() //--------------------------------------------------------------------------------------MENU
{
  printf("\n");
  printf("*******Gestion D'une Equipe De Football*******\n");
  printf("1. Ajouter un joueur\n");
  printf("2. Afficher la liste de tous les joueurs\n");
  printf("0. Quitter!\n");
  printf("**********************************************\n");
  printf("\n");
}

void questions(joueur J[], int taille) //-------------------------------------------------------------------INFO
{
  printf("\n");
  printf("************INFORMATIONS*************\n");
  printf("Entrez son nom: ");
  // fgets(J[taille].nom, 30, stdin);
  // strtok(J[taille].nom, "\n");
  scanf(" %[^\n]s", J[taille].nom);
  getchar();
  toUpperCase(J[taille].nom);
  printf("Entrez le prenom: ");
  // fgets(J[taille].prenom, 30, stdin);
  // strtok(J[taille].prenom, "\n");
  scanf(" %[^\n]s", J[taille].prenom);
  getchar();
  toUpperCase(J[taille].prenom);
  printf("Entrez le numero du maillot: ");
  scanf("%d", &J[taille].numeroMaillot);
  printf("Entrez son poste [gardien, defenseur, milieu ou attaquant]\n");
  printf("Poste: ");
  scanf(" %[^\n]s", J[taille].poste);
  getchar();
  // fgets(J[taille].poste, 30, stdin);
  // strtok(J[taille].poste, "\n");
  toUpperCase(J[taille].poste);
  printf("Entrez son age: ");
  scanf("%d", &J[taille].age);
  printf("Combien de buts il a marques: ");
  scanf("%d", &J[taille].buts);
  printf("*************************\n");
  printf("\n");
}

void afficherListe(joueur J[], int taille) //------------------------------------------------------------AFFICHAGE
{
  triParNom(J, taille);
  printf("\n");
  printf("*******Liste Des Joueurs*******\n");
  for (int i = 0; i < taille; i++)
  {
    printf("--------------------------Joueur N %d--------------------------\n", i + 1);
    printf("ID: %d | Nom: %s | Prenom: %s | Numero du maillot: %d | Poste: %s | Age: %d | Nombre de buts: %d\n", J[i].id, J[i].nom, J[i].prenom, J[i].numeroMaillot, J[i].poste, J[i].age, J[i].buts);
    printf("---------------------\n");
  };
  printf("*******************************\n");
  printf("\n");
}

void toUpperCase(char mot[]) //--------------------------------------------------------------------------UPPERCASE
{
  for (int i = 0; mot[i] != '\0'; i++)
  {
    mot[i] = toupper(mot[i]);
  }
}

void triParNom(joueur J[], int taille) //---------------------------------------------------------------TRI PAR NOM
{
  char temp;
  for (int i = 0; i < taille - 1; i++)
  {
    for (int j = i + 1; j < taille; j++)
    {
      if (strcmp(J[i].nom, J[j].nom) > 0)
      {
        strcpy(temp, J[i].nom);
        strcpy(J[i].nom, J[j].nom);
        strcpy(J[i].nom, temp);
      }
    }
  }
}

// void triParAge(joueur J[], int taille) //---------------------------------------------------------------TRI PAR AGE
// {
//   int temp;
//   for (int i = 0; i < taille - 1; i++)
//   {
//     for (int j = 0; j < taille - 1 -i; j++)
//     {
//       if (J[i].age > J[j].age)
//       {
//         temp = J[i].age;
//         J[i].age = J[j].age;
//         J[j].age = temp;
//       }
//     }
//   }
//

// void affichageParPoste(joueur J[], int taille)
// {
//   char choix[20];
//   printf("Choisissez le poste : ATTAQUANT / MILIEU / GARDIEN / DEFENSEUR\n");
//   fgets(choix, 30, stdin);
//   strtok(choix, "\n");
//   for (int i = 0; i < taille; i++)
//   {
//     if(strcmp(choix, J[i].poste) == 0) {
      
//     }
//   }
// }