all:
	gcc -c fila_prioridade_encadeada.c -o fila_prioridade_encadeada.o
	gcc main.c fila_prioridade_encadeada.o -o main
	./main