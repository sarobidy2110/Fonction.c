# include <stdio.h>
int volume (int L, int l, int h);
void valeur ();
int L, l, h;

int volume (int L, int l, int h)
{
    int V;
    V= L * l * h;
    return(V);
}
void valeur ()
{
    printf("Entrer la valeur de L\n");
    scanf("%d", & L);
    printf("Entrer la valeur de l\n");
    scanf("%d", & l);
    printf("Entrer la valeur de h\n");
    scanf("%d", &h);
}
int main()
{
    int V;
    valeur();
    V= volume(L, l, h);
    printf("Volume = %d", V);
    return 0;
  }  
    
