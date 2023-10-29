#include <stdio.h>
#include <stdlib.h>  //sudo apt install gcc
int main (int argc ,char*argv[])
{
printf("Bonjour le monde ");
return 0;
}
// compilation gcc <nom_fichier_c>-o r//r est le nom de l'executable
// lancer le .exe r
// strace ./ a.exe ou a
typedef struct trame
{
    size_t taille ;
    int etat ;  // 1 si occupee 0 si libre
    char contenu ;
    int adresse ;
    int compteur ;
}trame ;

typedef struct processus
{
    size_t taille ;
    int page_debut ;
    int page_fin ;
} processus;

typedef struct page
{
    int numero_page;// adresse
    size_t taille ;
    trame contenu ;// sa valeur
}page ;

trame RAM[8];  // notre memoire physique possède 8 trames memoires
page table_pages[20] ; // notre table de pages contient 20 pages
/*for(i=0; i<=5;i++)
{
    printf(table_pages[i].numero_page);
}*/
void chargerPage(int numero_page, int numero_trame) // elle permet de charger le contenu de la page de numero de page
//numero_page dans la trame numero numero_trame de la memoire physique RAM
{
    table_pages[numero_page].contenu = RAM[numero_trame] ;
}

void AjusterCompteurAcces(int numero_trame)//elle donne la valeur 0 au compteur de la trame qu'on vient d'acceder
// RAM[numero_trame] et incremente les compteurs de toutes les autres trames
{
    int i ;
    for(i=0 ; i < 8; i++)
    {
        if (i != numero_trame)
            RAM[i].compteur += 1 ;
        RAM[numero_trame].compteur = 0 ;
    }
}

void PrepareAccesMemoire(int adresse_virtuelle)
{

}

int DecomposeAdresse(int adresse_virtuelle)
{
    int numero_page ;
    return numero_page ;
}

int trouverPage(int numero_page) // elle renvoit l'adresse de la trame qui contient le contenu de la page
{
    int numero_trame ;
    page page = table_pages[numero_page] ;
    numero_trame = page.contenu.adresse ;
    return numero_trame ;
}

int evincerPage()
{
    int numero_page_evince , adresse_receveur;
    numero_page_evince = TrouverValeurMaximum();
    copieMemoire(RAM[numero_page_evince].adresse,adresse_receveur,RAM[numero_page_evince].taille) ;
    return numero_page_evince ;
}

int TrouverValeurMaximum()
{
    int index_trame = -1 ;
    int compteur = 0 ;
    int i ;
    for (i=0 ; i<8 ; i++)
        if (RAM[i].compteur > compteur)
        {
            compteur = RAM[i].compteur ;
            index_trame = i ;
        }
    return index_trame ;
}

void copieMemoire(int adresse_source, int adresse_receiver, int nbre_octets)
{

}
