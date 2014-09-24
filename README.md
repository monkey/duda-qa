# Duda Quality Assurance

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

