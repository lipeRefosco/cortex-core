#/bin/bash;
test_folder=tests
output_ext=".test.out"

# Copy the source file to the test folder
rm -rf "$test_folder/cp_src"
cp -rf src/ "$test_folder/"
mv "$test_folder/src" "$test_folder/cp_src"

# List get all test files
test_files=$(find "$test_folder" -type f -name "*.c" -not -path "*/cp_src/*")

# List get module files
module_files=$(find "$test_folder/cp_src" -type f -name "*.c")
echo $module_files

# Compile phase
echo
echo "--------- COMPILE PHASE ---------"
echo

# Compile the each test
for file in $test_files; do
    echo "Compiling $file file!"
    gcc -g $file $module_files -o "$file$output_ext" -Wno-pointer-to-int-cast
done

# Run the test phase
echo 
echo "--------- RUNNING PHASE ---------"

# Run each test
for file in $test_files; do
    echo 
    echo "Running the $file test!"
    $file$output_ext
done