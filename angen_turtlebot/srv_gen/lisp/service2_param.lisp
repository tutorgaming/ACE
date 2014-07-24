; Auto-generated. Do not edit!


(cl:in-package angen_turtlebot-srv)


;//! \htmlinclude service2_param-request.msg.html

(cl:defclass <service2_param-request> (roslisp-msg-protocol:ros-message)
  ((wait_time
    :reader wait_time
    :initarg :wait_time
    :type cl:fixnum
    :initform 0)
   (will_shake
    :reader will_shake
    :initarg :will_shake
    :type cl:boolean
    :initform cl:nil)
   (is_straight_line
    :reader is_straight_line
    :initarg :is_straight_line
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass service2_param-request (<service2_param-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <service2_param-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'service2_param-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name angen_turtlebot-srv:<service2_param-request> is deprecated: use angen_turtlebot-srv:service2_param-request instead.")))

(cl:ensure-generic-function 'wait_time-val :lambda-list '(m))
(cl:defmethod wait_time-val ((m <service2_param-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader angen_turtlebot-srv:wait_time-val is deprecated.  Use angen_turtlebot-srv:wait_time instead.")
  (wait_time m))

(cl:ensure-generic-function 'will_shake-val :lambda-list '(m))
(cl:defmethod will_shake-val ((m <service2_param-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader angen_turtlebot-srv:will_shake-val is deprecated.  Use angen_turtlebot-srv:will_shake instead.")
  (will_shake m))

(cl:ensure-generic-function 'is_straight_line-val :lambda-list '(m))
(cl:defmethod is_straight_line-val ((m <service2_param-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader angen_turtlebot-srv:is_straight_line-val is deprecated.  Use angen_turtlebot-srv:is_straight_line instead.")
  (is_straight_line m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <service2_param-request>) ostream)
  "Serializes a message object of type '<service2_param-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'wait_time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'will_shake) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'is_straight_line) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <service2_param-request>) istream)
  "Deserializes a message object of type '<service2_param-request>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'wait_time)) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'will_shake) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'is_straight_line) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<service2_param-request>)))
  "Returns string type for a service object of type '<service2_param-request>"
  "angen_turtlebot/service2_paramRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'service2_param-request)))
  "Returns string type for a service object of type 'service2_param-request"
  "angen_turtlebot/service2_paramRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<service2_param-request>)))
  "Returns md5sum for a message object of type '<service2_param-request>"
  "694429f7c3dd2c589b1a96726970a0a2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'service2_param-request)))
  "Returns md5sum for a message object of type 'service2_param-request"
  "694429f7c3dd2c589b1a96726970a0a2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<service2_param-request>)))
  "Returns full string definition for message of type '<service2_param-request>"
  (cl:format cl:nil "uint8 wait_time~%bool will_shake~%bool is_straight_line~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'service2_param-request)))
  "Returns full string definition for message of type 'service2_param-request"
  (cl:format cl:nil "uint8 wait_time~%bool will_shake~%bool is_straight_line~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <service2_param-request>))
  (cl:+ 0
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <service2_param-request>))
  "Converts a ROS message object to a list"
  (cl:list 'service2_param-request
    (cl:cons ':wait_time (wait_time msg))
    (cl:cons ':will_shake (will_shake msg))
    (cl:cons ':is_straight_line (is_straight_line msg))
))
;//! \htmlinclude service2_param-response.msg.html

(cl:defclass <service2_param-response> (roslisp-msg-protocol:ros-message)
  ((Status
    :reader Status
    :initarg :Status
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass service2_param-response (<service2_param-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <service2_param-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'service2_param-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name angen_turtlebot-srv:<service2_param-response> is deprecated: use angen_turtlebot-srv:service2_param-response instead.")))

(cl:ensure-generic-function 'Status-val :lambda-list '(m))
(cl:defmethod Status-val ((m <service2_param-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader angen_turtlebot-srv:Status-val is deprecated.  Use angen_turtlebot-srv:Status instead.")
  (Status m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <service2_param-response>) ostream)
  "Serializes a message object of type '<service2_param-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'Status) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <service2_param-response>) istream)
  "Deserializes a message object of type '<service2_param-response>"
    (cl:setf (cl:slot-value msg 'Status) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<service2_param-response>)))
  "Returns string type for a service object of type '<service2_param-response>"
  "angen_turtlebot/service2_paramResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'service2_param-response)))
  "Returns string type for a service object of type 'service2_param-response"
  "angen_turtlebot/service2_paramResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<service2_param-response>)))
  "Returns md5sum for a message object of type '<service2_param-response>"
  "694429f7c3dd2c589b1a96726970a0a2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'service2_param-response)))
  "Returns md5sum for a message object of type 'service2_param-response"
  "694429f7c3dd2c589b1a96726970a0a2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<service2_param-response>)))
  "Returns full string definition for message of type '<service2_param-response>"
  (cl:format cl:nil "bool Status~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'service2_param-response)))
  "Returns full string definition for message of type 'service2_param-response"
  (cl:format cl:nil "bool Status~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <service2_param-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <service2_param-response>))
  "Converts a ROS message object to a list"
  (cl:list 'service2_param-response
    (cl:cons ':Status (Status msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'service2_param)))
  'service2_param-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'service2_param)))
  'service2_param-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'service2_param)))
  "Returns string type for a service object of type '<service2_param>"
  "angen_turtlebot/service2_param")