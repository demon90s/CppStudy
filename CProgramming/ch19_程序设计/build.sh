#! /bin/bash

# 自动编译源文件的脚本，使用方法：sh build.sh [rebuild | clear]

all_c_files=`ls *.c`
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
	for c_file in $all_c_files; do
		exe_file=${c_file%%.c*}.exe

		if [ "$1" == "clear" ]; then
			rm -f $exe_file
			continue
		fi

		if is_exclude_file $c_file; then
			continue
		fi

		if [ $exe_file -nt $c_file ] && [ "$1" != "rebuild" ]; then
			continue
		fi

		echo "[BUILDING] $c_file -> $exe_file"
		gcc -g -Wall $c_file -o $exe_file

		if [ "$?" != "0" ]; then
			return 1
		fi
	done

	# for cpp files
	arr_cpp_files=(ex_07.cpp)
	local i=0
	while [ "$i" != ${#arr_cpp_files[@]} ]
	do
		local cpp_file=${arr_cpp_files[$i]}
		local exe_file=${cpp_file%%.cpp*}.exe

		if [ "$1" == "clear" ]; then
			rm -f $exe_file
		else
			echo "[BUILDING] $cpp_file -> $exe_file"
			g++ -g -Wall -std=c++11 $cpp_file -o $exe_file
		fi
		
		i=$((i + 1))
	done
	

	return 0
}

main $1

exit $?
