#!/bin/sh
 
echo $LD_LIBRARY_PATH

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/lib

./nbdp -qws
