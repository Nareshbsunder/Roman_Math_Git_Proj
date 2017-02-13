## Process this file with automake to produce Makefile.in

TESTS = Roman_Math_test
check_PROGRAMS = Roman_Math_test
Roman_Math_test_SOURCES = Roman_Math_test.c $(top_builddir)/src/Roman_Math.h
Roman_Math_test_CFLAGS = @CHECK_CFLAGS@
Roman_Math_test_LDADD = $(top_builddir)/src/libRoman_Math.la @CHECK_LIBS@
