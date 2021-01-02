int exist_annee(tabAnneeMoy*e,int n,int aa);
int remplir_annees(tabAnneeMoy*e,char*fich);
int maximum(tabAnneeMoy*e,int n);
float calculer_moy(int aa, char*fich);
int trouver_annee_plus_seche(char*fich);
/*********************/
int exist_ouvrier_tab(tabOuvrierAbs*e,int n,int id);
int remplir_tabOuvrier(tabOuvrierAbs*e,int aa);
int calculer_somme(char*id,int flag,int aa);
int maximum_abs(tabOuvrierAbs*e,int n);
ouvrier trouver_meilleur(int aa,int flag);
