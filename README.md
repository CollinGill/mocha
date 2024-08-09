# Mocha

## Goals

- [x] Scanner
- [ ] Parser
  - [ ] Syntax verification
  - [ ] Type checking
  - [ ] IR code generation
- [ ] Instruction
  - [ ] Selection
  - [ ] Scheduling
- [ ] Register allocation
- [ ] Multi-platform support
- [ ] Self-hosted

## Building and Compiling

Building Mocha
```bash
$ mkdir build
$ cd build
$ cmake ../
$ make
```

Compiling a Mocha file

```bash
$ ./mocha file_name.moc [OPTIONS]
```
