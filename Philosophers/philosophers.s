	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15
	.globl	_ft_atoi                ## -- Begin function ft_atoi
	.p2align	4, 0x90
_ft_atoi:                               ## @ft_atoi
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	$0, -16(%rbp)
	movl	$1, -20(%rbp)
	movl	$0, -24(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax
	movslq	-24(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$9, %edx
	jl	LBB0_3
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movq	-8(%rbp), %rax
	movslq	-24(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$13, %edx
	movb	$1, %sil
	movb	%sil, -25(%rbp)         ## 1-byte Spill
	jle	LBB0_4
LBB0_3:                                 ##   in Loop: Header=BB0_1 Depth=1
	movq	-8(%rbp), %rax
	movslq	-24(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$32, %edx
	sete	%sil
	movb	%sil, -25(%rbp)         ## 1-byte Spill
LBB0_4:                                 ##   in Loop: Header=BB0_1 Depth=1
	movb	-25(%rbp), %al          ## 1-byte Reload
	testb	$1, %al
	jne	LBB0_5
	jmp	LBB0_6
LBB0_5:                                 ##   in Loop: Header=BB0_1 Depth=1
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	jmp	LBB0_1
LBB0_6:
	movq	-8(%rbp), %rax
	movslq	-24(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$43, %edx
	je	LBB0_8
## %bb.7:
	movq	-8(%rbp), %rax
	movslq	-24(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$45, %edx
	jne	LBB0_11
LBB0_8:
	movq	-8(%rbp), %rax
	movslq	-24(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$45, %edx
	jne	LBB0_10
## %bb.9:
	movl	$-1, -20(%rbp)
LBB0_10:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
LBB0_11:
	jmp	LBB0_12
LBB0_12:                                ## =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
	movb	%al, %cl
	movq	-8(%rbp), %rdx
	movslq	-24(%rbp), %rsi
	movsbl	(%rdx,%rsi), %eax
	cmpl	$48, %eax
	movb	%cl, -26(%rbp)          ## 1-byte Spill
	jl	LBB0_14
## %bb.13:                              ##   in Loop: Header=BB0_12 Depth=1
	movq	-8(%rbp), %rax
	movslq	-24(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$57, %edx
	setle	%sil
	movb	%sil, -26(%rbp)         ## 1-byte Spill
LBB0_14:                                ##   in Loop: Header=BB0_12 Depth=1
	movb	-26(%rbp), %al          ## 1-byte Reload
	testb	$1, %al
	jne	LBB0_15
	jmp	LBB0_16
LBB0_15:                                ##   in Loop: Header=BB0_12 Depth=1
	imulq	$10, -16(%rbp), %rax
	movq	-8(%rbp), %rcx
	movslq	-24(%rbp), %rdx
	movsbl	(%rcx,%rdx), %esi
	subl	$48, %esi
	movslq	%esi, %rcx
	addq	%rcx, %rax
	movq	%rax, -16(%rbp)
	movl	-24(%rbp), %esi
	addl	$1, %esi
	movl	%esi, -24(%rbp)
	jmp	LBB0_12
LBB0_16:
	movq	-16(%rbp), %rax
	movslq	-20(%rbp), %rcx
	imulq	%rcx, %rax
	movl	%eax, %edx
	movl	%edx, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_check_args             ## -- Begin function check_args
	.p2align	4, 0x90
_check_args:                            ## @check_args
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -16(%rbp)
	movl	$0, -20(%rbp)
LBB1_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_5 Depth 2
	movq	-16(%rbp), %rax
	movslq	-20(%rbp), %rcx
	cmpq	$0, (%rax,%rcx,8)
	je	LBB1_11
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	movq	-16(%rbp), %rax
	movslq	-20(%rbp), %rcx
	movq	(%rax,%rcx,8), %rax
	cmpb	$0, (%rax)
	jne	LBB1_4
## %bb.3:
	movl	$1, -4(%rbp)
	jmp	LBB1_12
LBB1_4:                                 ##   in Loop: Header=BB1_1 Depth=1
	movl	$0, -24(%rbp)
LBB1_5:                                 ##   Parent Loop BB1_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	-16(%rbp), %rax
	movslq	-20(%rbp), %rcx
	movq	(%rax,%rcx,8), %rax
	movslq	-24(%rbp), %rcx
	cmpb	$0, (%rax,%rcx)
	je	LBB1_10
## %bb.6:                               ##   in Loop: Header=BB1_5 Depth=2
	movq	-16(%rbp), %rax
	movslq	-20(%rbp), %rcx
	movq	(%rax,%rcx,8), %rax
	movslq	-24(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$48, %edx
	jl	LBB1_8
## %bb.7:                               ##   in Loop: Header=BB1_5 Depth=2
	movq	-16(%rbp), %rax
	movslq	-20(%rbp), %rcx
	movq	(%rax,%rcx,8), %rax
	movslq	-24(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$57, %edx
	jle	LBB1_9
LBB1_8:
	movl	$1, -4(%rbp)
	jmp	LBB1_12
LBB1_9:                                 ##   in Loop: Header=BB1_5 Depth=2
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	jmp	LBB1_5
LBB1_10:                                ##   in Loop: Header=BB1_1 Depth=1
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -20(%rbp)
	jmp	LBB1_1
LBB1_11:
	movl	$0, -4(%rbp)
LBB1_12:
	movl	-4(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_fill_params            ## -- Begin function fill_params
	.p2align	4, 0x90
_fill_params:                           ## @fill_params
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movl	$0, -60(%rbp)
LBB2_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$5, -60(%rbp)
	jge	LBB2_3
## %bb.2:                               ##   in Loop: Header=BB2_1 Depth=1
	movl	-60(%rbp), %eax
	movl	%eax, %ecx
	addl	$1, %ecx
	movl	%ecx, -60(%rbp)
	movslq	%eax, %rdx
	movl	$-1, -32(%rbp,%rdx,4)
	jmp	LBB2_1
LBB2_3:
	movl	$0, -60(%rbp)
LBB2_4:                                 ## =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
	movb	%al, %cl
	cmpl	$5, -60(%rbp)
	movb	%cl, -61(%rbp)          ## 1-byte Spill
	jge	LBB2_6
## %bb.5:                               ##   in Loop: Header=BB2_4 Depth=1
	movq	-48(%rbp), %rax
	movslq	-60(%rbp), %rcx
	cmpq	$0, (%rax,%rcx,8)
	setne	%dl
	movb	%dl, -61(%rbp)          ## 1-byte Spill
LBB2_6:                                 ##   in Loop: Header=BB2_4 Depth=1
	movb	-61(%rbp), %al          ## 1-byte Reload
	testb	$1, %al
	jne	LBB2_7
	jmp	LBB2_10
LBB2_7:                                 ##   in Loop: Header=BB2_4 Depth=1
	movq	-48(%rbp), %rax
	movslq	-60(%rbp), %rcx
	movq	(%rax,%rcx,8), %rdi
	callq	_ft_atoi
	movslq	-60(%rbp), %rcx
	movl	%eax, -32(%rbp,%rcx,4)
	movslq	-60(%rbp), %rcx
	cmpl	$0, -32(%rbp,%rcx,4)
	jne	LBB2_9
## %bb.8:
	movl	$1, -36(%rbp)
	jmp	LBB2_11
LBB2_9:                                 ##   in Loop: Header=BB2_4 Depth=1
	movl	-60(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -60(%rbp)
	jmp	LBB2_4
LBB2_10:
	movl	-32(%rbp), %eax
	movq	-56(%rbp), %rcx
	movl	%eax, (%rcx)
	movl	-28(%rbp), %eax
	movq	-56(%rbp), %rcx
	movl	%eax, 4(%rcx)
	movl	-24(%rbp), %eax
	movq	-56(%rbp), %rcx
	movl	%eax, 8(%rcx)
	movl	-20(%rbp), %eax
	movq	-56(%rbp), %rcx
	movl	%eax, 12(%rcx)
	movl	-16(%rbp), %eax
	movq	-56(%rbp), %rcx
	movl	%eax, 24(%rcx)
	movq	-56(%rbp), %rcx
	movl	$0, 28(%rcx)
	movq	-56(%rbp), %rcx
	movl	$0, 32(%rcx)
	movl	$0, -36(%rbp)
LBB2_11:
	movl	-36(%rbp), %eax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	movl	%eax, -68(%rbp)         ## 4-byte Spill
	jne	LBB2_13
## %bb.12:
	movl	-68(%rbp), %eax         ## 4-byte Reload
	addq	$80, %rsp
	popq	%rbp
	retq
LBB2_13:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_check_params           ## -- Begin function check_params
	.p2align	4, 0x90
_check_params:                          ## @check_params
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -16(%rbp)
	movq	-16(%rbp), %rdi
	cmpl	$0, 24(%rdi)
	jne	LBB3_2
## %bb.1:
	movl	$1, -4(%rbp)
	jmp	LBB3_10
LBB3_2:
	movq	-16(%rbp), %rax
	cmpl	$1, (%rax)
	jl	LBB3_4
## %bb.3:
	movq	-16(%rbp), %rax
	cmpl	$200, (%rax)
	jle	LBB3_5
LBB3_4:
	movl	$1, -4(%rbp)
	jmp	LBB3_10
LBB3_5:
	movq	-16(%rbp), %rax
	cmpl	$60, 4(%rax)
	jl	LBB3_8
## %bb.6:
	movq	-16(%rbp), %rax
	cmpl	$60, 8(%rax)
	jl	LBB3_8
## %bb.7:
	movq	-16(%rbp), %rax
	cmpl	$60, 12(%rax)
	jge	LBB3_9
LBB3_8:
	movl	$1, -4(%rbp)
	jmp	LBB3_10
LBB3_9:
	movl	$0, -4(%rbp)
LBB3_10:
	movl	-4(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_get_current_time       ## -- Begin function get_current_time
	.p2align	4, 0x90
_get_current_time:                      ## @get_current_time
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	xorl	%eax, %eax
	movl	%eax, %esi
	leaq	-16(%rbp), %rdi
	callq	_gettimeofday
	imulq	$1000, -16(%rbp), %rsi  ## imm = 0x3E8
	movl	-8(%rbp), %ecx
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	cltd
	movl	$1000, %ecx             ## imm = 0x3E8
	idivl	%ecx
	movslq	%eax, %rdi
	addq	%rdi, %rsi
	movq	%rsi, %rax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_ft_usleep              ## -- Begin function ft_usleep
	.p2align	4, 0x90
_ft_usleep:                             ## @ft_usleep
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	callq	_get_current_time
	movslq	-4(%rbp), %rsi
	addq	%rsi, %rax
	movq	%rax, -24(%rbp)
LBB5_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-24(%rbp), %rax
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	callq	_get_current_time
	xorl	%ecx, %ecx
	movb	%cl, %dl
	movq	-32(%rbp), %rsi         ## 8-byte Reload
	cmpq	%rax, %rsi
	movb	%dl, -33(%rbp)          ## 1-byte Spill
	jbe	LBB5_4
## %bb.2:                               ##   in Loop: Header=BB5_1 Depth=1
	xorl	%eax, %eax
	movb	%al, %cl
	cmpq	$0, -16(%rbp)
	movb	%cl, -33(%rbp)          ## 1-byte Spill
	je	LBB5_4
## %bb.3:                               ##   in Loop: Header=BB5_1 Depth=1
	movq	-16(%rbp), %rax
	cmpl	$0, 32(%rax)
	setne	%cl
	xorb	$-1, %cl
	movb	%cl, -33(%rbp)          ## 1-byte Spill
LBB5_4:                                 ##   in Loop: Header=BB5_1 Depth=1
	movb	-33(%rbp), %al          ## 1-byte Reload
	testb	$1, %al
	jne	LBB5_5
	jmp	LBB5_6
LBB5_5:                                 ##   in Loop: Header=BB5_1 Depth=1
	movl	$50, %edi
	callq	_usleep
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	jmp	LBB5_1
LBB5_6:
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_init_forks             ## -- Begin function init_forks
	.p2align	4, 0x90
_init_forks:                            ## @init_forks
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	%edi, -12(%rbp)
	movslq	-12(%rbp), %rax
	shlq	$6, %rax
	movq	%rax, %rdi
	callq	_malloc
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	LBB6_2
## %bb.1:
	movq	$0, -8(%rbp)
	jmp	LBB6_11
LBB6_2:
	movl	$0, -16(%rbp)
LBB6_3:                                 ## =>This Inner Loop Header: Depth=1
	movl	-16(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jge	LBB6_10
## %bb.4:                               ##   in Loop: Header=BB6_3 Depth=1
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	-24(%rbp), %rcx
	movslq	-16(%rbp), %rdx
	shlq	$6, %rdx
	addq	%rdx, %rcx
	movq	%rcx, %rdi
	callq	_pthread_mutex_init
	cmpl	$0, %eax
	je	LBB6_9
## %bb.5:
	jmp	LBB6_6
LBB6_6:                                 ## =>This Inner Loop Header: Depth=1
	movl	-16(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -16(%rbp)
	cmpl	$0, %eax
	jl	LBB6_8
## %bb.7:                               ##   in Loop: Header=BB6_6 Depth=1
	movq	-24(%rbp), %rax
	movslq	-16(%rbp), %rcx
	shlq	$6, %rcx
	addq	%rcx, %rax
	movq	%rax, %rdi
	callq	_pthread_mutex_destroy
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	jmp	LBB6_6
LBB6_8:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	callq	_free
	movq	$0, -8(%rbp)
	jmp	LBB6_11
LBB6_9:                                 ##   in Loop: Header=BB6_3 Depth=1
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	jmp	LBB6_3
LBB6_10:
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
LBB6_11:
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_assign_forks           ## -- Begin function assign_forks
	.p2align	4, 0x90
_assign_forks:                          ## @assign_forks
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	movl	$0, -24(%rbp)
LBB7_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-24(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jge	LBB7_3
## %bb.2:                               ##   in Loop: Header=BB7_1 Depth=1
	movq	-16(%rbp), %rax
	movslq	-24(%rbp), %rcx
	shlq	$6, %rcx
	addq	%rcx, %rax
	movq	-8(%rbp), %rcx
	movslq	-24(%rbp), %rdx
	imulq	$56, %rdx, %rdx
	addq	%rdx, %rcx
	movq	%rax, 16(%rcx)
	movq	-16(%rbp), %rax
	movl	-24(%rbp), %esi
	addl	$1, %esi
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	movl	%esi, %eax
	cltd
	idivl	-20(%rbp)
	movslq	%edx, %rcx
	shlq	$6, %rcx
	movq	-32(%rbp), %rdi         ## 8-byte Reload
	addq	%rcx, %rdi
	movq	-8(%rbp), %rcx
	movslq	-24(%rbp), %r8
	imulq	$56, %r8, %r8
	addq	%r8, %rcx
	movq	%rdi, 24(%rcx)
	movl	-24(%rbp), %edx
	addl	$1, %edx
	movl	%edx, -24(%rbp)
	jmp	LBB7_1
LBB7_3:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_create_philo           ## -- Begin function create_philo
	.p2align	4, 0x90
_create_philo:                          ## @create_philo
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	movl	-20(%rbp), %edx
	movq	-8(%rbp), %rsi
	movl	%edx, (%rsi)
	movl	-20(%rbp), %eax
	cltd
	movl	$2, %ecx
	idivl	%ecx
	movq	-8(%rbp), %rsi
	movl	%edx, 4(%rsi)
	movq	-16(%rbp), %rsi
	movq	16(%rsi), %rsi
	movq	-8(%rbp), %rdi
	movq	%rsi, 32(%rdi)
	movq	-8(%rbp), %rsi
	movl	$0, 40(%rsi)
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rdi
	movq	%rsi, 48(%rdi)
	movq	-8(%rbp), %rsi
	movq	$0, 16(%rsi)
	movq	-8(%rbp), %rsi
	movq	$0, 24(%rsi)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_init_philos            ## -- Begin function init_philos
	.p2align	4, 0x90
_init_philos:                           ## @init_philos
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	movq	-16(%rbp), %rdi
	movslq	(%rdi), %rdi
	imulq	$56, %rdi, %rdi
	callq	_malloc
	movq	%rax, -32(%rbp)
	cmpq	$0, -32(%rbp)
	jne	LBB9_2
## %bb.1:
	movq	$0, -8(%rbp)
	jmp	LBB9_6
LBB9_2:
	movl	$0, -20(%rbp)
LBB9_3:                                 ## =>This Inner Loop Header: Depth=1
	movl	-20(%rbp), %eax
	movq	-16(%rbp), %rcx
	cmpl	(%rcx), %eax
	jge	LBB9_5
## %bb.4:                               ##   in Loop: Header=BB9_3 Depth=1
	movq	-32(%rbp), %rax
	movslq	-20(%rbp), %rcx
	imulq	$56, %rcx, %rcx
	addq	%rcx, %rax
	movq	-16(%rbp), %rsi
	movl	-20(%rbp), %edx
	movq	%rax, %rdi
	callq	_create_philo
	movl	-20(%rbp), %edx
	addl	$1, %edx
	movl	%edx, -20(%rbp)
	jmp	LBB9_3
LBB9_5:
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
LBB9_6:
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_write_message          ## -- Begin function write_message
	.p2align	4, 0x90
_write_message:                         ## @write_message
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rsi
	movq	48(%rsi), %rsi
	addq	$40, %rsi
	movq	%rsi, %rdi
	callq	_pthread_mutex_lock
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	callq	_get_current_time
	movq	-8(%rbp), %rsi
	movq	48(%rsi), %rsi
	subq	16(%rsi), %rax
	movq	-8(%rbp), %rsi
	movl	(%rsi), %ecx
	addl	$1, %ecx
	movq	-16(%rbp), %rsi
	leaq	L_.str(%rip), %rdi
	movq	%rsi, -32(%rbp)         ## 8-byte Spill
	movq	%rax, %rsi
	movl	%ecx, %edx
	movq	-32(%rbp), %rcx         ## 8-byte Reload
	movb	$0, %al
	callq	_printf
	movq	-8(%rbp), %rcx
	movq	48(%rcx), %rcx
	addq	$40, %rcx
	movq	%rcx, %rdi
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	callq	_pthread_mutex_unlock
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_action                 ## -- Begin function action
	.p2align	4, 0x90
_action:                                ## @action
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	movq	%rcx, -32(%rbp)
	movq	%r8, -40(%rbp)
	cmpq	$0, -32(%rbp)
	je	LBB11_2
## %bb.1:
	movq	-32(%rbp), %rdi
	callq	_pthread_mutex_lock
	movq	-8(%rbp), %rdi
	leaq	L_.str.1(%rip), %rsi
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	callq	_write_message
LBB11_2:
	cmpq	$0, -40(%rbp)
	je	LBB11_4
## %bb.3:
	movq	-40(%rbp), %rdi
	callq	_pthread_mutex_lock
	movq	-8(%rbp), %rdi
	leaq	L_.str.1(%rip), %rsi
	movl	%eax, -48(%rbp)         ## 4-byte Spill
	callq	_write_message
LBB11_4:
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	callq	_write_message
	cmpl	$0, -20(%rbp)
	jle	LBB11_6
## %bb.5:
	movl	-20(%rbp), %edi
	movq	-8(%rbp), %rax
	movq	48(%rax), %rsi
	callq	_ft_usleep
LBB11_6:
	cmpq	$0, -40(%rbp)
	je	LBB11_8
## %bb.7:
	movq	-40(%rbp), %rdi
	callq	_pthread_mutex_unlock
	movl	%eax, -52(%rbp)         ## 4-byte Spill
LBB11_8:
	cmpq	$0, -32(%rbp)
	je	LBB11_10
## %bb.9:
	movq	-32(%rbp), %rdi
	callq	_pthread_mutex_unlock
	movl	%eax, -56(%rbp)         ## 4-byte Spill
LBB11_10:
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_routine                ## -- Begin function routine
	.p2align	4, 0x90
_routine:                               ## @routine
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	-16(%rbp), %rdi
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rdi
	movq	48(%rdi), %rdi
	movq	%rdi, -32(%rbp)
	movq	-24(%rbp), %rdi
	cmpl	$0, 4(%rdi)
	jne	LBB12_2
## %bb.1:
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	-24(%rbp), %rdi
	movq	-32(%rbp), %rdx
	movl	8(%rdx), %edx
	leaq	L_.str.2(%rip), %rsi
	movq	%rcx, -40(%rbp)         ## 8-byte Spill
	movq	-40(%rbp), %r8          ## 8-byte Reload
	callq	_action
LBB12_2:
	jmp	LBB12_3
LBB12_3:                                ## =>This Inner Loop Header: Depth=1
	movq	-24(%rbp), %rdi
	movq	-32(%rbp), %rax
	movl	8(%rax), %edx
	movq	-24(%rbp), %rax
	movq	24(%rax), %rcx
	movq	-24(%rbp), %rax
	movq	16(%rax), %r8
	leaq	L_.str.3(%rip), %rsi
	callq	_action
	callq	_get_current_time
	xorl	%edx, %edx
	movl	%edx, %ecx
	movq	-24(%rbp), %rsi
	movq	%rax, 32(%rsi)
	movq	-24(%rbp), %rax
	movl	40(%rax), %edx
	addl	$1, %edx
	movl	%edx, 40(%rax)
	movq	-24(%rbp), %rdi
	movq	-32(%rbp), %rax
	movl	12(%rax), %edx
	leaq	L_.str.4(%rip), %rsi
	movq	%rcx, -48(%rbp)         ## 8-byte Spill
	movq	-48(%rbp), %r8          ## 8-byte Reload
	callq	_action
	xorl	%edx, %edx
	xorl	%r9d, %r9d
	movl	%r9d, %eax
	movq	-24(%rbp), %rdi
	leaq	L_.str.2(%rip), %rsi
	movq	%rax, %rcx
	movq	%rax, %r8
	callq	_action
	jmp	LBB12_3
	.cfi_endproc
                                        ## -- End function
	.globl	_start_simulation       ## -- Begin function start_simulation
	.p2align	4, 0x90
_start_simulation:                      ## @start_simulation
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	$0, -16(%rbp)
LBB13_1:                                ## =>This Inner Loop Header: Depth=1
	movl	-16(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jge	LBB13_3
## %bb.2:                               ##   in Loop: Header=BB13_1 Depth=1
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	-8(%rbp), %rcx
	movslq	-16(%rbp), %rdx
	imulq	$56, %rdx, %rdx
	addq	%rdx, %rcx
	addq	$8, %rcx
	movq	-8(%rbp), %rdx
	movslq	-16(%rbp), %rdi
	imulq	$56, %rdi, %rdi
	addq	%rdi, %rdx
	movq	%rcx, %rdi
	leaq	_routine(%rip), %rcx
	movq	%rdx, -24(%rbp)         ## 8-byte Spill
	movq	%rcx, %rdx
	movq	-24(%rbp), %rcx         ## 8-byte Reload
	callq	_pthread_create
	movl	-16(%rbp), %r8d
	addl	$1, %r8d
	movl	%r8d, -16(%rbp)
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	jmp	LBB13_1
LBB13_3:
	movl	$0, -16(%rbp)
LBB13_4:                                ## =>This Inner Loop Header: Depth=1
	movl	-16(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jge	LBB13_6
## %bb.5:                               ##   in Loop: Header=BB13_4 Depth=1
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	-8(%rbp), %rcx
	movslq	-16(%rbp), %rdx
	imulq	$56, %rdx, %rdx
	addq	%rdx, %rcx
	movq	8(%rcx), %rdi
	callq	_pthread_join
	movl	-16(%rbp), %r8d
	addl	$1, %r8d
	movl	%r8d, -16(%rbp)
	movl	%eax, -32(%rbp)         ## 4-byte Spill
	jmp	LBB13_4
LBB13_6:
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$368, %rsp              ## imm = 0x170
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -308(%rbp)
	movl	%edi, -312(%rbp)
	movq	%rsi, -320(%rbp)
	cmpl	$6, -312(%rbp)
	jg	LBB14_2
## %bb.1:
	cmpl	$5, -312(%rbp)
	jge	LBB14_3
LBB14_2:
	movl	$1, -308(%rbp)
	jmp	LBB14_14
LBB14_3:
	movq	-320(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	callq	_check_args
	cmpl	$0, %eax
	je	LBB14_5
## %bb.4:
	movl	$1, -308(%rbp)
	jmp	LBB14_14
LBB14_5:
	movq	-320(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	leaq	-304(%rbp), %rsi
	callq	_fill_params
	cmpl	$0, %eax
	je	LBB14_7
## %bb.6:
	movl	$1, -308(%rbp)
	jmp	LBB14_14
LBB14_7:
	leaq	-304(%rbp), %rdi
	callq	_check_params
	cmpl	$0, %eax
	je	LBB14_9
## %bb.8:
	movl	$1, -308(%rbp)
	jmp	LBB14_14
LBB14_9:
	callq	_get_current_time
	movq	%rax, -288(%rbp)
	movl	-304(%rbp), %edi
	callq	_init_forks
	movq	%rax, -336(%rbp)
	cmpq	$0, -336(%rbp)
	jne	LBB14_11
## %bb.10:
	movl	$1, -308(%rbp)
	jmp	LBB14_14
LBB14_11:
	leaq	-304(%rbp), %rdi
	callq	_init_philos
	movq	%rax, -328(%rbp)
	cmpq	$0, -328(%rbp)
	jne	LBB14_13
## %bb.12:
	movl	$1, -308(%rbp)
	jmp	LBB14_14
LBB14_13:
	movq	-328(%rbp), %rdi
	movq	-336(%rbp), %rsi
	movl	-304(%rbp), %edx
	callq	_assign_forks
	xorl	%edx, %edx
	movl	%edx, %esi
	leaq	-304(%rbp), %rdi
	addq	$40, %rdi
	callq	_pthread_mutex_init
	xorl	%edx, %edx
	movl	%edx, %esi
	leaq	-304(%rbp), %rdi
	addq	$104, %rdi
	movl	%eax, -340(%rbp)        ## 4-byte Spill
	callq	_pthread_mutex_init
	xorl	%edx, %edx
	movl	%edx, %esi
	leaq	-304(%rbp), %rdi
	addq	$168, %rdi
	movl	%eax, -344(%rbp)        ## 4-byte Spill
	callq	_pthread_mutex_init
	xorl	%edx, %edx
	movl	%edx, %esi
	leaq	-304(%rbp), %rdi
	addq	$232, %rdi
	movl	%eax, -348(%rbp)        ## 4-byte Spill
	callq	_pthread_mutex_init
	movq	-328(%rbp), %rdi
	movl	-304(%rbp), %esi
	movl	%eax, -352(%rbp)        ## 4-byte Spill
	callq	_start_simulation
LBB14_14:
	movl	-308(%rbp), %eax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	movl	%eax, -356(%rbp)        ## 4-byte Spill
	jne	LBB14_16
## %bb.15:
	movl	-356(%rbp), %eax        ## 4-byte Reload
	addq	$368, %rsp              ## imm = 0x170
	popq	%rbp
	retq
LBB14_16:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%ld %d %s\n"

L_.str.1:                               ## @.str.1
	.asciz	"has taken a fork"

L_.str.2:                               ## @.str.2
	.asciz	"is thinking"

L_.str.3:                               ## @.str.3
	.asciz	"is eating"

L_.str.4:                               ## @.str.4
	.asciz	"is sleeping"


.subsections_via_symbols
