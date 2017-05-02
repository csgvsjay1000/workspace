// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: IM.Message.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "IM.Message.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace IM {
namespace Message {

namespace {

const ::google::protobuf::Descriptor* IMMsgData_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  IMMsgData_reflection_ = NULL;
const ::google::protobuf::Descriptor* IMMsgDataAck_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  IMMsgDataAck_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_IM_2eMessage_2eproto() {
  protobuf_AddDesc_IM_2eMessage_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "IM.Message.proto");
  GOOGLE_CHECK(file != NULL);
  IMMsgData_descriptor_ = file->message_type(0);
  static const int IMMsgData_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IMMsgData, from_user_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IMMsgData, to_session_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IMMsgData, msg_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IMMsgData, create_time_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IMMsgData, msg_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IMMsgData, msg_data_),
  };
  IMMsgData_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      IMMsgData_descriptor_,
      IMMsgData::default_instance_,
      IMMsgData_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IMMsgData, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IMMsgData, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(IMMsgData));
  IMMsgDataAck_descriptor_ = file->message_type(1);
  static const int IMMsgDataAck_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IMMsgDataAck, user_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IMMsgDataAck, session_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IMMsgDataAck, msg_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IMMsgDataAck, session_type_),
  };
  IMMsgDataAck_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      IMMsgDataAck_descriptor_,
      IMMsgDataAck::default_instance_,
      IMMsgDataAck_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IMMsgDataAck, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(IMMsgDataAck, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(IMMsgDataAck));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_IM_2eMessage_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    IMMsgData_descriptor_, &IMMsgData::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    IMMsgDataAck_descriptor_, &IMMsgDataAck::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_IM_2eMessage_2eproto() {
  delete IMMsgData::default_instance_;
  delete IMMsgData_reflection_;
  delete IMMsgDataAck::default_instance_;
  delete IMMsgDataAck_reflection_;
}

void protobuf_AddDesc_IM_2eMessage_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::IM::BaseDefine::protobuf_AddDesc_IM_2eBaseDefine_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\020IM.Message.proto\022\nIM.Message\032\023IM.BaseD"
    "efine.proto\"\231\001\n\tIMMsgData\022\024\n\014from_user_i"
    "d\030\001 \002(\r\022\025\n\rto_session_id\030\002 \002(\r\022\016\n\006msg_id"
    "\030\003 \002(\r\022\023\n\013create_time\030\004 \002(\r\022(\n\010msg_type\030"
    "\005 \002(\0162\026.IM.BaseDefine.MsgType\022\020\n\010msg_dat"
    "a\030\006 \002(\014\"u\n\014IMMsgDataAck\022\017\n\007user_id\030\001 \002(\r"
    "\022\022\n\nsession_id\030\002 \002(\r\022\016\n\006msg_id\030\003 \002(\r\0220\n\014"
    "session_type\030\004 \002(\0162\032.IM.BaseDefine.Sessi"
    "onType", 326);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "IM.Message.proto", &protobuf_RegisterTypes);
  IMMsgData::default_instance_ = new IMMsgData();
  IMMsgDataAck::default_instance_ = new IMMsgDataAck();
  IMMsgData::default_instance_->InitAsDefaultInstance();
  IMMsgDataAck::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_IM_2eMessage_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_IM_2eMessage_2eproto {
  StaticDescriptorInitializer_IM_2eMessage_2eproto() {
    protobuf_AddDesc_IM_2eMessage_2eproto();
  }
} static_descriptor_initializer_IM_2eMessage_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int IMMsgData::kFromUserIdFieldNumber;
const int IMMsgData::kToSessionIdFieldNumber;
const int IMMsgData::kMsgIdFieldNumber;
const int IMMsgData::kCreateTimeFieldNumber;
const int IMMsgData::kMsgTypeFieldNumber;
const int IMMsgData::kMsgDataFieldNumber;
#endif  // !_MSC_VER

IMMsgData::IMMsgData()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:IM.Message.IMMsgData)
}

void IMMsgData::InitAsDefaultInstance() {
}

IMMsgData::IMMsgData(const IMMsgData& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:IM.Message.IMMsgData)
}

void IMMsgData::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  from_user_id_ = 0u;
  to_session_id_ = 0u;
  msg_id_ = 0u;
  create_time_ = 0u;
  msg_type_ = 1;
  msg_data_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

IMMsgData::~IMMsgData() {
  // @@protoc_insertion_point(destructor:IM.Message.IMMsgData)
  SharedDtor();
}

void IMMsgData::SharedDtor() {
  if (msg_data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete msg_data_;
  }
  if (this != default_instance_) {
  }
}

void IMMsgData::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* IMMsgData::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return IMMsgData_descriptor_;
}

const IMMsgData& IMMsgData::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_IM_2eMessage_2eproto();
  return *default_instance_;
}

IMMsgData* IMMsgData::default_instance_ = NULL;

IMMsgData* IMMsgData::New() const {
  return new IMMsgData;
}

