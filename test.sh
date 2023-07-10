assert(){
    expected="$1"
    input="$2"

    ./out $input > tmp.s || exit
    gcc -o tmp tmp.s
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
assert 21 '10+10-3+4'

echo "OK"