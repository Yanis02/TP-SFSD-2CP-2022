#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LNOF.h"   // LObarreF
#include "TOF.h"    // TOF
#include "random.h" // randomize
#define PRIMARY 100069
#include "conio2.h"
#include <time.h>
#include <windows.h>
#include"TP.h"
#define lar 160

int main(){

fichg*f;
Tbloc buf;
int NE;
int j=1;
int i=1;
int nb=0;
int reply,mat,matt,mattt,x=1;
int cout_lecture=0;
int cout_ecriture=0;

Sleep(2000);
TP(50,10);
Sleep(1000);
system("cls");


    Sleep(2000);
	acceuil();
	gotoxy(1,40);
	message_attente();
TENREG*tab;//declaration de la table d index
tab=malloc(sizeof(TENREG)*350000);
Tenrg en;
  //allouer dynamiquement la zone mémoire nécessaire pour la table d index
f=Ouvrir("PERSONNEL-ANP_DZ.bin",'n');//creation du fichier
Fermer(f);


printf("\n\n\t\tVeuillez donner le nombre d'enregistrements que vous voulez creer:\t");
scanf("%d",&NE);
printf("\n\n");
printf("\t\t\t\t ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ _________ ____ ____ ____ ____ ____ ____ ____  \n"
       "\t\t\t\t||C |||H |||A |||R |||G |||E |||M |||E |||N |||T |||       |||I |||N |||I |||T |||I |||A |||L || \n"
       "\t\t\t\t||__|||__|||__|||__|||__|||__|||__|||__|||__|||__|||_______|||__|||__|||__|||__|||__|||__|||__|| \n"
       "\t\t\t\t|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/_______\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\| \n");
chargem_init("PERSONNEL-ANP_DZ.bin",NE,tab);
printf("\n\n\t\t\t\t\t\t\tChargement en cours, veuillez patienter svp... ");
Sleep(2000);
Color(10,0);
printf("\n\n\t\t\t\t\t\t\t  Chargement initial fait avec success !\n");
 f=Ouvrir("PERSONNEL-ANP_DZ.bin",'a');
 cout_ecriture=entete(f,1);
 Fermer(f);
 quicksort(tab,1,NE);//trier la table d index
int ce1=0;
creation_index("index.bin",NE,tab);
cout_ecriture=cout_ecriture+ce1;
Sleep(500);
Color(15,0);
printf("\n\n\t\t\t\tAFFICHEGE DE L'ENTETE:\t");
f=Ouvrir("PERSONNEL-ANP_DZ.bin",'a');
printf("\tNombre de blocs:  %d",entete(f,1));
printf("\t\tNombre d'enregistrements: %d\n\n\n",entete(f,2));
Fermer(f);

int continu=1;
while(continu==1){
menu();
scanf("%d",&reply);
switch(reply){    // les choix du menu
    case  1:             // inserer un nouvel enregistrement
    {
    system("cls");
    int jour,annee,mois,region,force,wilaya,groupe;
    char nom[30];
    char prenom[30];
    int ce2=0;
    int cl2=0;
    printf("\n\nEntrez le matricule que vous voulez inserer:\n");
    scanf("%d",&mat);
    while (mat<111111 || mat>999999){
        Color(12,0);
        printf("Matricule errone! \nEntrez un autre!\t");
        scanf("%d",&mat);
    }
    en.matricule=mat;
    printf("\nEntrez le nom\n");
    scanf("%s",nom);
    printf("\nEntrez le prenom\n");
    scanf("%s",prenom);
    printf("\nEntrez la date de naissance:\n");
    printf("\tJour de naissance:\t");
    scanf("%d",&jour);
    printf("\n\tMois de naissance:\t");
    scanf("%d",&mois);
    printf("\n\tAnnee de naissance:\t");
    scanf("%d",&annee);
    printf("\nEntrez le numero de la wilaya de naissance:\t");
    scanf("%d",&wilaya);
    printf("\nVeuillez choisir votre groupe sanguin:\n");
    printf("1- O+\n2- A+\n3- B+\n4- O-\n5- A-\n6- AB+\n7- B-\n8- AB-\n");
    scanf("%d",&groupe);
    printf("\nEntrez le numero qui correspond a votre region militaire:\n");
    printf("1- 1RM-Blida\n"
           "2- 2RM-Oran\n"
           "3- 3RM-Bechar\n"
           "4- 4RM-Ouargla\n"
           "5- 5RM-Constantine\n"
           "6- 6RM-Tamanrasset\n");
    scanf("%d",&region);
    printf("\nEntrez le numero qui correspond a la force militaire:\n");
    printf("1- Armee de terre\n"
           "2- Armee de l'air\n"
           "3- Marine nationale\n"
           "4- Defense aerienne du territoire\n"
           "5- Gendarmerie nationale\n"
           "6- Garde republicaine\n"
           "7- Departement du renseignement et de la securite\n"
           "8- Sante militaire\n");
    scanf("%d",&force);
    en.date_de_naissance.annee=annee;
    en.date_de_naissance.jour=jour;
    en.date_de_naissance.mois=mois;
    en.force_militaire=force;
    en.groupe_sanguin=groupe;
    strcpy(en.prenom,prenom);
    strcpy(en.nom,nom);
    en.region=region;
    en.wilaya_de_naissance=wilaya;
    system("cls");
    insertion("PERSONNEL-ANP_DZ.bin",en,tab,NE+nb,&cl2,&ce2);
    cout_lecture=cout_lecture+cl2;
    cout_ecriture=cout_ecriture+ce2;
    Color(15,0);
    printf("\nAffichage de l'enregistrement insere:\n\n");
    f=Ouvrir("PERSONNEL-ANP_DZ.bin",'a');
    LireDir(f,entete(f,1),&buf);
    cout_lecture++;
    printf("\nLe nombre des enregistrements est: %d\n\n",entete(f,2));
    printf("\n Matricule  |       Nom       |     Prenom      |Date naissance|       Willaya        | G-S |          Grade          |       Force militaire        |     Region \n ");
    Color(10,0);
    printf("%-10d | %-15s | %-15s |  %.2d/%.2d/%.4d  | %-20s | %-3s | %-23s | %-28s | %-17s \n",
           buf.t[buf.nb].matricule, buf.t[buf.nb].nom, buf.t[buf.nb].prenom, buf.t[buf.nb].date_de_naissance.jour, buf.t[buf.nb].date_de_naissance.mois,
           buf.t[buf.nb].date_de_naissance.annee, Wilaya_Naissance[buf.t[buf.nb].wilaya_de_naissance-1], Groupe_Sanguin[buf.t[buf.nb].groupe_sanguin-1], Grade[buf.t[buf.nb].grade-1], Force_Armee[buf.t[buf.nb].force_militaire-1],
           Region_Militaire[buf.t[buf.nb].region-1]);
    Fermer(f);
    nb++;
    break;
    }

    case 2:
    {
    system("cls");
    printf("\n\nEntrez le matricule de l'enregistrement que vous voulez modifier:\t");
    scanf("%d",&matt);
    int m,n,found;
    int cl3=0;
    int ce3=0;
   recherche_dichotomique(tab,NE+nb,matt,&m,&found);
    if(found==1 && tab[m].efface==0){
        f=Ouvrir("PERSONNEL-ANP_DZ.bin",'a');
        LireDir(f,tab[m].num_bloc,&buf);
        cout_lecture++;
        printf("\n\nAvant modification:\n\n");
        printf("Matricule   %d  | Region   %s\n\n",buf.t[tab[m].num_enreg].matricule,Region_Militaire[buf.t[tab[m].num_enreg].region-1]);
        Fermer(f);
    printf("\nVeuillez choisir la nouvelle region:\n");
    printf("1- 1RM-Blida\n2- 2RM-Oran\n3- 3RM-Bechar\n4- 4RM-Ouargla\n5- 5RM-Constantine\n6- 6RM-Tamenrasset\n");
    int newregion;
    scanf("%d",&newregion);
    modifier_region("PERSONNEL-ANP_DZ.bin",matt,newregion-1,tab,NE+nb,&cl3,&ce3);
    cout_lecture=cout_lecture+cl3;
    cout_ecriture=cout_ecriture+ce3;
    f=Ouvrir("PERSONNEL-ANP_DZ.bin",'a');
    LireDir(f,tab[m].num_bloc,&buf);
    cout_lecture++;
    Color(15,0);
    printf("\nAffichage apres modification: \n");
    Color(10,0);
    printf("Matricule %d  | Region %s\n",buf.t[tab[m].num_enreg].matricule,Region_Militaire[buf.t[tab[m].num_enreg].region]);
    Fermer(f);
    }else{
        Color(12,0);
        printf("Ce matricule n'existe pas dans le fichier\n");}

    break;
    }

    case 3:
    {
    system("cls");
    int sup,exist;
    int cl4=0;
    int ce4=0;
    printf("\n\nEntrer le matricule de l'enregistrement que vous voulez supprimer: \t");
    f=Ouvrir("PERSONNEL-ANP_DZ.bin",'a');
    scanf("%d",&mattt);
    supprimer("PERSONNEL-ANP_DZ.bin",mattt,tab,NE+nb,&exist,&sup,&cl4,&ce4);
    cout_ecriture=cout_ecriture+2;
    cout_lecture=cout_lecture+2;
   /*while(sup==1 || exist==0); {
        scanf("%d",&mattt);
        supprimer("PERSONNEL-ANP_DZ.bin",mattt,tab,300000+nb,&exist,&sup);
    }*/
    Fermer(f);
    break;
    }

    case 4:
    {
    system("cls");
    int FA, i,j;
    int Cl=0;
    int Ce=0;
    Tbloc temp;
    printf("\nVeuillez selectionner la force armee que vous voulez supprimer: \t\n");
    printf("1- Armee de terre\n"
           "2- Armee de l'air\n"
           "3- Marine nationale\n"
           "4- Defense aerienne du territoire\n"
           "5- Gendarmerie nationale\n"
           "6- Garde republicaine\n"
           "7- Departement du renseignement et de la securite\n"
           "8- Sante militaire\n\n");
    printf("Tapez le numero qui correspond a votre requete:\t");
    scanf("%d", &FA);
    printf("\n\n");
    supprimer_force("PERSONNEL-ANP_DZ.bin",FA,&Cl,&Ce,tab,NE+nb);
    cout_ecriture=cout_ecriture+Ce;
    cout_lecture=cout_lecture+Cl;
    printf_point(10);
    Color(10,0);
    printf("\t\tSuppression terminee avec succes! \n\n");
    f=Ouvrir("PERSONNEL-ANP_DZ.bin",'a');
    Color(15,0);
    printf("\n\tNombre d'enregistrement actuel:  %d", entete(f,2));


    Fermer(f);
     break;
    }

    case 5:

    {
    system("cls");
    int RM;
    int MIN, MAX;
    printf("\nVeuillez indiquer la region militaire que vous voulez consulter: \t\n");
    printf("\t\t1- 1RM-Blida\n"
           "\t\t2- 2RM-Oran\n"
           "\t\t3- 3RM-Bechar\n"
           "\t\t4- 4RM-Ouargla\n"
           "\t\t5- 5RM-Constantine\n"
           "\t\t6- 6RM-Tamanrasset\n\n");
    printf("\nTapez le numero qui correspond a votre requete:\t");
    scanf("%d",&RM);
    printf("\tVeuillez preciser l'intervalle d'age:\n");
    printf("\t\tEntre l'annee:\t");
    scanf("%d", &MIN);
    printf("\t\tEt l'annee:\t");
    scanf("%d", &MAX);
    if (AgeIntervalle(MIN, MAX)){
        int minAge, maxAge;
        minAge = 2022 - MAX;
        maxAge = 2022 - MIN;
        f=Ouvrir("PERSONNEL-ANP_DZ.bin",'a');
        printf("\n   Matricule     |             Nom               |            Prenom             | Age  \n");
        while(x<100){
            LireDir(f,x,&buf);
            cout_lecture++;
            x=buf.suiv;
            for(j=0; j<buf.nb; j++){
                    if (buf.t[j].region == RM-1){
                        int AGE = (2022 - buf.t[j].date_de_naissance.annee);
                            if (AGE>=minAge && AGE<=maxAge){
                                Color(10,0);
                                printf("%-8d \t | %-20.20s \t | %-20.20s \t | %-4d \t\n", buf.t[j].matricule , buf.t[j].nom , buf.t[j].prenom, AGE);
                            }
                    }
            }

        }
    }
    else{
        Color(12,0);
        printf("Cet interval n'est pas valide!");
    }
    Fermer(f);
        break;
    }


    case 6:
    {
    system("cls");
    int categorie;
    printf("\n\nLes categorie de grades sont:\n");
    printf("\t\t1- Officiers-generaux\n"
           "\t\t2- Officiers-superieurs\n"
           "\t\t3- Officiers\n"
           "\t\t4- Sous-officiers\n"
           "\t\t5- Hommes de troupes\n\n");
    printf("\n\tVeuillez choisir la categorie correspondante:\t");
    scanf("%d", &categorie);
    f=Ouvrir("PERSONNEL-ANP_DZ.bin",'a');
    printf("\n\nConsultation des 5 premiers blocs:\n\n");
    printf("\n   Matricule     |                  Nom                  |                 Prenom                 |   Grade    \n");
    x=1;
    while(x<5){
        Color(10,0);
        LireDir(f,x,&buf);
        cout_lecture++;
        x=buf.suiv;
        for(j=1; j<buf.nb; j++){
            if(categorie == 1)
            {
                if(buf.t[j].grade == 0 || buf.t[j].grade == 1 || buf.t[j].grade == 2)
                    printf("%-8d \t | %-30.20s \t | %-30.20s \t | %-30s \t\n", buf.t[j].matricule , buf.t[j].nom , buf.t[j].prenom, Grade[buf.t[j].grade]);
            }
            else if(categorie == 2)
            {
                if(buf.t[j].grade == 3 || buf.t[j].grade == 4 || buf.t[j].grade == 5)
                    printf("%-8d \t | %-30.20s \t | %-30.20s \t | %-30s \t\n", buf.t[j].matricule , buf.t[j].nom , buf.t[j].prenom, Grade[buf.t[j].grade]);
            }
            else if(categorie == 3)
            {
                    if(buf.t[j].grade == 6 || buf.t[j].grade == 7 || buf.t[j].grade == 8 || buf.t[j].grade == 9)
                        printf("%-8d \t | %-30.20s \t | %-30.20s \t | %-30s \t\n", buf.t[j].matricule , buf.t[j].nom , buf.t[j].prenom, Grade[buf.t[j].grade]);
            }
                else if(categorie == 4)
                    {
                        if(buf.t[j].grade == 10 || buf.t[j].grade == 11 || buf.t[j].grade == 12 || buf.t[j].grade == 13)
                            printf("%-8d \t | %-30.20s \t | %-30.20s \t | %-30s \t\n", buf.t[j].matricule , buf.t[j].nom , buf.t[j].prenom, Grade[buf.t[j].grade]);
                    }
                    else if(categorie == 5)
                    {
                        if(buf.t[j].grade == 14 || buf.t[j].grade == 15 || buf.t[j].grade == 16)
                            printf("%-8d \t | %-30.20s \t | %-30.20s \t | %-30s \t\n", buf.t[j].matricule , buf.t[j].nom , buf.t[j].prenom, Grade[buf.t[j].grade]);
                    }
        }
    }
    Fermer(f);
    break;
    }

    case 7:{
    system("cls");
    fichg*f1;
    fichg*f2;
    fichg*f3;
    fichg*f4;
    fichg*f5;
    fichg*f6;
    printf("\n\nVotre fichier sera fragmente en 6 fichiers selon les 6 regions militaires\n\n");
    printf("\t\t\tTraitement en cours...\n");
    fragmentation("PERSONNEL-ANP_DZ.bin","F1.bin","F2.bin","F3.bin","F4.bin","F5.bin","F6.bin");
    f1=Ouvrir("F1.bin",'a');
    f2=Ouvrir("F2.bin",'a');
    f3=Ouvrir("F3.bin",'a');
    f4=Ouvrir("F4.bin",'a');
    f5=Ouvrir("F5.bin",'a');
    f6=Ouvrir("F6.bin",'a');
    f=Ouvrir("PERSONNEL-ANP_DZ.bin",'a');
    cout_ecriture=cout_ecriture+entete(f1,1)+entete(f2,1)+entete(f3,1)+entete(f4,1)+entete(f5,1)+entete(f6,1);
    cout_lecture=cout_lecture+entete(f,1);
    Fermer(f);
    Fermer(f1);
    Fermer(f2);
    Fermer(f3);
    Fermer(f4);
    Fermer(f5);
    Fermer(f6);
    Sleep(2000);
    Color(10,0);
    printf("\n\tFragmentation terminee! Merci de consulter votre dossier.\n");
    break;
    }

    case 8:
    {
    system("cls");
    int x = 1;

    printf("\n\n\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+\n"
           "\t\t\t\t\t\t\t|R|E|P|R|E|S|E|N|T|A|T|I|O|N| |G|R|A|P|H|I|Q|U|E|\n"
           "\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+\n");
    f=Ouvrir("PERSONNEL-ANP_DZ.bin",'a');
    printf("\n\n\nMatricule  |       Nom       |     Prenom     |Date naissance|       Willaya       | G-S |          Grade          |       Force militaire        |     Region  \n\n\n");
    printf("\t  TETE  \n"
           "\t  |  |   \n"
           "\t  |  |   \n"
           "\t _|__|_  \n"
           "\t \\    /   \n"
           "\t  \\  /    \n"
           "\t   \\/     \n");
    while(x<=3){
    LireDir(f,x,&buf);
    cout_lecture++;
    Color(15,0);

    printf("     _______________\n"
           "    | Bloc numero %d |\n",x);
    printf("______________________________________________________________________________________________________________________________________________________________________\n");
    x++;
    for(j=1; j<buf.nb; j++){
        Color(10,0);
        printf("%-10d | %-15.15s | %-15.15s | %.2d/%.2d/%.4d | %-20s | %-3s | %-23s | %-28s | %-17s \n",
               buf.t[j].matricule, buf.t[j].nom, buf.t[j].prenom, buf.t[j].date_de_naissance.jour, buf.t[j].date_de_naissance.mois,
               buf.t[j].date_de_naissance.annee, Wilaya_Naissance[buf.t[j].wilaya_de_naissance], Groupe_Sanguin[buf.t[j].groupe_sanguin], Grade[buf.t[j].grade],
               Force_Armee[buf.t[j].force_militaire], Region_Militaire[buf.t[j].region]);

    }
    Color(15,0);
    printf("______________________________________________________________________________________________________________________________________________________________________\n");
    printf("\t Suivant  \n"
           "\t  |  |   \n"
           "\t  |%d |   \n"
           "\t _|__|_  \n"
           "\t \\    /   \n"
           "\t  \\  /    \n"
           "\t   \\/     \n", buf.suiv);

    }
    break;
    }

    default:
        printf("Ce choix ne figure pas dans le menu!\n Veuillez choisir une autre fois");
}
// Affichage a la fin du programme
Color(15,0);
printf("\n\nLES COUTS: \n COUT DE LECTURES: %-4d   \n COUT D'ECRITURE:  %-4d\n",cout_lecture,cout_ecriture);
Color(10,0);
printf("\n\n\t\tVoulez vous:");
printf("\t\t\t1- Continuer \t\t 2- Sortir\n");
scanf("%d",&continu);
system("cls");
}
creation_index("index.bin",NE+nb,tab);//mise ajour du fichier index
printf("\n\n");
Color(15,0);
printf("\n\n\t\t\t\t\t\t\t\t\tFIN DU PROGRAMME\n\n\n\n\t\t\t\t\t\t\t\tVOTRE COUT DE LECTURE TOTALE: %d\n\n\t\t\t\t\t\t\t\tVOTRE COUT D'ECRITURE TOTALE: %d\n\n\n\n\n\n\n",cout_lecture,cout_ecriture);
Color(10,0);
printf("\n\n\n\n\n\n\t\t\t\t_  _ ____ ____ ____ _    ___  ____ _  _ ____    _  _ ____ ___ ____ ____    ____ ___ ___ ____ _  _ ___ _ ____ _  _ \n"
       "\t\t\t\t|\\/| |___ |__/ |    |    |__] |  | |  | |__/    |  | |  |  |  |__/ |___    |__|  |   |  |___ |\\ |  |  | |  | |\\ | \n"
       "\t\t\t\t|  | |___ |  \\ |___ |    |    |__| |__| |  \\     \\/  |__|  |  |  \\ |___    |  |  |   |  |___ | \\|  |  | |__| | \\| \n");
Color(15,0);
printf("\n\n\n\n\t\t\t\t\t\t\tDigne Heritiere de l'Armee de Liberation Nationale\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
return 0;
}
