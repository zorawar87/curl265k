#!/bin/bash

Name=curl-7.58.0
Tar=$Name.tar.gz
Dir=$1
if [[ ! -z $Dir && -d $Dir ]]; then
    echo will configure curl in $Dir
else 
  Dir=/usr/local/
  echo using $Dir to setup curl
fi

if [ -f $Tar ]; then
  if [ ! -d $Name ]; then
    tar -xzf $Tar
  fi
  cd $Name
  ./configure --prefix=$Dir &>../configure.log && echo "configured successfully" &&
  make &>../make.log && echo "made successfully" &&
  make test &>test.log && echo "tests passed" &&
  make install &> install.log && echo "done"
  exit 0
else
  echo quitting
  exit 1
fi

