#!/usr/bin/env bash

set -u

assert() {
    local expected="$1"
    local src_code="$2"

    ./tcc -S "${src_code}" > ./tmp-asm.s
    echo "<asm>"
    cat ./tmp-asm.s
    echo "</asm>"

    cc -o tmp-a.out tmp-asm.s
    ./tmp-a.out
    local got="$?"
    # echo "ret val: ${got}"
    

    if [ "${got}" = "${expected}" ]; then
        echo "${src_code} => ${got}"
    else
        echo "${src_code} => ${got}" >&2
        exit 1
    fi

}


#set -x
assert 4 4

echo ok
