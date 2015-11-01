// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: messageGame.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "../../../Headers/Utils/Socket/messageGame.pb.h"


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

namespace {

const ::google::protobuf::Descriptor* msg_game_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  msg_game_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_messageGame_2eproto() {
  protobuf_AddDesc_messageGame_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "messageGame.proto");
  GOOGLE_CHECK(file != NULL);
  msg_game_descriptor_ = file->message_type(0);
  static const int msg_game_offsets_[14] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msg_game, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msg_game, tipo_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msg_game, x_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msg_game, y_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msg_game, nombre_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msg_game, imagen_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msg_game, ancho_base_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msg_game, alto_base_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msg_game, fps_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msg_game, delay_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msg_game, total_frames_line_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msg_game, pixels_dimension_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msg_game, owner_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msg_game, newpath_),
  };
  msg_game_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      msg_game_descriptor_,
      msg_game::default_instance_,
      msg_game_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msg_game, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msg_game, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(msg_game));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_messageGame_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    msg_game_descriptor_, &msg_game::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_messageGame_2eproto() {
  delete msg_game::default_instance_;
  delete msg_game_reflection_;
}

void protobuf_AddDesc_messageGame_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\021messageGame.proto\"\362\001\n\010msg_game\022\n\n\002id\030\001"
    " \002(\005\022\014\n\004tipo\030\002 \002(\t\022\t\n\001x\030\003 \001(\005\022\t\n\001y\030\004 \001(\005"
    "\022\016\n\006nombre\030\005 \001(\t\022\016\n\006imagen\030\006 \001(\t\022\022\n\nanch"
    "o_base\030\007 \001(\005\022\021\n\talto_base\030\010 \001(\005\022\013\n\003fps\030\t"
    " \001(\005\022\r\n\005delay\030\n \001(\005\022\031\n\021total_frames_line"
    "\030\013 \001(\005\022\030\n\020pixels_dimension\030\014 \001(\005\022\r\n\005owne"
    "r\030\r \001(\t\022\017\n\007newPath\030\016 \001(\010", 264);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "messageGame.proto", &protobuf_RegisterTypes);
  msg_game::default_instance_ = new msg_game();
  msg_game::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_messageGame_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_messageGame_2eproto {
  StaticDescriptorInitializer_messageGame_2eproto() {
    protobuf_AddDesc_messageGame_2eproto();
  }
} static_descriptor_initializer_messageGame_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int msg_game::kIdFieldNumber;
const int msg_game::kTipoFieldNumber;
const int msg_game::kXFieldNumber;
const int msg_game::kYFieldNumber;
const int msg_game::kNombreFieldNumber;
const int msg_game::kImagenFieldNumber;
const int msg_game::kAnchoBaseFieldNumber;
const int msg_game::kAltoBaseFieldNumber;
const int msg_game::kFpsFieldNumber;
const int msg_game::kDelayFieldNumber;
const int msg_game::kTotalFramesLineFieldNumber;
const int msg_game::kPixelsDimensionFieldNumber;
const int msg_game::kOwnerFieldNumber;
const int msg_game::kNewPathFieldNumber;
#endif  // !_MSC_VER

msg_game::msg_game()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:msg_game)
}

void msg_game::InitAsDefaultInstance() {
}

msg_game::msg_game(const msg_game& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:msg_game)
}

void msg_game::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  id_ = 0;
  tipo_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  x_ = 0;
  y_ = 0;
  nombre_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  imagen_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ancho_base_ = 0;
  alto_base_ = 0;
  fps_ = 0;
  delay_ = 0;
  total_frames_line_ = 0;
  pixels_dimension_ = 0;
  owner_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  newpath_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

msg_game::~msg_game() {
  // @@protoc_insertion_point(destructor:msg_game)
  SharedDtor();
}

void msg_game::SharedDtor() {
  if (tipo_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete tipo_;
  }
  if (nombre_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete nombre_;
  }
  if (imagen_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete imagen_;
  }
  if (owner_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete owner_;
  }
  if (this != default_instance_) {
  }
}

void msg_game::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* msg_game::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return msg_game_descriptor_;
}

const msg_game& msg_game::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_messageGame_2eproto();
  return *default_instance_;
}

msg_game* msg_game::default_instance_ = NULL;

msg_game* msg_game::New() const {
  return new msg_game;
}

