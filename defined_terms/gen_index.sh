#! /bin/bash

old_dir=$(pwd)
out_file=terms_index.md

#######################################################################

# 设置每一个章节名字

get_all_chapters()
{
cat << !CHAPTERS!
第1章_开始
第2章_变量和基本类型
!CHAPTERS!
}

#第3章_字符串、向量和数组
#第4章_表达式
#第5章_语句
#第6章_函数
#第7章_类

chapters=$(get_all_chapters)

######################################################################

# 生成该章节的索引文本
gen_ch_index()
{
	dir=$1
	cd $dir
	terms=$(ls *.md) # 所有的术语文本
	cd $old_dir

	for term in $terms; do
		# 截取术语的英文名：文件名 -> 去掉后缀.md -> 将'_'替换成' '
		term_name=${term%.md}
		term_name=$(echo $term_name | sed 's/_/ /g')
		
		# 截取术语的中文名：文件第一行 -> 参数（... -> 参数
		first_line=$(head -1 ./$dir/$term)
		term_name_cn=${first_line%%（*}
		if [ "$first_line" = "$term_name_cn" ]; then
			# 没有中文的情况
			tag="[$term_name](./$dir/$term)"
		else
			tag="[$term_name_cn $term_name](./$dir/$term)"
		fi

		echo -e "- $tag" >> $out_file
	done
}

gen_index()
{
	n_ch=0 		# 当前处理的第几章
	for ch_name in $chapters; do
		n_ch=$(($n_ch + 1))

		cur_ch=ch # 章节的英文路径开头

		if [ $n_ch -lt 10 ]; then
			cur_ch=ch0
		fi

		cur_ch=${cur_ch}$n_ch

		echo "### $ch_name" >> $out_file
		echo >> $out_file
		gen_ch_index $cur_ch
		echo >> $out_file
	done

	return 0
}

rm -f $out_file
touch $out_file

gen_index
