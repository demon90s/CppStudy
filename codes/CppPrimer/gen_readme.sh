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
第7章_类
第8章_IO库
第9章_顺序容器
第10章_泛型算法
第11章_关联容器
第12章_动态内存
第13章_拷贝控制
第14章_操作重载与类型转换
第15章_面向对象程序设计
第16章_模板与泛型编程
第17章_标准库特殊设施
第18章_用于大型程序的工具
第19章_特殊工具与技术
!CHAPTERS!
}

chapters=$(get_all_chapters)

######################################################################

# 生成一个章节练习的md文本

gen_exercise_txt()
{
	ch_name=$1				# 章节名
	ch_name=${ch_name/_/ }			# 取消下划线

	ch_dir=$(ls -d $2*)			# 章节路径
	n_ch=$3					# 第几章

	#echo "$ch_name $ch_dir"

	cd $ch_dir

	exercise_files=$(ls -d exercise*); # 所有的练习文件，包括目录
	echo "## $ch_name" >> $readme_file
	echo >> $readme_file
	echo "|A|L|L|E|X|E|" >> $readme_file
	echo "| :-: | :-: | :-: | :-: | :-: | :-: |" >> $readme_file # 居中
	
	num=0	# 第几个练习
	for exercise_file in $exercise_files; do

		num=$((num + 1))

		# exercise_1_01a.cpp --> 01a.cpp --> 1a.cpp --> 1a --> 练习1.1a
		tab_name=${exercise_file##*_}
		tab_name=${tab_name##0}
		tab_name=${tab_name%%.*}
		tab_name=练习$n_ch.$tab_name

		echo -e "|[$tab_name]($ch_dir/$exercise_file \"./$ch_dir/$exercise_file\")\c" >> $readme_file

		# 6列一行
		if [ $((num % 6)) = "0" ]; then
			echo "|" >> $readme_file
		fi
	done

	if [ $((num % 6)) != "0" ]; then
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

	echo "### 案例代码" >> $readme_file
	echo >> $readme_file

	for file in $example_files; do
		grep_file=$file
		if [ -d $file ]; then
			grep_file=$file/main.cpp
		fi

		# // example: 数组形参（p193） --> 数组形参（p193）
		desc=$(grep "// example" $grep_file)
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

	echo '# C++ Primer第五版学习笔记' >> $readme_file
	echo -e '\n学习环境：CentOS7 gcc4.8.5' >> $readme_file
	echo -e '\n以下内容需要更高的编译器版本支持：\n\n- 正则表达式库\n\n- 一些IO操纵符，比如hexfloat\n\n可以使用[在线编译器](http://coliru.stacked-crooked.com/)编译运行相关代码。' >> $readme_file
	echo -e '\n---' >> $readme_file
	echo >> $readme_file

	gen_readme

	return 0
}

main

exit 0
