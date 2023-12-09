#/bin/bash;
test_folder=tests
cp_src="$test_folder/cp_src/"
output_ext=".test.out"

# copy the source file to the test folder
cp -rf src/* "$cp_src"

# list get all file of tests
c_files=$(find "$test_folder" -type f -name "*.c" -not -path "*/cp_src/*")

# compile the each test
for file in "$c_files"; do
    echo
    echo "Compiling $file file!"
    gcc $file tests/cp_src/*.c  -o "$file$output_ext"
    echo "................."
    echo
done

# run each test
for file in "$c_files"; do
    echo "Running the $file test!"
    $file$output_ext
    echo 
    echo "................."
    echo
done