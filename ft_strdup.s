%ifdef os_mac

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

%endif

%ifdef os_linux

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
			call malloc
			mov	rsi, r8
			mov	rdi, rax
			call ft_strcpy
			mov	rax, rdi
			ret

%endif
