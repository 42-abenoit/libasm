%ifdef	os_mac

extern	___error
global	_ft_write

section	.text
_ft_write:
			push	rsi
			mov		rsi, 0x0
			mov	rax, 0x20000BD
			syscall
			pop		rsi
			cmp rax, 9
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

%endif

%ifdef os_linux

extern	__errno_location
global	ft_write

section	.text
ft_write:
			push	r8
			push	rsi
			mov		rsi, 0x0
			mov	rax, 0x05
			syscall
			pop		rsi
			cmp rax, 9
			jz ret_error
			mov	rax, 0x01
			syscall
			cmp	rax, 0
			jl	ret_error
			pop		r8
			ret

ret_error:
			neg		rax
			mov		r8, rax
			call	__errno_location
			mov		[rax], r8
			mov		rax, -1
			pop		r8
			ret

%endif
