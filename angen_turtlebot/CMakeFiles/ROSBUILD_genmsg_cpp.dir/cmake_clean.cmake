FILE(REMOVE_RECURSE
  "msg_gen"
  "srv_gen"
  "src/angen_turtlebot/msg"
  "src/angen_turtlebot/srv"
  "msg_gen"
  "srv_gen"
  "CMakeFiles/ROSBUILD_genmsg_cpp"
  "msg_gen/cpp/include/angen_turtlebot/navigaton_status.h"
  "msg_gen/cpp/include/angen_turtlebot/navigation_command.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
