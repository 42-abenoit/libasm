global	ft_strdup
extern	ft_strlen
extern	ft_strcpy
extern	malloc

section	.text

ft_strdup:	
			mov	r8, rdi
			call ft_strlen
			inc	rax
			mov	rdi, rax
			call malloc wrt ..plt
			mov	rsi, r8
			mov	rdi, rax
			call ft_strcpy
			mov	rax, rdi
			ret
