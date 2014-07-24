/* Auto-generated by genmsg_cpp for file /home/angenuser/ros_workspace/angen_cognitive_environment/angen_apps/srv/AngenActuatorsStatus.srv */
#ifndef ANGEN_APPS_SERVICE_ANGENACTUATORSSTATUS_H
#define ANGEN_APPS_SERVICE_ANGENACTUATORSSTATUS_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "ros/service_traits.h"




namespace angen_apps
{
template <class ContainerAllocator>
struct AngenActuatorsStatusRequest_ {
  typedef AngenActuatorsStatusRequest_<ContainerAllocator> Type;

  AngenActuatorsStatusRequest_()
  : room_name()
  , actuator_name()
  , status()
  {
  }

  AngenActuatorsStatusRequest_(const ContainerAllocator& _alloc)
  : room_name(_alloc)
  , actuator_name(_alloc)
  , status(_alloc)
  {
  }

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _room_name_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  room_name;

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _actuator_name_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  actuator_name;

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _status_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  status;


  typedef boost::shared_ptr< ::angen_apps::AngenActuatorsStatusRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::angen_apps::AngenActuatorsStatusRequest_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct AngenActuatorsStatusRequest
typedef  ::angen_apps::AngenActuatorsStatusRequest_<std::allocator<void> > AngenActuatorsStatusRequest;

typedef boost::shared_ptr< ::angen_apps::AngenActuatorsStatusRequest> AngenActuatorsStatusRequestPtr;
typedef boost::shared_ptr< ::angen_apps::AngenActuatorsStatusRequest const> AngenActuatorsStatusRequestConstPtr;


template <class ContainerAllocator>
struct AngenActuatorsStatusResponse_ {
  typedef AngenActuatorsStatusResponse_<ContainerAllocator> Type;

  AngenActuatorsStatusResponse_()
  {
  }

  AngenActuatorsStatusResponse_(const ContainerAllocator& _alloc)
  {
  }


  typedef boost::shared_ptr< ::angen_apps::AngenActuatorsStatusResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::angen_apps::AngenActuatorsStatusResponse_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct AngenActuatorsStatusResponse
typedef  ::angen_apps::AngenActuatorsStatusResponse_<std::allocator<void> > AngenActuatorsStatusResponse;

typedef boost::shared_ptr< ::angen_apps::AngenActuatorsStatusResponse> AngenActuatorsStatusResponsePtr;
typedef boost::shared_ptr< ::angen_apps::AngenActuatorsStatusResponse const> AngenActuatorsStatusResponseConstPtr;

struct AngenActuatorsStatus
{

typedef AngenActuatorsStatusRequest Request;
typedef AngenActuatorsStatusResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;
}; // struct AngenActuatorsStatus
} // namespace angen_apps

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::angen_apps::AngenActuatorsStatusRequest_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::angen_apps::AngenActuatorsStatusRequest_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::angen_apps::AngenActuatorsStatusRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "a97cfb375f1d8956bb5deea093104771";
  }

  static const char* value(const  ::angen_apps::AngenActuatorsStatusRequest_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xa97cfb375f1d8956ULL;
  static const uint64_t static_value2 = 0xbb5deea093104771ULL;
};

template<class ContainerAllocator>
struct DataType< ::angen_apps::AngenActuatorsStatusRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "angen_apps/AngenActuatorsStatusRequest";
  }

  static const char* value(const  ::angen_apps::AngenActuatorsStatusRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::angen_apps::AngenActuatorsStatusRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "string room_name\n\
string actuator_name\n\
string status\n\
\n\
";
  }

  static const char* value(const  ::angen_apps::AngenActuatorsStatusRequest_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros


namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::angen_apps::AngenActuatorsStatusResponse_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::angen_apps::AngenActuatorsStatusResponse_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::angen_apps::AngenActuatorsStatusResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const  ::angen_apps::AngenActuatorsStatusResponse_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::angen_apps::AngenActuatorsStatusResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "angen_apps/AngenActuatorsStatusResponse";
  }

  static const char* value(const  ::angen_apps::AngenActuatorsStatusResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::angen_apps::AngenActuatorsStatusResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "\n\
\n\
";
  }

  static const char* value(const  ::angen_apps::AngenActuatorsStatusResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::angen_apps::AngenActuatorsStatusResponse_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::angen_apps::AngenActuatorsStatusRequest_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.room_name);
    stream.next(m.actuator_name);
    stream.next(m.status);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct AngenActuatorsStatusRequest_
} // namespace serialization
} // namespace ros


namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::angen_apps::AngenActuatorsStatusResponse_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct AngenActuatorsStatusResponse_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace service_traits
{
template<>
struct MD5Sum<angen_apps::AngenActuatorsStatus> {
  static const char* value() 
  {
    return "a97cfb375f1d8956bb5deea093104771";
  }

  static const char* value(const angen_apps::AngenActuatorsStatus&) { return value(); } 
};

template<>
struct DataType<angen_apps::AngenActuatorsStatus> {
  static const char* value() 
  {
    return "angen_apps/AngenActuatorsStatus";
  }

  static const char* value(const angen_apps::AngenActuatorsStatus&) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<angen_apps::AngenActuatorsStatusRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "a97cfb375f1d8956bb5deea093104771";
  }

  static const char* value(const angen_apps::AngenActuatorsStatusRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<angen_apps::AngenActuatorsStatusRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "angen_apps/AngenActuatorsStatus";
  }

  static const char* value(const angen_apps::AngenActuatorsStatusRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<angen_apps::AngenActuatorsStatusResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "a97cfb375f1d8956bb5deea093104771";
  }

  static const char* value(const angen_apps::AngenActuatorsStatusResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<angen_apps::AngenActuatorsStatusResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "angen_apps/AngenActuatorsStatus";
  }

  static const char* value(const angen_apps::AngenActuatorsStatusResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace service_traits
} // namespace ros

#endif // ANGEN_APPS_SERVICE_ANGENACTUATORSSTATUS_H
