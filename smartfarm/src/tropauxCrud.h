void ajouter_Nouv_tropaux(tropaux t);
int exist_tropaux(char*id);
tropaux trouver_tropaux(char*id);
void modifier_tropaux(char*id,char*zone,char*veterinaire,char*signe,int nbVaccin);
void supprimer_tropaux(char*id);
void afficher_tropaux(GtkWidget* treeview1,char*l);
/*********************/
int rechercher_tropaux_par_type(GtkWidget* treeview1,char*l,char*type);







