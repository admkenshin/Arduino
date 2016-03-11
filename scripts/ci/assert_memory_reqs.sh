#!/bin/bash
set -ev

PROGRAM_SIZE = grep "text"
VARIABLES_SIZE = grep "var_text"

CONST_MAX_PRGMEM = 32000
CONST_MAX_RAM = 2048

if [$PROGRAM_SIZE > someValue]; then
  return 1
fi
if [$VARIABLES_SIZE > someOtherValue]; then
  return 1
fi
