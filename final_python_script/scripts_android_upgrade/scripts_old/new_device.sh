#!/bin/bash
if test "$1" = ""
then
	echo "Need a build variant config file"
	exit 1
fi

file="$1"
manufacturer=""
device=""
src_manufacturer=""
src_device=""
platform=""

while IFS= read -r line
do
	if [[ $line = *TARGET_MANUFACTURER_NAME* ]];
	then
		manufacturer="$(cut -d'=' -f2 <<<"$line")"
	fi

	if [[ $line = *TARGET_DEVICE_NAME* ]];
	then
		device="$(cut -d'=' -f2 <<<"$line")"
	fi
	
	if [[ $line = *SOURCE_DEVICE_NAME* ]];
	then
		src_device="$(cut -d'=' -f2 <<<"$line")"
	fi
	
	if [[ $line = *SOURCE_MANUFACTURER_NAME* ]];
	then
		src_manufacturer="$(cut -d'=' -f2 <<<"$line")"
	fi
	
	if [[ $line = *TARGET_PLATFORM* ]];
	then
		platform="$(cut -d'=' -f2 <<<"$line")"
	fi


done < "$file"


sh populate-new-device.sh $manufacturer $device

#cat > device/$manufacturer/$device/build_id.mk << EOF
#export BUILD_ID=1.0.1-ga-rc2
#export BUILD_NUMBER=20190426
#EOF

python3 ./python_scripts/copy_files.py $manufacturer $device $src_manufacturer $src_device $platform 

python3 ./python_scripts/Boardconfig.py $manufacturer $device $src_manufacturer $src_device $platform
python3 ./python_scripts/device-vendor.py $manufacturer $device $src_manufacturer $src_device $platform
python3 ./python_scripts/BoardConfigVendor.py $manufacturer $device $src_manufacturer $src_device $platform
python3 ./python_scripts/sabresd.py $manufacturer $device $src_manufacturer $src_device $platform
python3 ./python_scripts/AndroidBoard.py $manufacturer $device $src_manufacturer $src_device $platform

if [ $platform == "qcom" ]
then
echo "inside qcom"
python3 ./python_scripts/common.py $manufacturer $device $src_manufacturer $src_device $platform
fi

if [ $platform == "nxp" ]
then
echo "inside nxp"
python3 ./python_scripts/ImxPathConfig.py $manufacturer $device $src_manufacturer $src_device $platform
#python3 ./python_scripts/build_aospP.py $manufacturer $device $src_manufacturer $src_device $platform
fi
