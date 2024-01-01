dnl Process this file with autoconf to produce a configure script.
dnl i.e. autoconf configure.ac > ../configure

dnl For most systems a configure script is hardly required.

AC_INIT(dpic,2021.04.10)
AC_CONFIG_AUX_DIR(autoconf/scripts)
m4_include(m4/ax_check_compile_flag.m4)

AC_LANG_C

PACKAGE=dpic
UCPACKAGE=DPIC
VERSION=2024.01.01
AC_SUBST(PACKAGE)
AC_SUBST(VERSION)
AC_SUBST(UCPACKAGE)
AC_DEFINE_UNQUOTED(PACKAGE, "$PACKAGE")
AC_DEFINE_UNQUOTED(PROGRAM_NAME, "$PACKAGE")
AC_DEFINE_UNQUOTED(VERSION, "$VERSION")

AC_ARG_ENABLE(safemode,
  [  --enable-safemode      compile with sh and copy disabled],
  if test "$enable_safemode" = "yes"; then
    AC_SUBST(safe_mode,-dSAFE_MODE)
  fi
)

CFLAGS=${CFLAGS:-"-O"}
AC_PROG_CC

AC_PROG_INSTALL
AC_PROG_MAKE_SET

AC_CHECK_HEADERS([time.h math.h assert.h])

dnl -DRAND and -DNO_SNPRINTF are retained but no longer implemented
dnl MinGW requires -liberty
AC_CHECK_FUNC(random,,
  [AC_CHECK_LIB(iberty,random,
   AC_SUBST(iberty,-liberty),AC_SUBST(defrand,-DRAND))])

AC_CHECK_FUNC(snprintf,,[AC_SUBST(defno_snprintf,-DNO_SNPRINTF)])

test -z "$INSTALL_DATA" && INSTALL_DATA='${INSTALL} -m 644'
AC_SUBST(INSTALL_DATA)

AC_OUTPUT(Makefile)

dnl EOF
