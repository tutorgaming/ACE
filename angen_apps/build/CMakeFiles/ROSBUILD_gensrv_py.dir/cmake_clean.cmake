FILE(REMOVE_RECURSE
  "../srv_gen"
  "../src/angen_apps/srv"
  "../srv_gen"
  "CMakeFiles/ROSBUILD_gensrv_py"
  "../src/angen_apps/srv/__init__.py"
  "../src/angen_apps/srv/_AngenActuatorsStatus.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_gensrv_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
