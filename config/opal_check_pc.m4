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
        
        AC_MSG_NOTICE([Parsing pc file for $1])

        ompi_pc_libs=""

        # No directory passed in, must be installed on the
        # machine. Check where pkg-config would look
        AS_IF([test -n "$2"],
           [ompi_pc_libs=$(grep "Libs:" $2/$1.pc)],
           [
             m4_foreach(ompi_pc_path, [/usr/lib/pkgconfig, /usr/share/pkgconfig, /usr/local/lib/pkgconfig, /usr/local/share/pkgconfig, /usr/lib64/pkgconfig],
              [
               if test -f ompi_pc_path/$1.pc; then
                 AC_MSG_NOTICE([Found config file ompi_pc_path/$1.pc])
                 ompi_pc_libs=$(grep "Libs:" ompi_pc_path/$1.pc)
                 if test -z "$ompi_pc_libs"; then
                   break
                 fi
               fi
              ])
          ]
        )
        AS_IF([test -n "$ompi_pc_libs"],
              [
                AC_MSG_NOTICE([Found libs $ompi_pc_libs])
                for pc_lib in $(echo $ompi_pc_libs); do
                    AC_MSG_NOTICE([Checking $pc_lib])
                    if $GREP -q "\-l" <<< "$pc_lib"; then
                      AC_MSG_NOTICE([Appending $pc_lib to OMPI_DEPS_LFLAGS])
                      OMPI_DEPS_LFLAGS="$OMPI_DEPS_LFLAGS $pc_lib"
                    fi
                done
              ],
              [AC_MSG_ERROR([Could not find viable $1.pc])]
        )
])
