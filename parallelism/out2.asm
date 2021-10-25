
no_avx:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 3f 00 00 	mov    0x3fd9(%rip),%rax        # 4fe8 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	callq  *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	retq   

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 42 3f 00 00    	pushq  0x3f42(%rip)        # 4f68 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 43 3f 00 00 	bnd jmpq *0x3f43(%rip)        # 4f70 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	pushq  $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmpq 1020 <.plt>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	pushq  $0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmpq 1020 <.plt>
    104f:	90                   	nop
    1050:	f3 0f 1e fa          	endbr64 
    1054:	68 02 00 00 00       	pushq  $0x2
    1059:	f2 e9 c1 ff ff ff    	bnd jmpq 1020 <.plt>
    105f:	90                   	nop
    1060:	f3 0f 1e fa          	endbr64 
    1064:	68 03 00 00 00       	pushq  $0x3
    1069:	f2 e9 b1 ff ff ff    	bnd jmpq 1020 <.plt>
    106f:	90                   	nop
    1070:	f3 0f 1e fa          	endbr64 
    1074:	68 04 00 00 00       	pushq  $0x4
    1079:	f2 e9 a1 ff ff ff    	bnd jmpq 1020 <.plt>
    107f:	90                   	nop
    1080:	f3 0f 1e fa          	endbr64 
    1084:	68 05 00 00 00       	pushq  $0x5
    1089:	f2 e9 91 ff ff ff    	bnd jmpq 1020 <.plt>
    108f:	90                   	nop
    1090:	f3 0f 1e fa          	endbr64 
    1094:	68 06 00 00 00       	pushq  $0x6
    1099:	f2 e9 81 ff ff ff    	bnd jmpq 1020 <.plt>
    109f:	90                   	nop
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	68 07 00 00 00       	pushq  $0x7
    10a9:	f2 e9 71 ff ff ff    	bnd jmpq 1020 <.plt>
    10af:	90                   	nop
    10b0:	f3 0f 1e fa          	endbr64 
    10b4:	68 08 00 00 00       	pushq  $0x8
    10b9:	f2 e9 61 ff ff ff    	bnd jmpq 1020 <.plt>
    10bf:	90                   	nop
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	68 09 00 00 00       	pushq  $0x9
    10c9:	f2 e9 51 ff ff ff    	bnd jmpq 1020 <.plt>
    10cf:	90                   	nop
    10d0:	f3 0f 1e fa          	endbr64 
    10d4:	68 0a 00 00 00       	pushq  $0xa
    10d9:	f2 e9 41 ff ff ff    	bnd jmpq 1020 <.plt>
    10df:	90                   	nop

Disassembly of section .plt.got:

00000000000010e0 <__cxa_finalize@plt>:
    10e0:	f3 0f 1e fa          	endbr64 
    10e4:	f2 ff 25 e5 3e 00 00 	bnd jmpq *0x3ee5(%rip)        # 4fd0 <__cxa_finalize@GLIBC_2.2.5>
    10eb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

00000000000010f0 <_ZSt17__throw_bad_allocv@plt>:
    10f0:	f3 0f 1e fa          	endbr64 
    10f4:	f2 ff 25 7d 3e 00 00 	bnd jmpq *0x3e7d(%rip)        # 4f78 <_ZSt17__throw_bad_allocv@GLIBCXX_3.4>
    10fb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001100 <_ZSt20__throw_length_errorPKc@plt>:
    1100:	f3 0f 1e fa          	endbr64 
    1104:	f2 ff 25 75 3e 00 00 	bnd jmpq *0x3e75(%rip)        # 4f80 <_ZSt20__throw_length_errorPKc@GLIBCXX_3.4>
    110b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001110 <_ZNSolsEf@plt>:
    1110:	f3 0f 1e fa          	endbr64 
    1114:	f2 ff 25 6d 3e 00 00 	bnd jmpq *0x3e6d(%rip)        # 4f88 <_ZNSolsEf@GLIBCXX_3.4>
    111b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001120 <__cxa_atexit@plt>:
    1120:	f3 0f 1e fa          	endbr64 
    1124:	f2 ff 25 65 3e 00 00 	bnd jmpq *0x3e65(%rip)        # 4f90 <__cxa_atexit@GLIBC_2.2.5>
    112b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001130 <_ZdlPv@plt>:
    1130:	f3 0f 1e fa          	endbr64 
    1134:	f2 ff 25 5d 3e 00 00 	bnd jmpq *0x3e5d(%rip)        # 4f98 <_ZdlPv@GLIBCXX_3.4>
    113b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001140 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>:
    1140:	f3 0f 1e fa          	endbr64 
    1144:	f2 ff 25 55 3e 00 00 	bnd jmpq *0x3e55(%rip)        # 4fa0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GLIBCXX_3.4>
    114b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001150 <_Znwm@plt>:
    1150:	f3 0f 1e fa          	endbr64 
    1154:	f2 ff 25 4d 3e 00 00 	bnd jmpq *0x3e4d(%rip)        # 4fa8 <_Znwm@GLIBCXX_3.4>
    115b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001160 <__stack_chk_fail@plt>:
    1160:	f3 0f 1e fa          	endbr64 
    1164:	f2 ff 25 45 3e 00 00 	bnd jmpq *0x3e45(%rip)        # 4fb0 <__stack_chk_fail@GLIBC_2.4>
    116b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001170 <_ZNSt8ios_base4InitC1Ev@plt>:
    1170:	f3 0f 1e fa          	endbr64 
    1174:	f2 ff 25 3d 3e 00 00 	bnd jmpq *0x3e3d(%rip)        # 4fb8 <_ZNSt8ios_base4InitC1Ev@GLIBCXX_3.4>
    117b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001180 <memmove@plt>:
    1180:	f3 0f 1e fa          	endbr64 
    1184:	f2 ff 25 35 3e 00 00 	bnd jmpq *0x3e35(%rip)        # 4fc0 <memmove@GLIBC_2.2.5>
    118b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001190 <_Unwind_Resume@plt>:
    1190:	f3 0f 1e fa          	endbr64 
    1194:	f2 ff 25 2d 3e 00 00 	bnd jmpq *0x3e2d(%rip)        # 4fc8 <_Unwind_Resume@GCC_3.0>
    119b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

00000000000011a0 <_start>:
    11a0:	f3 0f 1e fa          	endbr64 
    11a4:	31 ed                	xor    %ebp,%ebp
    11a6:	49 89 d1             	mov    %rdx,%r9
    11a9:	5e                   	pop    %rsi
    11aa:	48 89 e2             	mov    %rsp,%rdx
    11ad:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    11b1:	50                   	push   %rax
    11b2:	54                   	push   %rsp
    11b3:	4c 8d 05 36 0f 00 00 	lea    0xf36(%rip),%r8        # 20f0 <__libc_csu_fini>
    11ba:	48 8d 0d bf 0e 00 00 	lea    0xebf(%rip),%rcx        # 2080 <__libc_csu_init>
    11c1:	48 8d 3d c1 00 00 00 	lea    0xc1(%rip),%rdi        # 1289 <main>
    11c8:	ff 15 12 3e 00 00    	callq  *0x3e12(%rip)        # 4fe0 <__libc_start_main@GLIBC_2.2.5>
    11ce:	f4                   	hlt    
    11cf:	90                   	nop

00000000000011d0 <deregister_tm_clones>:
    11d0:	48 8d 3d 41 3e 00 00 	lea    0x3e41(%rip),%rdi        # 5018 <__TMC_END__>
    11d7:	48 8d 05 3a 3e 00 00 	lea    0x3e3a(%rip),%rax        # 5018 <__TMC_END__>
    11de:	48 39 f8             	cmp    %rdi,%rax
    11e1:	74 15                	je     11f8 <deregister_tm_clones+0x28>
    11e3:	48 8b 05 ee 3d 00 00 	mov    0x3dee(%rip),%rax        # 4fd8 <_ITM_deregisterTMCloneTable>
    11ea:	48 85 c0             	test   %rax,%rax
    11ed:	74 09                	je     11f8 <deregister_tm_clones+0x28>
    11ef:	ff e0                	jmpq   *%rax
    11f1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    11f8:	c3                   	retq   
    11f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001200 <register_tm_clones>:
    1200:	48 8d 3d 11 3e 00 00 	lea    0x3e11(%rip),%rdi        # 5018 <__TMC_END__>
    1207:	48 8d 35 0a 3e 00 00 	lea    0x3e0a(%rip),%rsi        # 5018 <__TMC_END__>
    120e:	48 29 fe             	sub    %rdi,%rsi
    1211:	48 89 f0             	mov    %rsi,%rax
    1214:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1218:	48 c1 f8 03          	sar    $0x3,%rax
    121c:	48 01 c6             	add    %rax,%rsi
    121f:	48 d1 fe             	sar    %rsi
    1222:	74 14                	je     1238 <register_tm_clones+0x38>
    1224:	48 8b 05 c5 3d 00 00 	mov    0x3dc5(%rip),%rax        # 4ff0 <_ITM_registerTMCloneTable>
    122b:	48 85 c0             	test   %rax,%rax
    122e:	74 08                	je     1238 <register_tm_clones+0x38>
    1230:	ff e0                	jmpq   *%rax
    1232:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1238:	c3                   	retq   
    1239:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001240 <__do_global_dtors_aux>:
    1240:	f3 0f 1e fa          	endbr64 
    1244:	80 3d 05 3f 00 00 00 	cmpb   $0x0,0x3f05(%rip)        # 5150 <completed.8060>
    124b:	75 2b                	jne    1278 <__do_global_dtors_aux+0x38>
    124d:	55                   	push   %rbp
    124e:	48 83 3d 7a 3d 00 00 	cmpq   $0x0,0x3d7a(%rip)        # 4fd0 <__cxa_finalize@GLIBC_2.2.5>
    1255:	00 
    1256:	48 89 e5             	mov    %rsp,%rbp
    1259:	74 0c                	je     1267 <__do_global_dtors_aux+0x27>
    125b:	48 8b 3d a6 3d 00 00 	mov    0x3da6(%rip),%rdi        # 5008 <__dso_handle>
    1262:	e8 79 fe ff ff       	callq  10e0 <__cxa_finalize@plt>
    1267:	e8 64 ff ff ff       	callq  11d0 <deregister_tm_clones>
    126c:	c6 05 dd 3e 00 00 01 	movb   $0x1,0x3edd(%rip)        # 5150 <completed.8060>
    1273:	5d                   	pop    %rbp
    1274:	c3                   	retq   
    1275:	0f 1f 00             	nopl   (%rax)
    1278:	c3                   	retq   
    1279:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001280 <frame_dummy>:
    1280:	f3 0f 1e fa          	endbr64 
    1284:	e9 77 ff ff ff       	jmpq   1200 <register_tm_clones>

