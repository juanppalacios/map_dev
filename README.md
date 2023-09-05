# Getting Started

First, you need to connect the msp432 board using `openocd`

```bash
>$ make
>$ openocd -f board/ti_msp432_launchpad.cfg
```

Now, we need to open a new terminal to run flash our binary onto hardware

```bash
>$ arm-none-eabi-gdb
>$ (gdb) target remote :3333
>$ (gdb) load ./out/hello_world.out
>$ (gdb) continue
```

Instructions for gdb debugging:
```bash
>$ arm-none-eabi-gdb
>$ (gdb) remote target :3333
>$ (gdb) file ./out/hello_world.out
>$ (gdb) continue
# hit ctrl-c to stop it wherever it lands
>$ (gdb) print delay
>$ (gbb) set delay=1000
>$ (gdb) continue
# hit ctrl-c to stop it wherever it lands
>$ (gdb) print delay
>$ (gbb) set delay=1000
>$ (gdb) continue
```

```bash
Program received signal SIGINT, Interrupt.
0x0000031c in main () at src/main.c:107
107             for (volatile uint32_t i = delay; i > 0; i--);
(gdb) set delay=10000
(gdb) continue
Continuing.
(gdb) ^C
Program received signal SIGINT, Interrupt.
0x0000031a in main () at src/main.c:107
107             for (volatile uint32_t i = delay; i > 0; i--);
(gdb) set delay=100000
(gdb) continue
Continuing.
^C
Program received signal SIGINT, Interrupt.
0x0000031e in main () at src/main.c:107
107             for (volatile uint32_t i = delay; i > 0; i--);
(gdb) set delay=100
(gdb) continue
Continuing.
^C
Program received signal SIGINT, Interrupt.
0x0000031c in main () at src/main.c:107
107             for (volatile uint32_t i = delay; i > 0; i--);
(gdb) 
```

You should be able to see that these values have changed now.

<!-- Or run a helper script to perform this task for you -->

<!-- todo: modify our makefile to connect to target -->
<!-- todo: modify our makefile to upload code to target -->