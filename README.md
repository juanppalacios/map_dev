# Note: work-in-progress

# Getting Started

First, you need to connect the msp432 board using `openocd`.
Compile your code and launch openocd:

```bash
>$ make
>$ openocd -f board/ti_msp432_launchpad.cfg
```

Now, we need to open a new terminal to flash our binary onto the MSP432.

```bash
>$ arm-none-eabi-gdb
>$ (gdb) target remote :3333
>$ (gdb) load ./out/hello_world.out
>$ (gdb) continue
```

# Debugging

You can also debug your application using `gdb`.
Use the `file` command to set your gdb context to the .out file, for example, `hello_world.out`

```bash
>$ arm-none-eabi-gdb
>$ (gdb) remote target :3333
>$ (gdb) file ./out/hello_world.out
>$ (gdb) continue
# hit ctrl-c to stop it wherever it lands
>$ (gdb) print delay
>$ (gbb) set delay=10000
>$ (gdb) continue
# hit ctrl-c to stop it wherever it lands
>$ (gdb) print delay
>$ (gbb) set delay=1000
>$ (gdb) continue
```

You should now see that your LEDs cycle through colors much faster.
This is some example terminal output for the program included in this example repo.

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