global	ft_atoi_base
extern	ft_strlen
section	.text

ft_atoi_base:
				jmp	check_base_init

check_base_init:
				xor	r12, r12
				mov	r14, base
				mov	byte [r14], 0
				xor	r9, r9
				jmp	check_base

check_base:
				mov r13b, BYTE [rsi + r12]
				cmp	r13b, 0
				je	base_end
				jmp	alrd_set

alrd_set:
				cmp	BYTE [r14 + r9], 0
				je	next_base
				cmp	r13b, BYTE [r14 + r9]
				je	ret_zero
				inc	r9
				jmp	alrd_set

next_base:
				mov	BYTE [r14 + r9], r13b
				mov	BYTE [r14 + r9 + 1], 0
				xor	r9, r9
				inc	r12
				jmp	check_base

base_end:
				cmp r12, 1
				jle	ret_zero
				jmp	skip_spaces

skip_spaces:
				mov	r13, rdi
				xor	r8, r8
				jmp	loop_cmp_spc

loop_cmp_spc:
				cmp	byte [r13 + r8], ' '
				jz	loop_inc
				cmp	byte [r13 + r8], 0x0c
				jz	loop_inc
				cmp	byte [r13 + r8], 0x0a
				jz	loop_inc
				cmp	byte [r13 + r8], 0x0d
				jz	loop_inc
				cmp	byte [r13 + r8], 0x09
				jz	loop_inc
				cmp	byte [r13 + r8], 0x0b
				jz	loop_inc
				jmp	count_sign

loop_inc:
				inc	r8
				jmp	loop_cmp_spc

count_sign:
				xor	r15, r15
				jmp	loop_cmp_sign

loop_cmp_sign:
				cmp	byte [r13 + r8], '+'
				jz	loop_inc_sign
				cmp	byte [r13 + r8], '-'
				jz	sign_inc
				jmp	atoi_init

loop_inc_sign:
				inc	r8
				jmp	loop_cmp_sign

sign_inc:
				inc	r15
				jmp	loop_inc_sign

atoi_init:
				mov	rdi, r13
				call	ft_strlen
				cmp	rax, 0
				jz	ret_zero
				xor	r9, r9
				xor	rax, rax
				jmp	base_index

base_index:
				cmp	byte[r13 + r8], 0
				je	ret_nbr
				cmp	byte[r14 + r9], 0
				je	ret_nbr
				mov	r11b, byte[r13 + r8]
				cmp	byte[r14 + r9], r11b
				je	add_nbr
				inc r9
				jmp base_index

add_nbr:
				mul	r12
				add	rax, r9
				inc	r8
				xor r9, r9
				jmp	base_index

ret_zero:
				mov	rax, 0
				ret

ret_nbr:
				cmp	r15, 0
				jnz	calc_sign
				ret

calc_sign:
				push	rax
				mov	rax, r15
				mov	r15, 2
				div	r15
				cmp	rdx, 1
				je	ret_neg
				pop	rax
				ret

ret_neg:
				pop	rax
				neg	rax
				ret

section .bss
base:		resb	128
