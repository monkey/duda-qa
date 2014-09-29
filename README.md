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

                     | API Object         |                    | Methods           | Web Service Test
---------------------|--------------------|--------------------|-------------------|----------------------
 :white_check_mark:  | Console            |                    |                   |
                     |                    | :white_check_mark: | dashboard         | console/dashboard_01/
                     |                    | :white_check_mark: | dashboard         | console/dashboard_02/
                     |                    | :white_check_mark: | debug             | console/debug/
 :white_check_mark:  | Cookie             |                    |                   |
                     |                    | :white_check_mark: | cmp               | cookie/
                     |                    | :white_check_mark: | destroy           | cookie/
                     |                    | :white_check_mark: | get               | cookie/
                     |                    | :white_check_mark: | set               | cookie/
 :white_check_mark:  | Configuration      |                    |                   |
                     |                    | :white_check_mark: | bind_messages     | config/bind_messages/
                     |                    | :white_check_mark: | service_name      | config/service_name/
                     |                    | :white_check_mark: | service_root      | config/service_root/
 :white_check_mark:  | Data               |                    |                   |
                     |                    | :white_check_mark: | get_path          | data/
                     |                    | :white_check_mark: | locate            | data/
                     |                    | :white_check_mark: | set_path          | data/
 :white_check_mark:  | File Configuration |                    |                   |
                     |                    | :white_check_mark: | free_conf         | fconf/
                     |                    | :white_check_mark: | get_path          | fconf/
                     |                    | :white_check_mark: | read_conf         | fconf/
                     |                    | :white_check_mark: | read_file         | fconf/
                     |                    | :white_check_mark: | section_get       | fconf/
                     |                    | :white_check_mark: | section_key       | fconf/
                     |                    | :white_check_mark: | set_path          | fconf/
 :warning:           | Events             |                    |                   |
                     |                    | :no_entry:         | add               |
                     |                    | :white_check_mark: | create_signal_fd  | event/create_signal_fd/
                     |                    | :no_entry:         | delete            |
                     |                    | :white_check_mark: | duda_event_signal_set_callback | event/signal_callback/
                     |                    | :no_entry:         | delete            |
                     |                    | :no_entry:         | lookup            |
                     |                    | :no_entry:         | mode              |
                     |                    | :white_check_mark: | signal            | event/signal_callback/
 :warning:           | Garbage Collector  |                    |                   |
                     |                    | :no_entry:         | add               |
 :warning:           | Memory Handler     |                    |                   |
                     |                    | :no_entry:         | alloc             |
                     |                    | :no_entry:         | alloc_z           |
                     |                    | :no_entry:         | free              |
                     |                    | :no_entry:         | realloc           |
 :warning:           | Global Worker      |                    |                   |
                     |                    | :no_entry:         | get               |
                     |                    | :no_entry:         | init              |
                     |                    | :no_entry:         | set               |
 :warning:           | Log Writer         |                    |                   |
                     |                    | :no_entry:         | duda_loogger_create |
                     |                    | :no_entry:         | print             |
 :warning:           | Parameters         |                    |                   |
                     |                    | :no_entry:         | count             |
                     |                    | :no_entry:         | get               |
                     |                    | :no_entry:         | get_number        |
                     |                    | :no_entry:         | len               |


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
