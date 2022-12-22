//implementation de la structure----------------------------------
//les table en MC pour l'affichege
char *Wilaya_Naissance[58] = {"Adrar", "Chlef", "Laghouat", "Oum El Bouaghi", "Batna", "Bejaia", "Biskra", "Bechar",
                            "Blida", "Bouira", "Tamanrasset", "Tebessa", "Tlemcen", "Tiaret", "Tizi Ouzou", "Alger",
                            "Djelfa", "Jijel", "Setif", "Saida", "Skikda", "Sidi Bel Abbes", "Annaba", "Guelma", "Constantine",
                            "Medea", "M'Sila", "Mostaganem", "Masacra", "Ouargla", "Oran", "El Bayadh", "Illizi", "Bordj Bou Arreridj",
                            "Boumerdes", "El Tarf", "Tindouf", "Tissemesilt", "El Oued", "Khenchela", "Souk Ahras", "Tipaza", "Mila",
                            "Ain Defla", "Naama", "Ain Timouchent", "Ghardaia", "Relizane", "Timimoun", "Bordj Badji Mokhtar",
                            "Ouled Djellal", "Beni Abbes", "In Salah", "In Guezzam", "Touggourt", "Djanet", "M'Ghair", "El Meniaa"};

char *Groupe_Sanguin[8] = {"O+", "A+", "B+", "O-", "A-", "AB+", "B-", "AB-"};

char *Grade[17] = {"General corps d'armee", "General-Major", "General", "Colonel", "Lieutenant-colonel", "Commandant",
                   "Capitaine", "Lieutenant", "Sous-lieutenant", "Aspirant", "Adjudant-chef", "Adjudant", "Sergent-chef",
                   "Sergent", "Caporal-chef", "Caporal", "Djoundi"};

char *Force_Armee[8] = {"Armee de terre", "Armee de l'air", "Marine nationale", "Defense aerienne territoire",
                        "Gendarmerie nationale", "Garde republicaine", "D.R.S",
                        "Sante militaire"};

char *Region_Militaire[6] = {"1RM-Blida", "2RM-Oran", "3RM-Bechar", "4RM-Ouargla", "5RM-Constantine", "6RM-Tamanrasset"};



int leap(int year){//fonction qui dit si une annee est bisextille ou non
if (year%400==0){
    return 1;
}else if(year%100==0){
return 0;}else
if (year%4==0){
return 1;}else{
return 0;}
}

//procédures fondamentaux---------------------------------------
void chargem_init(char*nomf,int Nb,TENREG*tab){//chargement initial d'un fichier avec nb enregistrements + remplire une table d index en sortie
int i,j,l,k;
i=1;
j=1;
l=1;
fichg*f;
Tbloc buf;
Tenrg e;
f=Ouvrir(nomf,'a');
int lower = 111111, upper = 999999;//cette etape est necessaire pour generer un matricule unique(notre solution est basée sur une caractéristique des nombres premiers)
int num = (rand() % (upper - lower + 1)) + lower;
for(k=1;k<Nb;k++){
    if (num > 999999){
            num = lower + (num % upper);
            }
    e.matricule=num;
              num += PRIMARY;

    tab[l].cle=e.matricule;
    tab[l].num_bloc=i;
    tab[l].num_enreg=j;
    tab[l].efface=0;
    l++;
    strcpy(e.nom,randname(random(4,30)));
    strcpy(e.prenom,randname(random(4,30)));
    e.date_de_naissance.mois=random(1,12);
    e.date_de_naissance.annee=random(1945,2003);
    if(e.date_de_naissance.mois==2 && leap(e.date_de_naissance.annee)==1){
        e.date_de_naissance.jour=random(1,29);
    }
    if(e.date_de_naissance.mois==2 && leap(e.date_de_naissance.annee)==0){
                    e.date_de_naissance.jour=random(1,28);}


        if(e.date_de_naissance.mois==4 || e.date_de_naissance.mois==6 ||e.date_de_naissance.mois==9 || e.date_de_naissance.mois==11){
        e.date_de_naissance.jour=random(1,30);
        }else{
            e.date_de_naissance.jour=random(1,31);
        }


            e.wilaya_de_naissance=random(0,57);
            e.groupe_sanguin=random(0,7);
            e.region=random(0,5);
            e.force_militaire=random(0,7);
            e.grade=random(0,16);

  if(j<88){
    buf.t[j]=e;
    j++;

  }else{
  buf.nb=j-1;
  buf.suiv=i+1;
  EcrireDir(f,i,buf);
  i++;
 buf.t[1]=e;

  j=2;


  }
}
buf.nb=j-1;
buf.suiv=-1;
EcrireDir(f,i,buf);
Aff_entete(f,1,i);
Aff_entete(f,2,Nb);

Fermer(f);
}



