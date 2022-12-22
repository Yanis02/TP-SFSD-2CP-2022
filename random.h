//fonctions aleatoires//
//1----------------------------
int random(int min,int max){//generer un nombre aleatoirement entre deux valeurs min et max
int x=max-min+1;
int   r=rand();
int y=(r%x)+min;
return y;}
//2-------------------------------
char*randname(int nb){// generer un nom aleatoire qui a nb caractères
int i;
int j;
char*name=malloc(nb+1);
char Chr1[26] = "abcdefghijklmnopqrstuvwxyz";
for(i=0;i<nb;i++){
 j=random(1,25);
  *(name+i)=Chr1[j];
}
name[i]= '\0';
return (name);
}
//3---------------------------------

char* randwilaya(int i){//generer un nom de wilaya à partir d'un nombre donné
char wilayas[]="Adrar/Chlef/Laghouat/OumElBouagui/Batna/Bejaia/Biskra/Bechar/Blida/Bouira/Tamenrasset/Tebessa/Tlemcen/Tiaret/Tizi Ouzou/Alger/Djelfa/Jijel/Setif/Saida/Skikda/Sidi Belabbes/Annaba/Guelma/Constantine/Medea/Mostaganem/M'sila/Mascara/Ouergla/Oran/El-bayadh/Illizi/B.B.Arreridj/Boumerdas/El Tarf/Tindouf/Tissemsilet/El Oued/Khenchla/Souk Ahras/Tipaza/Mila/Ain Defla/Naama/Ain Temouchent/Ghardaia/Relizane";
const char d[2]="/";
char*ville=strtok(wilayas,d);
for (int j=1;j<i;j++){
 ville=strtok(NULL,d);
}
return ville;
}
//4-----------------------------------
char* randgrps(int i){//generer un groupe sanguin à partir d'un nombre donné
char groupes[]="O+/A+/B+/O-/A-/AB+/B-/AB-";
const char d[2]="/";
char*sang=strtok(groupes,d);
for (int j=1;j<i;j++){
 sang=strtok(NULL,d);
}
return sang;
}
//5-----------------------------------------
char* randgrade(int i){//generer un grade à partir d'un nombre donné
char grades[]="general de corps d'armee/general-major/general/colonel/lieutenant-colonel/commandant/capitaine/lieutenant/sous-lieutenant/aspirant/adjudant-chef/adjudant/sergent-chef/sergent/caporal-chef/caporal/djoundi";
const char d[2]="/";
char*grade=strtok(grades,d);
for (int j=1;j<i;j++){
 grade=strtok(NULL,d);
}
return grade;
}
//6------------------------------------------
char* randforce(int i){//generer une force armée à partir d'un nombre donné
char forces[]="armee de terre/armee de l'air/marine nationale/defense aerienne du territoire/gendarmerie nationale/garde republicaine/departement du renseignement et de la securite/sante militaire";
const char d[2]="/";
char*force=strtok(forces,d);
for (int j=1;j<i;j++){
 force=strtok(NULL,d);
}
return force;
}
//7-----------------------------------------------
char* randregion(int i){ //generer une region militaire à partir d'un nombre donné
char regions[]="1RM-Blida/2RM-Oran/3RM-Bechar/4RM-Ouargla/5RM-Constantine/6RM-Tamenraset";
const char d[2]="/";
char*region=strtok(regions,d);
for (int j=1;j<i;j++){
 region=strtok(NULL,d);
}
return region;
}
