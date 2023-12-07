#/bin/bash;

# copy the source file to the test folder
cp -rf src/* tests/cp_src/

# compile the each test



gcc tests/test_*.c -o tests/test_*.c.test.out