
(cl:in-package :asdf)

(defsystem "angen_turtlebot-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "navigaton_status" :depends-on ("_package_navigaton_status"))
    (:file "_package_navigaton_status" :depends-on ("_package"))
    (:file "navigation_command" :depends-on ("_package_navigation_command"))
    (:file "_package_navigation_command" :depends-on ("_package"))
  ))