void IMMsgData::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<IMMsgData*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 63) {
    ZR_(from_user_id_, create_time_);
    msg_type_ = 1;
    if (has_msg_data()) {
      if (msg_data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        msg_data_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool IMMsgData::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:IM.Message.IMMsgData)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 from_user_id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &from_user_id_)));
          set_has_from_user_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_to_session_id;
        break;
      }

      // required uint32 to_session_id = 2;
      case 2: {
        if (tag == 16) {
         parse_to_session_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &to_session_id_)));
          set_has_to_session_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_msg_id;
        break;
      }

      // required uint32 msg_id = 3;
      case 3: {
        if (tag == 24) {
         parse_msg_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &msg_id_)));
          set_has_msg_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_create_time;
        break;
      }

      // required uint32 create_time = 4;
      case 4: {
        if (tag == 32) {
         parse_create_time:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &create_time_)));
          set_has_create_time();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_msg_type;
        break;
      }

      // required .IM.BaseDefine.MsgType msg_type = 5;
      case 5: {
        if (tag == 40) {
         parse_msg_type:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::IM::BaseDefine::MsgType_IsValid(value)) {
            set_msg_type(static_cast< ::IM::BaseDefine::MsgType >(value));
          } else {
            mutable_unknown_fields()->AddVarint(5, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_msg_data;
        break;
      }

      // required bytes msg_data = 6;
      case 6: {
        if (tag == 50) {
         parse_msg_data:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_msg_data()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:IM.Message.IMMsgData)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:IM.Message.IMMsgData)
  return false;
#undef DO_
}

void IMMsgData::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:IM.Message.IMMsgData)
  // required uint32 from_user_id = 1;
  if (has_from_user_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->from_user_id(), output);
  }

  // required uint32 to_session_id = 2;
  if (has_to_session_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->to_session_id(), output);
  }

  // required uint32 msg_id = 3;
  if (has_msg_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->msg_id(), output);
  }

  // required uint32 create_time = 4;
  if (has_create_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->create_time(), output);
  }

  // required .IM.BaseDefine.MsgType msg_type = 5;
  if (has_msg_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      5, this->msg_type(), output);
  }

  // required bytes msg_data = 6;
  if (has_msg_data()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      6, this->msg_data(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:IM.Message.IMMsgData)
}

::google::protobuf::uint8* IMMsgData::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:IM.Message.IMMsgData)
  // required uint32 from_user_id = 1;
  if (has_from_user_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->from_user_id(), target);
  }

  // required uint32 to_session_id = 2;
  if (has_to_session_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->to_session_id(), target);
  }

  // required uint32 msg_id = 3;
  if (has_msg_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->msg_id(), target);
  }

  // required uint32 create_time = 4;
  if (has_create_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(4, this->create_time(), target);
  }

  // required .IM.BaseDefine.MsgType msg_type = 5;
  if (has_msg_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      5, this->msg_type(), target);
  }

  // required bytes msg_data = 6;
  if (has_msg_data()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        6, this->msg_data(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:IM.Message.IMMsgData)
  return target;
}

int IMMsgData::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 from_user_id = 1;
    if (has_from_user_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->from_user_id());
    }

    // required uint32 to_session_id = 2;
    if (has_to_session_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->to_session_id());
    }

    // required uint32 msg_id = 3;
    if (has_msg_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->msg_id());
    }

    // required uint32 create_time = 4;
    if (has_create_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->create_time());
    }

    // required .IM.BaseDefine.MsgType msg_type = 5;
    if (has_msg_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->msg_type());
    }

    // required bytes msg_data = 6;
    if (has_msg_data()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->msg_data());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void IMMsgData::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const IMMsgData* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const IMMsgData*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void IMMsgData::MergeFrom(const IMMsgData& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_from_user_id()) {
      set_from_user_id(from.from_user_id());
    }
    if (from.has_to_session_id()) {
      set_to_session_id(from.to_session_id());
    }
    if (from.has_msg_id()) {
      set_msg_id(from.msg_id());
    }
    if (from.has_create_time()) {
      set_create_time(from.create_time());
    }
    if (from.has_msg_type()) {
      set_msg_type(from.msg_type());
    }
    if (from.has_msg_data()) {
      set_msg_data(from.msg_data());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void IMMsgData::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void IMMsgData::CopyFrom(const IMMsgData& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool IMMsgData::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000003f) != 0x0000003f) return false;

  return true;
}

void IMMsgData::Swap(IMMsgData* other) {
  if (other != this) {
    std::swap(from_user_id_, other->from_user_id_);
    std::swap(to_session_id_, other->to_session_id_);
    std::swap(msg_id_, other->msg_id_);
    std::swap(create_time_, other->create_time_);
    std::swap(msg_type_, other->msg_type_);
    std::swap(msg_data_, other->msg_data_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata IMMsgData::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = IMMsgData_descriptor_;
  metadata.reflection = IMMsgData_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int IMMsgDataAck::kUserIdFieldNumber;
const int IMMsgDataAck::kSessionIdFieldNumber;
const int IMMsgDataAck::kMsgIdFieldNumber;
const int IMMsgDataAck::kSessionTypeFieldNumber;
#endif  // !_MSC_VER

IMMsgDataAck::IMMsgDataAck()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:IM.Message.IMMsgDataAck)
}

void IMMsgDataAck::InitAsDefaultInstance() {
}

IMMsgDataAck::IMMsgDataAck(const IMMsgDataAck& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:IM.Message.IMMsgDataAck)
}

