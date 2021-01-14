extern	___error
global	_ft_write

section	.text
_ft_write:
			push	rsi
			mov		rsi, 0x0
			mov	rax, 0x20000BD
			syscall
			cmp rax, 9
			pop		rsi
			jz ret_error
			mov	rax, 0x2000004
			syscall
			cmp	rax, 0
			jl	ret_error
   			ret

ret_error:
			neg	rax
			push	rax
			call	___error
			pop	rax
			mov	rax, -1
			ret