void quicksort(TENREG number[],int first,int last){//tri par fusion recursive (compléxité de O(nlog n))
   int i, j, pivot;
   TENREG temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(number[i].cle<=number[pivot].cle&&i<last)
         i++;
         while(number[j].cle>number[pivot].cle)
         j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);
   }
}

void creation_index(char*nomf,int nb,TENREG*tab){ //creation du fichier d index à partir d'une table d index

TOF*f;
TENREG e;
BUFFER buf;
int i=1,j=1,k;
f=ouvrir(nomf,'n');
//fermer(f);
//f=ouvrir(nomf,'a');
int l=1;
for(k=1;k<nb;k++){
    e.cle=tab[l].cle;
    e.num_bloc=tab[l].num_bloc;
    e.num_enreg=tab[l].num_enreg;
    l++;
    if(j<=88){
       buf.t[j]=e;
       j++;
    }else{
    buf.nb=j-1;
    ecriredir(f,i,buf);

    i++;
    buf.t[1]=e;
    j=2;

    }
}
  buf.nb=j-1;
   ecriredir(f,i,buf);
  Affentete(f,1,i);
  Affentete(f,2,nb);
  fermer(f);

}

void recherche_dichotomique(TENREG tableau[], int taille, int valeur,int*i,int*trouv){ //recherche dichotomique dans la table d index qui retourne en plus l indice du tableau ou la cle va exister
    *trouv=0;
	int borne_inf = 0;
	int borne_sup = taille - 1;

	int position_milieu;
	while( borne_inf < borne_sup )
	{
		position_milieu = borne_inf + ((borne_sup - borne_inf) / 2);

		//--- Variante : arrêt si élément trouvé au niveau du "milieu"...
		//               mais cela génère plus de tests !!!
		if( tableau[position_milieu].cle == valeur )
		{
			 *trouv=1;

			 *i=position_milieu;

		}
		//--- Fin de la variante

		if( tableau[position_milieu].cle < valeur )
		{
			borne_inf = position_milieu + 1;
		}
		else // tableau[position_milieu] >= valeur
		{
			borne_sup = position_milieu;
		}
	}

	int position_resultat = -1;
	if( tableau[borne_inf].cle == valeur )
	{
		*trouv=1;
		*i=borne_inf;

	}

}

//insertion
void insertion(char*nomf,Tenrg e,TENREG t[],int taille,int*cout_l,int* cout_ec){
fichg*f;
Tbloc buf,buf1;
TENREG en;
int nb,trouv;
int i;
recherche_dichotomique(t,taille,e.matricule,&nb,&trouv);
while(trouv==1 && t[nb].efface==0){
    Color(12,0);
    printf("\nCe matricule existe deja! \n\nVeuillez saisir un autre\n");
    scanf("%d",&e.matricule);
    recherche_dichotomique(t,taille,e.matricule,&nb,&trouv);

}if(trouv!=1 || (trouv==1 || t[nb].efface==1)){
f=Ouvrir(nomf,'a');
i=entete(f,1);
LireDir(f,i,&buf);
cout_l++;
if(buf.nb<88){
    buf.t[buf.nb+1]=e;
    buf.nb=buf.nb+1;
    Aff_entete(f,2,entete(f,2)+1);
   EcrireDir(f,i,buf);
   *cout_ec++;

}else{
buf.suiv=i+1;
EcrireDir(f,i,buf);
*cout_ec++;
i++;
Aff_entete(f,1,i);
buf1.t[0]=e;
buf1.nb=1;
buf1.suiv=-1;
    Aff_entete(f,2,entete(f,2)+1);

    EcrireDir(f,i,buf1);
    *cout_ec++;


}

int Nb=insertSorted(t,taille,e.matricule,i,buf.nb,350000);

}

Fermer(f);

printf_point(10);
Color(10,0);
printf("Insertion bien faite!\n");
}


