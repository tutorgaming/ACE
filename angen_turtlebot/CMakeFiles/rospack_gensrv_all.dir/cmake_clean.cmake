FILE(REMOVE_RECURSE
  "msg_gen"
  "srv_gen"
  "src/angen_turtlebot/msg"
  "src/angen_turtlebot/srv"
  "msg_gen"
  "srv_gen"
  "CMakeFiles/rospack_gensrv_all"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/rospack_gensrv_all.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