0000000000001289 <main>:
    1289:	f3 0f 1e fa          	endbr64 
    128d:	55                   	push   %rbp
    128e:	48 89 e5             	mov    %rsp,%rbp
    1291:	41 57                	push   %r15
    1293:	41 56                	push   %r14
    1295:	41 55                	push   %r13
    1297:	41 54                	push   %r12
    1299:	53                   	push   %rbx
    129a:	48 81 ec b8 00 00 00 	sub    $0xb8,%rsp
    12a1:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    12a8:	00 00 
    12aa:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
    12ae:	31 c0                	xor    %eax,%eax
    12b0:	f3 0f 10 05 94 1d 00 	movss  0x1d94(%rip),%xmm0        # 304c <_ZStL19piecewise_construct+0x44>
    12b7:	00 
    12b8:	f3 0f 11 45 a0       	movss  %xmm0,-0x60(%rbp)
    12bd:	f3 0f 10 05 8b 1d 00 	movss  0x1d8b(%rip),%xmm0        # 3050 <_ZStL19piecewise_construct+0x48>
    12c4:	00 
    12c5:	f3 0f 11 45 a4       	movss  %xmm0,-0x5c(%rbp)
    12ca:	f3 0f 10 05 82 1d 00 	movss  0x1d82(%rip),%xmm0        # 3054 <_ZStL19piecewise_construct+0x4c>
    12d1:	00 
    12d2:	f3 0f 11 45 a8       	movss  %xmm0,-0x58(%rbp)
    12d7:	f3 0f 10 05 79 1d 00 	movss  0x1d79(%rip),%xmm0        # 3058 <_ZStL19piecewise_construct+0x50>
    12de:	00 
    12df:	f3 0f 11 45 ac       	movss  %xmm0,-0x54(%rbp)
    12e4:	f3 0f 10 05 70 1d 00 	movss  0x1d70(%rip),%xmm0        # 305c <_ZStL19piecewise_construct+0x54>
    12eb:	00 
    12ec:	f3 0f 11 45 b0       	movss  %xmm0,-0x50(%rbp)
    12f1:	f3 0f 10 05 67 1d 00 	movss  0x1d67(%rip),%xmm0        # 3060 <_ZStL19piecewise_construct+0x58>
    12f8:	00 
    12f9:	f3 0f 11 45 b4       	movss  %xmm0,-0x4c(%rbp)
    12fe:	f3 0f 10 05 5e 1d 00 	movss  0x1d5e(%rip),%xmm0        # 3064 <_ZStL19piecewise_construct+0x5c>
    1305:	00 
    1306:	f3 0f 11 45 b8       	movss  %xmm0,-0x48(%rbp)
    130b:	f3 0f 10 05 55 1d 00 	movss  0x1d55(%rip),%xmm0        # 3068 <_ZStL19piecewise_construct+0x60>
    1312:	00 
    1313:	f3 0f 11 45 bc       	movss  %xmm0,-0x44(%rbp)
    1318:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
    131c:	49 89 c6             	mov    %rax,%r14
    131f:	41 bf 08 00 00 00    	mov    $0x8,%r15d
    1325:	48 8d 45 80          	lea    -0x80(%rbp),%rax
    1329:	48 89 c7             	mov    %rax,%rdi
    132c:	e8 89 03 00 00       	callq  16ba <_ZNSaIfEC1Ev>
    1331:	48 8d 55 80          	lea    -0x80(%rbp),%rdx
    1335:	4c 89 f6             	mov    %r14,%rsi
    1338:	4c 89 ff             	mov    %r15,%rdi
    133b:	4c 89 f1             	mov    %r14,%rcx
    133e:	4c 89 fb             	mov    %r15,%rbx
    1341:	48 89 df             	mov    %rbx,%rdi
    1344:	48 8d 85 40 ff ff ff 	lea    -0xc0(%rbp),%rax
    134b:	48 89 d1             	mov    %rdx,%rcx
    134e:	48 89 fa             	mov    %rdi,%rdx
    1351:	48 89 c7             	mov    %rax,%rdi
    1354:	e8 a1 03 00 00       	callq  16fa <_ZNSt6vectorIfSaIfEEC1ESt16initializer_listIfERKS0_>
    1359:	48 8d 45 80          	lea    -0x80(%rbp),%rax
    135d:	48 89 c7             	mov    %rax,%rdi
    1360:	e8 75 03 00 00       	callq  16da <_ZNSaIfED1Ev>
    1365:	f3 0f 10 05 ff 1c 00 	movss  0x1cff(%rip),%xmm0        # 306c <_ZStL19piecewise_construct+0x64>
    136c:	00 
    136d:	f3 0f 11 45 a0       	movss  %xmm0,-0x60(%rbp)
    1372:	f3 0f 10 05 f6 1c 00 	movss  0x1cf6(%rip),%xmm0        # 3070 <_ZStL19piecewise_construct+0x68>
    1379:	00 
    137a:	f3 0f 11 45 a4       	movss  %xmm0,-0x5c(%rbp)
    137f:	f3 0f 10 05 ed 1c 00 	movss  0x1ced(%rip),%xmm0        # 3074 <_ZStL19piecewise_construct+0x6c>
    1386:	00 
    1387:	f3 0f 11 45 a8       	movss  %xmm0,-0x58(%rbp)
    138c:	f3 0f 10 05 e4 1c 00 	movss  0x1ce4(%rip),%xmm0        # 3078 <_ZStL19piecewise_construct+0x70>
    1393:	00 
    1394:	f3 0f 11 45 ac       	movss  %xmm0,-0x54(%rbp)
    1399:	f3 0f 10 05 db 1c 00 	movss  0x1cdb(%rip),%xmm0        # 307c <_ZStL19piecewise_construct+0x74>
    13a0:	00 
    13a1:	f3 0f 11 45 b0       	movss  %xmm0,-0x50(%rbp)
    13a6:	f3 0f 10 05 d2 1c 00 	movss  0x1cd2(%rip),%xmm0        # 3080 <_ZStL19piecewise_construct+0x78>
    13ad:	00 
    13ae:	f3 0f 11 45 b4       	movss  %xmm0,-0x4c(%rbp)
    13b3:	f3 0f 10 05 c9 1c 00 	movss  0x1cc9(%rip),%xmm0        # 3084 <_ZStL19piecewise_construct+0x7c>
    13ba:	00 
    13bb:	f3 0f 11 45 b8       	movss  %xmm0,-0x48(%rbp)
    13c0:	f3 0f 10 05 c0 1c 00 	movss  0x1cc0(%rip),%xmm0        # 3088 <_ZStL19piecewise_construct+0x80>
    13c7:	00 
    13c8:	f3 0f 11 45 bc       	movss  %xmm0,-0x44(%rbp)
    13cd:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
    13d1:	49 89 c4             	mov    %rax,%r12
    13d4:	41 bd 08 00 00 00    	mov    $0x8,%r13d
    13da:	48 8d 45 80          	lea    -0x80(%rbp),%rax
    13de:	48 89 c7             	mov    %rax,%rdi
    13e1:	e8 d4 02 00 00       	callq  16ba <_ZNSaIfEC1Ev>
    13e6:	48 8d 55 80          	lea    -0x80(%rbp),%rdx
    13ea:	4c 89 e6             	mov    %r12,%rsi
    13ed:	4c 89 ef             	mov    %r13,%rdi
    13f0:	4c 89 e1             	mov    %r12,%rcx
    13f3:	4c 89 eb             	mov    %r13,%rbx
    13f6:	48 89 df             	mov    %rbx,%rdi
    13f9:	48 8d 85 60 ff ff ff 	lea    -0xa0(%rbp),%rax
    1400:	48 89 d1             	mov    %rdx,%rcx
    1403:	48 89 fa             	mov    %rdi,%rdx
    1406:	48 89 c7             	mov    %rax,%rdi
    1409:	e8 ec 02 00 00       	callq  16fa <_ZNSt6vectorIfSaIfEEC1ESt16initializer_listIfERKS0_>
    140e:	48 8d 45 80          	lea    -0x80(%rbp),%rax
    1412:	48 89 c7             	mov    %rax,%rdi
    1415:	e8 c0 02 00 00       	callq  16da <_ZNSaIfED1Ev>
    141a:	48 8d 45 80          	lea    -0x80(%rbp),%rax
    141e:	48 89 c7             	mov    %rax,%rdi
    1421:	e8 74 02 00 00       	callq  169a <_ZNSt6vectorIfSaIfEEC1Ev>
    1426:	c7 85 38 ff ff ff 00 	movl   $0x0,-0xc8(%rbp)
    142d:	00 00 00 
    1430:	83 bd 38 ff ff ff 07 	cmpl   $0x7,-0xc8(%rbp)
    1437:	0f 8f 86 00 00 00    	jg     14c3 <main+0x23a>
    143d:	8b 85 38 ff ff ff    	mov    -0xc8(%rbp),%eax
    1443:	48 63 d0             	movslq %eax,%rdx
    1446:	48 8d 85 40 ff ff ff 	lea    -0xc0(%rbp),%rax
    144d:	48 89 d6             	mov    %rdx,%rsi
    1450:	48 89 c7             	mov    %rax,%rdi
    1453:	e8 1c 04 00 00       	callq  1874 <_ZNSt6vectorIfSaIfEEixEm>
    1458:	f3 0f 10 00          	movss  (%rax),%xmm0
    145c:	f3 0f 11 85 2c ff ff 	movss  %xmm0,-0xd4(%rbp)
    1463:	ff 
    1464:	8b 85 38 ff ff ff    	mov    -0xc8(%rbp),%eax
    146a:	48 63 d0             	movslq %eax,%rdx
    146d:	48 8d 85 60 ff ff ff 	lea    -0xa0(%rbp),%rax
    1474:	48 89 d6             	mov    %rdx,%rsi
    1477:	48 89 c7             	mov    %rax,%rdi
    147a:	e8 f5 03 00 00       	callq  1874 <_ZNSt6vectorIfSaIfEEixEm>
    147f:	f3 0f 10 08          	movss  (%rax),%xmm1
    1483:	f3 0f 11 8d 28 ff ff 	movss  %xmm1,-0xd8(%rbp)
    148a:	ff 
    148b:	8b 85 38 ff ff ff    	mov    -0xc8(%rbp),%eax
    1491:	48 63 d0             	movslq %eax,%rdx
    1494:	48 8d 45 80          	lea    -0x80(%rbp),%rax
    1498:	48 89 d6             	mov    %rdx,%rsi
    149b:	48 89 c7             	mov    %rax,%rdi
    149e:	e8 d1 03 00 00       	callq  1874 <_ZNSt6vectorIfSaIfEEixEm>
    14a3:	f3 0f 10 85 2c ff ff 	movss  -0xd4(%rbp),%xmm0
    14aa:	ff 
    14ab:	f3 0f 5c 85 28 ff ff 	subss  -0xd8(%rbp),%xmm0
    14b2:	ff 
    14b3:	f3 0f 11 00          	movss  %xmm0,(%rax)
    14b7:	83 85 38 ff ff ff 01 	addl   $0x1,-0xc8(%rbp)
    14be:	e9 6d ff ff ff       	jmpq   1430 <main+0x1a7>
    14c3:	48 8d 35 3f 1b 00 00 	lea    0x1b3f(%rip),%rsi        # 3009 <_ZStL19piecewise_construct+0x1>
    14ca:	48 8d 3d 6f 3b 00 00 	lea    0x3b6f(%rip),%rdi        # 5040 <_ZSt4cout@@GLIBCXX_3.4>
    14d1:	e8 6a fc ff ff       	callq  1140 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    14d6:	c7 85 3c ff ff ff 00 	movl   $0x0,-0xc4(%rbp)
    14dd:	00 00 00 
    14e0:	83 bd 3c ff ff ff 07 	cmpl   $0x7,-0xc4(%rbp)
    14e7:	7f 42                	jg     152b <main+0x2a2>
    14e9:	8b 85 3c ff ff ff    	mov    -0xc4(%rbp),%eax
    14ef:	48 63 d0             	movslq %eax,%rdx
    14f2:	48 8d 45 80          	lea    -0x80(%rbp),%rax
    14f6:	48 89 d6             	mov    %rdx,%rsi
    14f9:	48 89 c7             	mov    %rax,%rdi
    14fc:	e8 73 03 00 00       	callq  1874 <_ZNSt6vectorIfSaIfEEixEm>
    1501:	8b 00                	mov    (%rax),%eax
    1503:	66 0f 6e c0          	movd   %eax,%xmm0
    1507:	48 8d 3d 32 3b 00 00 	lea    0x3b32(%rip),%rdi        # 5040 <_ZSt4cout@@GLIBCXX_3.4>
    150e:	e8 fd fb ff ff       	callq  1110 <_ZNSolsEf@plt>
    1513:	48 8d 35 f8 1a 00 00 	lea    0x1af8(%rip),%rsi        # 3012 <_ZStL19piecewise_construct+0xa>
    151a:	48 89 c7             	mov    %rax,%rdi
    151d:	e8 1e fc ff ff       	callq  1140 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    1522:	83 85 3c ff ff ff 01 	addl   $0x1,-0xc4(%rbp)
    1529:	eb b5                	jmp    14e0 <main+0x257>
    152b:	bb 00 00 00 00       	mov    $0x0,%ebx
    1530:	48 8d 45 80          	lea    -0x80(%rbp),%rax
    1534:	48 89 c7             	mov    %rax,%rdi
    1537:	e8 72 02 00 00       	callq  17ae <_ZNSt6vectorIfSaIfEED1Ev>
    153c:	48 8d 85 60 ff ff ff 	lea    -0xa0(%rbp),%rax
    1543:	48 89 c7             	mov    %rax,%rdi
    1546:	e8 63 02 00 00       	callq  17ae <_ZNSt6vectorIfSaIfEED1Ev>
    154b:	48 8d 85 40 ff ff ff 	lea    -0xc0(%rbp),%rax
    1552:	48 89 c7             	mov    %rax,%rdi
    1555:	e8 54 02 00 00       	callq  17ae <_ZNSt6vectorIfSaIfEED1Ev>
    155a:	89 d8                	mov    %ebx,%eax
    155c:	48 8b 4d c8          	mov    -0x38(%rbp),%rcx
    1560:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
    1567:	00 00 
    1569:	74 76                	je     15e1 <main+0x358>
    156b:	eb 6f                	jmp    15dc <main+0x353>
    156d:	f3 0f 1e fa          	endbr64 
    1571:	48 89 c3             	mov    %rax,%rbx
    1574:	48 8d 45 80          	lea    -0x80(%rbp),%rax
    1578:	48 89 c7             	mov    %rax,%rdi
    157b:	e8 5a 01 00 00       	callq  16da <_ZNSaIfED1Ev>
    1580:	48 89 d8             	mov    %rbx,%rax
    1583:	48 89 c7             	mov    %rax,%rdi
    1586:	e8 05 fc ff ff       	callq  1190 <_Unwind_Resume@plt>
    158b:	f3 0f 1e fa          	endbr64 
    158f:	48 89 c3             	mov    %rax,%rbx
    1592:	48 8d 45 80          	lea    -0x80(%rbp),%rax
    1596:	48 89 c7             	mov    %rax,%rdi
    1599:	e8 3c 01 00 00       	callq  16da <_ZNSaIfED1Ev>
    159e:	eb 22                	jmp    15c2 <main+0x339>
    15a0:	f3 0f 1e fa          	endbr64 
    15a4:	48 89 c3             	mov    %rax,%rbx
    15a7:	48 8d 45 80          	lea    -0x80(%rbp),%rax
    15ab:	48 89 c7             	mov    %rax,%rdi
    15ae:	e8 fb 01 00 00       	callq  17ae <_ZNSt6vectorIfSaIfEED1Ev>
    15b3:	48 8d 85 60 ff ff ff 	lea    -0xa0(%rbp),%rax
    15ba:	48 89 c7             	mov    %rax,%rdi
    15bd:	e8 ec 01 00 00       	callq  17ae <_ZNSt6vectorIfSaIfEED1Ev>
    15c2:	48 8d 85 40 ff ff ff 	lea    -0xc0(%rbp),%rax
    15c9:	48 89 c7             	mov    %rax,%rdi
    15cc:	e8 dd 01 00 00       	callq  17ae <_ZNSt6vectorIfSaIfEED1Ev>
    15d1:	48 89 d8             	mov    %rbx,%rax
    15d4:	48 89 c7             	mov    %rax,%rdi
    15d7:	e8 b4 fb ff ff       	callq  1190 <_Unwind_Resume@plt>
    15dc:	e8 7f fb ff ff       	callq  1160 <__stack_chk_fail@plt>
    15e1:	48 81 c4 b8 00 00 00 	add    $0xb8,%rsp
    15e8:	5b                   	pop    %rbx
    15e9:	41 5c                	pop    %r12
    15eb:	41 5d                	pop    %r13
    15ed:	41 5e                	pop    %r14
    15ef:	41 5f                	pop    %r15
    15f1:	5d                   	pop    %rbp
    15f2:	c3                   	retq   

