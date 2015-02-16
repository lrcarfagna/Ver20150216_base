#include <stdio.h>
#include <stdlib.h>

#define N_VALORI_DA_INSERIRE 7
#define VALORE_MASSIMO 3

float potenza(int base, int esponente);
void aggiornaFrequenza(int frequenze[], int valore);

int main(int argc, char** argv) {
    int b, e;
    float p;
    int i;
    int frequenze[VALORE_MASSIMO+1];
    int v;
    
    // ---- Sezione 1
    printf("Inserisci la base (numero relativo): ");
    scanf("%d", &b);
    
    printf("Inserisci l'esponente (numero relativo): ");
    scanf("%d", &e);
    
    p = potenza(b, e);
    printf("%d^%d=%f\n", b, e, p);
    
    // ---- Sezione 2
    // Inizializzazione del vettore delle frequenze
    for(i=0; i<VALORE_MASSIMO+1; i++)
        frequenze[i] = 0;
    
    // Inserimento dei valori
    printf("\nInserisci %d numeri da 0 a %d (inclusi)\n", N_VALORI_DA_INSERIRE, VALORE_MASSIMO);
    for(i=0; i<N_VALORI_DA_INSERIRE; i++) {
        printf("Inserisci il %do valore: ", i+1);
        scanf("%d", &v);
        aggiornaFrequenza(frequenze, v);
    }
    
    // Stampa delle frequenze
    for(i=0; i<VALORE_MASSIMO+1; i++) {
        printf("Hai inserito il valore %d per %d volte\n", i, frequenze[i]);
    }
    
    return (EXIT_SUCCESS);
}

/*
 * Calcola la potenza.
 * Sia base che esponente sono un numero relativo (negativo, nullo o positivo).
 * NOTA: considera 0^0=1
 */
float potenza(int base, int esponente) {
    
    int i;
    int numeratore=1;
    int denominatore=base;
    
    float risultato=(float)base;
    
    if(esponente==0) risultato=1;
    else{
        if(esponente>0)
            for(i=1;i<esponente;i++) 
               risultato=risultato*base;
        else{
            if(esponente<0){
                esponente*=-1;
                for(i=1;i<esponente;i++) denominatore=denominatore*base;
                risultato=(float)numeratore/denominatore;
            }
    
    
        }
    
    return risultato;
    }
}

/*
 * Calcola la frequenza di un determinato valore, incrementando di 1 quanto
 * contenuto nella posizione valore.
 * 
 * Esempio:
 * valore = 2
 * Se frequenze[2] vale 1 prima della chiamata, allora frequenze[2] varrà 2 
 * dopo la chiamata.
 */
void aggiornaFrequenza(int frequenze[], int valore) {
    
    int i;
    for(i=0;i<N_VALORI_DA_INSERIRE;i++) if(i==valore) frequenze[i]++;
    return;
    
}
