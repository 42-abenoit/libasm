global	ft_strdup
extern	ft_strlen
extern	ft_strcpy
extern	malloc

section	.text

ft_strdup:	
			mov	rcx, rdi
			push	rcx
			call ft_strlen
			inc	rax
			mov	rdi, rax
			call malloc wrt ..plt
			pop	rcx
			mov	rdi, rcx
			mov	rsi, rax
			call ft_strcpy
			mov	rax, rsi
			ret
