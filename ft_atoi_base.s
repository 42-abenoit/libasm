global	ft_atoi_base
section	.text

ft_atoi_base:
				jmp	check_base_init

check_base_init:
				xor	r12, r12
				xor	r14, r14
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
				inc	r12
				xor	r9, r9
				jmp	check_base

base_end:
				cmp r12, 1
				jle	ret_zero
				jmp	atoi_init

atoi_init:
				mov	r13, rdi
				xor	r8, r8		;init counters and nbr
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
				ret

section	.data
.FORBIDDEN	db	"-+' '\f\n\r\t\v"
