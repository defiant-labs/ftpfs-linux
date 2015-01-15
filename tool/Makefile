MYCODEDIR := .

# Directories to search for header files

SEARCHDIRS := -I- -I${MYCODEDIR}

# makemake variables

DEPENDFLAGS  := -g -Wall -Werror ${SEARCHDIRS}
TOUCHHEADERS := ${MYCODEDIR}/*.h

# C preprocessor (C, C++, FORTRAN)

CPPFLAGS = 

# C compiler

CC     := gcc
CFLAGS  = ${DEPENDFLAGS}

%.o : %.c
	${CC} ${CPPFLAGS} ${CFLAGS} -c $< -o $@

# C linker

LINKER    := gcc
LDFLAGS    = 
LOADLIBES := -lm


# This is what makemake added


# ftpmount

ftpmount :: ./ftpmount.o
  ifeq (${suffix ftpmount}, .a)
	@${RM} $@
	${AR} crs $@ ${filter-out %.a %.so, $^}
  else
  ifeq (${suffix ftpmount}, .so)
	${LINKER} -shared ${LDFLAGS} -o $@ ${filter-out %.a %.so, $^} ${LOADLIBES}
  else
	${LINKER} ${LDFLAGS} -o $@ ${filter-out %.a %.so, $^} ${LOADLIBES}
  endif
  endif

# list of all source files

MM_ALL_TARGETS := ftpmount

# target for making everything

.PHONY : all
all: ${MM_ALL_TARGETS}

# target for removing all object files

.PHONY : tidy
tidy::
	@${RM} core ./ftpmount.o

# target for removing all object files

.PHONY : clean
clean:: tidy
	@${RM} ${MM_ALL_TARGETS}

# list of all source files

MM_ALL_SOURCES := ./ftpmount.c

# target for checking a source file

CHECKSYNTAXFILE := ${basename ${filter %${CHECKSTRING}, ${MM_ALL_SOURCES}}}

.PHONY : checksyntax
checksyntax:
  ifneq (${CHECKSYNTAXFILE},)
	@${MAKE} ${addsuffix .o, ${CHECKSYNTAXFILE}}
  else
	@echo No target to make ${CHECKSTRING}
  endif


# target for touching appropriate source files

.PHONY : touch
touch::
	@list=$$(grep -l ${TOUCHSTRING} ${MM_ALL_SOURCES}); \
     for file in $$list; do { echo $$file; touch $$file; } done


# target for calculating dependencies (MAKEMAKE)

.PHONY : jdepend
jdepend:
	@${MAKEMAKE} --depend Makefile -- ${DEPENDFLAGS} --  ./ftpmount.c ./ftpmount.o

install:
	strip ./ftpmount
	cp ./ftpmount /usr/local/bin/ftpmount

