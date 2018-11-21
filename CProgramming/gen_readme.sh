#! /bin/bash

# 创建 README.md 的脚本

filename=README.md
chapters=26

main()
{
	rm -f $filename
	touch $filename

	echo -e "# C语言程序设计：现代方法\n" >> $filename
	echo -e "学习环境：CentOS 7, VS Code & MinGW & Git-Bash\n" >> $filename
	echo -e "---\n" >> $filename

	# gen exercises
	echo -e "## 练习题\n" >> $filename
	local i=2
	while [ $i -le $chapters ]; do
		local chapter_prefix=ch$(printf "%.2d\n" $i)
		local chapter_num=$i
		i=$((i+1))

		local chapter_dir=$(ls -d $chapter_prefix* 2>/dev/null)
		if [ "$chapter_dir" == "" ]; then
			continue
		fi

		cd "$chapter_dir"

		local ex_files=$(ls -f ex_*)

		local chapter_name="第${chapter_num}章 ${chapter_dir##*_}"
		echo -e "### $chapter_name\n" >> ../$filename

		echo "|E|X|E|R|C|I|S|E|" >> ../$filename
		echo "| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |" >> ../$filename
			
		local num=0 # 第几个练习
		for ex_file in $ex_files; do
			num=$((num + 1))
			echo -e "|[练习$num](./$chapter_dir/$ex_file)\c" >> ../$filename

			# 8列一行
			if [ $((num % 8)) = "0" ]; then
				echo "|" >> ../$filename
			fi
		done

		if [ $((num % 8)) != "0" ]; then
			echo "|" >> ../$filename
		fi

		echo >> ../$filename

		cd ..
	done

}

main $@
