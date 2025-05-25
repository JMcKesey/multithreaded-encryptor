# 🔐 Multithreaded File Encryptor

Multithreaded File Encryptor is a high-performance C++ application that encrypts and decrypts all `.txt` files within a specified directory using a user-defined secret key. The project leverages multithreading to process files concurrently, significantly improving speed on multi-core systems.

---

## 🚀 Features

- 🔒 **Robust Encryption** — Simple yet effective encryption logic based on user-supplied secret key.
- 🧵 **Multithreaded Processing** — Files are encrypted/decrypted in parallel using a thread-safe queue system.
- 📂 **Batch Directory Processing** — Recursively processes all `.txt` files in the given directory.
- 🔁 **Two-Way Functionality** — Supports both encryption and decryption using the same secret key.
- 📄 **.env Configuration** — Secret key is securely stored in a `.env` file.
- 🛠️ **Minimal Dependencies** — Clean C++ implementation with no external cryptographic libraries.
- 💡 **Planned AES Support** — Future versions will support AES encryption without 3rd-party dependencies.

---

## ⚙️ How It Works

1. All `.txt` files in the target directory are collected.
2. A thread-safe queue holds file paths to be processed.
3. Worker threads pick files from the queue and encrypt or decrypt them using the key from `.env`.
4. The output overwrites the original file to prevent redundant storage.

---

## 🧪 Build Instructions

1. **Clone the repository**
   ```bash
   git clone https://github.com/your-username/multithreaded-file-encryptor.git
   cd multithreaded-file-encryptor
   ```

2. **Create `.env` file**
Place your secret key in a file named `.env` in the root of the project

3. **Build the project**
   ```bash
   make
   ```

4. **Run the executable**
   ```bash
   ./encrypt_decrypt
   ```

## 🔬 Testing
A python script has been provided in order to conduct your own testing, simply specify the directory in which you would like to place your randomly generated files.

## ⏳ Future Plans
* ✅ AES encryption support only using STL
* 🌐 QT6 GUI for non-technical users