//modification de la region d un enregistrement donnee
void modifier_region(char*nomf,int matricule,int  region,TENREG t[],int taille,int*cout_l,int *cout_ec){
int trouve,i,j,b;
fichg*f;
Tbloc buf;
Tenrg e;
f=Ouvrir(nomf,'a');
recherche_dichotomique(t,taille,matricule,&b,&trouve);
if(trouve==1 && t[b].efface==0){
    i=t[b].num_bloc;
    j=t[b].num_enreg;
    LireDir(f,i,&buf);

    e=buf.t[j];
    e.region=region;
    buf.t[j]=e;
    EcrireDir(f,i,buf);
    printf("\n\n");
    printf_point(10);
    Color(10,0);
    printf("\tModification enregistree\n");
}else{
    Color(12,0);
    printf("Matricule non trouve! \n");
}
Fermer(f);
}
//suppression par matricule
void supprimer(char*nomf,int matricule,TENREG t[],int taille,int *existe,int*supprime,int*cout_l,int*cout_ec){ //supprimer un enregistrement donné par son matricule
int trouve,b,i,j;
fichg*f;                                                       //taille: la taille de la table d index
Tbloc buf;
Tenrg e;
recherche_dichotomique(t,taille,matricule,&b,&trouve);
if(trouve==0){
    Color(12,0);
    printf("Ce matricule n'existe pas! \nEntrez un autre\n");
    *existe=0;
    *supprime=0;
}else{*existe=1;
       if(t[b].efface==1){
        printf("Ce matricule a ete deja supprime! \nEntrez un autre:\n");
        *supprime=1;
       }else{
           *supprime=0;
           f=Ouvrir(nomf,'a');
           LireDir(f,entete(f,1),&buf);
           *cout_l++;
           e=buf.t[buf.nb];
           if(buf.nb==1){
            Aff_entete(f,1,entete(f,1)-1);
           }
           buf.nb=buf.nb-1;
           EcrireDir(f,entete(f,1),buf);
           *cout_ec++;
           i=t[b].num_bloc;
           j=t[b].num_enreg;
           LireDir(f,i,&buf);
           *cout_l++;
           buf.t[j]=e;
           EcrireDir(f,i,buf);
           *cout_ec;
           t[b].efface=1;
           Aff_entete(f,2,entete(f,2)-1);
        Fermer(f);
        printf("\n\n");
        printf_point(10);
        Color(10,0);
        printf("\tSuppression terminee!\n");
       }
}

}

int insertSorted(TENREG arr[], int n,int key,int bloc,int enreg, int capacity){//inserer un element dans un tableau dans l ordre decroissant
    // Cannot insert more elements if n is already
    // more than or equal to capacity
    if (n >= capacity)
        return n;

    int i;
    TENREG e;
    e.cle = key;
    e.efface=0;
    e.num_bloc=bloc;
    e.num_enreg=enreg;
    for (i = n - 1; (i >= 0 && arr[i].cle > key); i--)
        arr[i + 1] = arr[i];

    arr[i + 1] = e;

    return (n + 1);
}

int AgeIntervalle(int min , int max){  // cette fonction calcule l'intervalle d'age
    if (min >= 1940 && min <= 2003 && max >= 1940 && min <= 2003 )
        return 1;
    return 0;
}

