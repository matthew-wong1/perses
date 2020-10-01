#!/usr/bin/env bash

set -o pipefail
set -o nounset

readonly TOOLS=("creduce" \
    "gcc" \
    "clang" \
    "go" \
    "rustc" \
    "ktlint" \
    "scala")

missing=""
for tool in "${TOOLS[@]}" ; do
  if ! command -v "${tool}" &> /dev/null ; then
    missing="${missing} ${tool}"
  fi
done

if [[ "${missing}" != "" ]] ; then
  echo "The following tools are missing: ${missing}"
  exit 1
else
  exit 0
fi