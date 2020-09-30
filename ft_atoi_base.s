global	ft_atoi_base
extern	ft_strlen
section	.text

ft_atoi_base:
				push	rdi
				mov	rdi, rsi
				call ft_strlen
				mov	r12, rax	;r12 = ft_strlen
				pop	rdi
				xor	r8, r8	;init counters and nbr
				xor	r9, r9
				xor	r10, r10
				jmp	base_index

base_index:
				cmp	byte[rdi + r8], 0
				je	ret_nbr
				cmp	byte[rsi + r9], 0
				je	ret_nbr
				mov	r11b, byte[rdi + r8]
				cmp	byte[rsi + r9], r11b
				je	add_nbr
				inc r9
				jmp base_index

add_nbr:
				mov rax, r10
				mov	rdx, r12
				mul	rax
				add	rax, r9
				mov	r10, rax
				inc	r8
				xor r9, r9
				jmp	base_index

ret_nbr:
				mov	rax, r10
				ret
