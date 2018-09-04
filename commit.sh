show_status() {
	git config core.quotepath false

	if git status | grep 'nothing to commit'; then
		return 1
	else
		echo "Changed files: "
		git status -s -u
		return 0
	fi
}

commit() {
	rm -fr site

	git add *
	git commit -m "commit"

	echo "Committing ..."
	git push origin master
	
	python -m mkdocs gh-deploy --force
}

function main
{
	if ! show_status; then
		return 0
	fi

	echo -e "--------------------------\nIs it ok [y/n]: \c"
	read answer

	if [ "$answer" == "y" ]; then
		commit
	fi
}

main $@
