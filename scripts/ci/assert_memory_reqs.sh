#!/bin/bash
set -ev

PROGRAM_SIZE = grep "text"
VARIABLES_SIZE = grep "var_text"

if [$PROGRAM_SIZE > someValue]; then
  return 1
fi
if [$VARIABLES_SIZE > someOtherValue]; then
  return 1
fi
