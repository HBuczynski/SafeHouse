#!/bin/bash

ipAddress=$1

snapshots_folder_name="snapshot"

# Create basic target folder.
if [ ! -d $snapshots_folder_name ]; then
    mkdir $snapshots_folder_name
fi

cd ${snapshots_folder_name}
fileName=`date '+%Y%m%d_%H:%M:%S'`'.jpg'
touch ${fileName}
raspistill -o ${fileName}
