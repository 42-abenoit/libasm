%ifdef os_mac

global	_ft_strdup
extern	_ft_strlen
extern	_ft_strcpy
extern	_malloc

section	.text

_ft_strdup:	
			push	r8
			mov	r8, rdi
			push	r8
			call _ft_strlen
			pop		r8
			inc	rax
			mov	rdi, rax
			push	r8
			call _malloc
			pop		r8
			cmp		rax, 0
			jz		end
			mov	rsi, r8
			mov	rdi, rax
			push	r8
			call _ft_strcpy
			pop		r8
			mov	rax, rdi
			mov	rdi, r8
			jmp	end

end:
			pop		r8
			ret

%endif

%ifdef os_linux

global	ft_strdup
extern	ft_strlen
extern	ft_strcpy
extern	malloc

section	.text

ft_strdup:	
			push	r8
			mov	r8, rdi
			push	r8
			call ft_strlen
			pop		r8
			inc	rax
			mov	rdi, rax
			push	r8
			call malloc
			pop		r8
			cmp		rax, 0
			jz		end
			mov	rsi, r8
			mov	rdi, rax
			push	r8
			call ft_strcpy
			pop		r8
			mov	rax, rdi
			mov	rdi, r8
			jmp	end

end:
			pop		r8
			ret

%endif
