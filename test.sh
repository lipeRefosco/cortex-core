#/bin/bash;
test_folder=tests
output_ext=".test.out"

# copy the source file to the test folder
rm -rf "$test_folder/cp_src"
cp -rf src/ "$test_folder/"
mv "$test_folder/src" "$test_folder/cp_src"

# list get all test files
test_files=$(find "$test_folder" -type f -name "*.c" -not -path "*/cp_src/*")

# list get module files
module_files=$(find "$test_folder/cp_src" -type f)

# compile the each test
for file in "$test_files"; do
    echo
    echo "Compiling $file file!"
    gcc $file $module_files -o "$file$output_ext"
    echo "................."
    echo
done

# run each test
for file in "$test_files"; do
    echo "Running the $file test!"
    $file$output_ext
    echo 
    echo "................."
    echo
done