00000000000015f3 <_Z41__static_initialization_and_destruction_0ii>:
    15f3:	f3 0f 1e fa          	endbr64 
    15f7:	55                   	push   %rbp
    15f8:	48 89 e5             	mov    %rsp,%rbp
    15fb:	48 83 ec 10          	sub    $0x10,%rsp
    15ff:	89 7d fc             	mov    %edi,-0x4(%rbp)
    1602:	89 75 f8             	mov    %esi,-0x8(%rbp)
    1605:	83 7d fc 01          	cmpl   $0x1,-0x4(%rbp)
    1609:	75 32                	jne    163d <_Z41__static_initialization_and_destruction_0ii+0x4a>
    160b:	81 7d f8 ff ff 00 00 	cmpl   $0xffff,-0x8(%rbp)
    1612:	75 29                	jne    163d <_Z41__static_initialization_and_destruction_0ii+0x4a>
    1614:	48 8d 3d 36 3b 00 00 	lea    0x3b36(%rip),%rdi        # 5151 <_ZStL8__ioinit>
    161b:	e8 50 fb ff ff       	callq  1170 <_ZNSt8ios_base4InitC1Ev@plt>
    1620:	48 8d 15 e1 39 00 00 	lea    0x39e1(%rip),%rdx        # 5008 <__dso_handle>
    1627:	48 8d 35 23 3b 00 00 	lea    0x3b23(%rip),%rsi        # 5151 <_ZStL8__ioinit>
    162e:	48 8b 05 c3 39 00 00 	mov    0x39c3(%rip),%rax        # 4ff8 <_ZNSt8ios_base4InitD1Ev@GLIBCXX_3.4>
    1635:	48 89 c7             	mov    %rax,%rdi
    1638:	e8 e3 fa ff ff       	callq  1120 <__cxa_atexit@plt>
    163d:	90                   	nop
    163e:	c9                   	leaveq 
    163f:	c3                   	retq   

0000000000001640 <_GLOBAL__sub_I_main>:
    1640:	f3 0f 1e fa          	endbr64 
    1644:	55                   	push   %rbp
    1645:	48 89 e5             	mov    %rsp,%rbp
    1648:	be ff ff 00 00       	mov    $0xffff,%esi
    164d:	bf 01 00 00 00       	mov    $0x1,%edi
    1652:	e8 9c ff ff ff       	callq  15f3 <_Z41__static_initialization_and_destruction_0ii>
    1657:	5d                   	pop    %rbp
    1658:	c3                   	retq   
    1659:	90                   	nop

