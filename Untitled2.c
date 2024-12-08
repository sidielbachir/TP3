#include<stdio.h>
#include<stdlib.h>
typedef struct element {
int val;
struct element *suivant;
}element;

element* creerListe()
{
	element* liste=NULL;
	
	return liste;
}

element* ajouterEnDebut(element* L,int N)
{
	element *New=(element*)malloc(sizeof(element));
	if(New!=NULL)
	{
	    New->val=N;
		New->suivant=L;
		L=New;	
	}
	return L;
}
element* chargerListe(int Tab[],int Size,element* liste)
{
	int i=0;
	for(i=0;i<Size;i++)
	{
		liste=ajouterEnDebut(liste,Tab[i]);
	}
	return liste;
}


void afficherListe(element* liste)
{
	element* temp=liste;
	while(temp!=NULL)
	{
		printf("%d->",temp->val);
		temp=temp->suivant;
	}
	printf("NULL");
}

element* supprimerEnFin(element* liste)
{
	element* temp=liste;
	element* Pre=temp;
	
	while(temp!=NULL)
	{
		if(temp->suivant == NULL)
		
		{
		   Pre->suivant=NULL;	
		   free(temp);
		   return liste;	
		}
		else
		Pre=temp;
		temp=temp->suivant;	
	}
		
}

void viderListe(element* liste)
{
	element* temp=liste;
	if(liste!=NULL)
		while(temp!=NULL)
		{
			liste=liste->suivant;
			free(temp);
			temp=liste;
		}
	if(liste==NULL)
	printf("\nListe vide!!!\n");	
}

int main()
{
	int Tab[10]={1,3,5,7,8,10,9,11,13,20};
	int Size=10;
	int N=40;
	element*liste=creerListe();
	
	element*L=chargerListe(Tab,10,liste);
	afficherListe(L);
	printf("\n\n");
	element* L1=supprimerEnFin(L);
	afficherListe(L1);
	printf("\n\n");
	element* L2=ajouterEnDebut(L1,N);
	afficherListe(L2);
	printf("\n\n");
	viderListe(L2);
	
	return 0;
}