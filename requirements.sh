#!/bin/bash

# Variables
CURRENT_DIR=$PWD
INPUT_ARGS=$@

# Flags
UPDATE="False"

# Checks for any flag
while test $# -gt 0; do
    case "$1" in
        -u )
            UPDATE="True"
            shift
        ;;
        -update )
            UPDATE="True"
            shift
        ;;
    esac
done


clone_and_install_libzmq () {
    # Creates Requirements folder
    mkdir -p requirements
    cd requirements

    # Clone
    git clone https://github.com/zeromq/libzmq.git

    # Installation
    cd libzmq
    mkdir -p build
    cd build
    cmake ..
    sudo make -j4 install

    cd $CURRENT_DIR
}

clone_and_install_cppzmq () {
    # Creates Requirements folder
    mkdir -p requirements
    cd requirements

    # Clone
    git clone https://github.com/zeromq/cppzmq.git

    # Installation
    cd cppzmq
    mkdir -p build
    cd build
    cmake ..
    sudo make -j4 install

    cd $CURRENT_DIR
}

clone_and_install_logging () {
    # Creates Requirements folder
    mkdir -p requirements
    cd requirements

    # Clone
    git clone https://github.com/andremmvgabriel/Logger.git

    # Installation
    cd Logger
    ./install.sh $INPUT_ARGS
    cd $CURRENT_DIR
}

if [ -f "/usr/local/lib/libzmq.a" ]; then
    if [ $UPDATE == "True" ]; then
        echo "> Updating LIBZMQ lib file..."
        clone_and_install_libzmq
        echo "   Update done!"
    else 
        echo "> LIBZMQ detected in the libraries folder. Skipping installation..."
    fi
else
    echo "> LIBZMQ was not detected in the libraries folder. Installing..."
    clone_and_install_libzmq
    echo "   LIBZMQ successfully installed!"
fi


if [ -f "/usr/local/include/zmq.hpp" ]; then
    if [ $UPDATE == "True" ]; then
        echo "> Updating CPPZMQ lib file..."
        clone_and_install_cppzmq
        echo "   Update done!"
    else 
        echo "> CPPZMQ detected in the libraries folder. Skipping installation..."
    fi
else
    echo "> CPPZMQ was not detected in the libraries folder. Installing..."
    clone_and_install_cppzmq
    echo "   CPPZMQ successfully installed!"
fi

clone_and_install_logging

# Removes the generated directories and files, if any
if [ -d "${CURRENT_DIR}/requirements" ]; then
    sudo rm -r requirements
fi