void msg_game::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<msg_game*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 255) {
    ZR_(id_, x_);
    ZR_(y_, ancho_base_);
    if (has_tipo()) {
      if (tipo_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        tipo_->clear();
      }
    }
    if (has_nombre()) {
      if (nombre_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        nombre_->clear();
      }
    }
    if (has_imagen()) {
      if (imagen_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        imagen_->clear();
      }
    }
    alto_base_ = 0;
  }
  if (_has_bits_[8 / 32] & 16128) {
    ZR_(fps_, total_frames_line_);
    ZR_(pixels_dimension_, newpath_);
    if (has_owner()) {
      if (owner_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        owner_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool msg_game::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:msg_game)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_tipo;
        break;
      }

      // required string tipo = 2;
      case 2: {
        if (tag == 18) {
         parse_tipo:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_tipo()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->tipo().data(), this->tipo().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "tipo");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_x;
        break;
      }

      // optional int32 x = 3;
      case 3: {
        if (tag == 24) {
         parse_x:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &x_)));
          set_has_x();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_y;
        break;
      }

      // optional int32 y = 4;
      case 4: {
        if (tag == 32) {
         parse_y:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &y_)));
          set_has_y();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_nombre;
        break;
      }

      // optional string nombre = 5;
      case 5: {
        if (tag == 42) {
         parse_nombre:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_nombre()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->nombre().data(), this->nombre().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "nombre");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_imagen;
        break;
      }

      // optional string imagen = 6;
      case 6: {
        if (tag == 50) {
         parse_imagen:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_imagen()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->imagen().data(), this->imagen().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "imagen");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_ancho_base;
        break;
      }

      // optional int32 ancho_base = 7;
      case 7: {
        if (tag == 56) {
         parse_ancho_base:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &ancho_base_)));
          set_has_ancho_base();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(64)) goto parse_alto_base;
        break;
      }

      // optional int32 alto_base = 8;
      case 8: {
        if (tag == 64) {
         parse_alto_base:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &alto_base_)));
          set_has_alto_base();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(72)) goto parse_fps;
        break;
      }

      // optional int32 fps = 9;
      case 9: {
        if (tag == 72) {
         parse_fps:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &fps_)));
          set_has_fps();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(80)) goto parse_delay;
        break;
      }

      // optional int32 delay = 10;
      case 10: {
        if (tag == 80) {
         parse_delay:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &delay_)));
          set_has_delay();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(88)) goto parse_total_frames_line;
        break;
      }

      // optional int32 total_frames_line = 11;
      case 11: {
        if (tag == 88) {
         parse_total_frames_line:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &total_frames_line_)));
          set_has_total_frames_line();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(96)) goto parse_pixels_dimension;
        break;
      }

      // optional int32 pixels_dimension = 12;
      case 12: {
        if (tag == 96) {
         parse_pixels_dimension:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &pixels_dimension_)));
          set_has_pixels_dimension();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(106)) goto parse_owner;
        break;
      }

      // optional string owner = 13;
      case 13: {
        if (tag == 106) {
         parse_owner:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_owner()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->owner().data(), this->owner().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "owner");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(112)) goto parse_newPath;
        break;
      }

      // optional bool newPath = 14;
      case 14: {
        if (tag == 112) {
         parse_newPath:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &newpath_)));
          set_has_newpath();
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
  // @@protoc_insertion_point(parse_success:msg_game)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:msg_game)
  return false;
#undef DO_
}

