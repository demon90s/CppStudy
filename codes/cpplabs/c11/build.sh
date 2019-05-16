#! /bin/bash

# 自动编译源文件的脚本，使用方法：sh build.sh [rebuild | clear]

all_cpp_files=`ls *.cpp`
exclude_files=""

is_exclude_file() {
	for file in $exclude_files; do
		if [ "$file" = "$1" ]; then
			return 0
		fi
	done

	return 1
}

main() {
	for cpp_file in $all_cpp_files; do
		exe_file=${cpp_file%%.cpp*}

		if [ "$1" == "clear" ]; then
			rm -f $exe_file
			continue
		fi

		if is_exclude_file $cpp_file; then
			continue
		fi

		if [ $exe_file -nt $cpp_file ] && [ "$1" != "rebuild" ]; then
			continue
		fi

		echo "[BUILDING] $cpp_file -> $exe_file"
		g++ -g -Wall -std=c++11 $cpp_file -o $exe_file

		if [ "$?" != "0" ]; then
			return 1
		fi
	done

	return 0
}

main $1

exit $?
