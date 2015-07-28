# Created with genmake.pl v1.1 on Wed Mar 29 14:51:21 2006
# genmake.pl home: http://muquit.com/muquit/software/
# Copryright: GNU GPL (http://www.gnu.org/copyleft/gpl.html)
##----------------------------------------------------------------------------
rm=/bin/rm -f
CC= g++ -O3 -Wall -ansi 
DEFS=  
PROGNAME= magic
INCLUDES=  
LIBS=


DEFINES= $(INCLUDES) $(DEFS) 
CFLAGS= $(DEFINES)

SRCS =	main.cc \
        evaluate.cc \
        print_square.cc \
        copy_square.cc \
        random_swap.cc \
        transform.c  \
        track_element.cc \
        init_square.cc  \
	init_square_old.cc \
	descend.cc

OBJS = 	main.o  \
        evaluate.o\
        print_square.o \
        copy_square.o \
        random_swap.o \
        transform.o \
        track_element.o \
        init_square.o   \
	init_square_old.o \
	descend.o

.cc.o:
	$(rm) $@
	$(CC) $(CFLAGS) -c $*.cc

all: $(PROGNAME)

$(PROGNAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(PROGNAME) $(OBJS) $(LIBS)

clean:
	$(rm) $(OBJS) $(PROGNAME) core *~ $(PROGNAME).exe
