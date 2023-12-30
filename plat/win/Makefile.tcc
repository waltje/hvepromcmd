# Makefile for use with TinyC (TCC) on Windows.

ifndef ARCH
 ARCH	:= x86
endif

CC		:= tcc
LD		:= tcc
WINDRES		:= windres
RM		:= del 2>NUL /q

ifeq ($(ARCH),x86)
 AFLAG		:= -m32
 RCTARGET	:= pe-i386
else
 AFLAG		:= -m64
 RCTARGET	:= pe-x86-64
endif

CFLAGS		:= $(AFLAG) -Wall -Os -Iplat/win
LDFLAGS		:= $(AFLAG) -s
RCFLAGS		:= --input-format=rc -O coff
ifdef RCTARGET
 RCFLAGS	+= --target=$(RCTARGET)
endif
RCFLAGS		+= -D RC_INVOKED -o


NAME		:= hvepromcmd.exe
OBJ		:= main.o pgm.o test_descriptions.o serial.o util.o
SYSOBJ		:= hvepromcmd.res getopt.o

VPATH		:= . plat/win


.SUFFIXES:	.c .o .rc .res

.c.o:		$<
		@echo Compiling $<
		@$(CC) $(CFLAGS) -o $@ -c $<

.rc.res:	$<
		@echo Processing $<
		@$(WINDRES) $(RCFLAGS) $@ $<


$(NAME):	$(SYSOBJ) $(OBJ)
		@echo Linking $@
		@$(LD) $(LDFLAGS) -o $@ $(SYSOBJ) $(OBJ)


clean:
		@$(RM) $(OBJ) $(SYSOBJ)

clobber:	clean
		@$(RM) $(NAME)


# End of file.
