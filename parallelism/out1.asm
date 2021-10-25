
avx:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	callq  *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	retq   

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 72 2f 00 00    	pushq  0x2f72(%rip)        # 3f98 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 73 2f 00 00 	bnd jmpq *0x2f73(%rip)        # 3fa0 <_GLOBAL_OFFSET_TABLE_+0x10>
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

Disassembly of section .plt.got:

0000000000001080 <__cxa_finalize@plt>:
    1080:	f3 0f 1e fa          	endbr64 
    1084:	f2 ff 25 45 2f 00 00 	bnd jmpq *0x2f45(%rip)        # 3fd0 <__cxa_finalize@GLIBC_2.2.5>
    108b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001090 <_ZNSolsEf@plt>:
    1090:	f3 0f 1e fa          	endbr64 
    1094:	f2 ff 25 0d 2f 00 00 	bnd jmpq *0x2f0d(%rip)        # 3fa8 <_ZNSolsEf@GLIBCXX_3.4>
    109b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010a0 <__cxa_atexit@plt>:
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	f2 ff 25 05 2f 00 00 	bnd jmpq *0x2f05(%rip)        # 3fb0 <__cxa_atexit@GLIBC_2.2.5>
    10ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010b0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>:
    10b0:	f3 0f 1e fa          	endbr64 
    10b4:	f2 ff 25 fd 2e 00 00 	bnd jmpq *0x2efd(%rip)        # 3fb8 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GLIBCXX_3.4>
    10bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010c0 <__stack_chk_fail@plt>:
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	f2 ff 25 f5 2e 00 00 	bnd jmpq *0x2ef5(%rip)        # 3fc0 <__stack_chk_fail@GLIBC_2.4>
    10cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010d0 <_ZNSt8ios_base4InitC1Ev@plt>:
    10d0:	f3 0f 1e fa          	endbr64 
    10d4:	f2 ff 25 ed 2e 00 00 	bnd jmpq *0x2eed(%rip)        # 3fc8 <_ZNSt8ios_base4InitC1Ev@GLIBCXX_3.4>
    10db:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