000000000000165a <_ZNSt12_Vector_baseIfSaIfEE12_Vector_implD1Ev>:
    165a:	f3 0f 1e fa          	endbr64 
    165e:	55                   	push   %rbp
    165f:	48 89 e5             	mov    %rsp,%rbp
    1662:	48 83 ec 10          	sub    $0x10,%rsp
    1666:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    166a:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    166e:	48 89 c7             	mov    %rax,%rdi
    1671:	e8 64 00 00 00       	callq  16da <_ZNSaIfED1Ev>
    1676:	90                   	nop
    1677:	c9                   	leaveq 
    1678:	c3                   	retq   
    1679:	90                   	nop

000000000000167a <_ZNSt12_Vector_baseIfSaIfEEC1Ev>:
    167a:	f3 0f 1e fa          	endbr64 
    167e:	55                   	push   %rbp
    167f:	48 89 e5             	mov    %rsp,%rbp
    1682:	48 83 ec 10          	sub    $0x10,%rsp
    1686:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    168a:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    168e:	48 89 c7             	mov    %rax,%rdi
    1691:	e8 60 01 00 00       	callq  17f6 <_ZNSt12_Vector_baseIfSaIfEE12_Vector_implC1Ev>
    1696:	90                   	nop
    1697:	c9                   	leaveq 
    1698:	c3                   	retq   
    1699:	90                   	nop

000000000000169a <_ZNSt6vectorIfSaIfEEC1Ev>:
    169a:	f3 0f 1e fa          	endbr64 
    169e:	55                   	push   %rbp
    169f:	48 89 e5             	mov    %rsp,%rbp
    16a2:	48 83 ec 10          	sub    $0x10,%rsp
    16a6:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    16aa:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    16ae:	48 89 c7             	mov    %rax,%rdi
    16b1:	e8 c4 ff ff ff       	callq  167a <_ZNSt12_Vector_baseIfSaIfEEC1Ev>
    16b6:	90                   	nop
    16b7:	c9                   	leaveq 
    16b8:	c3                   	retq   
    16b9:	90                   	nop

00000000000016ba <_ZNSaIfEC1Ev>:
    16ba:	f3 0f 1e fa          	endbr64 
    16be:	55                   	push   %rbp
    16bf:	48 89 e5             	mov    %rsp,%rbp
    16c2:	48 83 ec 10          	sub    $0x10,%rsp
    16c6:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    16ca:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    16ce:	48 89 c7             	mov    %rax,%rdi
    16d1:	e8 c2 01 00 00       	callq  1898 <_ZN9__gnu_cxx13new_allocatorIfEC1Ev>
    16d6:	90                   	nop
    16d7:	c9                   	leaveq 
    16d8:	c3                   	retq   
    16d9:	90                   	nop

00000000000016da <_ZNSaIfED1Ev>:
    16da:	f3 0f 1e fa          	endbr64 
    16de:	55                   	push   %rbp
    16df:	48 89 e5             	mov    %rsp,%rbp
    16e2:	48 83 ec 10          	sub    $0x10,%rsp
    16e6:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    16ea:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    16ee:	48 89 c7             	mov    %rax,%rdi
    16f1:	e8 b2 01 00 00       	callq  18a8 <_ZN9__gnu_cxx13new_allocatorIfED1Ev>
    16f6:	90                   	nop
    16f7:	c9                   	leaveq 
    16f8:	c3                   	retq   
    16f9:	90                   	nop

00000000000016fa <_ZNSt6vectorIfSaIfEEC1ESt16initializer_listIfERKS0_>:
    16fa:	f3 0f 1e fa          	endbr64 
    16fe:	55                   	push   %rbp
    16ff:	48 89 e5             	mov    %rsp,%rbp
    1702:	53                   	push   %rbx
    1703:	48 83 ec 38          	sub    $0x38,%rsp
    1707:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
    170b:	48 89 f0             	mov    %rsi,%rax
    170e:	48 89 d6             	mov    %rdx,%rsi
    1711:	48 89 f2             	mov    %rsi,%rdx
    1714:	48 89 45 c0          	mov    %rax,-0x40(%rbp)
    1718:	48 89 55 c8          	mov    %rdx,-0x38(%rbp)
    171c:	48 89 4d d0          	mov    %rcx,-0x30(%rbp)
    1720:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1727:	00 00 
    1729:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    172d:	31 c0                	xor    %eax,%eax
    172f:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    1733:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
    1737:	48 89 d6             	mov    %rdx,%rsi
    173a:	48 89 c7             	mov    %rax,%rdi
    173d:	e8 76 01 00 00       	callq  18b8 <_ZNSt12_Vector_baseIfSaIfEEC1ERKS0_>
    1742:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
    1746:	48 89 c7             	mov    %rax,%rdi
    1749:	e8 aa 01 00 00       	callq  18f8 <_ZNKSt16initializer_listIfE3endEv>
    174e:	48 89 c3             	mov    %rax,%rbx
    1751:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
    1755:	48 89 c7             	mov    %rax,%rdi
    1758:	e8 85 01 00 00       	callq  18e2 <_ZNKSt16initializer_listIfE5beginEv>
    175d:	48 89 c1             	mov    %rax,%rcx
    1760:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    1764:	48 89 da             	mov    %rbx,%rdx
    1767:	48 89 ce             	mov    %rcx,%rsi
    176a:	48 89 c7             	mov    %rax,%rdi
    176d:	e8 c0 01 00 00       	callq  1932 <_ZNSt6vectorIfSaIfEE19_M_range_initializeIPKfEEvT_S5_St20forward_iterator_tag>
    1772:	eb 1e                	jmp    1792 <_ZNSt6vectorIfSaIfEEC1ESt16initializer_listIfERKS0_+0x98>
    1774:	f3 0f 1e fa          	endbr64 
    1778:	48 89 c3             	mov    %rax,%rbx
    177b:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    177f:	48 89 c7             	mov    %rax,%rdi
    1782:	e8 9b 00 00 00       	callq  1822 <_ZNSt12_Vector_baseIfSaIfEED1Ev>
    1787:	48 89 d8             	mov    %rbx,%rax
    178a:	48 89 c7             	mov    %rax,%rdi
    178d:	e8 fe f9 ff ff       	callq  1190 <_Unwind_Resume@plt>
    1792:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1796:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    179d:	00 00 
    179f:	74 05                	je     17a6 <_ZNSt6vectorIfSaIfEEC1ESt16initializer_listIfERKS0_+0xac>
    17a1:	e8 ba f9 ff ff       	callq  1160 <__stack_chk_fail@plt>
    17a6:	48 83 c4 38          	add    $0x38,%rsp
    17aa:	5b                   	pop    %rbx
    17ab:	5d                   	pop    %rbp
    17ac:	c3                   	retq   
    17ad:	90                   	nop

00000000000017ae <_ZNSt6vectorIfSaIfEED1Ev>:
    17ae:	f3 0f 1e fa          	endbr64 
    17b2:	55                   	push   %rbp
    17b3:	48 89 e5             	mov    %rsp,%rbp
    17b6:	48 83 ec 10          	sub    $0x10,%rsp
    17ba:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    17be:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    17c2:	48 89 c7             	mov    %rax,%rdi
    17c5:	e8 1c 02 00 00       	callq  19e6 <_ZNSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv>
    17ca:	48 89 c2             	mov    %rax,%rdx
    17cd:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    17d1:	48 8b 48 08          	mov    0x8(%rax),%rcx
    17d5:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    17d9:	48 8b 00             	mov    (%rax),%rax
    17dc:	48 89 ce             	mov    %rcx,%rsi
    17df:	48 89 c7             	mov    %rax,%rdi
    17e2:	e8 11 02 00 00       	callq  19f8 <_ZSt8_DestroyIPffEvT_S1_RSaIT0_E>
    17e7:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    17eb:	48 89 c7             	mov    %rax,%rdi
    17ee:	e8 2f 00 00 00       	callq  1822 <_ZNSt12_Vector_baseIfSaIfEED1Ev>
    17f3:	90                   	nop
    17f4:	c9                   	leaveq 
    17f5:	c3                   	retq   

00000000000017f6 <_ZNSt12_Vector_baseIfSaIfEE12_Vector_implC1Ev>:
    17f6:	f3 0f 1e fa          	endbr64 
    17fa:	55                   	push   %rbp
    17fb:	48 89 e5             	mov    %rsp,%rbp
    17fe:	48 83 ec 10          	sub    $0x10,%rsp
    1802:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1806:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    180a:	48 89 c7             	mov    %rax,%rdi
    180d:	e8 a8 fe ff ff       	callq  16ba <_ZNSaIfEC1Ev>
    1812:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1816:	48 89 c7             	mov    %rax,%rdi
    1819:	e8 08 02 00 00       	callq  1a26 <_ZNSt12_Vector_baseIfSaIfEE17_Vector_impl_dataC1Ev>
    181e:	90                   	nop
    181f:	c9                   	leaveq 
    1820:	c3                   	retq   
    1821:	90                   	nop

0000000000001822 <_ZNSt12_Vector_baseIfSaIfEED1Ev>:
    1822:	f3 0f 1e fa          	endbr64 
    1826:	55                   	push   %rbp
    1827:	48 89 e5             	mov    %rsp,%rbp
    182a:	48 83 ec 10          	sub    $0x10,%rsp
    182e:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1832:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1836:	48 8b 50 10          	mov    0x10(%rax),%rdx
    183a:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    183e:	48 8b 00             	mov    (%rax),%rax
    1841:	48 29 c2             	sub    %rax,%rdx
    1844:	48 89 d0             	mov    %rdx,%rax
    1847:	48 c1 f8 02          	sar    $0x2,%rax
    184b:	48 89 c2             	mov    %rax,%rdx
    184e:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1852:	48 8b 08             	mov    (%rax),%rcx
    1855:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1859:	48 89 ce             	mov    %rcx,%rsi
    185c:	48 89 c7             	mov    %rax,%rdi
    185f:	e8 f4 01 00 00       	callq  1a58 <_ZNSt12_Vector_baseIfSaIfEE13_M_deallocateEPfm>
    1864:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1868:	48 89 c7             	mov    %rax,%rdi
    186b:	e8 ea fd ff ff       	callq  165a <_ZNSt12_Vector_baseIfSaIfEE12_Vector_implD1Ev>
    1870:	90                   	nop
    1871:	c9                   	leaveq 
    1872:	c3                   	retq   
    1873:	90                   	nop

