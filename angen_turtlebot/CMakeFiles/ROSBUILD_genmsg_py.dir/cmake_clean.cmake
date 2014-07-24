FILE(REMOVE_RECURSE
  "msg_gen"
  "srv_gen"
  "src/angen_turtlebot/msg"
  "src/angen_turtlebot/srv"
  "msg_gen"
  "srv_gen"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "src/angen_turtlebot/msg/__init__.py"
  "src/angen_turtlebot/msg/_navigaton_status.py"
  "src/angen_turtlebot/msg/_navigation_command.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
