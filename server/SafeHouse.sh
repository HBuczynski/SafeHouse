#!/bin/bash

cd target/bin

sudo pkill -f dbus-daem
sudo hcitool hci0 up
sudo ./main_rpi
