	.file	"basic.c"
	.globl	data
	.data
	.align 4
	.type	data, @object
	.size	data, 4
data:
	.long	10
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	movl	$20, 24(%esp)
	movl	$4, (%esp)
	call	malloc
	movl	%eax, 28(%esp)
	movl	28(%esp), %eax
	movl	$30, (%eax)
	call	getchar
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
