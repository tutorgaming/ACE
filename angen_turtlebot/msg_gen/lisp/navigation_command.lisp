; Auto-generated. Do not edit!


(cl:in-package angen_turtlebot-msg)


;//! \htmlinclude navigation_command.msg.html

(cl:defclass <navigation_command> (roslisp-msg-protocol:ros-message)
  ((location
    :reader location
    :initarg :location
    :type cl:fixnum
    :initform 0)
   (caller
    :reader caller
    :initarg :caller
    :type cl:string
    :initform ""))
)

(cl:defclass navigation_command (<navigation_command>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <navigation_command>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'navigation_command)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name angen_turtlebot-msg:<navigation_command> is deprecated: use angen_turtlebot-msg:navigation_command instead.")))

(cl:ensure-generic-function 'location-val :lambda-list '(m))
(cl:defmethod location-val ((m <navigation_command>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader angen_turtlebot-msg:location-val is deprecated.  Use angen_turtlebot-msg:location instead.")
  (location m))

(cl:ensure-generic-function 'caller-val :lambda-list '(m))
(cl:defmethod caller-val ((m <navigation_command>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader angen_turtlebot-msg:caller-val is deprecated.  Use angen_turtlebot-msg:caller instead.")
  (caller m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <navigation_command>) ostream)
  "Serializes a message object of type '<navigation_command>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'location)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'caller))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'caller))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <navigation_command>) istream)
  "Deserializes a message object of type '<navigation_command>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'location)) (cl:read-byte istream))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'caller) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'caller) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<navigation_command>)))
  "Returns string type for a message object of type '<navigation_command>"
  "angen_turtlebot/navigation_command")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'navigation_command)))
  "Returns string type for a message object of type 'navigation_command"
  "angen_turtlebot/navigation_command")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<navigation_command>)))
  "Returns md5sum for a message object of type '<navigation_command>"
  "87e245bd936b9d0853e860f013c1a5fa")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'navigation_command)))
  "Returns md5sum for a message object of type 'navigation_command"
  "87e245bd936b9d0853e860f013c1a5fa")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<navigation_command>)))
  "Returns full string definition for message of type '<navigation_command>"
  (cl:format cl:nil "uint8 location~%string caller~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'navigation_command)))
  "Returns full string definition for message of type 'navigation_command"
  (cl:format cl:nil "uint8 location~%string caller~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <navigation_command>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'caller))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <navigation_command>))
  "Converts a ROS message object to a list"
  (cl:list 'navigation_command
    (cl:cons ':location (location msg))
    (cl:cons ':caller (caller msg))
))
