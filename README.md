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

The following list represents the status of each core API objects and it methods available. Unchecked boxes are _work in process_.

                     | Object             | Test          | Methods      | Comments
---------------------|--------------------|---------------|--------------|-----------------------|
 :white_check_mark:  | Console            |               |              |                       |
                     | :white_check_mark: | dashboard_01  |              | Request redirect      |
                     | :white_check_mark: |               | dashboard    |                       |
                     | :white_check_mark: | dashboard_02  |              | Direct dashboard load |
                     | :white_check_mark: |               | dashboard    |                       |
                     | :white_check_mark: | debug         |              | Write message through debug() method          |
                     | :white_check_mark: |               | debug        |                                               |
 :white_check_mark:  | Cookie             |               |              |                                               |
                     | :white_check_mark: | ALL           |              | Set cookie, get, compare and destroy          |
                     | :white_check_mark: |               | cmp          |                                               | 
                     | :white_check_mark: |               | destroy      |                                               |
                     | :white_check_mark: |               | get          |                                               |
                     | :white_check_mark: |               | set          |                                               |
                     | | | | | 
 :white_check_mark:  | Configuration      |               |               |                                               |
 :white_check_mark:  |                    | bind_messages | bind_messages | Write message to stdout and stderr, validate console file |
 :white_check_mark:  |                    | service_name  | service_name  | Alter service name and validate new service URL |
 :white_check_mark:  |                    | service_root  | service_root  | Make the service the owner of the server, check new URL |
 :white_check_mark:  | Data               |               |               |                       |
 :white_check_mark:  |                    | ALL           | get_path, locate, set_path | Locate file path, override Data path and compose new one |
 :white_check_mark:  | File Configuration |               |               |                       |
 :white_check_mark:  |                    | ALL           | free_conf, get_path, read_conf, read_file, section_get, section_key, set_path| Read configuration file |
 :warning:           | Events             |
 :no_entry:          |                    | ???           | add           |                       |
 :white_check_mark:  |                    | create_signal_fd |            | Spawn a worker and set a new listener, trap request and update a global value |
                     |                    |                  | create_signal_fd |                 |


- [ ] Events
  - [ ] add()
  - [x] create_signal_fd()
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

## Contact

Eduardo Silva <eduardo@monkey.io>
