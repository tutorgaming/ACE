FILE(REMOVE_RECURSE
  "../srv_gen"
  "../src/angen_apps/srv"
  "../srv_gen"
  "CMakeFiles/ROSBUILD_gensrv_cpp"
  "../srv_gen/cpp/include/angen_apps/AngenActuatorsStatus.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_gensrv_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
