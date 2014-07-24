; Auto-generated. Do not edit!


(cl:in-package angen_turtlebot-msg)


;//! \htmlinclude navigaton_status.msg.html

(cl:defclass <navigaton_status> (roslisp-msg-protocol:ros-message)
  ((status
    :reader status
    :initarg :status
    :type cl:string
    :initform "")
   (caller
    :reader caller
    :initarg :caller
    :type cl:string
    :initform ""))
)

(cl:defclass navigaton_status (<navigaton_status>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <navigaton_status>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'navigaton_status)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name angen_turtlebot-msg:<navigaton_status> is deprecated: use angen_turtlebot-msg:navigaton_status instead.")))

(cl:ensure-generic-function 'status-val :lambda-list '(m))
(cl:defmethod status-val ((m <navigaton_status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader angen_turtlebot-msg:status-val is deprecated.  Use angen_turtlebot-msg:status instead.")
  (status m))

(cl:ensure-generic-function 'caller-val :lambda-list '(m))
(cl:defmethod caller-val ((m <navigaton_status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader angen_turtlebot-msg:caller-val is deprecated.  Use angen_turtlebot-msg:caller instead.")
  (caller m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <navigaton_status>) ostream)
  "Serializes a message object of type '<navigaton_status>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'status))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'status))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'caller))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'caller))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <navigaton_status>) istream)
  "Deserializes a message object of type '<navigaton_status>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'status) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'status) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<navigaton_status>)))
  "Returns string type for a message object of type '<navigaton_status>"
  "angen_turtlebot/navigaton_status")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'navigaton_status)))
  "Returns string type for a message object of type 'navigaton_status"
  "angen_turtlebot/navigaton_status")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<navigaton_status>)))
  "Returns md5sum for a message object of type '<navigaton_status>"
  "5621ef7591b337dd599209f825a644b4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'navigaton_status)))
  "Returns md5sum for a message object of type 'navigaton_status"
  "5621ef7591b337dd599209f825a644b4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<navigaton_status>)))
  "Returns full string definition for message of type '<navigaton_status>"
  (cl:format cl:nil "string status~%string caller~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'navigaton_status)))
  "Returns full string definition for message of type 'navigaton_status"
  (cl:format cl:nil "string status~%string caller~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <navigaton_status>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'status))
     4 (cl:length (cl:slot-value msg 'caller))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <navigaton_status>))
  "Converts a ROS message object to a list"
  (cl:list 'navigaton_status
    (cl:cons ':status (status msg))
    (cl:cons ':caller (caller msg))
))
