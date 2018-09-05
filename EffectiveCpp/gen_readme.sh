# 生成 README.md 文件

#! /bin/bash

FILE=README.md
OLD_PATH=$(pwd)

code_convert()
{
	cd ${OLD_PATH}/src/rules

	for rule in rule*; do
		if iconv -f gb2312 -t utf8 $rule > /dev/nul 2>&1 ; then
			iconv -f gb2312 -t utf8 $rule -o $rule
		fi
	done

	cd $OLD_PATH
}

main()
{
	rm -f $FILE
	touch $FILE

	#echo "generate README.md for EffectiveCpp"

	echo "# Effective C++ Rules" >> $FILE
	echo -e "\n测试环境：vs2015 CentOS7，使用 CMake 构建" >> $FILE
	echo -e "\n---" >> $FILE

	code_convert

	# generate link
	cd ${OLD_PATH}/src/rules
	for rule_h in rule*.h; do
		local desc=$(sed -n 1p $rule_h)

		desc=$(echo $desc | sed 's/\/\/ //g')

		echo -e "\n[$desc](./src/rules/$rule_h)\n" >> $OLD_PATH/$FILE
	done
}

main $@
