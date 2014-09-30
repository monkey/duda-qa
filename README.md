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

- :white_check_mark: fully implemented and functional
- :warning:  work in process
- :no_entry: not yet implemented


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
                     |                    | :white_check_mark: | alloc             |
                     |                    | :white_check_mark: | alloc_z           |
                     |                    | :white_check_mark: | free              |
                     |                    | :white_check_mark: | realloc           |
 :no_entry:          | Global Worker      |                    |                   |
                     |                    | :no_entry:         | get               |
                     |                    | :no_entry:         | init              |
                     |                    | :no_entry:         | set               |
 :white_check_mark:  | Log Writer         |                    |                   |
                     |                    | :white_check_mark: | duda_logger_create | log_writer/
                     |                    | :white_check_mark: | print             | log_writer/
 :no_entry:          | Parameters         |                    |                   |
                     |                    | :no_entry:         | count             |
                     |                    | :no_entry:         | get               |
                     |                    | :no_entry:         | get_number        |
                     |                    | :no_entry:         | len               |
 :no_entry:          | Query String       |                    |                   |
                     |                    | :no_entry:         | cmp               |
                     |                    | :no_entry:         | count             |
                     |                    | :no_entry:         | get               |
                     |                    | :no_entry:         | get_id            |
 :no_entry:          | Response           |                    |                   |
                     |                    | :no_entry:         | cont              |
                     |                    | :no_entry:         | end               |
                     |                    | :no_entry:         | finalize          |
                     |                    | :no_entry:         | flush             |
                     |                    | :no_entry:         | headers_off       |
                     |                    | :no_entry:         | http_content_length |
                     |                    | :no_entry:         | http_content_type   |
                     |                    | :no_entry:         | http_header       |
                     |                    | :no_entry:         | http_header_n     |
                     |                    | :no_entry:         | http_status       |
                     |                    | :no_entry:         | get               |
                     |                    | :no_entry:         | print             |
                     |                    | :no_entry:         | printf            |
                     |                    | :no_entry:         | send_headers      |
                     |                    | :no_entry:         | sendfile          |
                     |                    | :no_entry:         | sendfile_range    |
                     |                    | :no_entry:         | wait              |
 :no_entry:          | Request            |                    |                   |
                     |                    | :no_entry:         | content_length    |
                     |                    | :no_entry:         | content_type      |
                     |                    | :no_entry:         | get_data          |
                     |                    | :no_entry:         | header_cmp        |
                     |                    | :no_entry:         | header_contains   |
                     |                    | :no_entry:         | header_get        |
                     |                    | :no_entry:         | is_data           |
                     |                    | :no_entry:         | is_delete         |
                     |                    | :no_entry:         | is_get            |
                     |                    | :no_entry:         | is_head           |
                     |                    | :no_entry:         | is_post           |
                     |                    | :no_entry:         | is_put            |
                     |                    | :no_entry:         | validate_request  |
                     |                    | :no_entry:         | validate_socket   |
 :no_entry:          | Router             |                    |                   |
                     |                    | :no_entry:         | map               |
                     |                    | :no_entry:         | root              |
 :no_entry:          | Sessions           |                    |                   |
                     |                    | :no_entry:         | create            |
                     |                    | :no_entry:         | destroy           |
                     |                    | :no_entry:         | init              |
                     |                    | :no_entry:         | isset             |
 :no_entry:          | Workers            |                    |                   |
                     |                    | :no_entry:         | pre_loop          |
                     |                    | :no_entry:         | spawn             |
 :no_entry:          | Time Handling      |                    |                   |
                     |                    | :no_entry:         | next_hours        |
                     |                    | :no_entry:         | now               |
                     |                    | :no_entry:         | tomorrow          |
 :no_entry:          | Dthread            |                    |                   |
                     |                    | :no_entry:         | create            |
                     |                    | :no_entry:         | resume            |
                     |                    | :no_entry:         | running           |
                     |                    | :no_entry:         | status            |
                     |                    | :no_entry:         | yield             |

## Contact

Eduardo Silva <eduardo@monkey.io>
