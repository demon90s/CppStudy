#! /bin/bash

while true; do
	sleep 3

	if git pull origin master | grep '^Updating' ; then

		echo "[$(date)] mkdocs gh-deploy"
		mkdocs gh-deploy

	fi
done
