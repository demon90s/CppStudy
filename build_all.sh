#! /bin/bash

# 重新编译所有文件，用于全局检测

main()
{
	echo -e "\n========Make sure gcc version >= 4.9.2========\n\n"
	sleep 1

	for directory in ./ch*
	do
		cd $directory

		if ! sh build.sh rebuild ; then
			return 1
		fi

		# 进入example目录，这些目录采用Makefile来编译文件
		for example_d in ./example*
		do
			if [ -d $example_d ]; then
				cd $example_d

				make clean
				make

				cd ..
			fi
		done

		cd ..
	done

	return 0
}

time main

exit $?
