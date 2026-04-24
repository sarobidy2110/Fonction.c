#include<stdio.h> 
#include<stdlib.h>
#include<math.h>


void aff_puis(char **T);
float calcul(char **T, int x);
void aff (float y);

void aff (float y)
{
  printf("y = %f\n", y);
}

void  aff_puis(char **T)
{
  printf("%c\n", T[1][2]);
}

float calcul( char **T, int x)
{
  int i=2;
  float y=0;
  while(T[1][i]!= '\0')
  {
    if (T[1][i]!='x' && T[1][i+1]=='x' && T[1][i+2]== '^' )
    {
      y +=(T[1][i] - '0') * pow(x,T[1][i+3] - '0');
      i+=4;
    }
    else if (T[1][i]=='x' && T[1][i+1]=='^')
    {
      y += pow(x,T[1][i+2] - '0');
      i+=3;
    }
    else if (T[1][i]=='x' )
    {
      y+=x;
      i+=1;
    }
    else if (T[1][i]>='0' && T[1][i]<='9')
    {
      y+=(T[1][i] - '0');
      i+=1;
    }
    else 
    {
    i++;
    }
  }
  return (y);
}

int main(int argc, char *argv[])
{
  int x; 
  float y;
  if (argc < 3)
  {
  printf ("erreur: manque d'arguments\n");
  return 1;
  }
  x=atoi(argv[2]);
  aff_puis(argv);
  y = calcul(argv, x);
  aff(y);
  return (0);
}
