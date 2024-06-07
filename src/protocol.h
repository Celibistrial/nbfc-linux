#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include "error.h"
#include "nxjson.h"

#define PROTOCOL_END_MARKER     "\nEND"
#define PROTOCOL_END_MARKER_LEN 4

Error* Protocol_Send_Json(int, const nx_json*);
Error* Protocol_Receive_Json(int, char**, const nx_json**);
Error* Protocol_Send_Error(int, const char*);
Error* Protocol_Send(int, const void*, size_t);

static inline Error* Protocol_Send_End(int socket) {
  return Protocol_Send(socket, PROTOCOL_END_MARKER, PROTOCOL_END_MARKER_LEN);
}

#endif
