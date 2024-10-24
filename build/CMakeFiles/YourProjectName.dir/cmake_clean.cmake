file(REMOVE_RECURSE
  "CMakeFiles/YourProjectName.dir/main.cpp.o"
  "bin/myfile.pdb"
  "bin/myfile"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/YourProjectName.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
