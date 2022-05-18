assert(){
    expected="$1"
    input="$2"

    ./out $input > tmp.s || exit
    gcc -static -o tmp tmp.s
    ./tmp
    res=$?

    if [ $res -eq $expected ]; then
        echo "$input -> $res"
    else
        echo "$input -> $expected expected, but got $res"
        exit 1
    fi
}

assert 0 0
assert 1 1

echo "OK"