0000000000001874 <_ZNSt6vectorIfSaIfEEixEm>:
    1874:	f3 0f 1e fa          	endbr64 
    1878:	55                   	push   %rbp
    1879:	48 89 e5             	mov    %rsp,%rbp
    187c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1880:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    1884:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1888:	48 8b 00             	mov    (%rax),%rax
    188b:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    188f:	48 c1 e2 02          	shl    $0x2,%rdx
    1893:	48 01 d0             	add    %rdx,%rax
    1896:	5d                   	pop    %rbp
    1897:	c3                   	retq   

0000000000001898 <_ZN9__gnu_cxx13new_allocatorIfEC1Ev>:
    1898:	f3 0f 1e fa          	endbr64 
    189c:	55                   	push   %rbp
    189d:	48 89 e5             	mov    %rsp,%rbp
    18a0:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    18a4:	90                   	nop
    18a5:	5d                   	pop    %rbp
    18a6:	c3                   	retq   
    18a7:	90                   	nop

00000000000018a8 <_ZN9__gnu_cxx13new_allocatorIfED1Ev>:
    18a8:	f3 0f 1e fa          	endbr64 
    18ac:	55                   	push   %rbp
    18ad:	48 89 e5             	mov    %rsp,%rbp
    18b0:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    18b4:	90                   	nop
    18b5:	5d                   	pop    %rbp
    18b6:	c3                   	retq   
    18b7:	90                   	nop

00000000000018b8 <_ZNSt12_Vector_baseIfSaIfEEC1ERKS0_>:
    18b8:	f3 0f 1e fa          	endbr64 
    18bc:	55                   	push   %rbp
    18bd:	48 89 e5             	mov    %rsp,%rbp
    18c0:	48 83 ec 10          	sub    $0x10,%rsp
    18c4:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    18c8:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    18cc:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    18d0:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    18d4:	48 89 d6             	mov    %rdx,%rsi
    18d7:	48 89 c7             	mov    %rax,%rdi
    18da:	e8 b3 01 00 00       	callq  1a92 <_ZNSt12_Vector_baseIfSaIfEE12_Vector_implC1ERKS0_>
    18df:	90                   	nop
    18e0:	c9                   	leaveq 
    18e1:	c3                   	retq   

00000000000018e2 <_ZNKSt16initializer_listIfE5beginEv>:
    18e2:	f3 0f 1e fa          	endbr64 
    18e6:	55                   	push   %rbp
    18e7:	48 89 e5             	mov    %rsp,%rbp
    18ea:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    18ee:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    18f2:	48 8b 00             	mov    (%rax),%rax
    18f5:	5d                   	pop    %rbp
    18f6:	c3                   	retq   
    18f7:	90                   	nop

00000000000018f8 <_ZNKSt16initializer_listIfE3endEv>:
    18f8:	f3 0f 1e fa          	endbr64 
    18fc:	55                   	push   %rbp
    18fd:	48 89 e5             	mov    %rsp,%rbp
    1900:	53                   	push   %rbx
    1901:	48 83 ec 18          	sub    $0x18,%rsp
    1905:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    1909:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    190d:	48 89 c7             	mov    %rax,%rdi
    1910:	e8 cd ff ff ff       	callq  18e2 <_ZNKSt16initializer_listIfE5beginEv>
    1915:	48 89 c3             	mov    %rax,%rbx
    1918:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    191c:	48 89 c7             	mov    %rax,%rdi
    191f:	e8 a4 01 00 00       	callq  1ac8 <_ZNKSt16initializer_listIfE4sizeEv>
    1924:	48 c1 e0 02          	shl    $0x2,%rax
    1928:	48 01 d8             	add    %rbx,%rax
    192b:	48 83 c4 18          	add    $0x18,%rsp
    192f:	5b                   	pop    %rbx
    1930:	5d                   	pop    %rbp
    1931:	c3                   	retq   

0000000000001932 <_ZNSt6vectorIfSaIfEE19_M_range_initializeIPKfEEvT_S5_St20forward_iterator_tag>:
    1932:	f3 0f 1e fa          	endbr64 
    1936:	55                   	push   %rbp
    1937:	48 89 e5             	mov    %rsp,%rbp
    193a:	53                   	push   %rbx
    193b:	48 83 ec 38          	sub    $0x38,%rsp
    193f:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
    1943:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
    1947:	48 89 55 c8          	mov    %rdx,-0x38(%rbp)
    194b:	48 8b 55 c8          	mov    -0x38(%rbp),%rdx
    194f:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    1953:	48 89 d6             	mov    %rdx,%rsi
    1956:	48 89 c7             	mov    %rax,%rdi
    1959:	e8 80 01 00 00       	callq  1ade <_ZSt8distanceIPKfENSt15iterator_traitsIT_E15difference_typeES3_S3_>
    195e:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    1962:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    1966:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    196a:	48 89 c7             	mov    %rax,%rdi
    196d:	e8 74 00 00 00       	callq  19e6 <_ZNSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv>
    1972:	48 89 c2             	mov    %rax,%rdx
    1975:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1979:	48 89 d6             	mov    %rdx,%rsi
    197c:	48 89 c7             	mov    %rax,%rdi
    197f:	e8 b2 01 00 00       	callq  1b36 <_ZNSt6vectorIfSaIfEE17_S_check_init_lenEmRKS0_>
    1984:	48 89 c6             	mov    %rax,%rsi
    1987:	48 89 df             	mov    %rbx,%rdi
    198a:	e8 2d 02 00 00       	callq  1bbc <_ZNSt12_Vector_baseIfSaIfEE11_M_allocateEm>
    198f:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    1993:	48 89 02             	mov    %rax,(%rdx)
    1996:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    199a:	48 8b 00             	mov    (%rax),%rax
    199d:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    19a1:	48 c1 e2 02          	shl    $0x2,%rdx
    19a5:	48 01 c2             	add    %rax,%rdx
    19a8:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    19ac:	48 89 50 10          	mov    %rdx,0x10(%rax)
    19b0:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    19b4:	48 89 c7             	mov    %rax,%rdi
    19b7:	e8 2a 00 00 00       	callq  19e6 <_ZNSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv>
    19bc:	48 89 c1             	mov    %rax,%rcx
    19bf:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    19c3:	48 8b 10             	mov    (%rax),%rdx
    19c6:	48 8b 75 c8          	mov    -0x38(%rbp),%rsi
    19ca:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    19ce:	48 89 c7             	mov    %rax,%rdi
    19d1:	e8 1d 02 00 00       	callq  1bf3 <_ZSt22__uninitialized_copy_aIPKfPffET0_T_S4_S3_RSaIT1_E>
    19d6:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    19da:	48 89 42 08          	mov    %rax,0x8(%rdx)
    19de:	90                   	nop
    19df:	48 83 c4 38          	add    $0x38,%rsp
    19e3:	5b                   	pop    %rbx
    19e4:	5d                   	pop    %rbp
    19e5:	c3                   	retq   

00000000000019e6 <_ZNSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv>:
    19e6:	f3 0f 1e fa          	endbr64 
    19ea:	55                   	push   %rbp
    19eb:	48 89 e5             	mov    %rsp,%rbp
    19ee:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    19f2:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    19f6:	5d                   	pop    %rbp
    19f7:	c3                   	retq   

00000000000019f8 <_ZSt8_DestroyIPffEvT_S1_RSaIT0_E>:
    19f8:	f3 0f 1e fa          	endbr64 
    19fc:	55                   	push   %rbp
    19fd:	48 89 e5             	mov    %rsp,%rbp
    1a00:	48 83 ec 20          	sub    $0x20,%rsp
    1a04:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1a08:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    1a0c:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    1a10:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    1a14:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1a18:	48 89 d6             	mov    %rdx,%rsi
    1a1b:	48 89 c7             	mov    %rax,%rdi
    1a1e:	e8 05 02 00 00       	callq  1c28 <_ZSt8_DestroyIPfEvT_S1_>
    1a23:	90                   	nop
    1a24:	c9                   	leaveq 
    1a25:	c3                   	retq   

0000000000001a26 <_ZNSt12_Vector_baseIfSaIfEE17_Vector_impl_dataC1Ev>:
    1a26:	f3 0f 1e fa          	endbr64 
    1a2a:	55                   	push   %rbp
    1a2b:	48 89 e5             	mov    %rsp,%rbp
    1a2e:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1a32:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1a36:	48 c7 00 00 00 00 00 	movq   $0x0,(%rax)
    1a3d:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1a41:	48 c7 40 08 00 00 00 	movq   $0x0,0x8(%rax)
    1a48:	00 
    1a49:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1a4d:	48 c7 40 10 00 00 00 	movq   $0x0,0x10(%rax)
    1a54:	00 
    1a55:	90                   	nop
    1a56:	5d                   	pop    %rbp
    1a57:	c3                   	retq   

0000000000001a58 <_ZNSt12_Vector_baseIfSaIfEE13_M_deallocateEPfm>:
    1a58:	f3 0f 1e fa          	endbr64 
    1a5c:	55                   	push   %rbp
    1a5d:	48 89 e5             	mov    %rsp,%rbp
    1a60:	48 83 ec 20          	sub    $0x20,%rsp
    1a64:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1a68:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    1a6c:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    1a70:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
    1a75:	74 17                	je     1a8e <_ZNSt12_Vector_baseIfSaIfEE13_M_deallocateEPfm+0x36>
    1a77:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1a7b:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    1a7f:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
    1a83:	48 89 ce             	mov    %rcx,%rsi
    1a86:	48 89 c7             	mov    %rax,%rdi
    1a89:	e8 c4 01 00 00       	callq  1c52 <_ZNSt16allocator_traitsISaIfEE10deallocateERS0_Pfm>
    1a8e:	90                   	nop
    1a8f:	c9                   	leaveq 
    1a90:	c3                   	retq   
    1a91:	90                   	nop

