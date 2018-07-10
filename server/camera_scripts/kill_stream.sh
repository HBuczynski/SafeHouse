#!/bin/bash


if pgrep raspivid; then sudo killall raspivid; fi
if pgrep vlc; then sudo killall vlc; fi
