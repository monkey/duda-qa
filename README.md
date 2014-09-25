# Duda I/O - Quality Assurance

The following repository is a complete QA test over every API found in the Core Objects of Duda I/O version DST-2.

# Unit tests

Once the run program load the unit tests index, it goes inside each unit test directory and lookup for three files: _pre.sh_, _qa.htt_ and _pos.sh_.

  script | description
---------|-----------
pre.sh   | If found, it will be run as the first thing. This kind of script is mostly used to cleanup or prepare the environment.
qa.htt   | This is the real HTTP Test Unit that perform the request and validate the server response. The script is interpreted by the __httest__ tool. Once it exits, the return value is validated.
pos.sh   | If found, it will be run after the _qa.htt_ test, it's made for post HTTP evaluations. Once it exists, the return value is validated.

## Usage

The tool assumes you have installed __dudac__ tool in your system:

```bash
$ pip install dudac
```

now build [Duda I/O](http://duda.io) stack using __dudac__ and with a simple example
service:

```bash
$ dudac -w core/console/debug
```

then break the service with CTRL-C, the stack have been built and is ready to be used with
the unit tests. The final step is just to launcht the __run__ Python script:

```bash
$ ./run
```
Optionally if you are using a custom stack on your file system, you can point it through the environment variable _DUDAC\_STAGE_, e.g:

```bash
$ export DUDAC_STAGE=/home/foo/stack/
```

note: after set the environment variable, __dudac__ will expect to find a __monkey__ directory
inside _/home/foo/stack/_.

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
- [x] Configuration
  - [x] bind_messages()
  - [x] service_name()
  - [x] service_root()
- [x] Data
  - [x] get_path()
  - [x] locate()
  - [x] set_path()
- [x] File Configuration
  - [x] free_conf()
  - [x] get_path()
  - [x] read_conf()
  - [x] read_file()
  - [x] section_get()
  - [x] section_key()
  - [x] set_path()
- [ ] Events
  - [ ] add()
  - [ ] create_signal_fd()
  - [ ] delete()
  - [x] duda_event_signal_set_callback()
  - [ ] lookup()
  - [ ] mode()
  - [x] signal()
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
  - [ ] count()
  - [ ] get()
  - [ ] get_number()
  - [ ] len()
- [ ] Query String
  - [ ] cmp()
  - [ ] count()
  - [ ] get()
  - [ ] get_id()
- [ ] Response
  - [ ] cont()
  - [ ] end()
  - [ ] finalize()
  - [ ] flush()
  - [ ] headers_off()
  - [ ] http_content_length()
  - [ ] http_content_type()
  - [ ] http_header()
  - [ ] http_header_n()
  - [ ] http_status()
  - [ ] print()
  - [ ] printf()
  - [ ] send_headers()
  - [ ] sendfile()
  - [ ] sendfile_range()
  - [ ] wait()
- [ ] Request
  - [ ] content_length()
  - [ ] content_type()
  - [ ] get_data()
  - [ ] header_cmp()
  - [ ] header_contains()
  - [ ] header_get()
  - [ ] is_data()
  - [ ] is_delete()
  - [ ] is_get()
  - [ ] is_head()
  - [ ] is_post()
  - [ ] is_put()
  - [ ] validate_request()
  - [ ] validate_socket()
- [ ] Router
  - [ ] map()
  - [ ] root()
- [ ] Sessions
  - [ ] create()
  - [ ] destroy()
  - [ ] get()
  - [ ] init()
  - [ ] isset()
- [ ] Workers
  - [ ] pre_loop()
  - [ ] spawn()
- [ ] Time handling
  - [ ] next_hours()
  - [ ] now()
  - [ ] tomorrow()
- [ ] Dthread
  - [ ] create()
  - [ ] resume()
  - [ ] running()
  - [ ] status()
  - [ ] yield()
