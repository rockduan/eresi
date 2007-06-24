##
## Makefile for elfsh
##
## Started on  Fri Nov  2 16:32:29 2001 mayhem
##

include ../config.h

SRC			= main.c tables.c
OBJ			= $(SRC:.c=.o)
OBJ32			= $(SRC:.c=.32.o)
OBJ64			= $(SRC:.c=.64.o)
CC			?= gcc
RM			= rm -f
NAME			= evarista
NAME32			= evarista32
NAME64			= evarista64

CFLAGS32		+= -fPIC -g3 -gstabs+ -Wall -Iinclude $(DYNOPT) $(BUILDOP)\
			 -I../libelfsh/include/ -I../elibc/include/ \
			 -I../libdump/include/ -I../libasm/include/ \
			 -I../e2dbg/include/ -I/usr/pkg/include/  \
			-I../libaspect/include/ -I../librevm/include/ \
			-I../libui/include/ -I../libmjollnir/include/ \
			-I../libedfmt/include/ -DELFSH_INTERN $(STATOPT2) \
			$(ASMOPT) -DELFSH32 $(NCURSESLNOPT) $(READLNOPT)

CFLAGS64		+= -fPIC -g3 -gstabs+ -Wall -Iinclude $(DYNOPT) $(BUILDOP)\
			 -I../libelfsh/include/ -I../elibc/include/ \
			 -I../libdump/include/ -I../libasm/include/ \
			 -I../e2dbg/include/ -I/usr/pkg/include/  \
			-I../libaspect/include/ -I../librevm/include/ \
			-I../libui/include/ -I../libmjollnir/include/ \
			-I../libedfmt/include/ -DELFSH_INTERN $(STATOPT2) \
			$(ASMOPT) -DELFSH64 $(NCURSESLNOPT) $(READLNOPT)

LDFLAGS32		+= -L../libedfmt/ -L../libelfsh/ -ledfmt32 -lelfsh32      \
			-L../libdump/ -L/usr/pkg/lib/ -L../libmjollnir/		  \
			-lmjollnir32 $(LPTHREAD) -L../elibc -lcelfsh32		  \
			-L../libasm/ -lasm $(LDUIOPT32) -g3		          \
			-L../liballocproxy -L../libmjollnir/          		  \
			-L../libaspect/ -laspect32 -L../librevm/ -lrevm32         \
			-lallocproxy $(LDMJOLLNIR) $(DLOPT)  			  \
			-L/usr/freeware/lib32/ $(DYNOPT) $(BITS) $(EXTRAOPT) 	  \
			$(LDDUMPOPT) $(LDNCURSESLNOPT) $(LDREADLNOPT) $(READLNOPT)

LDFLAGS64		+= -L../libelfsh/ -lelfsh64 -L../libdump/ -L/usr/pkg/lib/ \
			-L../libmjollnir/ -lmjollnir64 $(LPTHREAD) -L../elibc 	  \
			-lcelfsh64 -L../libasm/ -lasm $(LDUIOPT64) -g3 	          \
			-L../liballocproxy -L../libmjollnir/          		  \
			-L../libaspect/ -laspect64 -L../librevm/ -lrevm64         \
			-lallocproxy -L../libedfmt/ -ledfmt64 $(LDMJOLLNIR)       \
			$(DLOPT)  -L/usr/freeware/lib32/ $(DYNOPT) $(BITS)        \
			$(EXTRAOPT) $(LDDUMPOPT) $(LDNCURSESLNOPT) $(LDREADLNOPT) \
			$(READLNOPT)

all			: all32 all64

all32			: $(OBJ32)
			@$(CC) $(OBJ32) -o $(NAME32) $(LDFLAGS32) $(STATOPT)

all64			: $(OBJ64)
			@$(CC) $(OBJ64) -o $(NAME64) $(LDFLAGS64) $(STATOPT)

clean		       :
		       @$(RM) $(OBJ) *~ \#* *\# .\#* *.32.o *.64.o
		       @$(RM) include/*~ include/\#* include/*\# include/.\#*

fclean		       : clean
		       @$(RM) $(NAME) $(NAME32) $(NAME64) $(OBJ_DYN)

%.32.o : %.c
			$(CC) $(CFLAGS32) -c -o $@ $<
%.64.o : %.c
			$(CC) $(CFLAGS64) -c -o $@ $<