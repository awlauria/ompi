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

dnl OPAL_CHECK_LFLAGS
dnl Get the -l flags using pkg-config on the passed in .pc file, and
dnl append them to OMPI_DEPS_LFLAGS.
dnl
dnl Requires 1 or more arguments.
dnl
dnl Arg 1 (Required): the name of the .pc file to look for (hwloc/pmix/libevent_core).pc
dnl 
dnl Arg 2..n (Optional): The search path for the .pc file above and any dependencies.
dnl                      These search will be appended and set in the env variable
dnl                      PKG_CONFIG_PATH to tell pkg-config where to locate the .pc
dnl                      file from argument 1, and its dependencies.
dnl
dnl                    
dnl
AC_DEFUN([OPAL_CHECK_LFLAGS], [

         AC_MSG_INFO([for pc file for $1])

         num_paths=$#
         save_name=$1
         env_to_set=""

         AS_LITERAL_WORD_IF([$1], [], m4_fatal([Non-literal argument $1])])
         $1_OMPI_PC_DIR=""

         # Tell pkg-config where to find the .pc file from argument 1
         # as well as any/all dependencies.
         # The following block will append the path
         # to those .pc files into the pkg-config command.
         # num_paths > 1 implies there is at least one dependent .pc file
         # to append.
         if test $num_paths -gt 1; then
            $1_OMPI_PC_DIR=$2

            # Shift the arguments by one to get to the actual paths.
            args=m4_shift($@)

            # Iterate over the comma seperated arguments, and replace the ','
            for i in $(echo $args | sed "s/,/ /g"); do
               env_to_set="${env_to_set}:$i"
            done
         fi

         cmd="PKG_CONFIG_PATH=${env_to_set} pkg-config $save_name"
         AC_MSG_CHECKING([pkg-config command for $save_name])
         AC_MSG_RESULT([$cmd])

         pkg_config_result=$($cmd)
         AS_IF([test -z "$pkg_config_result"],
               [AC_MSG_ERROR([Could not find viable $save_name.pc])],
         [
           AC_MSG_CHECKING([pkg-config result for $save_name])
           AC_MSG_RESULT([$pkg_config_result])])
           OMPI_DEPS_LFLAGS="$OMPI_DEPS_LFLAGS $pkg_config_result"
         ]
)
