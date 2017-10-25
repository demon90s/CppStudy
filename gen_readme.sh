# 生成README.md文件

#! /bin/bash

old_dir=$(pwd)
readme_file=${old_dir}/README.md

#######################################################################

# 设置每一个章节名字

get_all_chapters()
{
cat << !CHAPTERS!
第1章_开始
第2章_变量和基本类型
第3章_字符串、向量和数组
第4章_表达式
第5章_语句
第6章_函数
!CHAPTERS!
}

chapters=$(get_all_chapters)

#第2章_变量和基本类型
#第3章_字符串、向量和数组
#第4章_表达式
#第5章_语句
#第6章_函数

######################################################################

# 生成一个章节练习的md文本

gen_exercise_txt()
{
	ch_name=$1				# 章节名
	ch_dir=$(ls -d $2*)		# 章节路径
	n_ch=$3					# 第几章

	#echo "$ch_name $ch_dir"

	cd $ch_dir

	exercise_files=$(ls -d exercise*); # 所有的练习文件，包括目录
	echo "### $ch_name" >> $readme_file
	echo >> $readme_file
	echo "|E|X|E|R|C|I|S|E|" >> $readme_file
	echo "| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |" >> $readme_file # 居中
	
	num=0	# 第几个练习
	for exercise_file in $exercise_files; do

		num=$((num + 1))

		# exercise_1_01a.cpp --> 01a.cpp --> 1a.cpp --> 1a --> 练习1.1a
		tab_name=${exercise_file##*_}
		tab_name=${tab_name##0}
		tab_name=${tab_name%%.*}
		tab_name=练习$n_ch.$tab_name

		echo -e "|[$tab_name]($ch_dir/$exercise_file)\c" >> $readme_file

		# 8列一行
		if [ $((num % 8)) = "0" ]; then
			echo "|" >> $readme_file
		fi
	done

	if [ $((num % 8)) != "0" ]; then
		echo "|" >> $readme_file
	fi
	
	echo >> $readme_file

	cd ..
	return 0
}

######################################################################

# 生成一个章节的案例代码的文本

gen_example_txt()
{
	ch_dir=$(ls -d $1*)		# 章节路径

	cd $ch_dir
	example_files=$(ls -d example* 2> /dev/null); # 所有的案例文件，包括目录

	if [ "$example_files" = "" ]; then
		cd ..
		return 0
	fi

	echo "#### 案例代码" >> $readme_file
	echo >> $readme_file

	for file in $example_files; do
		# // example: 数组形参（p193） --> 数组形参（p193）
		desc=$(grep "// example" $file)
		desc=${desc#*: }

		if [ "$desc" != "" ]; then
			echo "- [$desc]($ch_dir/$file)" >> $readme_file
			echo >> $readme_file
		fi
	done

	cd ..
	return 0
}

######################################################################

gen_readme()
{
	n_ch=0 		# 当前处理的第几章
	for ch_name in $chapters; do
		n_ch=$(($n_ch + 1))

		cur_ch=ch # 章节的英文路径开头

		if [ $n_ch -lt 10 ]; then
			cur_ch=ch0
		fi

		cur_ch=${cur_ch}$n_ch

		gen_exercise_txt $ch_name $cur_ch $n_ch
		gen_example_txt $cur_ch
	done

	return 0
}

main()
{
	rm -f $readme_file
	touch $readme_file

	gen_readme

	return 0
}

main

exit 0
