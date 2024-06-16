#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{   
    void escolha (int *mochila);
    int *mochila;
 
    printf("----------[OPÇÕES]----------");
    mochila = (int *) malloc (3 * sizeof (int));
    escolha(mochila);
    getchar();
    
    return 0;
}

void escolha (int *mochila)
{
    void ordenar(int *vetor);
    void salvar_mochila(int *vetor);
    
    printf("\nEscolha três itens:\n[1] - Oculos\n[2] - Agua\n[3] - Sanduiche\n[4] - Celular\n[5] - GameBoy ");
    
    for(int u = 1; u < 4; u++){
        
        printf("\nEscolha o %dº item ", u);
        scanf("%d", &mochila[u-1]);
    }
    ordenar(mochila);
    salvar_mochila(mochila);
}

void ordenar(int *vetor)
{
    int key, j;
    
    for(int i =1; i<3; i++)
    {
        key = vetor[i];
        j = i-1;
        while( key < vetor[j] && j >=0)
        {
            vetor[j + 1] = vetor[j];
            j--;
            
        }
        vetor[j+1] = key;    
    
    }
    
}

void salvar_mochila(int *vetor)
{
    FILE *p;
    p = fopen("save", "a");
    
    for(int i =0; i <3; i++)
    {
        
        switch(vetor[i]){
            case 1:
                fprintf(p, "óculos\n");
                break;
            case 2:
                fprintf(p, "água\n");
                break;
            case 3:
                fprintf(p, "Sanduiche\n");
                break;
            case 4:
                fprintf(p, "Celular\n");
                break;
            case 5:
                fprintf(p, "GameBoy\n");
                break;    
        }
        
    }
    fclose (p);
}
