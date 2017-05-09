.text
.globl __start

__start:

la $a0, A
la $a1, B
lw $t0, tam
l.d $f0, resul

loop:	beqz $t0, endloop
	l.d $f4, ($a0)
	l.d $f6, ($a1)
	mul.d $f2, $f4, $f6
	add.d $f0, $f0, $f2
	add $a0, $a0, 8
	add $a1, $a1, 8
	add $t0, $t0, -1
	j loop

endloop:

mov.d $f12, $f0
li $v0, 3
syscall

li $v0, 10
syscall

.data
A: .double 2.1, 3.3, 5.6
B: .double 0.2, 2.2, 3.9
tam: .word 3
resul: .double 0