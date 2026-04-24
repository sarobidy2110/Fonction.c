#include <stdio.h>
#include <stdlib.h>
int somme (int a , int b); 
int difference (int a, int b);
int produit (int a , int b);
int division (int a, int b);
int kajio (char o , int a, int b);

  int somme (int a, int b ) 
  {
    int s; 
    s=a+b;
    printf ("la somme est %d\n" , s);
    return (s) ; 
  }
  
  int difference (int a, int b)
  {
    int S;
    S=a-b ; 
    printf ("la difference est %d\n", S);
    return (S);  
  }
  
  int produit (int a ,int b)
  {
    int p ; 
    p=a*b; 
    printf ("le produit est %d\n" , p);
    return (p) ; 
  }
  
  int division (int a, int b) 
  {
    int d ; 
    d=a/b ; 
    printf ("la division est %d\n" , d) ;
  }
  
  
  int kajio (char o , int a , int b)
  {
  if (o=='+')
  {
    return (somme (a ,b)) ;
  }
    else if (o=='-')
    {
      return (difference (a ,b)); 
    } 
      else if (o=='x')
      {
        return (produit (a ,b)); 
      }
        else if (o=='/')
        {
          return (division (a, b)) ; 
        }
    }
          
int main (int nbrarg , char **par)
{
  int a, b;char o;
  a=atoi(par[1]);
  b=atoi(par[3]);
  o=*par[2];
  kajio(o ,a , b); 
  return (0) ; 
}


  
