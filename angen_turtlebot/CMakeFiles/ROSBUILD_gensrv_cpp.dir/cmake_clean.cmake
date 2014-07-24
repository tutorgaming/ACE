FILE(REMOVE_RECURSE
  "msg_gen"
  "srv_gen"
  "src/angen_turtlebot/msg"
  "src/angen_turtlebot/srv"
  "msg_gen"
  "srv_gen"
  "CMakeFiles/ROSBUILD_gensrv_cpp"
  "srv_gen/cpp/include/angen_turtlebot/service1_param.h"
  "srv_gen/cpp/include/angen_turtlebot/service2_param.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_gensrv_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
