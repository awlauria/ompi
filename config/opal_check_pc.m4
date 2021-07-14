dnl -*- shell-script -*-
dnl
dnl Copyright (c) 2021 IBM Corporation.  All rights reserved.
dnl
dnl $COPYRIGHT$
dnl
dnl Additional copyrights may follow
dnl
dnl $HEADER$
dnl

AC_DEFUN([OPAL_CHECK_LFLAGS], [
         AC_MSG_CHECKING([for pc file for])
         AC_MSG_RESULT([$1])

	 num_paths=$#
         save_name=$1
         cmd="pkg-config"
         $1_OMPI_PC_DIR=""
         if test $num_paths -gt 1; then
            $1_OMPI_PC_DIR=$2
            args=m4_shift($@)
            for i in $(echo $args | sed "s/,/ /g"); do
               cmd=" ${cmd} --with-path $i"
            done
         fi

         cmd="${cmd} --libs-only-l $save_name"
         AC_MSG_CHECKING([pkg-config command for $save_name])
         AC_MSG_RESULT([$cmd])

         TMP=$($cmd)
         AS_IF([test -z "$TMP"],
               [AC_MSG_ERROR([Could not find viable $save_name.pc])],
         [
           AC_MSG_CHECKING([pkg-config result for $save_name])
           AC_MSG_RESULT([$TMP])])
           OMPI_DEPS_LFLAGS="$OMPI_DEPS_LFLAGS $TMP"
         ]
)
