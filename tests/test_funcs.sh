test_module() {
  echo "testing $1"
  $1
  if [ $? -eq 0 ]
  then
    echo "$1 passed."
  else
    echo "$1 failed."
  fi
}

test_module tests/test_randint
