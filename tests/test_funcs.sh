test_module() {
  echo "testing $1"
  $1
  if [ $? -eq 0 ]
  then
    echo "$1 passed."
  else
    echo "$1 failed."
  fi
  echo
}

test_module tests/test_randint
test_module tests/test_randchar
test_module tests/test_mkalpha
test_module tests/test_mknumeric
test_module tests/test_mkalphanum
test_module tests/test_split
test_module tests/test_strllen
test_module tests/test_inlist
