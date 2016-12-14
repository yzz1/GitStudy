#!/bin/bash
#
# Based on the QRegExp-Editor script:
# https://gitorious.org/qregexp-editor/qregexp-editor/blobs/master/scripts/astyle-qregexp_editor
#
# apply razor-qt coding style to all c, cpp and header files in and below the current directory
#
# the coding style is defined in https://github.com/Razor-qt/razor-qt/wiki/Coding-Style
#
# requirements: installed astyle => 1.24

OPTS="--style=allman --indent-namespaces --indent-classes \
      --indent=spaces=4 --min-conditional-indent=0 \
      --align-pointer=type --align-reference=type --unpad-paren \
      --pad-header --pad-oper --keep-one-line-blocks \
      --delete-empty-lines --break-blocks --fill-empty-lines \
      --max-code-length=120"

astyle ${OPTS} $(find . -regex ".*\.\(c\|cpp\|h\)$")
