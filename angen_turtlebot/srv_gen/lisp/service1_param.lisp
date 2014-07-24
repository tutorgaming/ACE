; Auto-generated. Do not edit!


(cl:in-package angen_turtlebot-srv)


;//! \htmlinclude service1_param-request.msg.html

(cl:defclass <service1_param-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass service1_param-request (<service1_param-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <service1_param-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'service1_param-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name angen_turtlebot-srv:<service1_param-request> is deprecated: use angen_turtlebot-srv:service1_param-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <service1_param-request>) ostream)
  "Serializes a message object of type '<service1_param-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <service1_param-request>) istream)
  "Deserializes a message object of type '<service1_param-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<service1_param-request>)))
  "Returns string type for a service object of type '<service1_param-request>"
  "angen_turtlebot/service1_paramRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'service1_param-request)))
  "Returns string type for a service object of type 'service1_param-request"
  "angen_turtlebot/service1_paramRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<service1_param-request>)))
  "Returns md5sum for a message object of type '<service1_param-request>"
  "b6db00bb6b5b71eef0a515fe8c4c7c0e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'service1_param-request)))
  "Returns md5sum for a message object of type 'service1_param-request"
  "b6db00bb6b5b71eef0a515fe8c4c7c0e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<service1_param-request>)))
  "Returns full string definition for message of type '<service1_param-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'service1_param-request)))
  "Returns full string definition for message of type 'service1_param-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <service1_param-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <service1_param-request>))
  "Converts a ROS message object to a list"
  (cl:list 'service1_param-request
))
;//! \htmlinclude service1_param-response.msg.html

(cl:defclass <service1_param-response> (roslisp-msg-protocol:ros-message)
  ((Status
    :reader Status
    :initarg :Status
    :type cl:boolean
    :initform cl:nil)
   (Key
    :reader Key
    :initarg :Key
    :type cl:fixnum
    :initform 0))
)

(cl:defclass service1_param-response (<service1_param-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <service1_param-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'service1_param-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name angen_turtlebot-srv:<service1_param-response> is deprecated: use angen_turtlebot-srv:service1_param-response instead.")))

(cl:ensure-generic-function 'Status-val :lambda-list '(m))
(cl:defmethod Status-val ((m <service1_param-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader angen_turtlebot-srv:Status-val is deprecated.  Use angen_turtlebot-srv:Status instead.")
  (Status m))

(cl:ensure-generic-function 'Key-val :lambda-list '(m))
(cl:defmethod Key-val ((m <service1_param-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader angen_turtlebot-srv:Key-val is deprecated.  Use angen_turtlebot-srv:Key instead.")
  (Key m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <service1_param-response>) ostream)
  "Serializes a message object of type '<service1_param-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'Status) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'Key)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <service1_param-response>) istream)
  "Deserializes a message object of type '<service1_param-response>"
    (cl:setf (cl:slot-value msg 'Status) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'Key)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<service1_param-response>)))
  "Returns string type for a service object of type '<service1_param-response>"
  "angen_turtlebot/service1_paramResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'service1_param-response)))
  "Returns string type for a service object of type 'service1_param-response"
  "angen_turtlebot/service1_paramResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<service1_param-response>)))
  "Returns md5sum for a message object of type '<service1_param-response>"
  "b6db00bb6b5b71eef0a515fe8c4c7c0e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'service1_param-response)))
  "Returns md5sum for a message object of type 'service1_param-response"
  "b6db00bb6b5b71eef0a515fe8c4c7c0e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<service1_param-response>)))
  "Returns full string definition for message of type '<service1_param-response>"
  (cl:format cl:nil "bool Status~%uint8 Key~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'service1_param-response)))
  "Returns full string definition for message of type 'service1_param-response"
  (cl:format cl:nil "bool Status~%uint8 Key~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <service1_param-response>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <service1_param-response>))
  "Converts a ROS message object to a list"
  (cl:list 'service1_param-response
    (cl:cons ':Status (Status msg))
    (cl:cons ':Key (Key msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'service1_param)))
  'service1_param-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'service1_param)))
  'service1_param-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'service1_param)))
  "Returns string type for a service object of type '<service1_param>"
  "angen_turtlebot/service1_param")