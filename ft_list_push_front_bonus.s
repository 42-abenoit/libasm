global	ft_list_push_front
section	.text

ft_list_push_front:
					mov	r8,	[rsi]
					mov	rsi, r8
					mov rsi, rsi
					ret