0000000000001a92 <_ZNSt12_Vector_baseIfSaIfEE12_Vector_implC1ERKS0_>:
    1a92:	f3 0f 1e fa          	endbr64 
    1a96:	55                   	push   %rbp
    1a97:	48 89 e5             	mov    %rsp,%rbp
    1a9a:	48 83 ec 10          	sub    $0x10,%rsp
    1a9e:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1aa2:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    1aa6:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    1aaa:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1aae:	48 89 d6             	mov    %rdx,%rsi
    1ab1:	48 89 c7             	mov    %rax,%rdi
    1ab4:	e8 cb 01 00 00       	callq  1c84 <_ZNSaIfEC1ERKS_>
    1ab9:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1abd:	48 89 c7             	mov    %rax,%rdi
    1ac0:	e8 61 ff ff ff       	callq  1a26 <_ZNSt12_Vector_baseIfSaIfEE17_Vector_impl_dataC1Ev>
    1ac5:	90                   	nop
    1ac6:	c9                   	leaveq 
    1ac7:	c3                   	retq   

0000000000001ac8 <_ZNKSt16initializer_listIfE4sizeEv>:
    1ac8:	f3 0f 1e fa          	endbr64 
    1acc:	55                   	push   %rbp
    1acd:	48 89 e5             	mov    %rsp,%rbp
    1ad0:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1ad4:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1ad8:	48 8b 40 08          	mov    0x8(%rax),%rax
    1adc:	5d                   	pop    %rbp
    1add:	c3                   	retq   

0000000000001ade <_ZSt8distanceIPKfENSt15iterator_traitsIT_E15difference_typeES3_S3_>:
    1ade:	f3 0f 1e fa          	endbr64 
    1ae2:	55                   	push   %rbp
    1ae3:	48 89 e5             	mov    %rsp,%rbp
    1ae6:	48 83 ec 20          	sub    $0x20,%rsp
    1aea:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    1aee:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    1af2:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1af9:	00 00 
    1afb:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1aff:	31 c0                	xor    %eax,%eax
    1b01:	48 8d 45 e8          	lea    -0x18(%rbp),%rax
    1b05:	48 89 c7             	mov    %rax,%rdi
    1b08:	e8 a1 01 00 00       	callq  1cae <_ZSt19__iterator_categoryIPKfENSt15iterator_traitsIT_E17iterator_categoryERKS3_>
    1b0d:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1b11:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    1b15:	48 89 d6             	mov    %rdx,%rsi
    1b18:	48 89 c7             	mov    %rax,%rdi
    1b1b:	e8 9c 01 00 00       	callq  1cbc <_ZSt10__distanceIPKfENSt15iterator_traitsIT_E15difference_typeES3_S3_St26random_access_iterator_tag>
    1b20:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
    1b24:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
    1b2b:	00 00 
    1b2d:	74 05                	je     1b34 <_ZSt8distanceIPKfENSt15iterator_traitsIT_E15difference_typeES3_S3_+0x56>
    1b2f:	e8 2c f6 ff ff       	callq  1160 <__stack_chk_fail@plt>
    1b34:	c9                   	leaveq 
    1b35:	c3                   	retq   

0000000000001b36 <_ZNSt6vectorIfSaIfEE17_S_check_init_lenEmRKS0_>:
    1b36:	f3 0f 1e fa          	endbr64 
    1b3a:	55                   	push   %rbp
    1b3b:	48 89 e5             	mov    %rsp,%rbp
    1b3e:	53                   	push   %rbx
    1b3f:	48 83 ec 28          	sub    $0x28,%rsp
    1b43:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
    1b47:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
    1b4b:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1b52:	00 00 
    1b54:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    1b58:	31 c0                	xor    %eax,%eax
    1b5a:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
    1b5e:	48 8d 45 e7          	lea    -0x19(%rbp),%rax
    1b62:	48 89 d6             	mov    %rdx,%rsi
    1b65:	48 89 c7             	mov    %rax,%rdi
    1b68:	e8 17 01 00 00       	callq  1c84 <_ZNSaIfEC1ERKS_>
    1b6d:	48 8d 45 e7          	lea    -0x19(%rbp),%rax
    1b71:	48 89 c7             	mov    %rax,%rdi
    1b74:	e8 61 01 00 00       	callq  1cda <_ZNSt6vectorIfSaIfEE11_S_max_sizeERKS0_>
    1b79:	48 39 45 d8          	cmp    %rax,-0x28(%rbp)
    1b7d:	0f 97 c3             	seta   %bl
    1b80:	48 8d 45 e7          	lea    -0x19(%rbp),%rax
    1b84:	48 89 c7             	mov    %rax,%rdi
    1b87:	e8 4e fb ff ff       	callq  16da <_ZNSaIfED1Ev>
    1b8c:	84 db                	test   %bl,%bl
    1b8e:	74 0c                	je     1b9c <_ZNSt6vectorIfSaIfEE17_S_check_init_lenEmRKS0_+0x66>
    1b90:	48 8d 3d 81 14 00 00 	lea    0x1481(%rip),%rdi        # 3018 <_ZStL19piecewise_construct+0x10>
    1b97:	e8 64 f5 ff ff       	callq  1100 <_ZSt20__throw_length_errorPKc@plt>
    1b9c:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    1ba0:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
    1ba4:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
    1bab:	00 00 
    1bad:	74 05                	je     1bb4 <_ZNSt6vectorIfSaIfEE17_S_check_init_lenEmRKS0_+0x7e>
    1baf:	e8 ac f5 ff ff       	callq  1160 <__stack_chk_fail@plt>
    1bb4:	48 83 c4 28          	add    $0x28,%rsp
    1bb8:	5b                   	pop    %rbx
    1bb9:	5d                   	pop    %rbp
    1bba:	c3                   	retq   
    1bbb:	90                   	nop

0000000000001bbc <_ZNSt12_Vector_baseIfSaIfEE11_M_allocateEm>:
    1bbc:	f3 0f 1e fa          	endbr64 
    1bc0:	55                   	push   %rbp
    1bc1:	48 89 e5             	mov    %rsp,%rbp
    1bc4:	48 83 ec 10          	sub    $0x10,%rsp
    1bc8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1bcc:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    1bd0:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
    1bd5:	74 15                	je     1bec <_ZNSt12_Vector_baseIfSaIfEE11_M_allocateEm+0x30>
    1bd7:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1bdb:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    1bdf:	48 89 d6             	mov    %rdx,%rsi
    1be2:	48 89 c7             	mov    %rax,%rdi
    1be5:	e8 59 01 00 00       	callq  1d43 <_ZNSt16allocator_traitsISaIfEE8allocateERS0_m>
    1bea:	eb 05                	jmp    1bf1 <_ZNSt12_Vector_baseIfSaIfEE11_M_allocateEm+0x35>
    1bec:	b8 00 00 00 00       	mov    $0x0,%eax
    1bf1:	c9                   	leaveq 
    1bf2:	c3                   	retq   

0000000000001bf3 <_ZSt22__uninitialized_copy_aIPKfPffET0_T_S4_S3_RSaIT1_E>:
    1bf3:	f3 0f 1e fa          	endbr64 
    1bf7:	55                   	push   %rbp
    1bf8:	48 89 e5             	mov    %rsp,%rbp
    1bfb:	48 83 ec 20          	sub    $0x20,%rsp
    1bff:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1c03:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    1c07:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    1c0b:	48 89 4d e0          	mov    %rcx,-0x20(%rbp)
    1c0f:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    1c13:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
    1c17:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1c1b:	48 89 ce             	mov    %rcx,%rsi
    1c1e:	48 89 c7             	mov    %rax,%rdi
    1c21:	e8 4b 01 00 00       	callq  1d71 <_ZSt18uninitialized_copyIPKfPfET0_T_S4_S3_>
    1c26:	c9                   	leaveq 
    1c27:	c3                   	retq   

0000000000001c28 <_ZSt8_DestroyIPfEvT_S1_>:
    1c28:	f3 0f 1e fa          	endbr64 
    1c2c:	55                   	push   %rbp
    1c2d:	48 89 e5             	mov    %rsp,%rbp
    1c30:	48 83 ec 10          	sub    $0x10,%rsp
    1c34:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1c38:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    1c3c:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    1c40:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1c44:	48 89 d6             	mov    %rdx,%rsi
    1c47:	48 89 c7             	mov    %rax,%rdi
    1c4a:	e8 57 01 00 00       	callq  1da6 <_ZNSt12_Destroy_auxILb1EE9__destroyIPfEEvT_S3_>
    1c4f:	90                   	nop
    1c50:	c9                   	leaveq 
    1c51:	c3                   	retq   

0000000000001c52 <_ZNSt16allocator_traitsISaIfEE10deallocateERS0_Pfm>:
    1c52:	f3 0f 1e fa          	endbr64 
    1c56:	55                   	push   %rbp
    1c57:	48 89 e5             	mov    %rsp,%rbp
    1c5a:	48 83 ec 20          	sub    $0x20,%rsp
    1c5e:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1c62:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    1c66:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    1c6a:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    1c6e:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
    1c72:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1c76:	48 89 ce             	mov    %rcx,%rsi
    1c79:	48 89 c7             	mov    %rax,%rdi
    1c7c:	e8 39 01 00 00       	callq  1dba <_ZN9__gnu_cxx13new_allocatorIfE10deallocateEPfm>
    1c81:	90                   	nop
    1c82:	c9                   	leaveq 
    1c83:	c3                   	retq   

0000000000001c84 <_ZNSaIfEC1ERKS_>:
    1c84:	f3 0f 1e fa          	endbr64 
    1c88:	55                   	push   %rbp
    1c89:	48 89 e5             	mov    %rsp,%rbp
    1c8c:	48 83 ec 10          	sub    $0x10,%rsp
    1c90:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1c94:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    1c98:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    1c9c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1ca0:	48 89 d6             	mov    %rdx,%rsi
    1ca3:	48 89 c7             	mov    %rax,%rdi
    1ca6:	e8 37 01 00 00       	callq  1de2 <_ZN9__gnu_cxx13new_allocatorIfEC1ERKS1_>
    1cab:	90                   	nop
    1cac:	c9                   	leaveq 
    1cad:	c3                   	retq   

