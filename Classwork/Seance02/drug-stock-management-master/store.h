#ifndef MINI_PROJET_H_INCLUDED
#define MINI_PROJET_H_INCLUDED

typedef struct{
    int jr;
    int mo;
    int an;
}Date;

typedef struct{
    char ref[10];
    Date dtf;
    Date dtp;
}Lot;

typedef struct {
    char nomF[20];
    char adr[30];
    int tel;
}Fournisseur;

typedef struct{

    int numM;
    char lab[20];
    char nomM[30];
    float px;
    int Qstock;
    int S_stc;
    Lot lt;
    Fournisseur fr1;
    Fournisseur fr2;
    Fournisseur fr3;
    Fournisseur fr4;
    Fournisseur fr5;

}Medicament;

// fonction utilitaire
int menu();

void initDate(Date *date);
void initLot(Lot *lot);
void initFournisseur(Fournisseur *fr);
Fournisseur createFournisseur(int tel, char adr[], char nomF[]);
void initMedicament(Medicament *drug);
Medicament createDrug(char labnomM[], char nomM[], float px, int QStock, int S_stc, Lot lt);
void  printProvider(Medicament *drug);
#endif // MINI_PROJET_H_INCLUDED

