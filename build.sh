#!/bin/bash

BIN_DIR=bin

if [ -z "${MAKE_VERBOSE}" ]; then
  MAKE_FLAGS="--no-print-directory"
else
  MAKE_FLAGS="VERBOSE=1"
fi

do_clean() {
  rm -rf ${BIN_DIR}
}

do_build() {
  mkdir -p ${BIN_DIR}               && \
  cd ${BIN_DIR}                     && \
  cmake ..                          && \
  cmake --build . -- ${MAKE_FLAGS}
}

do_rebuild() {
  do_clean
  do_build
}

do_test() {
  ${BIN_DIR}/src/durak && echo "OK"
}

usage() {
  echo "$0 [clean|rebuild]"
}

case "$1" in
	"")          do_build;;
	"clean")     do_clean;;
	"rebuild")   do_rebuild;;
	"test")      do_test;;
	*)           usage
esac

# vim: ts=2 sw=2 et
