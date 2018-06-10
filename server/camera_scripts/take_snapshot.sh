#!/bin/bash

ipAddress=$1

snapshots_folder_name="snapshot"

# Create basic target folder.
if [ ! -d $snapshots_folder_name ]; then
    mkdir $snapshots_folder_name
fi

cd ${snapshots_folder_name}
#fileName=`date '+%Y%m%d_%H:%M:%S'`'.jpg'
fileName="img.jpg"
touch ${fileName}
raspistill -t 500 -vf -hf -o ${fileName}

sudo mv img.jpg /var/www/html
