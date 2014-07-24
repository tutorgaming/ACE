FILE(REMOVE_RECURSE
  "msg_gen"
  "srv_gen"
  "src/angen_turtlebot/msg"
  "src/angen_turtlebot/srv"
  "msg_gen"
  "srv_gen"
  "CMakeFiles/ROSBUILD_gensrv_lisp"
  "srv_gen/lisp/service1_param.lisp"
  "srv_gen/lisp/_package.lisp"
  "srv_gen/lisp/_package_service1_param.lisp"
  "srv_gen/lisp/service2_param.lisp"
  "srv_gen/lisp/_package.lisp"
  "srv_gen/lisp/_package_service2_param.lisp"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_gensrv_lisp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
