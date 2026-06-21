#include <stdio.h>
#include <stdlib.h>
FILE *monfichier;
char T[51][10];

void start ();
void nbr_premier ();
void statistique ();
void change ();
void inverse ();


void start()
{
  
  monfichier = fopen ("fichier.txt", "w+");
  if (monfichier == NULL)
  {
    printf ("Erreur d'ouverture de fichier\n");
    exit (0);
  }
  fprintf (monfichier, "2\n");
  fclose (monfichier);
}

/*trouver les 50 premiers nombres premiers */
void nbr_premier ()
{
  int i, n, r = 0, c;
  for (n = 3; r <= 50; n++)
  {
    c = 0;
    for (i = 1; i <= n; i++)
    {
      if (n % i == 0)
      {
        c++;
      }
    }
    if (c == 2)
    {
      r++;
      monfichier = fopen ("fichier.txt", "a");
      if (monfichier == NULL)
      {
        printf ("Erreur d'ouverture de fichier");
        exit (0);
      }
        fprintf (monfichier, "%d\n", n);
        fclose (monfichier);
    }
  }
}

/*lit le fichier dans le tableau global T, affiche les lignes multiples de 3 et compte le nombre total des caracteres*/
void statistique ()
{
  
  int i, j;
  int count = 0;
  
  monfichier = fopen ("fichier.txt", "r");
      if (monfichier == NULL)
      {
        fprintf (monfichier, "Erreur d'ouverture de fichier\n");
        exit (0);
      }

  for (i = 0; i < 51; i++)
  {
    if (fscanf (monfichier, "%s\n", T[i]) != 1)
    {
      break;/*fin du fichier*/
    }
  }
  fclose (monfichier);

  /*affichage et comptage*/
    for (i = 0; i < 51; i++)
    {
       if (i % 3 == 0)
       {
          printf ("%s\n", T[i]);
       }
    
       for (j = 0; T[i][j] != '\0'; j++)
       {
          count++;
       }
        printf ("il existe %d  caractère\n", count);
    }  
}
/*remplace chaque '5' par 'v' dans T, affiche les lignes modifiées, puis réecrit le fichier*/
void change ()
{
  
  int i, j, k = 0;
  char ligne [51];
  int compteur = 0;
  char v = 'v';
  
  for (i = 0; i < 51; i++)
  {
    for (j = 0; T[i][j] != '\0'; j++)
    {
      if (T[i][j] == '5')
      {
        T[i][j] = v;
        compteur++;
        ligne [k] = i;
        printf ("5 remplace a la ligne %d\n", ligne [k]); 
        k++;
        
      }
    }
  }  
        
      monfichier = fopen ("fichier.txt", "w");
      if (monfichier == NULL)
      {
        fprintf (monfichier, "Erreur d'ouverture de fichier\n");
        exit (0);
      }
      for (i = 0; i < 51; i++)
      {
        fprintf (monfichier, "%s\n", T[i]);
      }
      
  fclose (monfichier);
  printf ("total de 5 remplaces : %d\n", compteur);
}
  
/*réécrit le fichier avec chaque ligne à l'envers (les caractere dans l'ordre inverse)*/
void inverse()
{
  
  
  int i, j;
  monfichier = fopen ("fichier.txt", "w");
      if (monfichier == NULL)
      {
        fprintf (monfichier, "Erreur d'ouverture de fichier");
        exit (0);
      }
  for (i = 50; i >= 0; i--)
  {
    j=0;
     while (T[i][j]!= '\0')
    {
      j++;
    }
       for (j = j-1; j >= 0; j--)
       {
          fprintf (monfichier, "%c", T[i][j]);
       }
   fprintf (monfichier,"\n" );
  }
  fclose(monfichier);
}
 int main ()
  {
    start();
    nbr_premier ();
    statistique();
    change();
    inverse();
    return 0;
  }
  