void msg_game::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:msg_game)
  // required int32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
  }

  // required string tipo = 2;
  if (has_tipo()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->tipo().data(), this->tipo().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "tipo");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->tipo(), output);
  }

  // optional int32 x = 3;
  if (has_x()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->x(), output);
  }

  // optional int32 y = 4;
  if (has_y()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->y(), output);
  }

  // optional string nombre = 5;
  if (has_nombre()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->nombre().data(), this->nombre().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "nombre");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      5, this->nombre(), output);
  }

  // optional string imagen = 6;
  if (has_imagen()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->imagen().data(), this->imagen().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "imagen");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      6, this->imagen(), output);
  }

  // optional int32 ancho_base = 7;
  if (has_ancho_base()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(7, this->ancho_base(), output);
  }

  // optional int32 alto_base = 8;
  if (has_alto_base()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(8, this->alto_base(), output);
  }

  // optional int32 fps = 9;
  if (has_fps()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(9, this->fps(), output);
  }

  // optional int32 delay = 10;
  if (has_delay()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(10, this->delay(), output);
  }

  // optional int32 total_frames_line = 11;
  if (has_total_frames_line()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(11, this->total_frames_line(), output);
  }

  // optional int32 pixels_dimension = 12;
  if (has_pixels_dimension()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(12, this->pixels_dimension(), output);
  }

  // optional string owner = 13;
  if (has_owner()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->owner().data(), this->owner().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "owner");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      13, this->owner(), output);
  }

  // optional bool newPath = 14;
  if (has_newpath()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(14, this->newpath(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:msg_game)
}

::google::protobuf::uint8* msg_game::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:msg_game)
  // required int32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
  }

  // required string tipo = 2;
  if (has_tipo()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->tipo().data(), this->tipo().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "tipo");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->tipo(), target);
  }

  // optional int32 x = 3;
  if (has_x()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->x(), target);
  }

  // optional int32 y = 4;
  if (has_y()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->y(), target);
  }

  // optional string nombre = 5;
  if (has_nombre()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->nombre().data(), this->nombre().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "nombre");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->nombre(), target);
  }

  // optional string imagen = 6;
  if (has_imagen()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->imagen().data(), this->imagen().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "imagen");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        6, this->imagen(), target);
  }

  // optional int32 ancho_base = 7;
  if (has_ancho_base()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, this->ancho_base(), target);
  }

  // optional int32 alto_base = 8;
  if (has_alto_base()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(8, this->alto_base(), target);
  }

  // optional int32 fps = 9;
  if (has_fps()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(9, this->fps(), target);
  }

  // optional int32 delay = 10;
  if (has_delay()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(10, this->delay(), target);
  }

  // optional int32 total_frames_line = 11;
  if (has_total_frames_line()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(11, this->total_frames_line(), target);
  }

  // optional int32 pixels_dimension = 12;
  if (has_pixels_dimension()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(12, this->pixels_dimension(), target);
  }

  // optional string owner = 13;
  if (has_owner()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->owner().data(), this->owner().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "owner");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        13, this->owner(), target);
  }

  // optional bool newPath = 14;
  if (has_newpath()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(14, this->newpath(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:msg_game)
  return target;
}

int msg_game::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->id());
    }

    // required string tipo = 2;
    if (has_tipo()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->tipo());
    }

    // optional int32 x = 3;
    if (has_x()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->x());
    }

    // optional int32 y = 4;
    if (has_y()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->y());
    }

    // optional string nombre = 5;
    if (has_nombre()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->nombre());
    }

    // optional string imagen = 6;
    if (has_imagen()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->imagen());
    }

    // optional int32 ancho_base = 7;
    if (has_ancho_base()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->ancho_base());
    }

    // optional int32 alto_base = 8;
    if (has_alto_base()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->alto_base());
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional int32 fps = 9;
    if (has_fps()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->fps());
    }

    // optional int32 delay = 10;
    if (has_delay()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->delay());
    }

    // optional int32 total_frames_line = 11;
    if (has_total_frames_line()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->total_frames_line());
    }

    // optional int32 pixels_dimension = 12;
    if (has_pixels_dimension()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->pixels_dimension());
    }

    // optional string owner = 13;
    if (has_owner()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->owner());
    }

    // optional bool newPath = 14;
    if (has_newpath()) {
      total_size += 1 + 1;
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

void msg_game::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const msg_game* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const msg_game*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void msg_game::MergeFrom(const msg_game& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_tipo()) {
      set_tipo(from.tipo());
    }
    if (from.has_x()) {
      set_x(from.x());
    }
    if (from.has_y()) {
      set_y(from.y());
    }
    if (from.has_nombre()) {
      set_nombre(from.nombre());
    }
    if (from.has_imagen()) {
      set_imagen(from.imagen());
    }
    if (from.has_ancho_base()) {
      set_ancho_base(from.ancho_base());
    }
    if (from.has_alto_base()) {
      set_alto_base(from.alto_base());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_fps()) {
      set_fps(from.fps());
    }
    if (from.has_delay()) {
      set_delay(from.delay());
    }
    if (from.has_total_frames_line()) {
      set_total_frames_line(from.total_frames_line());
    }
    if (from.has_pixels_dimension()) {
      set_pixels_dimension(from.pixels_dimension());
    }
    if (from.has_owner()) {
      set_owner(from.owner());
    }
    if (from.has_newpath()) {
      set_newpath(from.newpath());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void msg_game::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void msg_game::CopyFrom(const msg_game& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool msg_game::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void msg_game::Swap(msg_game* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(tipo_, other->tipo_);
    std::swap(x_, other->x_);
    std::swap(y_, other->y_);
    std::swap(nombre_, other->nombre_);
    std::swap(imagen_, other->imagen_);
    std::swap(ancho_base_, other->ancho_base_);
    std::swap(alto_base_, other->alto_base_);
    std::swap(fps_, other->fps_);
    std::swap(delay_, other->delay_);
    std::swap(total_frames_line_, other->total_frames_line_);
    std::swap(pixels_dimension_, other->pixels_dimension_);
    std::swap(owner_, other->owner_);
    std::swap(newpath_, other->newpath_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata msg_game::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = msg_game_descriptor_;
  metadata.reflection = msg_game_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)