#include <stdio.h>
#include <string.h>

#include "fila_prioridade.h"
#include "tad_teste.h"

int main(){

    Teste* t1 = teste_criar("Teste da FILA");
    char str[200];
    TipoElemento elemento;
    bool resultado;


    /**************************************
    * Testes
    **************************************/
    FilaPrioridade* f = filaP_criar();
    filaP_inserir(f, 1);
    filaP_inserir(f, 2);
    filaP_inserir(f, 3);
    filaP_inserir(f, 4);
    filaP_inserir(f, 5);
    filaP_inserir(f, 6);
    filaP_inserir(f, 7);
    filaP_toString(f, str);
    teste_verificar(t1, strcmp(str, "[7,6,5,4,3,2,1]")==0, "Teste 1");
    filaP_destruir(&f);

    teste_verificar(t1, f == NULL, "Teste 2");

    f = filaP_criar();
    filaP_inserir(f, 5);
    filaP_inserir(f, 4);
    filaP_inserir(f, 3);
    filaP_inserir(f, 2);
    filaP_inserir(f, 1);
    filaP_toString(f, str);
    teste_verificar(t1, strcmp(str, "[5,4,3,2,1]")==0, "Teste 3");
    filaP_destruir(&f);

    f = filaP_criar();
    filaP_inserir(f, 10);
    filaP_inserir(f, 20);
    filaP_inserir(f, 15);
    filaP_inserir(f, 8);
    filaP_inserir(f, 5);
    filaP_inserir(f, 30);
    filaP_inserir(f, 22);
    filaP_toString(f, str);
    teste_verificar(t1, strcmp(str, "[30,22,20,15,10,8,5]")==0, "Teste 4");
    filaP_destruir(&f);
    

   f = filaP_criar();
    filaP_inserir(f, 10);
    filaP_inserir(f, 20);
    filaP_inserir(f, 15);
    filaP_inserir(f, 8);
    filaP_inserir(f, 5);
    filaP_inserir(f, 30);
    filaP_inserir(f, 22);
    filaP_toString(f, str);
    teste_verificar(t1, strcmp(str, "[30,22,20,15,10,8,5]")==0, "Teste 5");



    filaP_remover(f, &elemento);
    teste_verificar(t1, elemento == 30, "Teste 6");
    filaP_remover(f, &elemento);
    teste_verificar(t1, elemento == 22, "Teste 7");
    filaP_remover(f, &elemento);
    teste_verificar(t1, elemento == 20, "Teste 8");
    filaP_remover(f, &elemento);
    teste_verificar(t1, elemento == 15, "Teste 9");
    filaP_remover(f, &elemento);
    teste_verificar(t1, elemento == 10, "Teste 10");
    filaP_remover(f, &elemento);
    teste_verificar(t1, elemento == 8, "Teste 11");

    resultado = filaP_remover(f, NULL);
    teste_verificar(t1, resultado == false, "Teste 12");

    filaP_remover(f, &elemento);
    teste_verificar(t1, elemento == 5, "Teste 13");

    resultado = filaP_remover(f, &elemento);
    teste_verificar(t1, resultado == false, "Teste 14");
    resultado = filaP_remover(NULL, &elemento);
    teste_verificar(t1, resultado == false, "Teste 15");
    resultado = filaP_remover(f, NULL);
    teste_verificar(t1, resultado == false, "Teste 16");


    
    teste_relatorio(t1);    
    teste_desalocar(&t1);
    

}