void IMMsgDataAck::SharedCtor() {
  _cached_size_ = 0;
  user_id_ = 0u;
  session_id_ = 0u;
  msg_id_ = 0u;
  session_type_ = 1;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

IMMsgDataAck::~IMMsgDataAck() {
  // @@protoc_insertion_point(destructor:IM.Message.IMMsgDataAck)
  SharedDtor();
}

void IMMsgDataAck::SharedDtor() {
  if (this != default_instance_) {
  }
}

void IMMsgDataAck::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* IMMsgDataAck::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return IMMsgDataAck_descriptor_;
}

const IMMsgDataAck& IMMsgDataAck::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_IM_2eMessage_2eproto();
  return *default_instance_;
}

IMMsgDataAck* IMMsgDataAck::default_instance_ = NULL;

IMMsgDataAck* IMMsgDataAck::New() const {
  return new IMMsgDataAck;
}

void IMMsgDataAck::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<IMMsgDataAck*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 15) {
    ZR_(user_id_, msg_id_);
    session_type_ = 1;
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool IMMsgDataAck::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:IM.Message.IMMsgDataAck)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 user_id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &user_id_)));
          set_has_user_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_session_id;
        break;
      }

      // required uint32 session_id = 2;
      case 2: {
        if (tag == 16) {
         parse_session_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &session_id_)));
          set_has_session_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_msg_id;
        break;
      }

      // required uint32 msg_id = 3;
      case 3: {
        if (tag == 24) {
         parse_msg_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &msg_id_)));
          set_has_msg_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_session_type;
        break;
      }

      // required .IM.BaseDefine.SessionType session_type = 4;
      case 4: {
        if (tag == 32) {
         parse_session_type:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::IM::BaseDefine::SessionType_IsValid(value)) {
            set_session_type(static_cast< ::IM::BaseDefine::SessionType >(value));
          } else {
            mutable_unknown_fields()->AddVarint(4, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:IM.Message.IMMsgDataAck)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:IM.Message.IMMsgDataAck)
  return false;
#undef DO_
}

void IMMsgDataAck::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:IM.Message.IMMsgDataAck)
  // required uint32 user_id = 1;
  if (has_user_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->user_id(), output);
  }

  // required uint32 session_id = 2;
  if (has_session_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->session_id(), output);
  }

  // required uint32 msg_id = 3;
  if (has_msg_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->msg_id(), output);
  }

  // required .IM.BaseDefine.SessionType session_type = 4;
  if (has_session_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      4, this->session_type(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:IM.Message.IMMsgDataAck)
}

::google::protobuf::uint8* IMMsgDataAck::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:IM.Message.IMMsgDataAck)
  // required uint32 user_id = 1;
  if (has_user_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->user_id(), target);
  }

  // required uint32 session_id = 2;
  if (has_session_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->session_id(), target);
  }

  // required uint32 msg_id = 3;
  if (has_msg_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->msg_id(), target);
  }

  // required .IM.BaseDefine.SessionType session_type = 4;
  if (has_session_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      4, this->session_type(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:IM.Message.IMMsgDataAck)
  return target;
}

int IMMsgDataAck::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 user_id = 1;
    if (has_user_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->user_id());
    }

    // required uint32 session_id = 2;
    if (has_session_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->session_id());
    }

    // required uint32 msg_id = 3;
    if (has_msg_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->msg_id());
    }

    // required .IM.BaseDefine.SessionType session_type = 4;
    if (has_session_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->session_type());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void IMMsgDataAck::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const IMMsgDataAck* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const IMMsgDataAck*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void IMMsgDataAck::MergeFrom(const IMMsgDataAck& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_user_id()) {
      set_user_id(from.user_id());
    }
    if (from.has_session_id()) {
      set_session_id(from.session_id());
    }
    if (from.has_msg_id()) {
      set_msg_id(from.msg_id());
    }
    if (from.has_session_type()) {
      set_session_type(from.session_type());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void IMMsgDataAck::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void IMMsgDataAck::CopyFrom(const IMMsgDataAck& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool IMMsgDataAck::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000000f) != 0x0000000f) return false;

  return true;
}

void IMMsgDataAck::Swap(IMMsgDataAck* other) {
  if (other != this) {
    std::swap(user_id_, other->user_id_);
    std::swap(session_id_, other->session_id_);
    std::swap(msg_id_, other->msg_id_);
    std::swap(session_type_, other->session_type_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata IMMsgDataAck::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = IMMsgDataAck_descriptor_;
  metadata.reflection = IMMsgDataAck_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message
}  // namespace IM

// @@protoc_insertion_point(global_scope)