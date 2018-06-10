#!/bin/bash

cd target/bin

sudo pkill -f dbus-daem
sudo ./main_rpi
