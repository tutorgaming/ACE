FILE(REMOVE_RECURSE
  "msg_gen"
  "srv_gen"
  "src/angen_turtlebot/msg"
  "src/angen_turtlebot/srv"
  "msg_gen"
  "srv_gen"
  "CMakeFiles/ROSBUILD_genmsg_lisp"
  "msg_gen/lisp/navigaton_status.lisp"
  "msg_gen/lisp/_package.lisp"
  "msg_gen/lisp/_package_navigaton_status.lisp"
  "msg_gen/lisp/navigation_command.lisp"
  "msg_gen/lisp/_package.lisp"
  "msg_gen/lisp/_package_navigation_command.lisp"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_lisp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
