; Auto-generated. Do not edit!


(cl:in-package angen_apps-srv)


;//! \htmlinclude AngenActuatorsStatus-request.msg.html

(cl:defclass <AngenActuatorsStatus-request> (roslisp-msg-protocol:ros-message)
  ((room_name
    :reader room_name
    :initarg :room_name
    :type cl:string
    :initform "")
   (actuator_name
    :reader actuator_name
    :initarg :actuator_name
    :type cl:string
    :initform "")
   (status
    :reader status
    :initarg :status
    :type cl:string
    :initform ""))
)

(cl:defclass AngenActuatorsStatus-request (<AngenActuatorsStatus-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AngenActuatorsStatus-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AngenActuatorsStatus-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name angen_apps-srv:<AngenActuatorsStatus-request> is deprecated: use angen_apps-srv:AngenActuatorsStatus-request instead.")))

(cl:ensure-generic-function 'room_name-val :lambda-list '(m))
(cl:defmethod room_name-val ((m <AngenActuatorsStatus-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader angen_apps-srv:room_name-val is deprecated.  Use angen_apps-srv:room_name instead.")
  (room_name m))

(cl:ensure-generic-function 'actuator_name-val :lambda-list '(m))
(cl:defmethod actuator_name-val ((m <AngenActuatorsStatus-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader angen_apps-srv:actuator_name-val is deprecated.  Use angen_apps-srv:actuator_name instead.")
  (actuator_name m))

(cl:ensure-generic-function 'status-val :lambda-list '(m))
(cl:defmethod status-val ((m <AngenActuatorsStatus-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader angen_apps-srv:status-val is deprecated.  Use angen_apps-srv:status instead.")
  (status m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AngenActuatorsStatus-request>) ostream)
  "Serializes a message object of type '<AngenActuatorsStatus-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'room_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'room_name))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'actuator_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'actuator_name))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'status))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'status))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AngenActuatorsStatus-request>) istream)
  "Deserializes a message object of type '<AngenActuatorsStatus-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'room_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'room_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'actuator_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'actuator_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'status) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'status) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AngenActuatorsStatus-request>)))
  "Returns string type for a service object of type '<AngenActuatorsStatus-request>"
  "angen_apps/AngenActuatorsStatusRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AngenActuatorsStatus-request)))
  "Returns string type for a service object of type 'AngenActuatorsStatus-request"
  "angen_apps/AngenActuatorsStatusRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AngenActuatorsStatus-request>)))
  "Returns md5sum for a message object of type '<AngenActuatorsStatus-request>"
  "a97cfb375f1d8956bb5deea093104771")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AngenActuatorsStatus-request)))
  "Returns md5sum for a message object of type 'AngenActuatorsStatus-request"
  "a97cfb375f1d8956bb5deea093104771")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AngenActuatorsStatus-request>)))
  "Returns full string definition for message of type '<AngenActuatorsStatus-request>"
  (cl:format cl:nil "string room_name~%string actuator_name~%string status~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AngenActuatorsStatus-request)))
  "Returns full string definition for message of type 'AngenActuatorsStatus-request"
  (cl:format cl:nil "string room_name~%string actuator_name~%string status~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AngenActuatorsStatus-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'room_name))
     4 (cl:length (cl:slot-value msg 'actuator_name))
     4 (cl:length (cl:slot-value msg 'status))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AngenActuatorsStatus-request>))
  "Converts a ROS message object to a list"
  (cl:list 'AngenActuatorsStatus-request
    (cl:cons ':room_name (room_name msg))
    (cl:cons ':actuator_name (actuator_name msg))
    (cl:cons ':status (status msg))
))
;//! \htmlinclude AngenActuatorsStatus-response.msg.html

(cl:defclass <AngenActuatorsStatus-response> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass AngenActuatorsStatus-response (<AngenActuatorsStatus-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AngenActuatorsStatus-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AngenActuatorsStatus-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name angen_apps-srv:<AngenActuatorsStatus-response> is deprecated: use angen_apps-srv:AngenActuatorsStatus-response instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AngenActuatorsStatus-response>) ostream)
  "Serializes a message object of type '<AngenActuatorsStatus-response>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AngenActuatorsStatus-response>) istream)
  "Deserializes a message object of type '<AngenActuatorsStatus-response>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AngenActuatorsStatus-response>)))
  "Returns string type for a service object of type '<AngenActuatorsStatus-response>"
  "angen_apps/AngenActuatorsStatusResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AngenActuatorsStatus-response)))
  "Returns string type for a service object of type 'AngenActuatorsStatus-response"
  "angen_apps/AngenActuatorsStatusResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AngenActuatorsStatus-response>)))
  "Returns md5sum for a message object of type '<AngenActuatorsStatus-response>"
  "a97cfb375f1d8956bb5deea093104771")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AngenActuatorsStatus-response)))
  "Returns md5sum for a message object of type 'AngenActuatorsStatus-response"
  "a97cfb375f1d8956bb5deea093104771")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AngenActuatorsStatus-response>)))
  "Returns full string definition for message of type '<AngenActuatorsStatus-response>"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AngenActuatorsStatus-response)))
  "Returns full string definition for message of type 'AngenActuatorsStatus-response"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AngenActuatorsStatus-response>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AngenActuatorsStatus-response>))
  "Converts a ROS message object to a list"
  (cl:list 'AngenActuatorsStatus-response
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'AngenActuatorsStatus)))
  'AngenActuatorsStatus-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'AngenActuatorsStatus)))
  'AngenActuatorsStatus-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AngenActuatorsStatus)))
  "Returns string type for a service object of type '<AngenActuatorsStatus>"
  "angen_apps/AngenActuatorsStatus")