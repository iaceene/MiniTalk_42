# Minitalk

a simple project that demonstrates inter-process communication using Unix signals. It involves creating a **server** and a **client**, where the client sends messages to the server using signals, and the server decodes and handles those messages.

## Features
- **Server-Client Communication** using signals
- **Message Encoding and Decoding**: Messages are transmitted bit by bit using the `SIGUSR1` and `SIGUSR2` signals.
- **Signal-based Communication** instead of traditional sockets or IPC mechanisms.
- **Lightweight and efficient**: Demonstrates an interesting way to exchange information without relying on external libraries.

## How It Works

1. **Client**: Sends a message to the server by using a series of signals (`SIGUSR1` for `0` and `SIGUSR2` for `1`).
2. **Server**: Listens for incoming signals and reconstructs the message from the signals received.
3. **Communication Flow**:
   - The server needs to be running first.
   - The client sends a string (message) encoded in binary using signals.
   - The server receives the signals, decodes the message, and prints it on the console.

## Project Structure

```
minitalk/
├── src/                   # Main source directory
│   ├── src_client/         # Client source code
│   │   ├── cli_utiles.c    # Client utility functions
│   │   ├── client.h        # Client header file
│   │   ├── main.c          # Client program entry point
│   ├── src_server/         # Server source code
│   │   ├── ft_putnbr.c     # Helper function to print numbers
│   │   ├── main.c          # Server program entry point
│   │   ├── server.h        # Server header file
│   │   ├── srv_utiles.c    # Server utility functions
│   ├── Makefile            # Makefile to build the project
├── src_client_bonus/       # Bonus client source code
│   ├── cli_helper_bonus.c  # Bonus client helper functions
│   ├── cli_utiles_bonus.c  # Bonus client utility functions
│   ├── client_bonus.h      # Bonus client header file
│   ├── main_bonus.c        # Bonus client main entry point
├── src_server_bonus/       # Bonus server source code
│   ├── buffer_bonus.c      # Bonus buffer handling
│   ├── ft_putnbr_bonus.c   # Bonus number printing helper
│   ├── main_bonus.c        # Bonus server entry point
│   ├── server_bonus.h      # Bonus server header
│   ├── server_helper_bonus.c  # Bonus server helper functions
│   ├── srv_utiles_bonus.c  # Bonus server utility functions
└── README.md               # Project documentation
```

## Compilation

1. Clone the repository:
   ```bash
   git clone https://github.com/iaceene/minitalk42.git
   cd minitalk42
   ```

2. Use the `Makefile` to compile both the server and client:
   ```bash
   make
   ```

3. This will create the following executables:
   - `server`: The program that will listen for incoming signals.
   - `client`: The program that will send signals to the server.

## Usage

1. **Start the server**:
   Open a terminal and run the server program:
   ```bash
   ./server
   ```

2. **Start the client**:
   In another terminal, run the client program with the PID of the running server and the message you want to send:
   ```bash
   ./client <server_pid> "Hello, Minitalk!"
   ```

   Example:
   ```bash
   ./client 12345 "Hello"
   ```

   - The client will send the message "Hello" to the server, and the server will print it as it is decoded.

## Example

### Running the Server:
```bash
$ ./server
PID : 1234
```

### Running the Client:
```bash
$ ./client <server_pid> "Hello World"
```

The server will output:
```
>> Hello World
```

## Signal Handling

- The communication uses the `SIGUSR1` and `SIGUSR2` signals for encoding the message:
  - `SIGUSR1`: Represents a binary `1`
  - `SIGUSR2`: Represents a binary `0`

The message is sent bit by bit, with each signal representing a single bit of the message.

## Notes

- **Signal Safety**: Signals are a low-level form of inter-process communication. Ensure that your signal handler functions are minimal and do not rely on non-async-safe functions.
- **Error Handling**: The program assumes basic error handling, such as invalid PID or failure to send/receive signals.
- **OS Compatibility**: This project assumes you're working on a Unix-like operating system (Linux, macOS)..

---

If you have any questions or issues, feel free to open an issue or reach out!
