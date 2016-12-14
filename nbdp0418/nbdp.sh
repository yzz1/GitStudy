#!/bin/bash
appname=`basename $0 | sed s,\.sh$,,`
dirname=`dirname $0`
tmp="${dirname#?}"
if [ "${dirname%$tmp}" != "/" ]; then
  dirname=$PWD/$dirname
fi

echo "$LD_LIBRARY_PATH" |grep -q "$dirname"
if [ $? -ne 0 ]
then
  if [ -z "$LD_LIBRARY_PATH" ]
  then
    export LD_LIBRARY_PATH=$dirname/lib
  else
    export LD_LIBRARY_PATH=$dirname/lib:$LD_LIBRARY_PATH
  fi
fi
$dirname/$appname -qws $*
