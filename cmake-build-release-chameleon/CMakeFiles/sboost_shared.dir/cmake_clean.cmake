file(REMOVE_RECURSE
  "release/libsboost.pdb"
  "release/libsboost.so"
  "release/libsboost.so.1.0.0"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/sboost_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
