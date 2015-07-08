test_module() {
  echo "testing $1"
  $*
  if [ $? -eq 0 ]
  then
    echo "$* passed."
  else
    echo "$* failed."
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
test_module tests/test_join
test_module tests/test_randomstring
test_module tests/test_hashtable
test_module tests/test_superhash
test_module tests/test_sortlist
test_module bin/dg -n 10 -s numeric:10,alpha:5,state
