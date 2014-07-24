
(cl:in-package :asdf)

(defsystem "angen_turtlebot-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "service1_param" :depends-on ("_package_service1_param"))
    (:file "_package_service1_param" :depends-on ("_package"))
    (:file "service2_param" :depends-on ("_package_service2_param"))
    (:file "_package_service2_param" :depends-on ("_package"))
  ))