00000000000010e0 <_start>:
    10e0:	f3 0f 1e fa          	endbr64 
    10e4:	31 ed                	xor    %ebp,%ebp
    10e6:	49 89 d1             	mov    %rdx,%r9
    10e9:	5e                   	pop    %rsi
    10ea:	48 89 e2             	mov    %rsp,%rdx
    10ed:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    10f1:	50                   	push   %rax
    10f2:	54                   	push   %rsp
    10f3:	4c 8d 05 76 04 00 00 	lea    0x476(%rip),%r8        # 1570 <__libc_csu_fini>
    10fa:	48 8d 0d ff 03 00 00 	lea    0x3ff(%rip),%rcx        # 1500 <__libc_csu_init>
    1101:	48 8d 3d c1 00 00 00 	lea    0xc1(%rip),%rdi        # 11c9 <main>
    1108:	ff 15 d2 2e 00 00    	callq  *0x2ed2(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    110e:	f4                   	hlt    
    110f:	90                   	nop

0000000000001110 <deregister_tm_clones>:
    1110:	48 8d 3d f9 2e 00 00 	lea    0x2ef9(%rip),%rdi        # 4010 <__TMC_END__>
    1117:	48 8d 05 f2 2e 00 00 	lea    0x2ef2(%rip),%rax        # 4010 <__TMC_END__>
    111e:	48 39 f8             	cmp    %rdi,%rax
    1121:	74 15                	je     1138 <deregister_tm_clones+0x28>
    1123:	48 8b 05 ae 2e 00 00 	mov    0x2eae(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    112a:	48 85 c0             	test   %rax,%rax
    112d:	74 09                	je     1138 <deregister_tm_clones+0x28>
    112f:	ff e0                	jmpq   *%rax
    1131:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1138:	c3                   	retq   
    1139:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001140 <register_tm_clones>:
    1140:	48 8d 3d c9 2e 00 00 	lea    0x2ec9(%rip),%rdi        # 4010 <__TMC_END__>
    1147:	48 8d 35 c2 2e 00 00 	lea    0x2ec2(%rip),%rsi        # 4010 <__TMC_END__>
    114e:	48 29 fe             	sub    %rdi,%rsi
    1151:	48 89 f0             	mov    %rsi,%rax
    1154:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1158:	48 c1 f8 03          	sar    $0x3,%rax
    115c:	48 01 c6             	add    %rax,%rsi
    115f:	48 d1 fe             	sar    %rsi
    1162:	74 14                	je     1178 <register_tm_clones+0x38>
    1164:	48 8b 05 85 2e 00 00 	mov    0x2e85(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    116b:	48 85 c0             	test   %rax,%rax
    116e:	74 08                	je     1178 <register_tm_clones+0x38>
    1170:	ff e0                	jmpq   *%rax
    1172:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1178:	c3                   	retq   
    1179:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001180 <__do_global_dtors_aux>:
    1180:	f3 0f 1e fa          	endbr64 
    1184:	80 3d c5 2f 00 00 00 	cmpb   $0x0,0x2fc5(%rip)        # 4150 <completed.8060>
    118b:	75 2b                	jne    11b8 <__do_global_dtors_aux+0x38>
    118d:	55                   	push   %rbp
    118e:	48 83 3d 3a 2e 00 00 	cmpq   $0x0,0x2e3a(%rip)        # 3fd0 <__cxa_finalize@GLIBC_2.2.5>
    1195:	00 
    1196:	48 89 e5             	mov    %rsp,%rbp
    1199:	74 0c                	je     11a7 <__do_global_dtors_aux+0x27>
    119b:	48 8b 3d 66 2e 00 00 	mov    0x2e66(%rip),%rdi        # 4008 <__dso_handle>
    11a2:	e8 d9 fe ff ff       	callq  1080 <__cxa_finalize@plt>
    11a7:	e8 64 ff ff ff       	callq  1110 <deregister_tm_clones>
    11ac:	c6 05 9d 2f 00 00 01 	movb   $0x1,0x2f9d(%rip)        # 4150 <completed.8060>
    11b3:	5d                   	pop    %rbp
    11b4:	c3                   	retq   
    11b5:	0f 1f 00             	nopl   (%rax)
    11b8:	c3                   	retq   
    11b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000011c0 <frame_dummy>:
    11c0:	f3 0f 1e fa          	endbr64 
    11c4:	e9 77 ff ff ff       	jmpq   1140 <register_tm_clones>

00000000000011c9 <main>:
    11c9:	f3 0f 1e fa          	endbr64 
    11cd:	4c 8d 54 24 08       	lea    0x8(%rsp),%r10
    11d2:	48 83 e4 e0          	and    $0xffffffffffffffe0,%rsp
    11d6:	41 ff 72 f8          	pushq  -0x8(%r10)
    11da:	55                   	push   %rbp
    11db:	48 89 e5             	mov    %rsp,%rbp
    11de:	41 52                	push   %r10
    11e0:	48 81 ec 28 01 00 00 	sub    $0x128,%rsp
    11e7:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    11ee:	00 00 
    11f0:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    11f4:	31 c0                	xor    %eax,%eax
    11f6:	c5 fa 10 05 12 0e 00 	vmovss 0xe12(%rip),%xmm0        # 2010 <_ZStL19piecewise_construct+0xc>
    11fd:	00 
    11fe:	c5 fa 11 85 08 ff ff 	vmovss %xmm0,-0xf8(%rbp)
    1205:	ff 
    1206:	c5 fa 10 05 06 0e 00 	vmovss 0xe06(%rip),%xmm0        # 2014 <_ZStL19piecewise_construct+0x10>
    120d:	00 
    120e:	c5 fa 11 85 0c ff ff 	vmovss %xmm0,-0xf4(%rbp)
    1215:	ff 
    1216:	c5 fa 10 05 fa 0d 00 	vmovss 0xdfa(%rip),%xmm0        # 2018 <_ZStL19piecewise_construct+0x14>
    121d:	00 
    121e:	c5 fa 11 85 10 ff ff 	vmovss %xmm0,-0xf0(%rbp)
    1225:	ff 
    1226:	c5 fa 10 05 ee 0d 00 	vmovss 0xdee(%rip),%xmm0        # 201c <_ZStL19piecewise_construct+0x18>
    122d:	00 
    122e:	c5 fa 11 85 14 ff ff 	vmovss %xmm0,-0xec(%rbp)
    1235:	ff 
    1236:	c5 fa 10 05 e2 0d 00 	vmovss 0xde2(%rip),%xmm0        # 2020 <_ZStL19piecewise_construct+0x1c>
    123d:	00 
    123e:	c5 fa 11 85 18 ff ff 	vmovss %xmm0,-0xe8(%rbp)
    1245:	ff 
    1246:	c5 fa 10 05 d6 0d 00 	vmovss 0xdd6(%rip),%xmm0        # 2024 <_ZStL19piecewise_construct+0x20>
    124d:	00 
    124e:	c5 fa 11 85 1c ff ff 	vmovss %xmm0,-0xe4(%rbp)
    1255:	ff 
    1256:	c5 fa 10 05 ca 0d 00 	vmovss 0xdca(%rip),%xmm0        # 2028 <_ZStL19piecewise_construct+0x24>
    125d:	00 
    125e:	c5 fa 11 85 20 ff ff 	vmovss %xmm0,-0xe0(%rbp)
    1265:	ff 
    1266:	c5 fa 10 05 be 0d 00 	vmovss 0xdbe(%rip),%xmm0        # 202c <_ZStL19piecewise_construct+0x28>
    126d:	00 
    126e:	c5 fa 11 85 24 ff ff 	vmovss %xmm0,-0xdc(%rbp)
    1275:	ff 
    1276:	c5 fa 10 8d 08 ff ff 	vmovss -0xf8(%rbp),%xmm1
    127d:	ff 
    127e:	c5 fa 10 85 0c ff ff 	vmovss -0xf4(%rbp),%xmm0
    1285:	ff 
    1286:	c5 f8 14 d1          	vunpcklps %xmm1,%xmm0,%xmm2
    128a:	c5 fa 10 8d 10 ff ff 	vmovss -0xf0(%rbp),%xmm1
    1291:	ff 
    1292:	c5 fa 10 85 14 ff ff 	vmovss -0xec(%rbp),%xmm0
    1299:	ff 
    129a:	c5 f8 14 c9          	vunpcklps %xmm1,%xmm0,%xmm1
    129e:	c5 fa 10 9d 18 ff ff 	vmovss -0xe8(%rbp),%xmm3
    12a5:	ff 
    12a6:	c5 fa 10 85 1c ff ff 	vmovss -0xe4(%rbp),%xmm0
    12ad:	ff 
    12ae:	c5 f8 14 db          	vunpcklps %xmm3,%xmm0,%xmm3
    12b2:	c5 fa 10 a5 20 ff ff 	vmovss -0xe0(%rbp),%xmm4
    12b9:	ff 
    12ba:	c5 fa 10 85 24 ff ff 	vmovss -0xdc(%rbp),%xmm0
    12c1:	ff 
    12c2:	c5 f8 14 c4          	vunpcklps %xmm4,%xmm0,%xmm0
    12c6:	c5 f8 16 c3          	vmovlhps %xmm3,%xmm0,%xmm0
    12ca:	c5 f0 16 ca          	vmovlhps %xmm2,%xmm1,%xmm1
    12ce:	c4 e3 7d 18 c1 01    	vinsertf128 $0x1,%xmm1,%ymm0,%ymm0
    12d4:	c5 fc 29 85 50 ff ff 	vmovaps %ymm0,-0xb0(%rbp)
    12db:	ff 
    12dc:	c5 fa 10 05 4c 0d 00 	vmovss 0xd4c(%rip),%xmm0        # 2030 <_ZStL19piecewise_construct+0x2c>
    12e3:	00 
    12e4:	c5 fa 11 85 e8 fe ff 	vmovss %xmm0,-0x118(%rbp)
    12eb:	ff 
    12ec:	c5 fa 10 05 40 0d 00 	vmovss 0xd40(%rip),%xmm0        # 2034 <_ZStL19piecewise_construct+0x30>
    12f3:	00 
    12f4:	c5 fa 11 85 ec fe ff 	vmovss %xmm0,-0x114(%rbp)
    12fb:	ff 
    12fc:	c5 fa 10 05 34 0d 00 	vmovss 0xd34(%rip),%xmm0        # 2038 <_ZStL19piecewise_construct+0x34>
    1303:	00 
    1304:	c5 fa 11 85 f0 fe ff 	vmovss %xmm0,-0x110(%rbp)
    130b:	ff 
    130c:	c5 fa 10 05 28 0d 00 	vmovss 0xd28(%rip),%xmm0        # 203c <_ZStL19piecewise_construct+0x38>
    1313:	00 
    1314:	c5 fa 11 85 f4 fe ff 	vmovss %xmm0,-0x10c(%rbp)
    131b:	ff 
    131c:	c5 fa 10 05 1c 0d 00 	vmovss 0xd1c(%rip),%xmm0        # 2040 <_ZStL19piecewise_construct+0x3c>
    1323:	00 
    1324:	c5 fa 11 85 f8 fe ff 	vmovss %xmm0,-0x108(%rbp)
    132b:	ff 
    132c:	c5 fa 10 05 10 0d 00 	vmovss 0xd10(%rip),%xmm0        # 2044 <_ZStL19piecewise_construct+0x40>
    1333:	00 
    1334:	c5 fa 11 85 fc fe ff 	vmovss %xmm0,-0x104(%rbp)
    133b:	ff 
    133c:	c5 fa 10 05 04 0d 00 	vmovss 0xd04(%rip),%xmm0        # 2048 <_ZStL19piecewise_construct+0x44>
    1343:	00 
    1344:	c5 fa 11 85 00 ff ff 	vmovss %xmm0,-0x100(%rbp)
    134b:	ff 
    134c:	c5 fa 10 05 f8 0c 00 	vmovss 0xcf8(%rip),%xmm0        # 204c <_ZStL19piecewise_construct+0x48>
    1353:	00 
    1354:	c5 fa 11 85 04 ff ff 	vmovss %xmm0,-0xfc(%rbp)
    135b:	ff 
    135c:	c5 fa 10 8d e8 fe ff 	vmovss -0x118(%rbp),%xmm1
    1363:	ff 
    1364:	c5 fa 10 85 ec fe ff 	vmovss -0x114(%rbp),%xmm0
    136b:	ff 
    136c:	c5 f8 14 d1          	vunpcklps %xmm1,%xmm0,%xmm2
    1370:	c5 fa 10 8d f0 fe ff 	vmovss -0x110(%rbp),%xmm1
    1377:	ff 
    1378:	c5 fa 10 85 f4 fe ff 	vmovss -0x10c(%rbp),%xmm0
    137f:	ff 
    1380:	c5 f8 14 c9          	vunpcklps %xmm1,%xmm0,%xmm1
    1384:	c5 fa 10 9d f8 fe ff 	vmovss -0x108(%rbp),%xmm3
    138b:	ff 
    138c:	c5 fa 10 85 fc fe ff 	vmovss -0x104(%rbp),%xmm0
    1393:	ff 
    1394:	c5 f8 14 db          	vunpcklps %xmm3,%xmm0,%xmm3
    1398:	c5 fa 10 a5 00 ff ff 	vmovss -0x100(%rbp),%xmm4
    139f:	ff 
    13a0:	c5 fa 10 85 04 ff ff 	vmovss -0xfc(%rbp),%xmm0
    13a7:	ff 
    13a8:	c5 f8 14 c4          	vunpcklps %xmm4,%xmm0,%xmm0
    13ac:	c5 f8 16 c3          	vmovlhps %xmm3,%xmm0,%xmm0
    13b0:	c5 f0 16 ca          	vmovlhps %xmm2,%xmm1,%xmm1
    13b4:	c4 e3 7d 18 c1 01    	vinsertf128 $0x1,%xmm1,%ymm0,%ymm0
    13ba:	c5 fc 29 85 70 ff ff 	vmovaps %ymm0,-0x90(%rbp)
    13c1:	ff 
    13c2:	c5 fc 28 85 50 ff ff 	vmovaps -0xb0(%rbp),%ymm0
    13c9:	ff 
    13ca:	c5 fc 29 45 90       	vmovaps %ymm0,-0x70(%rbp)
    13cf:	c5 fc 28 85 70 ff ff 	vmovaps -0x90(%rbp),%ymm0
    13d6:	ff 
    13d7:	c5 fc 29 45 b0       	vmovaps %ymm0,-0x50(%rbp)
    13dc:	c5 fc 28 45 90       	vmovaps -0x70(%rbp),%ymm0
    13e1:	c5 fc 5c 45 b0       	vsubps -0x50(%rbp),%ymm0,%ymm0
    13e6:	c5 fc 29 85 30 ff ff 	vmovaps %ymm0,-0xd0(%rbp)
    13ed:	ff 
    13ee:	48 8d 85 30 ff ff ff 	lea    -0xd0(%rbp),%rax
    13f5:	48 89 85 28 ff ff ff 	mov    %rax,-0xd8(%rbp)
    13fc:	48 8d 35 02 0c 00 00 	lea    0xc02(%rip),%rsi        # 2005 <_ZStL19piecewise_construct+0x1>
    1403:	48 8d 3d 36 2c 00 00 	lea    0x2c36(%rip),%rdi        # 4040 <_ZSt4cout@@GLIBCXX_3.4>
    140a:	e8 a1 fc ff ff       	callq  10b0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    140f:	c7 85 e4 fe ff ff 00 	movl   $0x0,-0x11c(%rbp)
    1416:	00 00 00 
    1419:	83 bd e4 fe ff ff 07 	cmpl   $0x7,-0x11c(%rbp)
    1420:	7f 44                	jg     1466 <main+0x29d>
    1422:	8b 85 e4 fe ff ff    	mov    -0x11c(%rbp),%eax
    1428:	48 98                	cltq   
    142a:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    1431:	00 
    1432:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    1439:	48 01 d0             	add    %rdx,%rax
    143c:	8b 00                	mov    (%rax),%eax
    143e:	c5 f9 6e c0          	vmovd  %eax,%xmm0
    1442:	48 8d 3d f7 2b 00 00 	lea    0x2bf7(%rip),%rdi        # 4040 <_ZSt4cout@@GLIBCXX_3.4>
    1449:	e8 42 fc ff ff       	callq  1090 <_ZNSolsEf@plt>
    144e:	48 8d 35 b9 0b 00 00 	lea    0xbb9(%rip),%rsi        # 200e <_ZStL19piecewise_construct+0xa>
    1455:	48 89 c7             	mov    %rax,%rdi
    1458:	e8 53 fc ff ff       	callq  10b0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    145d:	83 85 e4 fe ff ff 01 	addl   $0x1,-0x11c(%rbp)
    1464:	eb b3                	jmp    1419 <main+0x250>
    1466:	b8 00 00 00 00       	mov    $0x0,%eax
    146b:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
    146f:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
    1476:	00 00 
    1478:	74 05                	je     147f <main+0x2b6>
    147a:	e8 41 fc ff ff       	callq  10c0 <__stack_chk_fail@plt>
    147f:	48 81 c4 28 01 00 00 	add    $0x128,%rsp
    1486:	41 5a                	pop    %r10
    1488:	5d                   	pop    %rbp
    1489:	49 8d 62 f8          	lea    -0x8(%r10),%rsp
    148d:	c3                   	retq   

000000000000148e <_Z41__static_initialization_and_destruction_0ii>:
    148e:	f3 0f 1e fa          	endbr64 
    1492:	55                   	push   %rbp
    1493:	48 89 e5             	mov    %rsp,%rbp
    1496:	48 83 ec 10          	sub    $0x10,%rsp
    149a:	89 7d fc             	mov    %edi,-0x4(%rbp)
    149d:	89 75 f8             	mov    %esi,-0x8(%rbp)
    14a0:	83 7d fc 01          	cmpl   $0x1,-0x4(%rbp)
    14a4:	75 32                	jne    14d8 <_Z41__static_initialization_and_destruction_0ii+0x4a>
    14a6:	81 7d f8 ff ff 00 00 	cmpl   $0xffff,-0x8(%rbp)
    14ad:	75 29                	jne    14d8 <_Z41__static_initialization_and_destruction_0ii+0x4a>
    14af:	48 8d 3d 9b 2c 00 00 	lea    0x2c9b(%rip),%rdi        # 4151 <_ZStL8__ioinit>
    14b6:	e8 15 fc ff ff       	callq  10d0 <_ZNSt8ios_base4InitC1Ev@plt>
    14bb:	48 8d 15 46 2b 00 00 	lea    0x2b46(%rip),%rdx        # 4008 <__dso_handle>
    14c2:	48 8d 35 88 2c 00 00 	lea    0x2c88(%rip),%rsi        # 4151 <_ZStL8__ioinit>
    14c9:	48 8b 05 28 2b 00 00 	mov    0x2b28(%rip),%rax        # 3ff8 <_ZNSt8ios_base4InitD1Ev@GLIBCXX_3.4>
    14d0:	48 89 c7             	mov    %rax,%rdi
    14d3:	e8 c8 fb ff ff       	callq  10a0 <__cxa_atexit@plt>
    14d8:	90                   	nop
    14d9:	c9                   	leaveq 
    14da:	c3                   	retq   

00000000000014db <_GLOBAL__sub_I_main>:
    14db:	f3 0f 1e fa          	endbr64 
    14df:	55                   	push   %rbp
    14e0:	48 89 e5             	mov    %rsp,%rbp
    14e3:	be ff ff 00 00       	mov    $0xffff,%esi
    14e8:	bf 01 00 00 00       	mov    $0x1,%edi
    14ed:	e8 9c ff ff ff       	callq  148e <_Z41__static_initialization_and_destruction_0ii>
    14f2:	5d                   	pop    %rbp
    14f3:	c3                   	retq   
    14f4:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    14fb:	00 00 00 
    14fe:	66 90                	xchg   %ax,%ax

0000000000001500 <__libc_csu_init>:
    1500:	f3 0f 1e fa          	endbr64 
    1504:	41 57                	push   %r15
    1506:	4c 8d 3d 6b 28 00 00 	lea    0x286b(%rip),%r15        # 3d78 <__frame_dummy_init_array_entry>
    150d:	41 56                	push   %r14
    150f:	49 89 d6             	mov    %rdx,%r14
    1512:	41 55                	push   %r13
    1514:	49 89 f5             	mov    %rsi,%r13
    1517:	41 54                	push   %r12
    1519:	41 89 fc             	mov    %edi,%r12d
    151c:	55                   	push   %rbp
    151d:	48 8d 2d 64 28 00 00 	lea    0x2864(%rip),%rbp        # 3d88 <__do_global_dtors_aux_fini_array_entry>
    1524:	53                   	push   %rbx
    1525:	4c 29 fd             	sub    %r15,%rbp
    1528:	48 83 ec 08          	sub    $0x8,%rsp
    152c:	e8 cf fa ff ff       	callq  1000 <_init>
    1531:	48 c1 fd 03          	sar    $0x3,%rbp
    1535:	74 1f                	je     1556 <__libc_csu_init+0x56>
    1537:	31 db                	xor    %ebx,%ebx
    1539:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1540:	4c 89 f2             	mov    %r14,%rdx
    1543:	4c 89 ee             	mov    %r13,%rsi
    1546:	44 89 e7             	mov    %r12d,%edi
    1549:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    154d:	48 83 c3 01          	add    $0x1,%rbx
    1551:	48 39 dd             	cmp    %rbx,%rbp
    1554:	75 ea                	jne    1540 <__libc_csu_init+0x40>
    1556:	48 83 c4 08          	add    $0x8,%rsp
    155a:	5b                   	pop    %rbx
    155b:	5d                   	pop    %rbp
    155c:	41 5c                	pop    %r12
    155e:	41 5d                	pop    %r13
    1560:	41 5e                	pop    %r14
    1562:	41 5f                	pop    %r15
    1564:	c3                   	retq   
    1565:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    156c:	00 00 00 00 

0000000000001570 <__libc_csu_fini>:
    1570:	f3 0f 1e fa          	endbr64 
    1574:	c3                   	retq   

Disassembly of section .fini:

0000000000001578 <_fini>:
    1578:	f3 0f 1e fa          	endbr64 
    157c:	48 83 ec 08          	sub    $0x8,%rsp
    1580:	48 83 c4 08          	add    $0x8,%rsp
    1584:	c3                   	retq   
