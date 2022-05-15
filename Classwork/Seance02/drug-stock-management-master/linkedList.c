#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "store.h"
#include "linkedList.h"
#define MAX_ID 1000
// static int id = 0;



// Initie la liste chaînée
List *initList(Medicament *drug)
{
    List *list = malloc(sizeof(*list));
    Item *item = malloc(sizeof(*item));

    if (list == NULL || item == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // Medicament medoc;
    // initMedicament(&medoc);
    item->medicament = *drug;
    item->next = NULL;
    list->first = item;

    return list;
}

// Initie la liste chaînée
List *initListByFile(FILE *FMED)
{
    FILE *fichier = fopen("db/FMED.txt", "r");
    int i=0;
    List *list = malloc(sizeof(*list));
    Item *item = malloc(sizeof(*item));
    Medicament drug;
    char dateFormated[12], datefFormated[12], texte[256];

    if (list == NULL || item == NULL)
    {
        exit(EXIT_FAILURE);
    }
    while(fgets(texte, 255, fichier) != 0){
        sscanf(texte, "%d\t%s\t%s\t%s\t%s\t%s\t%f\t%d\t%s\t%s\t%d\t%s\t%s\t%d\t%s\t%s\t%d\t%s\t%s\t%d\t%s\t%s\t%d\n", &drug.numM, drug.nomM, drug.lab, drug.lt.ref, datefFormated, dateFormated, &drug.px, &drug.Qstock, drug.fr1.nomF, drug.fr1.adr, &drug.fr1.tel, drug.fr2.nomF, drug.fr2.adr, &drug.fr2.tel, drug.fr3.nomF, drug.fr3.adr, &drug.fr3.tel, drug.fr4.nomF, drug.fr4.adr, &drug.fr4.tel, drug.fr5.nomF, drug.fr5.adr, &drug.fr5.tel);
        sscanf(datefFormated, "%d/%d/%d", &drug.lt.dtf.jr, &drug.lt.dtf.mo, &drug.lt.dtf.an);
        sscanf(dateFormated, "%d/%d/%d", &drug.lt.dtp.jr, &drug.lt.dtp.mo, &drug.lt.dtp.an);
        if(i==0){
            list = initList(&drug);
        }else{
            insertItem(list, &drug);
        }
        i++;
    }
    fclose(fichier);
    return list;
}

// Vérifie si la liste contient déja le médicament
int containItem(List *list, Medicament drug){
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Item *actuel = list->first;

    while(actuel != NULL && (strcmp(actuel->medicament.nomM , drug.nomM) != 0) ){
        actuel = actuel->next;
    }
    
    if(actuel != NULL){
        return true;
    }else{
        return false;
    }
}
// Vérifie si la liste contient déja le médicament
int containRefLot(List *list, Medicament drug){
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Item *actuel = list->first;
    while(actuel != NULL && (strcmp(actuel->medicament.lt.ref, drug.lt.ref) != 0)){
        actuel = actuel->next;
    }
    
    if(actuel != NULL){
        return true;
    }else{
        return false;
    }
}

// Insère un Medicament en début de liste
void insertItem(List *list, Medicament *drug)
{
    /* Création du nouvel élément */
    Item *new = malloc(sizeof(*new));
    if (list == NULL || new == NULL)
    {
        exit(EXIT_FAILURE);
    }
    if(containItem(list, *drug) && containRefLot(list, *drug)){
        listIncrement(list, *drug);
    }else{
        new->medicament = *drug;
        /* Insertion de l'élément au début de la list */
        new->next = list->first;
        list->first = new;
    }
}

//Incrémente un médicament dans la liste
void listIncrement(List *list, Medicament drug){
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Item *actuel = list->first;
    while(actuel != NULL && actuel->medicament.numM != drug.numM){
        actuel = actuel->next;
    }
    if(actuel != NULL){
        actuel->medicament.Qstock = actuel->medicament.Qstock + 1;
    }
}

// Afiche la liste des médicaments
void printDrugs(List *list)
{
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Item *current = list->first;

    printf("---------------------------------------------------------------------------------------------------------------------------");
    printf("\nNum\tNom\tLab\tRefLot\tDate Préemption\tPrix\tQuantité\n");
    printf("---------------------------------------------------------------------------------------------------------------------------\n");

    while (current != NULL)
    {
        char buffer[200];   
        printf("%s", displayDrug(&current->medicament, buffer));
        current = current->next;
    }
}

// Afiche la liste des médicaments en repture de stock
void printDrugsOff(List *list)
{
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Item *current = list->first;

    printf("---------------------------------------------------------------------------------------------------------------------------");
    printf("\nNum\tNom\tLab\tRefLot\tDate Préemption\tPrix\tQuantité\n");
    printf("---------------------------------------------------------------------------------------------------------------------------\n");

    while (current != NULL)
    {
        char buffer[200];
        if(current->medicament.Qstock == 0){
            printf("%s", displayDrug(&current->medicament, buffer));
        }
        current = current->next;
    }
}

// Afiche la liste des médicaments commençant par un nom
void printDrugsWithName(List *list, char *name)
{
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Item *current = list->first;

    printf("---------------------------------------------------------------------------------------------------------------------------");
    printf("\nNum\tNom\tLab\tRefLot\tDate Préemption\tPrix\tQuantité\n");
    printf("---------------------------------------------------------------------------------------------------------------------------\n");
    while (current != NULL){
        char buffer[200];
        if(startWith(current->medicament.nomM, name)){
            printf("%s", displayDrug(&current->medicament, buffer));
        }
        current = current->next;
    }
}

//  Vérifie sous la chaine commence par la sous-chaine
int startWith(char *string, char *subString){
    int sousChainePointer;
    if(strstr(string, subString) != NULL){
        sousChainePointer = *(strstr(string, subString));
        if(*string == sousChainePointer){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

// Retourne un Médicament grace à son numéro
Medicament getDrugById(List *list, int id){
    if(list == NULL)
        exit(EXIT_FAILURE);

    Item *actuel  = list->first;

    while (actuel != NULL && actuel->medicament.numM != id){
        actuel = actuel->next;
    }

    if(actuel == NULL)
    {
        Medicament drug;
        initMedicament(&drug);
        return drug;
    }
    else
        return actuel->medicament;
    
}

// Retourne un Médicament grace à son nom
Medicament getDrugByName(List *list, char *name){
    if(list == NULL)
        exit(EXIT_FAILURE);

    Item *actuel  = list->first;
    while (actuel != NULL && strcmp(actuel->medicament.nomM, name) != 0){
        actuel = actuel->next;
    }

    if(actuel == NULL)
    {
        Medicament drug;
        initMedicament(&drug);
        return drug;
    }
    else
        return actuel->medicament;
    
}
    
//  Affiche les informations sur un médicament
char *displayDrug(const Medicament *drug, char *buffer){
    char dateFormated[100];
    sprintf(dateFormated, "%d/%d/%d", drug->lt.dtp.jr, drug->lt.dtp.mo, drug->lt.dtp.an);
    sprintf(buffer,"%d\t%s\t%s\t%s\t%s\t%f\t%d\n",drug->numM, drug->nomM, drug->lab, drug->lt.ref, dateFormated, drug->px, drug->Qstock);

    return buffer;
}

//  Affiche toutes les informations sur un médicament
char *displayDrugAll(const Medicament *drug, char *buffer){
    char dateFormated[100], datefFormated[100], fr1Formated[100], fr2Formated[100], fr3Formated[100], fr4Formated[100], fr5Formated[100];
    if(strcmp(drug->fr1.nomF, "") != 0)
        sprintf(fr1Formated, "%s\t%s\t%d", drug->fr1.nomF, drug->fr1.adr, drug->fr1.tel);
    else
        sprintf(fr1Formated, "NULL");
    if(strcmp(drug->fr2.nomF, "") != 0)
        sprintf(fr2Formated, "%s\t%s\t%d", drug->fr2.nomF, drug->fr2.adr, drug->fr2.tel);
    else
        sprintf(fr2Formated, "NULL");
    if(strcmp(drug->fr3.nomF, "") != 0)
        sprintf(fr3Formated, "%s\t%s\t%d", drug->fr3.nomF, drug->fr3.adr, drug->fr3.tel);
    else
        sprintf(fr3Formated, "NULL");
    if(strcmp(drug->fr4.nomF, "") != 0)
        sprintf(fr4Formated, "%s\t%s\t%d", drug->fr4.nomF, drug->fr4.adr, drug->fr4.tel);
    else
        sprintf(fr4Formated, "NULL");
    if(strcmp(drug->fr5.nomF, "") != 0)
        sprintf(fr5Formated, "%s\t%s\t%d", drug->fr5.nomF, drug->fr5.adr, drug->fr5.tel);
    else
        sprintf(fr5Formated, "NULL");

    sprintf(datefFormated, "%d/%d/%d", drug->lt.dtf.jr, drug->lt.dtf.mo, drug->lt.dtf.an);
    sprintf(dateFormated, "%d/%d/%d", drug->lt.dtp.jr, drug->lt.dtp.mo, drug->lt.dtp.an);
    sprintf(buffer,"%d\t%s\t%s\t%s\t%s\t%s\t%f\t%d\t%s\t%s\t%s\t%s\t%s\n",drug->numM, drug->nomM, drug->lab, drug->lt.ref, datefFormated, dateFormated, drug->px, drug->Qstock, fr1Formated, fr2Formated, fr3Formated, fr4Formated, fr5Formated);
    return buffer;
}

//Sauvegarde le fichier dans le liste de fichier
void save(List *list) {
    if (list == NULL)
        exit(EXIT_FAILURE);

    FILE *folderFMED = NULL, *folderID = NULL;

    folderFMED = fopen("db/FMED.txt", "w+");
    folderID = fopen("db/id.txt", "w");

    if (folderFMED == NULL)
        exit(EXIT_FAILURE);

    Item *item = list->first;

    do{
        char buffer[200];
        fprintf(folderFMED,"%s", displayDrugAll(&item->medicament, buffer));
        item = item->next;
    }while (item->next != NULL);

    // Sauvegarde du dernier item ainsi que l'id
    char buf[200];
    fprintf(folderFMED,"%s", displayDrugAll(&item->medicament, buf));
    fprintf(folderID, "%d", list->first->medicament.numM + 1);

    
    fclose(folderFMED);
    fclose(folderID);
}

// Ajoute un médicament à la liste
void ajouterMed(List *list){
    Medicament *tempMedicament = malloc(sizeof(*tempMedicament));
    int nombreFournisseur;
    printf("Nom: ");
    scanf("%s", tempMedicament->nomM);
    printf("Laboratoire: ");
    scanf("%s", tempMedicament->lab);
    printf("Prix du medicament: ");
    scanf("%f", &tempMedicament->px);
    printf("Reférence du lot: ");
    scanf("%s", tempMedicament->lt.ref);
    printf("Numéro du secteur de stockage: ");
    scanf("%d", &tempMedicament->S_stc);
    printf("Quantité du médicament à ajouter: ");
    scanf("%d", &tempMedicament->Qstock);
    printf("\n---Date de fabrication---\n\n");
    printf("Jour de fabrication: ");
    scanf("%d", &tempMedicament->lt.dtf.jr);
    printf("Mois de fabrication: ");
    scanf("%d", &tempMedicament->lt.dtf.mo);
    printf("Année de fabrication: ");
    scanf("%d", &tempMedicament->lt.dtf.an);
    printf("\n---Date de peremption---\n\n");
    printf("Jour de peremption: ");
    scanf("%d", &tempMedicament->lt.dtp.jr);
    printf("Mois de peremption: ");
    scanf("%d", &tempMedicament->lt.dtp.mo);
    printf("Année de peremption: ");
    scanf("%d", &tempMedicament->lt.dtp.an);
    printf("Nombre de fournisseur: ");
    scanf("%d", &nombreFournisseur);
    Medicament drug = createDrug(tempMedicament->lab, tempMedicament->nomM, tempMedicament->px, tempMedicament->Qstock, tempMedicament->S_stc, tempMedicament->lt);
    
    if(nombreFournisseur > 0){
        printf("Nom du fournisseur 1: ");
        scanf("%s", drug.fr1.nomF);
        printf("Adresse du fournisseur 1: ");
        scanf("%s", drug.fr1.adr);
        printf("Numero de telephone du fournisseur 1: ");
        scanf("%d", &drug.fr1.tel);
    }
    if(nombreFournisseur > 1){
        printf("\\nNom du fournisseur 2: ");
        scanf("%s", drug.fr2.nomF);
        printf("Adresse du fournisseur 2: ");
        scanf("%s", drug.fr2.adr);
        printf("Numero de telephone du fournisseur 2: ");
        scanf("%d", &drug.fr3.tel);
    }
    if(nombreFournisseur > 2){
        printf("\\nNom du fournisseur 3: ");
        scanf("%s", drug.fr3.nomF);
        printf("Adresse du fournisseur 3: ");
        scanf("%s", drug.fr3.adr);
        printf("Numero de telephone du fournisseur 3: ");
        scanf("%d", &drug.fr3.tel);
    }
    if(nombreFournisseur > 4){
        printf("\\nNom du fournisseur 4: ");
        scanf("%s", drug.fr4.nomF);
        printf("Adresse du fournisseur 4: ");
        scanf("%s", drug.fr4.adr);
        printf("Numero de telephone du fournisseur 4: ");
        scanf("%d", &drug.fr4.tel);
    }
    if(nombreFournisseur > 4){
        printf("\\nNom du fournisseur 5: ");
        scanf("%s", drug.fr5.nomF);
        printf("Adresse du fournisseur 5: ");
        scanf("%s", drug.fr5.adr);
        printf("Numero de telephone du fournisseur 5: ");
        scanf("%d", &drug.fr5.tel);
    }
    insertItem(list, &drug);
}

//Permet de servir une ordonance
void servePrescription(List *list){
    List *MedocsList;
    int nbMedocs, idMedoc, nbMedoc, erreur = 0;
    double total = 0;
    printf("\nTest\n");
    Medicament tempMedicament;
    printf("\nCombien de medicament le client achète t'il?: ");
    scanf("%d", &nbMedocs);
    for(int i=1; i<=nbMedocs; i++){
        printf("\nNuméro du médicament %d : ", i);
        scanf("%d", &idMedoc);
        tempMedicament = getDrugById(list, idMedoc);
        if(strcmp(tempMedicament.nomM, "MedicamentNull") == 0){
            printf("\nMedicament inconu");
            erreur = 1;
            break;
        }
        printf("\nQuatité à acheter: ");
        scanf("%d", &nbMedoc);
        if(tempMedicament.Qstock < nbMedoc){
            printf("\nLa quantité demandé est supérieur à la quantité disponible");
            erreur = 1;
            break;
        }
        tempMedicament.Qstock = nbMedoc;
        if(i==1){   //Si on est au premier tour on inicie la liste avec le médicament
            MedocsList = initList(&tempMedicament);
        }else{  //Sinon on ajoute le médicament
            insertItem(MedocsList, &tempMedicament);
        }
    }
    if(erreur == 1){
        printf("\nUne erreur s'est produite veuillez resaisir l'ordonnance!");
    }else{
        system("clear");
        printf("Ordonnance:\n");
        printf("-----------------------------------------------");
        printf("\nNum\tNom\tQuantité\tPrix Unitaire\n");
        printf("-----------------------------------------------");
        Item *actuel = MedocsList->first;
        while(actuel != NULL){
            printf("\n%d\t%s\t%d\t%f", actuel->medicament.numM, actuel->medicament.nomM, actuel->medicament.Qstock, actuel->medicament.px);
            total = total + (actuel->medicament.Qstock * actuel->medicament.px);
            Item *actuel2 = list->first;
            while(actuel2 != NULL){
                if(actuel->medicament.numM == actuel2->medicament.numM){
                    actuel2->medicament.Qstock = actuel2->medicament.Qstock - actuel->medicament.Qstock;    //si on achète un médicament, on diminue sa quantité dans la
                }
                actuel2 = actuel2->next;
            }
            actuel = actuel->next;
        }
        printf("\n\n\t\t\tTOTAL: %f TND", total);
    }
}

// Vérifie si un médicament est périmé
int isExpired(Medicament *drug){
    time_t now = time(NULL);
    time(&now);
    struct tm *local = localtime(&now);
    int day = local->tm_mday, month = local->tm_mon + 1, year = local->tm_year + 1900;
    if(drug->lt.dtp.an < year){
            return true;
        }else if(drug->lt.dtp.an == year){
            if(drug->lt.dtp.mo < month){
                return true;
            }else if(drug->lt.dtp.mo == month){
                if(drug->lt.dtp.jr <= day){
                    return true;
                }
            }
        }
    return 0;
}

//Affiche les médicaments périmé
void printExpiredDrugs(List *list){
    Item *actuel = list->first;
    system("clear");
    printf("Affichage des medicaments périmes:\n");
    printf("-----------------------------------------------");
    printf("\nNom\tLot\tZone de stockage\tQuatité\n");
    printf("-----------------------------------------------");
    while(actuel != NULL){
        if(isExpired(&actuel->medicament)){
            printf("\n%s\t%s\t%d\t%d", actuel->medicament.nomM, actuel->medicament.lt.ref, actuel->medicament.S_stc, actuel->medicament.Qstock);
        }
        actuel = actuel->next;
    }
}

// Suprime le premier élément de la liste
void deleteItem(List *list, int id)
{
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Item *actuel = list->first, *prec;
    int erreur = 0;
    while(actuel != NULL){
        if(actuel->medicament.numM == id){
            if(isExpired(&actuel->medicament) || actuel->medicament.Qstock == 0){
                prec->next = actuel->next;
                free(actuel);
                break;
            }else{
                erreur = 1;
                printf("\nLe médicament ne peut être suprime");
            }
        }
        prec = actuel;
        actuel = actuel->next;
    }

    if(actuel == NULL){
        if(!erreur){
            printf("\nMedicament inconu");
        }
    }else{
        printf("\nLe medicament numero %d a bien été suprime", id);
    }
}
//Retourne l'identifiant suivant
int getId(){
    int id = 0;
    FILE *folder = NULL;
    folder = fopen("db/id.txt","r");
    
    if(folder == NULL)
        printf("File Error");
    
    char value[MAX_ID] = "";
    
    fgets(value, MAX_ID, folder);
    if(strcmp(value,"")){
        id = atoi(value);
    }
    else{
        printf("%s", value);
    }
    fclose(folder);
    FILE *floder = fopen("db/id.txt", "w");
    fprintf(folder, "%d", id+1);
    fclose(floder);
    return id;
}