sleep 1
cat /tmp/qa.duda.messages | grep "test to stderr"
if [ $? -eq 1 ]; then
    exit 1
fi

cat /tmp/qa.duda.messages | grep "test to stdout"
if [ $? -eq 1 ]; then
    exit 1
fi

cat /tmp/qa.duda.messages | grep "message using API"