0000000000001cae <_ZSt19__iterator_categoryIPKfENSt15iterator_traitsIT_E17iterator_categoryERKS3_>:
    1cae:	f3 0f 1e fa          	endbr64 
    1cb2:	55                   	push   %rbp
    1cb3:	48 89 e5             	mov    %rsp,%rbp
    1cb6:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1cba:	5d                   	pop    %rbp
    1cbb:	c3                   	retq   

0000000000001cbc <_ZSt10__distanceIPKfENSt15iterator_traitsIT_E15difference_typeES3_S3_St26random_access_iterator_tag>:
    1cbc:	f3 0f 1e fa          	endbr64 
    1cc0:	55                   	push   %rbp
    1cc1:	48 89 e5             	mov    %rsp,%rbp
    1cc4:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1cc8:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    1ccc:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    1cd0:	48 2b 45 f8          	sub    -0x8(%rbp),%rax
    1cd4:	48 c1 f8 02          	sar    $0x2,%rax
    1cd8:	5d                   	pop    %rbp
    1cd9:	c3                   	retq   

0000000000001cda <_ZNSt6vectorIfSaIfEE11_S_max_sizeERKS0_>:
    1cda:	f3 0f 1e fa          	endbr64 
    1cde:	55                   	push   %rbp
    1cdf:	48 89 e5             	mov    %rsp,%rbp
    1ce2:	48 83 ec 30          	sub    $0x30,%rsp
    1ce6:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
    1cea:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1cf1:	00 00 
    1cf3:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1cf7:	31 c0                	xor    %eax,%eax
    1cf9:	48 b8 ff ff ff ff ff 	movabs $0x1fffffffffffffff,%rax
    1d00:	ff ff 1f 
    1d03:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    1d07:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    1d0b:	48 89 c7             	mov    %rax,%rdi
    1d0e:	e8 e2 00 00 00       	callq  1df5 <_ZNSt16allocator_traitsISaIfEE8max_sizeERKS0_>
    1d13:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    1d17:	48 8d 55 f0          	lea    -0x10(%rbp),%rdx
    1d1b:	48 8d 45 e8          	lea    -0x18(%rbp),%rax
    1d1f:	48 89 d6             	mov    %rdx,%rsi
    1d22:	48 89 c7             	mov    %rax,%rdi
    1d25:	e8 e9 00 00 00       	callq  1e13 <_ZSt3minImERKT_S2_S2_>
    1d2a:	48 8b 00             	mov    (%rax),%rax
    1d2d:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
    1d31:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
    1d38:	00 00 
    1d3a:	74 05                	je     1d41 <_ZNSt6vectorIfSaIfEE11_S_max_sizeERKS0_+0x67>
    1d3c:	e8 1f f4 ff ff       	callq  1160 <__stack_chk_fail@plt>
    1d41:	c9                   	leaveq 
    1d42:	c3                   	retq   

0000000000001d43 <_ZNSt16allocator_traitsISaIfEE8allocateERS0_m>:
    1d43:	f3 0f 1e fa          	endbr64 
    1d47:	55                   	push   %rbp
    1d48:	48 89 e5             	mov    %rsp,%rbp
    1d4b:	48 83 ec 10          	sub    $0x10,%rsp
    1d4f:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1d53:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    1d57:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
    1d5b:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1d5f:	ba 00 00 00 00       	mov    $0x0,%edx
    1d64:	48 89 ce             	mov    %rcx,%rsi
    1d67:	48 89 c7             	mov    %rax,%rdi
    1d6a:	e8 d3 00 00 00       	callq  1e42 <_ZN9__gnu_cxx13new_allocatorIfE8allocateEmPKv>
    1d6f:	c9                   	leaveq 
    1d70:	c3                   	retq   

0000000000001d71 <_ZSt18uninitialized_copyIPKfPfET0_T_S4_S3_>:
    1d71:	f3 0f 1e fa          	endbr64 
    1d75:	55                   	push   %rbp
    1d76:	48 89 e5             	mov    %rsp,%rbp
    1d79:	48 83 ec 30          	sub    $0x30,%rsp
    1d7d:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    1d81:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    1d85:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    1d89:	c6 45 ff 01          	movb   $0x1,-0x1(%rbp)
    1d8d:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    1d91:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
    1d95:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1d99:	48 89 ce             	mov    %rcx,%rsi
    1d9c:	48 89 c7             	mov    %rax,%rdi
    1d9f:	e8 e4 00 00 00       	callq  1e88 <_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIPKfPfEET0_T_S6_S5_>
    1da4:	c9                   	leaveq 
    1da5:	c3                   	retq   

0000000000001da6 <_ZNSt12_Destroy_auxILb1EE9__destroyIPfEEvT_S3_>:
    1da6:	f3 0f 1e fa          	endbr64 
    1daa:	55                   	push   %rbp
    1dab:	48 89 e5             	mov    %rsp,%rbp
    1dae:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1db2:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    1db6:	90                   	nop
    1db7:	5d                   	pop    %rbp
    1db8:	c3                   	retq   
    1db9:	90                   	nop

0000000000001dba <_ZN9__gnu_cxx13new_allocatorIfE10deallocateEPfm>:
    1dba:	f3 0f 1e fa          	endbr64 
    1dbe:	55                   	push   %rbp
    1dbf:	48 89 e5             	mov    %rsp,%rbp
    1dc2:	48 83 ec 20          	sub    $0x20,%rsp
    1dc6:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1dca:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    1dce:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    1dd2:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    1dd6:	48 89 c7             	mov    %rax,%rdi
    1dd9:	e8 52 f3 ff ff       	callq  1130 <_ZdlPv@plt>
    1dde:	90                   	nop
    1ddf:	c9                   	leaveq 
    1de0:	c3                   	retq   
    1de1:	90                   	nop

0000000000001de2 <_ZN9__gnu_cxx13new_allocatorIfEC1ERKS1_>:
    1de2:	f3 0f 1e fa          	endbr64 
    1de6:	55                   	push   %rbp
    1de7:	48 89 e5             	mov    %rsp,%rbp
    1dea:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1dee:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    1df2:	90                   	nop
    1df3:	5d                   	pop    %rbp
    1df4:	c3                   	retq   

0000000000001df5 <_ZNSt16allocator_traitsISaIfEE8max_sizeERKS0_>:
    1df5:	f3 0f 1e fa          	endbr64 
    1df9:	55                   	push   %rbp
    1dfa:	48 89 e5             	mov    %rsp,%rbp
    1dfd:	48 83 ec 10          	sub    $0x10,%rsp
    1e01:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1e05:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1e09:	48 89 c7             	mov    %rax,%rdi
    1e0c:	e8 a9 00 00 00       	callq  1eba <_ZNK9__gnu_cxx13new_allocatorIfE8max_sizeEv>
    1e11:	c9                   	leaveq 
    1e12:	c3                   	retq   

0000000000001e13 <_ZSt3minImERKT_S2_S2_>:
    1e13:	f3 0f 1e fa          	endbr64 
    1e17:	55                   	push   %rbp
    1e18:	48 89 e5             	mov    %rsp,%rbp
    1e1b:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1e1f:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    1e23:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    1e27:	48 8b 10             	mov    (%rax),%rdx
    1e2a:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1e2e:	48 8b 00             	mov    (%rax),%rax
    1e31:	48 39 c2             	cmp    %rax,%rdx
    1e34:	73 06                	jae    1e3c <_ZSt3minImERKT_S2_S2_+0x29>
    1e36:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    1e3a:	eb 04                	jmp    1e40 <_ZSt3minImERKT_S2_S2_+0x2d>
    1e3c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1e40:	5d                   	pop    %rbp
    1e41:	c3                   	retq   

0000000000001e42 <_ZN9__gnu_cxx13new_allocatorIfE8allocateEmPKv>:
    1e42:	f3 0f 1e fa          	endbr64 
    1e46:	55                   	push   %rbp
    1e47:	48 89 e5             	mov    %rsp,%rbp
    1e4a:	48 83 ec 20          	sub    $0x20,%rsp
    1e4e:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1e52:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    1e56:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    1e5a:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1e5e:	48 89 c7             	mov    %rax,%rdi
    1e61:	e8 54 00 00 00       	callq  1eba <_ZNK9__gnu_cxx13new_allocatorIfE8max_sizeEv>
    1e66:	48 39 45 f0          	cmp    %rax,-0x10(%rbp)
    1e6a:	0f 97 c0             	seta   %al
    1e6d:	84 c0                	test   %al,%al
    1e6f:	74 05                	je     1e76 <_ZN9__gnu_cxx13new_allocatorIfE8allocateEmPKv+0x34>
    1e71:	e8 7a f2 ff ff       	callq  10f0 <_ZSt17__throw_bad_allocv@plt>
    1e76:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    1e7a:	48 c1 e0 02          	shl    $0x2,%rax
    1e7e:	48 89 c7             	mov    %rax,%rdi
    1e81:	e8 ca f2 ff ff       	callq  1150 <_Znwm@plt>
    1e86:	c9                   	leaveq 
    1e87:	c3                   	retq   

0000000000001e88 <_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIPKfPfEET0_T_S6_S5_>:
    1e88:	f3 0f 1e fa          	endbr64 
    1e8c:	55                   	push   %rbp
    1e8d:	48 89 e5             	mov    %rsp,%rbp
    1e90:	48 83 ec 20          	sub    $0x20,%rsp
    1e94:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1e98:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    1e9c:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    1ea0:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    1ea4:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
    1ea8:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1eac:	48 89 ce             	mov    %rcx,%rsi
    1eaf:	48 89 c7             	mov    %rax,%rdi
    1eb2:	e8 1b 00 00 00       	callq  1ed2 <_ZSt4copyIPKfPfET0_T_S4_S3_>
    1eb7:	c9                   	leaveq 
    1eb8:	c3                   	retq   
    1eb9:	90                   	nop

0000000000001eba <_ZNK9__gnu_cxx13new_allocatorIfE8max_sizeEv>:
    1eba:	f3 0f 1e fa          	endbr64 
    1ebe:	55                   	push   %rbp
    1ebf:	48 89 e5             	mov    %rsp,%rbp
    1ec2:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1ec6:	48 b8 ff ff ff ff ff 	movabs $0x1fffffffffffffff,%rax
    1ecd:	ff ff 1f 
    1ed0:	5d                   	pop    %rbp
    1ed1:	c3                   	retq   

