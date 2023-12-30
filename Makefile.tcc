# Makefile for use with TinyC (TCC) on Windows.

ifndef ARCH
 ARCH	:= x86
endif

CC	:= tcc
LD	:= tcc
RM	:= del 2>NUL /q

ifeq ($(ARCH),x86)
 AFLAG	:= -m32
else
 AFLAG	:= -m64
endif

CFLAGS	:= $(AFLAG) -Wall -Os
LDFLAGS	:= $(AFLAG) -s


SYSOBJ	:= getopt.o
OBJ	:= main.o pgm.o test_descriptions.o serial_win32.o util.o


.c.o:		$<
		$(CC) $(CFLAGS) -o $@ -c $<


hveprom.exe:	$(SYSOBJ) $(OBJ)
		$(LD) $(LDFLAGS) -o $@ $(SYSOBJ) $(OBJ)


clean:
		@$(RM) $(OBJ)

clobber:	clean
		@$(RM) hveprom.exe


# End of file.
