#!/bin/bash

cd target/bin

sudo pkill -f dbus-daem
sudo hciconfig hci0 up
sudo ./main_rpi
