# Self-Linker: Dynamic GOT Manipulation Example

This project demonstrates how to dynamically resolve symbols in a shared library (`libc`) and manipulate entries in the **Global Offset Table (GOT)** at runtime.

It showcases advanced concepts in systems programming, dynamic linking, and runtime relocation—foundational knowledge for IT security professionals, exploit developers, and systems engineers.

---

## Overview

**self-linker.c** performs the following steps:

- Prints the address of the process's **Global Offset Table**.
- Dynamically loads `libc.so.6` using `dlopen()`.
- Locates the `puts()` function address using `dlsym()`.
- Overwrites a GOT entry to point to the dynamically resolved `puts()` implementation.
- Invokes `puts()` to print messages.

This illustrates how functions can be **dynamically redirected at runtime**, a principle underpinning many hooking and instrumentation techniques in security and IT operations.

---

## Use Cases

This project can be used to:

- **Understand dynamic symbol resolution** (`dlopen`, `dlsym`, `dlclose`).
- Explore **dynamic relocation and GOT manipulation**.
- Demonstrate basic concepts relevant to:
  - **Binary patching and hooking**
  - **Dynamic analysis tools**
  - **Security research (e.g., GOT overwrite attacks)**
  - **Debugging and instrumentation**

---

## Building

Ensure you have a C compiler (e.g., `gcc`) and glibc installed.

Use the provided Makefile to build:

```
make
```

This generates:

- `self-linker`: the executable demonstrating GOT manipulation.

To clean up:

```
make clean
```

---

## Running

Execute:

```
./self-linker
```

You should see output similar to:

```
The first entry of the global offset table is 0x...
The GOT starts at address 0x...
handle 0x...
pointer to function 0x...
hello
world!
```

---

## Technical Details

- **Dynamic Linking API**:
  - `dlopen()` loads a shared object at runtime.
  - `dlsym()` resolves a symbol to its address.
  - `dlclose()` unloads the shared object.

- **GOT Manipulation**:
  - The program directly assigns the address of `puts()` into the GOT.
  - This demonstrates how a process can redirect its own function calls.

- **Security Implications**:
  - Overwriting GOT entries is a technique used in exploits (e.g., GOT overwrite).
  - This highlights why protections like RELRO (Relocation Read-Only) exist in hardened binaries.

---

## Limitations & Considerations

- The implementation assumes `libc.so.6` is located in `/lib/`. Adjust the path if necessary.
- The example directly accesses `_GLOBAL_OFFSET_TABLE_` using pointer arithmetic; this is platform-specific and primarily for educational use.
- This example **does not** implement error handling for all edge cases.

---

## Potential Extensions

- Extend to manipulate additional GOT entries or functions.
- Combine with LD_PRELOAD techniques for runtime hooking.
- Integrate with debugging tools to trace GOT changes.

---

## Authors

- Tenzin Dolma Gyalpo
- Eliza-Teodora Tuta
