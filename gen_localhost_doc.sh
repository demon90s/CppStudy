function main
{
	#nohup python -m mkdocs serve -a 127.0.0.1:8999 &
	python -m mkdocs serve -a 127.0.0.1:8999
}

main $@
