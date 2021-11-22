#! /bin/bash

while true; do
	sleep 3

	git pull origin master

	echo "[$(date)] mkdocs gh-deploy"
	mkdocs gh-deploy
done
