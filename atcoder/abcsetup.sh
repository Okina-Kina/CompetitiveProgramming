#!/bin/bash

if [ $# -ne 1 ]; then
  sudo echo "Usage: $0 2xx" 1>&2
  sudo exit 1
fi

if ! [[ "$1" =~ ^[1-9][0-9]{,2}$ ]]; then
  sudo echo "Usage: $0 2xx (x=[0-9])" 1>&2
  sudo exit 1
fi

if [ ! -e ABC ]; then
  sudo echo "Error: directory 'ABC' not exists." 1>&2
  sudo exit 1
fi

sudo mkdir -p ABC/$1

cp -n ../template.cpp ABC/$1/a.cpp
cp -n ../template.cpp ABC/$1/b.cpp
cp -n ../template.cpp ABC/$1/c.cpp
cp -n ../template.cpp ABC/$1/d.cpp
cp -n ../template.cpp ABC/$1/e.cpp
cp -n ../template.cpp ABC/$1/f.cpp
cp -n ../template.cpp ABC/$1/g.cpp
cp -n ../template.cpp ABC/$1/h.cpp

exit 0