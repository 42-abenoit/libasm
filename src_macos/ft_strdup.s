global	_ft_strdup
extern	_ft_strlen
extern	_ft_strcpy
extern	_malloc

section	.text

_ft_strdup:	
			mov	r8, rdi
			call _ft_strlen
			inc	rax
			mov	rdi, rax
			call _malloc
			mov	rsi, r8
			mov	rdi, rax
			call _ft_strcpy
			mov	rax, rdi
			ret
