file(REMOVE_RECURSE
  "libsboostd.a"
  "libsboostd.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/sboost_static.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
