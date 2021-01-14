%ifdef os_mac
global	_ft_read
extern	___error
section	.text

_ft_read:
			mov	rax, 0x2000003
			syscall
			cmp	rax, 0
			jle	ret_error
			ret

ret_error:
			neg	rax
			mov	r8, rax
			call	___error
			mov	[rax], r8
			mov	rax, -1
			ret

%endif
%ifdef os_linux

global	ft_read
extern	__errno_location
section	.text

ft_read:	xor	rax, rax
			syscall
			cmp	rax, 0
			jle	_error
			ret

_error:
			neg	rax
			mov	r8, rax
			call	__errno_location wrt ..plt
			mov	[rax], r8
			mov	rax, -1
			ret

%endif
