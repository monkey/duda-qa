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

The following table represents the status of each core API objects unit test and its methods available.
The boxes status means:

:white_check_mark: fully implemented
:warning: work in process
:no_entry: not yet implemented


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
 :white_check_mark:  | Events             |                    |                   |
                     |                    | :white_check_mark: | add               | event/events/
                     |                    | :white_check_mark: | create_signal_fd  | event/create_signal_fd/
                     |                    | :white_check_mark: | delete            | event/events/
                     |                    | :white_check_mark: | duda_event_signal_set_callback | event/signal_callback/
                     |                    | :white_check_mark: | lookup            | event/events/
                     |                    | :white_check_mark: | mode              | event/events/
                     |                    | :white_check_mark: | signal            | event/signal_callback/
 :white_check_mark:  | Garbage Collector  |                    |                   |
                     |                    | :white_check_mark: | add               | garbage_collector/
 :white_check_mark:  | Memory Handler     |                    |                   |
                     |                    | :white_check_mark: | alloc             | memory/
                     |                    | :white_check_mark: | alloc_z           | memory/
                     |                    | :white_check_mark: | free              | memory/
                     |                    | :white_check_mark: | realloc           | memory/
 :white_check_mark:  | Global Worker      |                    |                   |
                     |                    | :white_check_mark: | get               | global/
                     |                    | :white_check_mark: | init              | global/
                     |                    | :white_check_mark: | set               | global/
 :white_check_mark:  | Log Writer         |                    |                   |
                     |                    | :white_check_mark: | duda_logger_create | log_writer/
                     |                    | :white_check_mark: | print             | log_writer/
 :warning:           | Parameters         |                    |                   |
                     |                    | :warning:          | count             | parameters/
                     |                    | :warning:          | get               | parameters/
                     |                    | :warning:          | get_number        | parameters/
                     |                    | :warning:          | len               | parameters/
 :white_check_mark:  | Query String       |                    |                   |
                     |                    | :white_check_mark: | cmp               | query_string/
                     |                    | :white_check_mark: | count             | query_string/
                     |                    | :white_check_mark: | get               | query_string/
                     |                    | :white_check_mark: | get_id            | query_string/
 :warning:           | Response           |                    |                   |
                     |                    | :white_check_mark: | cont              | event/events/
                     |                    | :white_check_mark: | end               | event/events/
                     |                    | :white_check_mark: | finalize          | event/events/
                     |                    | :no_entry:         | flush             |
                     |                    | :no_entry:         | headers_off       |
                     |                    | :no_entry:         | http_content_length |
                     |                    | :no_entry:         | http_content_type   |
                     |                    | :white_check_mark: | http_header       | config/service_root/
                     |                    | :no_entry:         | http_header_n     |
                     |                    | :white_check_mark: | http_status       | event/events/
                     |                    | :no_entry:         | get               |
                     |                    | :no_entry:         | print             |
                     |                    | :white_check_mark: | printf            | event/events/
                     |                    | :no_entry:         | send_headers      |
                     |                    | :no_entry:         | sendfile          |
                     |                    | :no_entry:         | sendfile_range    |
                     |                    | :white_check_mark: | wait              | event/events/
 :white_check_mark:  | Request            |                    |                   |
                     |                    | :white_check_mark: | content_length    | request/
                     |                    | :white_check_mark: | content_type      | request/
                     |                    | :white_check_mark: | get_data          | request/
                     |                    | :white_check_mark: | header_cmp        | request/
                     |                    | :white_check_mark: | header_contains   | request/
                     |                    | :white_check_mark: | header_get        | request/
                     |                    | :white_check_mark: | is_data           | request/
                     |                    | :white_check_mark: | is_delete         | request/
                     |                    | :white_check_mark: | is_get            | request/
                     |                    | :white_check_mark: | is_head           | request/
                     |                    | :white_check_mark: | is_post           | request/
                     |                    | :white_check_mark: | is_put            | request/
                     |                    | :white_check_mark: | validate_request  | request/
                     |                    | :white_check_mark: | validate_socket   | request/
 :white_check_mark:  | Router             |                    |                   |
                     |                    | :white_check_mark: | map               | router/
                     |                    | :white_check_mark: | root              | router/
 :white_check_mark:  | Sessions           |                    |                   |
                     |                    | :white_check_mark: | create            | session/
                     |                    | :white_check_mark: | destroy           | session/
                     |                    | :white_check_mark: | get               | session/
                     |                    | :white_check_mark: | init              | session/
                     |                    | :white_check_mark: | isset             | session/
 :no_entry:          | Workers            |                    |                   |
                     |                    | :no_entry:         | pre_loop          |
                     |                    | :no_entry:         | spawn             |
 :white_check_mark:  | Time Handling      |                    |                   |
                     |                    | :white_check_mark: | next_hours        | time/
                     |                    | :white_check_mark: | now               | time/
                     |                    | :white_check_mark: | tomorrow          | time/
 :no_entry:          | Dthread            |                    |                   |
                     |                    | :no_entry:         | create            |
                     |                    | :no_entry:         | resume            |
                     |                    | :no_entry:         | running           |
                     |                    | :no_entry:         | status            |
                     |                    | :no_entry:         | yield             |

## Contact

Eduardo Silva <eduardo@monkey.io>
