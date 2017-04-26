.text # Aqui empieza el segmento de codigo

.globl __start

__start:

la $a0, mens	#Ingrese un numero: 
li $v0, 4
syscall

li $v0,5
syscall 	# recibir un entero por teclado
li $t1,0
li $t2,1
addi $t4,$v0,0 	#$t4 = contador

la $a0, mens_2  # La sucecion de fibonacci es:
li $v0 , 4
syscall

fibonacci:
add $t3,$t1,$t2 # cambiamos los valores
addi $t1,$t2,0
addi $t2,$t3,0
addi $t4,$t4,-1 # contador = contador + (-1)

li $v0,1
addi $a0,$t1,0
syscall 	# imprimir valor
beqz $t4,fin  	# imprimir un "," para mayor estetica
la $a0, jump
li $v0, 4
syscall
j fibonacci

fin:
li $v0,10
syscall 	# terminar programa

.data
jump: .asciiz ","
mens: .asciiz "Ingrese un numero: "
mens_2: .asciiz "La sucesion de fibonacci es: "