0000000000001ed2 <_ZSt4copyIPKfPfET0_T_S4_S3_>:
    1ed2:	f3 0f 1e fa          	endbr64 
    1ed6:	55                   	push   %rbp
    1ed7:	48 89 e5             	mov    %rsp,%rbp
    1eda:	53                   	push   %rbx
    1edb:	48 83 ec 28          	sub    $0x28,%rsp
    1edf:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    1ee3:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    1ee7:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    1eeb:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    1eef:	48 89 c7             	mov    %rax,%rdi
    1ef2:	e8 2b 00 00 00       	callq  1f22 <_ZSt12__miter_baseIPKfET_S2_>
    1ef7:	48 89 c3             	mov    %rax,%rbx
    1efa:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1efe:	48 89 c7             	mov    %rax,%rdi
    1f01:	e8 1c 00 00 00       	callq  1f22 <_ZSt12__miter_baseIPKfET_S2_>
    1f06:	48 89 c1             	mov    %rax,%rcx
    1f09:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    1f0d:	48 89 c2             	mov    %rax,%rdx
    1f10:	48 89 de             	mov    %rbx,%rsi
    1f13:	48 89 cf             	mov    %rcx,%rdi
    1f16:	e8 19 00 00 00       	callq  1f34 <_ZSt14__copy_move_a2ILb0EPKfPfET1_T0_S4_S3_>
    1f1b:	48 83 c4 28          	add    $0x28,%rsp
    1f1f:	5b                   	pop    %rbx
    1f20:	5d                   	pop    %rbp
    1f21:	c3                   	retq   

0000000000001f22 <_ZSt12__miter_baseIPKfET_S2_>:
    1f22:	f3 0f 1e fa          	endbr64 
    1f26:	55                   	push   %rbp
    1f27:	48 89 e5             	mov    %rsp,%rbp
    1f2a:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1f2e:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1f32:	5d                   	pop    %rbp
    1f33:	c3                   	retq   

0000000000001f34 <_ZSt14__copy_move_a2ILb0EPKfPfET1_T0_S4_S3_>:
    1f34:	f3 0f 1e fa          	endbr64 
    1f38:	55                   	push   %rbp
    1f39:	48 89 e5             	mov    %rsp,%rbp
    1f3c:	41 54                	push   %r12
    1f3e:	53                   	push   %rbx
    1f3f:	48 83 ec 20          	sub    $0x20,%rsp
    1f43:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    1f47:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    1f4b:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    1f4f:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    1f53:	48 89 c7             	mov    %rax,%rdi
    1f56:	e8 59 00 00 00       	callq  1fb4 <_ZSt12__niter_baseIPfET_S1_>
    1f5b:	49 89 c4             	mov    %rax,%r12
    1f5e:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    1f62:	48 89 c7             	mov    %rax,%rdi
    1f65:	e8 38 00 00 00       	callq  1fa2 <_ZSt12__niter_baseIPKfET_S2_>
    1f6a:	48 89 c3             	mov    %rax,%rbx
    1f6d:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1f71:	48 89 c7             	mov    %rax,%rdi
    1f74:	e8 29 00 00 00       	callq  1fa2 <_ZSt12__niter_baseIPKfET_S2_>
    1f79:	4c 89 e2             	mov    %r12,%rdx
    1f7c:	48 89 de             	mov    %rbx,%rsi
    1f7f:	48 89 c7             	mov    %rax,%rdi
    1f82:	e8 3f 00 00 00       	callq  1fc6 <_ZSt13__copy_move_aILb0EPKfPfET1_T0_S4_S3_>
    1f87:	48 89 c2             	mov    %rax,%rdx
    1f8a:	48 8d 45 d8          	lea    -0x28(%rbp),%rax
    1f8e:	48 89 d6             	mov    %rdx,%rsi
    1f91:	48 89 c7             	mov    %rax,%rdi
    1f94:	e8 62 00 00 00       	callq  1ffb <_ZSt12__niter_wrapIPfET_RKS1_S1_>
    1f99:	48 83 c4 20          	add    $0x20,%rsp
    1f9d:	5b                   	pop    %rbx
    1f9e:	41 5c                	pop    %r12
    1fa0:	5d                   	pop    %rbp
    1fa1:	c3                   	retq   

0000000000001fa2 <_ZSt12__niter_baseIPKfET_S2_>:
    1fa2:	f3 0f 1e fa          	endbr64 
    1fa6:	55                   	push   %rbp
    1fa7:	48 89 e5             	mov    %rsp,%rbp
    1faa:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1fae:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1fb2:	5d                   	pop    %rbp
    1fb3:	c3                   	retq   

0000000000001fb4 <_ZSt12__niter_baseIPfET_S1_>:
    1fb4:	f3 0f 1e fa          	endbr64 
    1fb8:	55                   	push   %rbp
    1fb9:	48 89 e5             	mov    %rsp,%rbp
    1fbc:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1fc0:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1fc4:	5d                   	pop    %rbp
    1fc5:	c3                   	retq   

0000000000001fc6 <_ZSt13__copy_move_aILb0EPKfPfET1_T0_S4_S3_>:
    1fc6:	f3 0f 1e fa          	endbr64 
    1fca:	55                   	push   %rbp
    1fcb:	48 89 e5             	mov    %rsp,%rbp
    1fce:	48 83 ec 30          	sub    $0x30,%rsp
    1fd2:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    1fd6:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    1fda:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    1fde:	c6 45 ff 01          	movb   $0x1,-0x1(%rbp)
    1fe2:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    1fe6:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
    1fea:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1fee:	48 89 ce             	mov    %rcx,%rsi
    1ff1:	48 89 c7             	mov    %rax,%rdi
    1ff4:	e8 18 00 00 00       	callq  2011 <_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIfEEPT_PKS3_S6_S4_>
    1ff9:	c9                   	leaveq 
    1ffa:	c3                   	retq   

0000000000001ffb <_ZSt12__niter_wrapIPfET_RKS1_S1_>:
    1ffb:	f3 0f 1e fa          	endbr64 
    1fff:	55                   	push   %rbp
    2000:	48 89 e5             	mov    %rsp,%rbp
    2003:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    2007:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    200b:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    200f:	5d                   	pop    %rbp
    2010:	c3                   	retq   

0000000000002011 <_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIfEEPT_PKS3_S6_S4_>:
    2011:	f3 0f 1e fa          	endbr64 
    2015:	55                   	push   %rbp
    2016:	48 89 e5             	mov    %rsp,%rbp
    2019:	48 83 ec 30          	sub    $0x30,%rsp
    201d:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    2021:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    2025:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    2029:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    202d:	48 2b 45 e8          	sub    -0x18(%rbp),%rax
    2031:	48 c1 f8 02          	sar    $0x2,%rax
    2035:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    2039:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    203e:	74 1f                	je     205f <_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIfEEPT_PKS3_S6_S4_+0x4e>
    2040:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2044:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    204b:	00 
    204c:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
    2050:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2054:	48 89 ce             	mov    %rcx,%rsi
    2057:	48 89 c7             	mov    %rax,%rdi
    205a:	e8 21 f1 ff ff       	callq  1180 <memmove@plt>
    205f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2063:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    206a:	00 
    206b:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    206f:	48 01 d0             	add    %rdx,%rax
    2072:	c9                   	leaveq 
    2073:	c3                   	retq   
    2074:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    207b:	00 00 00 
    207e:	66 90                	xchg   %ax,%ax

0000000000002080 <__libc_csu_init>:
    2080:	f3 0f 1e fa          	endbr64 
    2084:	41 57                	push   %r15
    2086:	4c 8d 3d ab 2c 00 00 	lea    0x2cab(%rip),%r15        # 4d38 <__frame_dummy_init_array_entry>
    208d:	41 56                	push   %r14
    208f:	49 89 d6             	mov    %rdx,%r14
    2092:	41 55                	push   %r13
    2094:	49 89 f5             	mov    %rsi,%r13
    2097:	41 54                	push   %r12
    2099:	41 89 fc             	mov    %edi,%r12d
    209c:	55                   	push   %rbp
    209d:	48 8d 2d a4 2c 00 00 	lea    0x2ca4(%rip),%rbp        # 4d48 <__do_global_dtors_aux_fini_array_entry>
    20a4:	53                   	push   %rbx
    20a5:	4c 29 fd             	sub    %r15,%rbp
    20a8:	48 83 ec 08          	sub    $0x8,%rsp
    20ac:	e8 4f ef ff ff       	callq  1000 <_init>
    20b1:	48 c1 fd 03          	sar    $0x3,%rbp
    20b5:	74 1f                	je     20d6 <__libc_csu_init+0x56>
    20b7:	31 db                	xor    %ebx,%ebx
    20b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    20c0:	4c 89 f2             	mov    %r14,%rdx
    20c3:	4c 89 ee             	mov    %r13,%rsi
    20c6:	44 89 e7             	mov    %r12d,%edi
    20c9:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    20cd:	48 83 c3 01          	add    $0x1,%rbx
    20d1:	48 39 dd             	cmp    %rbx,%rbp
    20d4:	75 ea                	jne    20c0 <__libc_csu_init+0x40>
    20d6:	48 83 c4 08          	add    $0x8,%rsp
    20da:	5b                   	pop    %rbx
    20db:	5d                   	pop    %rbp
    20dc:	41 5c                	pop    %r12
    20de:	41 5d                	pop    %r13
    20e0:	41 5e                	pop    %r14
    20e2:	41 5f                	pop    %r15
    20e4:	c3                   	retq   
    20e5:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    20ec:	00 00 00 00 

00000000000020f0 <__libc_csu_fini>:
    20f0:	f3 0f 1e fa          	endbr64 
    20f4:	c3                   	retq   

Disassembly of section .fini:

00000000000020f8 <_fini>:
    20f8:	f3 0f 1e fa          	endbr64 
    20fc:	48 83 ec 08          	sub    $0x8,%rsp
    2100:	48 83 c4 08          	add    $0x8,%rsp
    2104:	c3                   	retq   
