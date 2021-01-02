void ajouter_Nouv_ouvrier(ouvrier o);
int exist_ouvrier(char*id);
ouvrier trouver_ouvrier(char*id);
void modifier_ouvrier(char*id,char*permis,char*occupation,char*tel,char*email,char*adressePostale);
void afficher_ouvrier(GtkWidget* treeview1,char*l);
void supprimer_ouvrier(char*id);
void enregistrer_presence_ouvrier(absenteisme ab);
void afficher_single_ouvrier(ouvrier o,GtkWidget* treeview1);
void initializer_treeview_single_ouvrier(GtkWidget* treeview1);
