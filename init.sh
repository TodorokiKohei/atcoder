#!/bin/bash

home_dir=$(pwd)

function ch(){
    cd "${home_dir}" || exit
}

function cw(){
    date_dir="${home_dir}/$(date '+%Y_%m/%d')"
    if [[ ! -e "${date_dir}" ]]; then
        mkdir -p "${date_dir}"
    fi
    cd "${date_dir}" || exit
}


function mf(){
    cw
    if [[ $# != 4 ]]; then
        echo "use case: mf <b|r|g> <number> <a-g> <a-g>"
        return
    fi

    if [[ $1 != 'b' && $1 != 'r' && $1 != 'g' ]]; then
        echo "use case: mf <b|r|g> <number> <a-g> <a-g>"
        return
    fi

    if [[ $2 -le 0 ]]; then
        echo "use case: mf <b|r|g> <number> <a-g> <a-g>"
        return
    fi

    if [[ $3 < 'a' || $3 > 'h' ]]; then
        echo "use case: mf <b|r|g> <number> <a-g> <a-g>"
        return
    fi

    if [[ $4 < 'a' || $4 > 'h' ]]; then
        echo "use case: mf <b|r|g> <number> <a-g> <a-g>"
        return
    fi

    if [[ $3 > $4 ]]; then
        echo "use case: mf <b|r|g> <number> <a-g> <a-g>"
        return 
    fi

    for c in $(eval echo {$3..$4}); do
        project_dir="a$1c$2_${c}"
        if [[ ! -e project_dir ]]; then
            mkdir "${project_dir}"
        fi
        filename="${project_dir}/a.cpp"
        if [[ ! -e filename ]]; then
            touch "${filename}"
        fi
    done

}

function op(){
    code -r a.cpp
}

function tst(){
    g++ -std=c++17 -Wall -I ~/ac-library a.cpp && oj t
}

function sub(){
    oj s a.cpp
}

function g(){
    g++ -std=c++17 -Wall -I ~/ac-library $1
}