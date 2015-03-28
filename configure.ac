AC_INIT([gdbus-example], [0.1], [onurmark1@gmail.com])

AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])
AM_PROG_AR

LT_INIT

AC_PROG_CC

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile tests/Makefile])

PKG_CHECK_MODULES([GLIB], [glib-2.0 >= 2.40.2])
PKG_CHECK_MODULES([GIO], [gio-2.0 >= 2.40.2])

AC_OUTPUT
