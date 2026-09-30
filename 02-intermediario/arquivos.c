#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> 
 
void preenche (FILE *f){
   char inicial[50] = "Meu primeiro teste com arquivos";
   for (int i=0; i<strlen(inicial); i++){
      fputc(inicial[i], f);
   }
   fclose(f);
}  
 
void preencheS (FILE *f){
   char inicial[50] = "Meu segundo teste com arquivos";
   int retorno = fputs(inicial, f);
   if (retorno == EOF)
       printf("Erro ao gravar\n");
   fclose(f);
} 
 
void converte(FILE* f1, FILE* f2){

 char c = fgetc(f1);
    while (c != EOF)
    {
        fputc(toupper(c),f2);
        c = fgetc(f1);
    }
 
    fclose(f1);
    fclose(f2);
    system ("pause");

} 

void converteS(FILE* f1, FILE* f2){
   char str[100];
   
   char *res = fgets(str, 20, f1);
   
   if(res == NULL)
       printf("Erro na leitura\n");
   else{
       
       for (int i = 0; str[i] != '\0'; i++) {
            str[i] = toupper(str[i]);
    }
       
       int retorno = fputs(str, f2);
        if (retorno == EOF)
           printf("Erro ao gravar\n");
        fclose(f1);
   }    

}
int main()
{
    FILE *f1, *f2;
    f1 = fopen("minusculo.txt","w");
    f2 = fopen("maiusculo.txt","w");
    if (f1==NULL || f2==NULL)
    {
        printf("Erro na abertura\n");
        system("pause");
        exit(1);
    }
    
    preencheS(f1);
    
    f1 = fopen("minusculo.txt","r");
    
    converteS(f1, f2);
    
    
    return 0;
}