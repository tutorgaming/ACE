
(cl:in-package :asdf)

(defsystem "angen_apps-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "AngenActuatorsStatus" :depends-on ("_package_AngenActuatorsStatus"))
    (:file "_package_AngenActuatorsStatus" :depends-on ("_package"))
  ))