//fragmentation du fichier
void fragmentation(char* nomf,char*nomf1,char*nomf2,char*nomf3,char*nomf4,char*nomf5,char*nomf6){

int i,i1,i2,i3,i4,i5,i6;
i1=1;
i2=1;
i3=1;
i4=1;
i5=1;
i6=1;
i=1;
int j,j1,j2,j3,j4,j5,j6;
j2=1;
j3=1;
j4=1;
j5=1;
j6=1;
j=1;
j1=1;
Tbloc buf,buf1,buf2,buf3,buf4,buf5,buf6;
fichg*f;
fichg*f1;
fichg*f2;
fichg*f3;
fichg*f4;
fichg*f5;
fichg*f6;
f=Ouvrir(nomf,'a');
f1=Ouvrir(nomf1,'n');
f2=Ouvrir(nomf2,'n');
f3=Ouvrir(nomf3,'n');
f4=Ouvrir(nomf4,'n');
f5=Ouvrir(nomf5,'n');
f6=Ouvrir(nomf6,'n');
while(i<entete(f,1)){

    LireDir(f,i,&buf);

    for(j=1;j<buf.nb;j++){
        switch(buf.t[j].region){
        case 0:{
         if(j1<88){
            buf1.t[j1]=buf.t[j];
            j1++;
         }else{
         buf1.nb=j1-1;
         buf1.suiv=i1+1;
         EcrireDir(f1,i1,buf1);

         i1++;
         j1=2;

         }
         break;
        }
        case 1:{
        if(j2<88){
            buf2.t[j2]=buf.t[j];
            j2++;
         }else{
         buf2.nb=j2-1;
         buf2.suiv=i2+1;
         EcrireDir(f2,i2,buf2);

         i2++;
         j2=2;


        }
         break;
        }
        case 2:{
        if(j3<88){
            buf3.t[j3]=buf.t[j];
            j3++;
         }else{
         buf3.nb=j3-1;
         buf3.suiv=i3+1;
         EcrireDir(f3,i3,buf3);
         i3++;
         j3=2;


        }
        break;
    }
     case 3:{
     if(j4<88){
            buf4.t[j4]=buf.t[j];
            j4++;
         }else{
         buf4.nb=j4-1;
         buf4.suiv=i4+1;
         EcrireDir(f4,i4,buf4);
         i4++;
         j4=2;

     }
     break;
}
case 4:{
 if(j5<88){
            buf5.t[j5]=buf.t[j];
            j5++;
         }else{
         buf5.nb=j5-1;
         buf5.suiv=i5+1;
         EcrireDir(f5,i5,buf5);
         i5++;
         j5=2;

}
       break;
}
   case 5:{
   if(j6<88){
            buf6.t[j6]=buf.t[j];
            j6++;
         }else{
         buf6.nb=j6-1;
         buf6.suiv=i6+1;
         EcrireDir(f6,i6,buf6);
         i6++;
         j6=2;

   }
break;
}   }
}
i=buf.suiv;
}
buf1.nb=j1-1;
buf1.suiv=-1;
buf2.nb=j2-1;
buf2.suiv=-1;
buf3.nb=j3-1;
buf3.suiv=-1;
buf4.nb=j4-1;
buf4.suiv=-1;
buf5.nb=j5-1;
buf5.suiv=-1;
buf6.nb=j6-1;
buf6.suiv=-1;
EcrireDir(f1,i1,buf1);
EcrireDir(f2,i2,buf2);
EcrireDir(f3,i3,buf3);
EcrireDir(f4,i4,buf4);
EcrireDir(f5,i5,buf5);
EcrireDir(f6,i6,buf6);
Aff_entete(f1,1,i1);
Aff_entete(f2,1,i2);
Aff_entete(f3,1,i3);
Aff_entete(f4,1,i4);
Aff_entete(f5,1,i5);
Aff_entete(f6,1,i6);
Fermer(f);
Fermer(f1);
Fermer(f2);
Fermer(f3);
Fermer(f4);
Fermer(f5);
Fermer(f6);

}
//suppression de tous les enregistyrements d une force
void supprimer_force(char*nomf,int FA,int*cout_lect,int*cout_ecr,TENREG t[],int taille){
int  i,j,x=1,b,trouv;
fichg*f;
Tbloc temp,buf;
if(FA>=1 && FA<=8){
        f=Ouvrir(nomf,'a');
        while(x!=-1){
            //printf("\nBloc numero %d\n",x);
            LireDir(f,x,&buf);
            *cout_lect++;        //charger 1er bloc
            for(j=0; j<buf.nb; j++){
                //printf("\n%d\n",buf.t[j].force_militaire);
                if (buf.t[j].force_militaire == FA-1){
                    recherche_dichotomique(t,taille,buf.t[j].matricule,&b,&trouv);
                   t[b].efface=1;
                    buf.t[j] = buf.t[buf.nb-1];
                    buf.nb--;
                    j--;
                   // printf("%d \t | %-30s \t | %-30s \t | %d \t\n\n", buf.t[j].matricule, buf.t[j].nom, buf.t[j].prenom, buf.t[j].force_militaire);
                }
            }
            if (buf.nb == 0){
                LireDir(f,entete(f,1),&buf);
                *cout_lect++;
                Aff_entete(f,1,(entete(f,1)-1));
                EcrireDir(f,x,buf);
                *cout_ecr++;
                x--;
            }
            else
                Aff_entete(f,2,(entete(f,2)-1));
                EcrireDir(f,x,buf);
                *cout_ecr++;
            x=buf.suiv;
        }
    }
    else{
        Color(12,0);
        printf("Ce choix n'est pas valide!\n");
    }
    Fermer(f);

}
