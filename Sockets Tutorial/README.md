# TCP Echo Server

A basic single-threaded TCP echo server implementation for Windows using WinSock2.

## Overview

This server listens on port 54000 and echoes back any data it receives from clients. It's a foundational example for learning network programming concepts but **is not production-ready**.

## Features

- IPv4 TCP socket server
- Single client handling per connection
- Basic error handling
- Echo functionality (sends received data back to client)

## Requirements

- Windows OS
- C++ compiler with WinSock2 support
- ws2_32 library

## Compilation

```bash
g++ -o tcp_server main.cpp -lws2_32
```

Or with MSVC:
```bash
cl main.cpp ws2_32.lib
```

## Usage

1. Compile the program
2. Run the executable
3. Connect using telnet or a custom client:
   ```bash
   telnet localhost 54000
   ```
4. Type messages - they will be echoed back
5. Server handles one client at a time

## Architecture

```
[Client] ---> [Socket] ---> [Server Process] ---> [Echo Back] ---> [Client]
```

The server follows this flow:
1. Initialize WinSock2
2. Create TCP socket
3. Bind to port 54000
4. Listen for connections
5. Accept client connections (blocking)
6. Receive data, echo back, close connection
7. Repeat step 5

## Known Limitations

⚠️ **This is a learning example, not production code:**

- **Single-threaded**: Only handles one client at a time
- **Buffer overflow risk**: Fixed 4KB buffer without bounds checking
- **Incorrect send size**: Sends entire buffer instead of received bytes
- **No graceful shutdown**: Infinite loop with no exit condition
- **Limited error recovery**: Basic error handling only
- **Windows-only**: Uses WinSock2 (not portable)

## Code Issues to Address

1. **Wrong send size**:
   ```cpp
   // Current (wrong):
   send(clientSocket, buffer, sizeof(buffer), 0);
   
   // Should be:
   send(clientSocket, buffer, bytesReceived, 0);
   ```

2. **No null termination safety**:
   ```cpp
   // Add bounds checking:
   buffer[min(bytesReceived, sizeof(buffer)-1)] = '\0';
   ```

3. **Single client limitation**:
   - Consider threading or async I/O for multiple clients
   - Current design blocks other clients while serving one

## Learning Objectives

This code demonstrates:
- WinSock2 initialization and cleanup
- Socket creation, binding, and listening
- Basic client-server communication
- TCP connection lifecycle
- Error handling patterns in network code

## Next Steps for Improvement

1. **Multi-client support**: Implement threading or select/poll
2. **Proper message framing**: Handle partial receives/sends
3. **Configuration**: Make port and buffer size configurable
4. **Logging**: Replace cout/cerr with proper logging
5. **Graceful shutdown**: Handle SIGINT/SIGTERM
6. **Cross-platform**: Abstract socket operations
7. **Security**: Input validation, rate limiting, connection limits

## Network Programming Concepts

- **Socket**: Endpoint for communication
- **Bind**: Associate socket with local address/port
- **Listen**: Mark socket as passive (accepting connections)
- **Accept**: Extract first connection from queue
- **Blocking I/O**: Operations wait until complete

## Testing

Test with multiple scenarios:
- Single client connection
- Large message handling
- Client disconnection
- Multiple rapid connections
- Invalid data input

## Performance Characteristics

- **Throughput**: Limited by single-threaded design
- **Latency**: Low for single client, high queuing for multiple
- **Memory**: Fixed 4KB per connection
- **CPU**: Blocks on I/O operations

---

**Remember**: This is educational code. Real servers need proper architecture, error handling, security, and scalability considerations.