#!/bin/bash

raspivid -t 999999 -vf -hf -b 2000000 -o - |cvlc stream:///v/stdin --sout '#standard{access=http,mux=ts,dst=:8090}' :demux=h264
