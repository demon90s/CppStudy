#! /bin/bash

# 提交代码到github

get_all_dir() {
	all_files=`ls`
	for f in $all_files; do
		if [ -d $f ]; then
			echo -e "$f \c"
		fi
	done
}

clear_build() {
	all_dir=$(get_all_dir)
	for d in $all_dir; do
		cd $d
			if [ -f build.sh ]; then
				sh build.sh clear
			elif [ -f Makefile ]; then
				make clean
			fi
		cd ..
	done

	cd labs
	sh build.sh clear
	cd ..
}

show_status() {
	if git status | grep 'nothing to commit'; then
		return 1
	else
		echo "Changed files: "
		git status -s -u
		return 0
	fi
}

commit() {
	git add -f *
	git commit -m "commit"

	echo "Committing ..."
	git push origin master
}

main() {
	clear_build
	rm -rf site

	sh ./gen_readme.sh

	if [ "$1" = "-t" ]; then
		cd ./defined_terms
		sh ./gen_index.sh
		cd ..
	fi

	if ! show_status; then
		return 0
	fi

	echo -e "--------------------------\nIs it ok [y/n]: \c"
	read answer

	if [ "$answer" == "y" ]; then
		commit
	fi
}

main $*

exit 0
