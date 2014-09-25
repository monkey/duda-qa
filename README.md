# Duda I/O - Quality Assurance

The following repository is a complete QA test over every API found in the Core Objects of Duda I/O version DST-2.

# Unit tests

Once the run program load the unit tests index, it goes inside each unit test directory and lookup for three files:

- pre.sh
- qa.htt
- pos.sh

### pre.sh

If found, it will be run as the first thing. This kind of script is mostly used to cleanup or prepare the environment.

### qa.htt

This is the real HTTP Test Unit that perform the request and validate the server response. The script is interpreted by the __httest__ tool. Once it exits, the return value is validated.

### pos.sh

If found, it will be run after the _qa.htt_ test, it's made for post HTTP evaluations. Once it exists, the return value is validated.


## Status

Status of each unit test

- [x] Console
  - [x] dashboard()
  - [x] debug()
- [x] Cookies
  - [x] cmp()
  - [x] destroy()
  - [x] get()
  - [x] set()
- [ ] Configuration
  - [ ] bind_messages()
  - [ ] force_redirect()
  - [ ] service_name()
  - [ ] service_root()
- [ ] Data
  - [ ] get_path()
  - [ ] locate()
  - [ ] set_path()
- [ ] File Configuration
  - [ ] free_conf()
  - [ ] get_path()
  - [ ] read_conf()
  - [ ] read_file()
  - [ ] section_get()
  - [ ] section_key()
  - [ ] set_path()
- [ ] Events
  - [ ] add()
  - [ ] create_signal_fd()
  - [ ] delete()
  - [ ] duda_event_signal_set_callback()
  - [ ] lookup()
  - [ ] mode()
  - [ ] signal()
- [ ] Garbage Collector
  - [ ] add()
- [ ] Memory Handler
  - [ ] alloc()
  - [ ] alloc_z()
  - [ ] free()
  - [ ] realloc()
- [ ] Global Worker
  - [ ] get()
  - [ ] init()
  - [ ] set()
- [ ] Log Writer
  - [ ] duda_logger_create()
  - [ ] print()
- [ ] Parameters
- [ ] Query String
- [ ] Response
- [ ] Request
- [ ] Router
- [ ] Sessions
- [ ] Workers
- [ ] Time handling
- [ ] Dthread
